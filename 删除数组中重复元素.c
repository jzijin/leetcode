#include <stdio.h>
// int removeDuplicates(int* nums, int numsSize) {
//     //int newnums[numsSize] = {0};
//     int len = numsSize;
//     for(int i=0; i<len; i++)
//     {
//         for (int j=0; j<i; j++)
//         {
//             if(nums[i] == nums[j])
//             {
//                 len--;
//                 for(int l=i;l<len;l++)
//                 {
//                     nums[l] = nums[l+1];
//                 }
//                 i--;
//                 break;
//             }
//         }
        
//     }
//     return len;
// }


// 这个算法的速度更快一些
int removeDuplicates(int* nums, int numsSize) {
    //int newnums[numsSize] = {0};
    int i=0,j=0;
    if(!numsSize)
        return 0;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[j])
            nums[++j]=nums[i];       
    }
    return j+1;
}

int main()
{
    int nums[6] = {1,1,2,2,3,4};
    int len = removeDuplicates(nums, 6);
    printf("%d\n", len);
    for(int i=0;i<len;i++)
    {
        printf("%d\n", nums[i]);
    }
    return 0;
}