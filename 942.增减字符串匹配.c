/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int s_length = strlen(S);
    // printf("%d\n", s_length);
    *returnSize = s_length+1;
    int *target = (int *)malloc(sizeof(int)*(s_length+1));
    // printf("%d", sizeof(target))
    int min = 0;
    int max = s_length;
    int index=0;
    for(int i=0; i<s_length;i++)
    {
        if(S[i] == 'I')
        {
            target[index] = min;
            
            min++;
        }
        else
        {
            target[index] = max;
            max--;
        }
        index++;
    }
    // printf("index=%d max=%d", index, max);
    target[index] = max;
    return target;
    
}