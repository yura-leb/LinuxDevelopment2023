#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rhash.h>
#include <errno.h>
#include "config.h"

#ifdef USE_READLINE
  #include <readline/readline.h>
#endif

#ifndef DX
#define DX 3
#endif


int calculate_msg_from_string(const char* msg, int hash_id, int is_hexadeximal) {
    char digest[64];
    char output[130];

    int res = rhash_msg(hash_id, msg, strlen(msg), digest);
    if (res < 0) {
        fprintf(stderr, "Message digest calculation error\n");
        return 1;
    }

    if (is_hexadeximal) {
        rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1),
            RHPR_HEX);
    } else {
        rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1),
            RHPR_BASE64);
    }

    printf("%s\n", output);
    return 0;
}

int calculate_msg_from_file(const char* filepath, int hash_id, int is_hexadeximal) {
    char digest[64];
    char output[130];

    int res = rhash_file(hash_id, filepath, digest);
    if (res < 0) {
        fprintf(stderr, "LibRHash error: %s: %s\n", filepath, strerror(errno));
        return 1;
    }

    if (is_hexadeximal) {
        rhash_print_bytes(output, digest, rhash_get_digest_size(hash_id),
            RHPR_HEX);
    } else {
        rhash_print_bytes(output, digest, rhash_get_digest_size(hash_id),
            RHPR_BASE64);
    }

    printf("%s\n", output);
    return 0;
}


int main() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int is_hexadeximal = 0; // 0 for base64, 1 for hexadeximal
    int hash_id = 0;
    rhash_library_init();
    #ifdef USE_READLINE
    while ((line = readline(NULL)) != NULL) {
    #else
    while ((read = getline(&line, &len, stdin)) != -1) {
    #endif
        char* token = strtok(line, " \n");
        if (token) {
            if (strcasecmp(token, "MD5") == 0 || strcasecmp(token, "SHA1") == 0 || strcasecmp(token, "TTH") == 0) {
                if (token[0] >= 'a' && token[0] <= 'z') {
                    is_hexadeximal = 0;
                } else {
                    is_hexadeximal = 1;
                }

                if (strcasecmp(token, "MD5") == 0)
                    hash_id = RHASH_MD5;
                else if (strcasecmp(token, "SHA1") == 0)
                    hash_id = RHASH_SHA1;
                else
                    hash_id = RHASH_TTH;

                token = strtok(NULL, " \n");
                if (token) {
                    if (token[0] == '"') {

                        calculate_msg_from_string(token + 1, hash_id, is_hexadeximal);
                    } 
                    else {
                        calculate_msg_from_file(token, hash_id, is_hexadeximal);
                    }
                }
            } else {
                fprintf(stderr, "Unrecognized command: %s\n", token);
            }
        }
    }

    free(line);
    return 0;
}
