#include <string.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    if (n > m) return 0;

    unsigned long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= m; i++) {
        // Lower bound: can't match more of t than characters processed in s
        int min_j = (i < n) ? i : n;
        // Upper bound: leave enough characters in s to match remaining t
        int max_j = 1 > (n - (m - i)) ? 1 : (n - (m - i));

        for (int j = min_j; j >= max_j; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return (int)dp[n];
}