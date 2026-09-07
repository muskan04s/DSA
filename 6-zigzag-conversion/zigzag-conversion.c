#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Edge cases
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int count = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            // Add vertical column character
            result[count++] = s[j + i];

            // Add diagonal character for middle rows
            int diagIdx = j + cycleLen - i;
            if (i != 0 && i != numRows - 1 && diagIdx < len) {
                result[count++] = s[diagIdx];
            }
        }
    }

    result[count] = '\0';
    return result;
}