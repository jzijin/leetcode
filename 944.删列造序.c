int minDeletionSize(char** A, int ASize) {
    int res = 0;
    for(int i=0; i<strlen(A[0]); i++)// 判断第i列要不要删
    {
        for(int j=1; j<ASize; j++)
        {
            if (A[j][i] < A[j-1][i]) // 要删
            {
                res++;
                break;
            }
        }
    }
    return res;
}