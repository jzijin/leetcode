/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.85%)
 * Total Accepted:    10.2K
 * Total Submissions: 29.2K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge_(struct Interval *intervals, struct Interval *tmp, int start, int mid, int end)
{
    int i = start, j = mid+1, k = start;
    while(i!=mid+1&&j!=end+1)
    {
        if(intervals[i].start > intervals[j].start)
        {
            tmp[k++] = intervals[j++];
        }
        else
        {
            tmp[k++] = intervals[i++];
        }
    }
    while(i!=mid+1)
    {
        tmp[k++] = intervals[i++];
    }
    while(j!=end+1)
    {
        tmp[k++] = intervals[j++];
    }
    for(i = start; i<=end; i++)
    {
        intervals[i] = tmp[i];
    }
}
void mergesort(struct Interval *intervals, struct Interval *tmp, int start, int end)
{
    int mid;
    if(start < end)
    {
        mid = start + (end-start)/2; // 避免int数组的溢出
        mergesort(intervals, tmp, start, mid);
        mergesort(intervals, tmp, mid+1, end);
        merge_(intervals, tmp, start, mid, end);
    }
}
void insertsort(struct Interval *intervals, int intervalsSize)
{
    for (int i = 1; i < intervalsSize; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (intervals[j].start > intervals[i].start)
            {
                struct Interval tmp = intervals[j];
                intervals[j] = intervals[i];
                intervals[i] = tmp;
            }
        }
    }
}
void selectsort(struct Interval *intervals, int intervalsSize)
{
    int k;
    for (int i = 0; i < intervalsSize-1; i++)
    {
        k=i;
        for (int j = k + 1; j < intervalsSize; j++)
        {
            if (intervals[j].start < intervals[k].start)
            {
                k = j;
                
            }
        }
        if (i!=k)
        {
            struct Interval tmp = intervals[i];
            intervals[i] = intervals[k];
            intervals[k] = tmp;
        }
    }
}
// 快速排序法。。。 手写快速排序什么感受？？？？
void quicksort(struct Interval *intervals, int start, int end)
{
    int i, j;
    struct Interval temp;
    if (start > end)
    {
        return;
    }
    temp = intervals[start];
    i = start;
    j = end;
    while (i != j)
    {
        while (i < j && intervals[j].start >= temp.start)
        {
            j--;
        }
        while (i < j && intervals[i].start <= temp.start)
        {
            i++;
        }
        if (i < j)
        {
            struct Interval tmp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = tmp;
        }
    }
    intervals[start] = intervals[i];
    intervals[i] = temp;
    quicksort(intervals, start, i - 1);
    quicksort(intervals, i + 1, end);
}
// 开始堆排序
void swap(struct Interval *a, struct Interval *b)
{
    struct Interval temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(struct Interval *intervals, int start, int end)
{
    int dad = start;
    int son = 2*start + 1;
    while(son<=end)
    {
        if(son+1<=end && intervals[son+1].start > intervals[son].start)
        {
            son++;
        }
        if(intervals[dad].start > intervals[son].start)
        {
            return; // 父节点比子节点大 不需要排序
        }
        else
        {
            swap(&intervals[dad], &intervals[son]);
            dad = son;
            son = 2*dad + 1;
        }
    }
}
void heap_sort(struct Interval *intervals, int intervalsSize)
{
    for(int i=intervalsSize/2-1;i>=0;i--)
    {
        max_heapify(intervals, i, intervalsSize-1);
    }
    for(int i=intervalsSize-1; i>=0;i--)
    {
        swap(&intervals[i], &intervals[0]);
        max_heapify(intervals, 0, i-1);
    }
}

struct Interval *merge(struct Interval *intervals, int intervalsSize, int *returnSize)
{
    // 创建足够大小的 足够返回
    struct Interval *target = (struct Interval *)malloc(sizeof(struct Interval *) * intervalsSize);
    if (intervalsSize <= 0)
    {
        *returnSize = 0;
        return target;
    }

    // for (int i = 0; i < intervalsSize - 1; i++)
    // {
    //     for (int j = 0; j < intervalsSize - 1 - i; j++)
    //     {
    //         if (intervals[j].start > intervals[j + 1].start)
    //         {
    //             // 根据start元素的大小排序 冒泡排序
    //             struct Interval tmp = intervals[j];
    //             intervals[j] = intervals[j + 1];
    //             intervals[j + 1] = tmp;
    //         }
    //     }
    // }
    // 快速排序
    // quicksort(intervals, 0, intervalsSize - 1);
    // 选择排序
    // selectsort(intervals, intervalsSize);
    //插入排序
    // insertsort(intervals, intervalsSize);
    // 堆排序
    // heap_sort(intervals, intervalsSize);
    // 归并排序
    mergesort(intervals, target, 0, intervalsSize-1);
    int count = 0;
    for (int i = 0; i < intervalsSize - 1; i++)
    {
        // 如果满足条件 合并
        if (intervals[i].end >= intervals[i + 1].start)
        {
            // 更新start的值
            intervals[i + 1].start = intervals[i].start;
            // 更新end的值
            intervals[i + 1].end = intervals[i + 1].end > intervals[i].end ? intervals[i + 1].end : intervals[i].end;
        }
        else
        {
            // 如果不需要合并 那么把它记录下来
            target[count++] = intervals[i];
        }
    }
    // 处理最后一个节点
    target[count++] = intervals[intervalsSize - 1];
    *returnSize = count;
    return target;
}
