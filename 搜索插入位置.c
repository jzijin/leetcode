int searchInsert(int* nums, int numsSize, int target) {
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i] >= target)
        {
            return i;
        }        
    }
    return i;
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