/*
 * @lc app=leetcode.cn id=274 lang=c
 *
 * [274] H指数
 *
 * https://leetcode-cn.com/problems/h-index/description/
 *
 * algorithms
 * Medium (33.31%)
 * Total Accepted:    1.8K
 * Total Submissions: 5.2K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * 给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
 * 
 * h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有 h
 * 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）”
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: citations = [3,0,6,1,5]
 * 输出: 3 
 * 解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
 * 由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
 * 
 * 
 * 
 * 说明: 如果 h 有多种可能的值，h 指数是其中最大的那个。
 * 
 */
// 不知道为什么这边的 快速排序有点问题 妈的 居然把while 写成if 不可原谅 傻逼
void quicksort(int *citations, int start, int end)
{
    if(start > end)
    {
        return;
    }
    int i,j,temp;
    temp = citations[start];
    i = start;
    j = end;
    
    while(i!=j)
    {
        while(i<j&&citations[j] >= temp)
        {
            j--;
        }
        while(i<j&&citations[i] <= temp)
        {
            i++;
        }
        if(i<j)
        {
            int tmp = citations[i];
            citations[i] = citations[j];
            citations[j] = tmp;
        }
    }
    citations[start] = citations[i];
    citations[i] = temp;
    
    quicksort(citations, start, i-1);
    quicksort(citations, i+1, end);
}
int hIndex(int* citations, int citationsSize) {
    for(int i=0;i<citationsSize-1; i++)
    {
        int k = i;
        for(int j=k+1; j<citationsSize; j++)
        {
            if(citations[j] > citations[k])
            {
                k = j;
            }
        }
        if(i!=k)
        {
            int tmp = citations[i];
            citations[i] = citations[k];
            citations[k] = tmp;
        }
    }
    int cur = 0;
    for(int i=0; i<citationsSize; i++)
    {
        if (citations[i] > cur)
        {
            cur++;
        }
    }
    
    return cur;
}

