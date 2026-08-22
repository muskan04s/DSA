#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen index of each ASCII character
    int charMap[256];
    
    // Initialize all character positions to -1 (unseen)
    memset(charMap, -1, sizeof(charMap));
    
    int left = 0;
    int maxLength = 0;
    
    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char currentChar = (unsigned char)s[right];
        
        // If the character was seen inside the current window, move the left pointer
        if (charMap[currentChar] >= left) {
            left = charMap[currentChar] + 1;
        }
        
        // Update the character's last seen index
        charMap[currentChar] = right;
        
        // Calculate current window length
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}