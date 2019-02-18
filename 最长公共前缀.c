char *longestCommonPrefix(char **strs, int strsSize)
{
    int i, j, index;
    int last = 0;
    int flag = 1; // 用来第一次设置last 变量
    if (strsSize == 0)
    {
        return "";
    }
    if (strsSize == 1)
    {
        return *strs;
    }
    for (i = 0; i < strsSize - 1; i++)
    {
        if (*(*(strs + i)) == '\0' || *(*(strs + i + 1)) == '\0')
        {
            return "";
        }
        // 每次重进循环 重置index
        index = 0;
        // 计算
        int l = 0;
        while (1)
        {
            if (*(*(strs + i) + l) != *(*(strs + i + 1) + l))
            {
                break;
            }
            if (*(*(strs + i) + l) == *(*(strs + i + 1) + l))
            {
                index++;
            }
            l++;
        }
        if (flag)
        {
            last = index;
            flag = 0;
        }
        if (last > index)
        {
            last = index;
        }
    }
    if (!last)
    {
        return "";
    }
    // 多开辟一位来接收结束符'\0'
    char *target = (char *)malloc(sizeof(char) * (last + 1));
    for (j = 0; j < last; j++)
    {
        target[j] = *(*strs + j);
    }
    target[last] = '\0';
    return target;
}