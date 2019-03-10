int smallestRangeI(int* A, int ASize, int K) {
    // 简单选择排序
    // 本质上是找出最大值和最小值在和2*K来比较
    for(int i=1; i<ASize; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j] > A[i])
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
    return A[ASize-1]-A[0] > 2*K ? A[ASize-1]-A[0]-2*K:0;
}