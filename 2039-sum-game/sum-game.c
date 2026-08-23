#include <stdbool.h>
#include <string.h>

bool sumGame(char* num) {
    int diff = 0;
    int len = strlen(num);
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        diff += (num[i] == '?') ? 9 : (num[i] - '0') * 2;
        diff -= (num[j] == '?') ? 9 : (num[j] - '0') * 2;
    }
    
    return diff != 0;
}