#include <limits.h>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Always ensure nums1 is the smaller array to minimize binary search steps
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int i = low + (high - low) / 2; // Partition index for nums1
        int j = (m + n + 1) / 2 - i;   // Partition index for nums2

        // Handle edge cases using INT_MIN and INT_MAX for out-of-bounds bounds
        int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];

        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        // Valid partition found
        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 1) {
                // Odd total length: median is max of left elements
                return (double)MAX(left1, left2);
            } else {
                // Even total length: average of max of left and min of right
                return (MAX(left1, left2) + MIN(right1, right2)) / 2.0;
            }
        } 
        // Too many elements from nums1, shift partition left
        else if (left1 > right2) {
            high = i - 1;
        } 
        // Too few elements from nums1, shift partition right
        else {
            low = i + 1;
        }
    }

    return 0.0;
}