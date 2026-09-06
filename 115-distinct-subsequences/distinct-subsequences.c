#include <string.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    // dp[j] holds the number of ways to form t[0...j-1]
    unsigned long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    
    // Base case: empty t can always be formed 1 way
    dp[0] = 1;
    
    for (int i = 1; i <= m; i++) {
        // Traverse backwards to avoid overwriting values needed for current row
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    
    return (int)dp[n];
}