int removeElement(int* nums, int numsSize, int val) {
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == val)
        {
            
            for(int j=i; j<numsSize-1; j++)
            {
                nums[j] = nums[j+1];
            }
            numsSize--;
            i--;
        }
        
        
    }
    return numsSize;
}

// 直接和最后一个元素交换 
int removeElement(int* nums, int numsSize, int val) {
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == val)
        {
            
            nums[i] = nums[numsSize-1];
            numsSize--;
            i--;
        }
        
        
    }
    return numsSize;
}