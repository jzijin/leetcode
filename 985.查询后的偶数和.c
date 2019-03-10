/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int *queriesColSizes, int* returnSize) {
    *returnSize = queriesRowSize;
    int sum = 0;
    int index = 0;
    int* answer = (int *)malloc(sizeof(int)*queriesRowSize);
    for(int i=0; i<queriesRowSize; i++)
    {
        A[queries[i][1]] +=  queries[i][0];
        sum = 0;
        for(int j=0; j<ASize; j++)
        {
            if(A[j] % 2 == 0)
            {
                sum += A[j];
            }
        }
        answer[index++] = sum;
        
    }
    return answer;
}