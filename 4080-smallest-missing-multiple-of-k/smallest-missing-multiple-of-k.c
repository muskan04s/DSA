#include <stdbool.h>

int missingMultiple(int* nums, int numsSize, int k) {
    // Frequency array or hash table for elements up to max possible value (100)
    bool present[101] = {false};
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 100) {
            present[nums[i]] = true;
        }
    }
    
    // Check positive multiples of k starting from k
    for (int multiple = k; ; multiple += k) {
        // If the multiple exceeds constraints, it cannot be in nums
        if (multiple > 100 || !present[multiple]) {
            return multiple;
        }
    }
}