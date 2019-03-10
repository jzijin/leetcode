int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    if(N==1)
    {
        return 1;
    }
    int * target = (int *)malloc(sizeof(int)*(N+1));
    memset(target, 0, sizeof(int)*(N+1));
    int * target2 = (int *)malloc(sizeof(int)*(N+1));
    memset(target2, 0, sizeof(int)*(N+1));
    for(int i=0; i<trustRowSize; i++)
    {
        
        
        target2[trust[i][0]]++;
        target[trust[i][1]]++;
    }
    // for(int i=0; i<N+1; i++)
    for(int i=0; i<N+1; i++)
    {
        // printf("target=%d, target2 = %d", target[i], target2[i]);
        if(target[i] == N-1 && target2[i] == 0)
        {
            return i;
        }
    }
    return -1;
}