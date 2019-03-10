void quicksort(int *nums, int start, int end)
{
    int i,j,t,temp;
    
    if(start > end)
    {
        return;
    }
    temp = nums[start];
    i = start;
    j = end;
    while(i!=j)
    {
        while(i<j&&nums[j] >= temp)
        {
            j--;
        }
        while(i<j&&nums[i] <= temp)
        {
            i++;
        }
        if(i<j)
        {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        
    }
    nums[start] = nums[i];
    nums[i] = temp;
    quicksort(nums, start, i-1);
    quicksort(nums, i+1, end);
}
int largestPerimeter(int* A, int ASize) {
    quicksort(A, 0, ASize-1);
    int sum = 0;
    for(int i=ASize-1; i>=2;i--)
    {
        if(A[i] < A[i-1] + A[i-2])
        {
            sum =  A[i] + A[i-1] + A[i-2];
            break;
        }
    }
    return sum;
}