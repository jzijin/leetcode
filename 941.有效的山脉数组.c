bool validMountainArray(int* A, int ASize) {
    // 第一步先找到最大值
    int max = -1;
    int i;
    for(i=0; i<ASize; i++)
    {
        if(A[i] == max)
        {
            return false;
        }
        if(A[i] > max)
        {
            max = A[i];
        }
        if(A[i] < max)
        {
            break;
        }
    }
    // 如果是第一个数最大 或者说是最后一个数最大 那么应该直接返回否
    if(i == 1 || i==ASize)
    {
        return false;
    }
    printf("%d\n", i);
    // i = i-1;
    for(;i<ASize-1; i++)
    {
        if(A[i] <= A[i+1])
        {
            return false;
        }
    }
    return true;
    
}