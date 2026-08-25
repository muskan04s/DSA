#include <string.h>

int maximumLengthSubstring(char* s) {
    int freq[26] = {0};
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        freq[s[right] - 'a']++;
        
        // Shrink the window from the left if any character exceeds 2 occurrences
        while (freq[s[right] - 'a'] > 2) {
            freq[s[left] - 'a']--;
            left++;
        }
        
        // Track the maximum window size
        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    
    return maxLen;
}