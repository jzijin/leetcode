/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int aaa = K;
    int bbb = 0;
    while(aaa)
    {
        aaa/=10;
        bbb++;
    }
    int size = ASize > bbb ? ASize+1 : bbb+1;
    printf("%d\n", size);
    // exit(0);
    int *target = (int *)malloc(sizeof(int)*(size));
    memset(target, 0, sizeof(int)*(size));
    int index = 0;
    int end = ASize-1;
    int carry = 0;
    
    int tmp;
    int ccc = size-1;
    while(ccc)
    {
        int yu = K%10;
        K /=10;
        if(end < 0)
        {
            tmp = yu + carry;
        }
        else
        {
            tmp = A[end] + yu + carry;
        }
        
        if(tmp >= 10)
        {
            tmp = tmp - 10;
            carry = 1;
        }
        else
        {
            // 如果没有大于10的话 要重新把carry 变成0
            carry = 0;
        }
        target[index++] = tmp;
        end--;
        ccc--;
    }
    // 如果最高位数还是有进位的话
    if(carry)
    {
        target[index++] = carry;
    }
    
    for(int i=0; i<size; i++)
    {
        printf("%d\n", target[i]);
    }
    // 最后一位没有用到的话
    if(target[size-1] == 0)
    {
        *returnSize = size-1;
        int *final = (int *)malloc(sizeof(int)*(size-1));
        end = size-2;
        for(int i=0; i<size-1; i++)
        {
            final[i] = target[end];
            end--;
        }
        return final;
    }
    
        *returnSize = size;
        int *final = (int *)malloc(sizeof(int)*(size));
        end = size-1;
        for(int i=0; i<size; i++)
        {
            final[i] = target[end];
            end--;
        }
        return final;
}