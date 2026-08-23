#include <stdbool.h>
#include <string.h>

bool sumGame(char* num) {
    double diff = 0;
    
    // Two pointers moving inward: i from start, j from end
    for (int i = 0, j = strlen(num) - 1; i < j; i++, j--) {
        diff += (num[i] == '?') ? 4.5 : (num[i] - '0');
        diff -= (num[j] == '?') ? 4.5 : (num[j] - '0');
    }
    
    // If net diff is non-zero, Alice can force a win
    return diff != 0;
}

