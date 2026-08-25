#include <stdio.h>

int largestInteger(int* nums, int numsSize, int k) {
    int count[51] = {0};
    
    // Case 1: k == 1
    // Every element is its own subarray. Find the largest number with total frequency 1.
    if (k == 1) {
        for (int i = 0; i < numsSize; i++) {
            count[nums[i]]++;
        }
        for (int val = 50; val >= 0; val--) {
            if (count[val] == 1) {
                return val;
            }
        }
        return -1;
    }
    
    // Case 2: k == numsSize
    // Only 1 subarray exists (the entire array). Return the largest number in nums.
    if (k == numsSize) {
        int maxVal = -1;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        return maxVal;
    }
    
    // Case 3: 1 < k < numsSize
    // Only boundary elements (nums[0] and nums[numsSize - 1]) can appear in exactly one subarray.
    // Count full array occurrences to ensure they don't repeat elsewhere.
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    
    int ans = -1;
    if (count[nums[0]] == 1) {
        ans = nums[0];
    }
    if (count[nums[numsSize - 1]] == 1 && nums[numsSize - 1] > ans) {
        ans = nums[numsSize - 1];
    }
    
    return ans;
}