#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r;
    int c;
    int mask;
    int e;
} State;

#define MAX_M 20
#define MAX_N 20
#define MAX_MASKS 1024 // 2^10
#define MAX_QUEUE_SIZE 1500000

static int best_energy[MAX_M][MAX_N][MAX_MASKS];
static State queue[MAX_QUEUE_SIZE];

int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);
    
    int start_r = -1, start_c = -1;
    int litter_grid[MAX_M][MAX_N];
    memset(litter_grid, -1, sizeof(litter_grid));
    
    int litter_count = 0;
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (classroom[r][c] == 'S') {
                start_r = r;
                start_c = c;
            } else if (classroom[r][c] == 'L') {
                litter_grid[r][c] = litter_count++;
            }
        }
    }
    
    int full_mask = (1 << litter_count) - 1;
    if (full_mask == 0) return 0;
    
    memset(best_energy, -1, sizeof(best_energy));
    
    int head = 0, tail = 0;
    
    queue[tail++] = (State){start_r, start_c, 0, energy};
    best_energy[start_r][start_c][0] = energy;
    
    int moves = 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (head < tail) {
        int level_size = tail - head;
        
        for (int i = 0; i < level_size; i++) {
            State curr = queue[head++];
            
            if (curr.mask == full_mask) {
                return moves;
            }
            
            if (curr.e == 0) continue;
            
            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dirs[d][0];
                int nc = curr.c + dirs[d][1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int next_mask = curr.mask;
                    char cell = classroom[nr][nc];
                    
                    if (cell == 'L') {
                        next_mask |= (1 << litter_grid[nr][nc]);
                    }
                    
                    int next_e = (cell == 'R') ? energy : curr.e - 1;
                    
                    if (next_e > best_energy[nr][nc][next_mask]) {
                        best_energy[nr][nc][next_mask] = next_e;
                        queue[tail++] = (State){nr, nc, next_mask, next_e};
                    }
                }
            }
        }
        moves++;
    }
    
    return -1;
}