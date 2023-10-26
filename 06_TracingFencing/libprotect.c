#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

int remove(const char *pathname) {
    if (strstr(pathname, "PROTECT") != NULL) {
        printf("File deletion prevented: %s\n", pathname);
        return 0;
    }

    int (*orig_remove)(const char *) = dlsym(RTLD_NEXT, "remove");
    return orig_remove(pathname);
}