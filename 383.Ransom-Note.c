// 和350 两个数组的交集类似的
bool canConstruct(char* ransomNote, char* magazine) {
    int r_length = strlen(ransomNote);
    int m_length = strlen(magazine);
    if(r_length > m_length)
    {
        return false;
    }
    
    int index = 0;
    // 定义flag 数组来标识是否已经匹配过的字符 匹配数组选择小的 节省空间开销
    int *flag = (int *)malloc(sizeof(int) * m_length);
    memset(flag, 0, m_length);
    for (int i = 0; i < r_length; i++)
    {
        for (int j = 0; j < m_length; j++)
        {
            // 如果已经匹配过的话 结束本次
            if (flag[j] == 1)
            {
                continue;
            }
            if (ransomNote[i] == magazine[j])
            {
                // 匹配到的话 设定匹配数组
                flag[j] = 1;
                // 设定值
                ransomNote[index++] = ransomNote[i];
                break;
            }
        }
    }
    ransomNote[index] = '\0';
    
    if(strlen(ransomNote) < r_length)
    {
        return false;
    }
    return true;
}