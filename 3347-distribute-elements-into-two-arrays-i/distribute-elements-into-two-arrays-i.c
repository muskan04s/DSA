/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    //memory allocate 
    int* arr1 = (int*)malloc((numsSize) * sizeof(int));
    int* arr2 = (int*)malloc((numsSize) * sizeof(int));
    int* result =(int*)malloc((numsSize) * sizeof(int));

    //to track how many elements in memory
    int size1 = 0;
    int size2 = 0;

    //op 1
    arr1[size1++] = nums[0];
    //op2
    arr2[size2++] = nums[1];
    //condition check on rest elements 

    for(int i=2; i < numsSize; i++){
       if(arr1[size1-1] > arr2[size2-1]) {
        arr1[size1++] = nums[i];
       } else {
        arr2[size2++] = nums[i];
       }
    }

    //concatenate arr1
    int k = 0;
    for(int i = 0; i< size1; i++){
        result[k++] = arr1[i];
    }

    //concatenate arr2
    for(int i =0; i< size2; i++){
        result[k++]= arr2[i];
    }

    //free the dynamic space
    free(arr1);
    free(arr2);

    *returnSize = numsSize;
    return result;
}