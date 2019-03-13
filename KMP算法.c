/*
PMT中的值是字符串的前缀集合与后缀集合的交集中最长元素的长度。例如，对于”aba”，它的前缀集合为{”a”, ”ab”}，后缀 集合为{”ba”, ”a”}。两个集合的交集为{”a”}，那么长度最长的元素就是字符串”a”了，长 度为1，所以对于”aba”而言，它在PMT表中对应的值就是1。再比如，对于字符串”ababa”，它的前缀集合为{”a”, ”ab”, ”aba”, ”abab”}，它的后缀集合为{”baba”, ”aba”, ”ba”, ”a”}， 两个集合的交集为{”a”, ”aba”}，其中最长的元素为”aba”，长度为3。
*/
//https://blog.csdn.net/x__1998/article/details/79951598
// 主体的比较部分还是比较简单的 关键是如何才能计算得到next 数组呢
int KMP(char *t, char *p)
{
    int i = 0;
    int j = 0;

    while (i < strlen(t) && j < strlen(p))
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }

        if (j == strlen(p))
            return i - j;
        else
            return -1;
    }
}
// 下面介绍next数组的计算
/*
现在，我们再看一下如何编程快速求得next数组。其实，求next数组的过程完全可以看成字符串匹配的过程，即以模式字符串为主字符串，以模式字符串的前缀为目标字符串，一旦字符串匹配成功，那么当前的next值就是匹配成功的字符串的长度。

具体来说，就是从模式字符串的第一位(注意，不包括第0位)开始对自身进行匹配运算。 在任一位置，能匹配的最长长度就是当前位置的next值。如下图所示。
*/
//https://www.cnblogs.com/en-heng/p/5091365.html

// 得到next数组
void getnext(char* s, int* next)
{
    int i = 0;
    int k = -1;
    int m = strlen(s)
    while(i<m-1)
    {
        if k== -1 || s[i] == s[k]
        {
            i++; k++
            next[i] = k // 设置next

        }
        else
        {
            // 回溯
            k = next[k]
        }
        
    }
}
