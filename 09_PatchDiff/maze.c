#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init_maze(int n, char maze[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0 || j % 2 == 0) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = '.';
            }
        }
    }
}


void generate_maze(int n, char maze[n][n]) {
    srand(time(NULL)); 
    int num_rooms = (n - 1) / 2;
    int num_visited = 0;
    int visited[num_rooms][num_rooms]; 
    int visited_list[num_rooms * num_rooms];
    for (int i = 0; i < num_rooms; ++i) {
        for (int j = 0; j < num_rooms; ++j) {
            visited[i][j] = 0;
            visited_list[num_rooms * i + j] = 0;
        }
    }
    visited[0][0] = 1; 
    visited_list[0] = 0; 
    num_visited = 1;
    int unvisited = num_rooms * num_rooms - 1; 

    while (unvisited > 0) {
        int new_room_id = 0;
        int x = 0;
        int y = 0;
        int has_unvisited_neighbours = 0;
        int neighbors[4];
        int numNeighbors = 0;

        do {
            numNeighbors = 0;
            new_room_id = rand() % num_visited;
            x = visited_list[new_room_id] / num_rooms;
            y = visited_list[new_room_id] % num_rooms;
            

            if (x == 0) {
                if (visited[x + 1][y] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[0] = (x + 1) * num_rooms + y;
                    numNeighbors++;
                }
            } else if (x == num_rooms - 1) {
                if (visited[x - 1][y] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[0] = (x - 1) * num_rooms + y;
                    numNeighbors++;
                }
            } else {
                if (visited[x + 1][y] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = (x + 1) * num_rooms + y;
                    numNeighbors++;
                }
                if (visited[x - 1][y] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = (x - 1) * num_rooms + y;
                    numNeighbors++;
                }
            }

            if (y == 0) {
                if (visited[x][y + 1] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = x * num_rooms + y + 1;
                    numNeighbors++;
                }
            } else if (y == num_rooms - 1) {
                if (visited[x][y - 1] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = x * num_rooms + y - 1;
                    numNeighbors++;
                }
            } else {
                if (visited[x][y + 1] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = x * num_rooms + y + 1;
                    numNeighbors++;

                }
                if (visited[x][y - 1] == 0) {
                    has_unvisited_neighbours |= 1;
                    neighbors[numNeighbors] = x * num_rooms + y - 1;
                    numNeighbors++;
                }
            }

        } while (!(has_unvisited_neighbours));
        int i = 0;
        int nextX = 0;
        int nextY = 0;

        i = rand() % numNeighbors; 
        nextX = neighbors[i] / num_rooms;
        nextY = neighbors[i] % num_rooms;
        int deltaX = nextX - x;
        int deltaY = nextY - y;

        maze[2 * x + 1 + deltaX][2 * y + 1 + deltaY] = '.';

        
        visited[nextX][nextY] = 1;
        visited_list[num_visited] = nextX * num_rooms + nextY;
        num_visited++;
        unvisited--;
    }
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    int n = 13;
    char maze[n][n];

    init_maze(n, maze);
    generate_maze(n, maze);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}
