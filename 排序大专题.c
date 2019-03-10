//https://www.cnblogs.com/hokky/p/8529042.html
//https://blog.csdn.net/m0_37962600/article/details/81475585
/*
如果排序算法能保证：对于待排序的序列里任一对排序吗相同的记录a,b，在排序之后的序列中a,b的前后顺序
保持不变，就称这种排序是稳定的。也就是说，稳定的算法能够维持序列中的所有排序码相同的记录的相对位置
。如果一份排序算法不能保证上述条件，它就是不稳定的。
*/
// 插入排序
/*
void insertSort(int *arr[],int len){
    int i;
    int j;
    int temp;  //定义一个临时变量，用于交换数据时存储 
    for(i=1;i<len;i++){  //因为我们要对该待排序列的每一个元素都和前面的已排好序的序列进行插入，所以我们会对序列进行遍历 
        for(j=0;j<i;j++){  //第二层循环主要用于对已排好序的序列进行扫描，和要插入进来的数据进行逐一比较，然后决定插入到哪里 
        ////从前往后对已排好序的元素和待插入元素进行大小比较，然后直到找到一个元素比被插入元素大，则交换位置 
            if(arr[j]>arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
*/
// 选择排序
/*
给定数组：int[] arr={里面n个数据}；第1趟排序，在待排序数据arr[1]~arr[n]中选出最小的数据，将它与arrr[1]交换；第2趟，在待排序数据arr[2]~arr[n]中选出最小的数据，将它与r[2]交换；以此类推，第i趟在待排序数据arr[i]~arr[n]中选出最小的数据，将它与r[i]交换，直到全部排序完成。
*/
void selectsort(int *arr)
{
    for(int i=0; i<size-1; i++)
    {
        int k=i;
        for (int j=k+1; j<size; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j; // 记录目前找到的最小元素的位置
            }
        }
        // 内层循环后，也就是找到本轮循环的最小的数之后，在进行交换
        if(i != k)
        {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
// 快速排序
void quicksort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
    {
        return;
    }
    temp = a[left]; // temp 中存的就是基准数
    i = left;
    j = right;
    while (i != j)
    {
        // 顺序很重要， 要先从右往左找
        while (a[j] >= temp && i < j)
        {
            j--;
        }
        while (a[i] <= temp && i < j)
        {
            i++;
        }
        // 交换两个数在数组中的位置
        if (i < j)
        { // 当哨兵i和哨兵j没有相遇时
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    // 最终基准数归位

    a[left] = a[i];
    a[i] = temp;
    quicksort(left, i - 1);  // 继续处理左边的 这是递归的过程
    quicksort(i + 1, right); // 处理右边的， 这也是一个递归的过程
}

// 桶排序
/*
输入是由一个随机过程产生的[0, 1)区间上均匀分布的实数。将区间[0, 1)划分为n个大小相等的子区间（桶），每桶大小1/n：[0, 1/n)， [1/n, 2/n)， [2/n, 3/n)，…，[k/n, (k+1)/n )，…将n个输入元素分配到这些桶中，对桶中元素进行排序，然后依次连接桶输入0 ≤A[1..n] <1辅助数组B[0..n-1]是一指针数组，指向桶（链表）。
*/

/* 当数比较集中的时候非常适合用桶排序 可以极大的节省时间
一年的全国高考考生人数为500 万，分数使用标准分，最低100 ，最高900 ，没有小数，要求对这500 万元素的数组进行排序。
分析：对500W数据排序，如果基于比较的先进排序，平均比较次数为O(5000000*log5000000)≈1.112亿。但是我们发现，这些数据都有特殊的条件： 100=<score<=900。那么我们就可以考虑桶排序这样一个“投机取巧”的办法、让其在毫秒级别就完成500万排序。
方法：创建801(900-100)个桶。将每个考生的分数丢进f(score)=score-100的桶中。这个过程从头到尾遍历一遍数据只需要500W次。然后根据桶号大小依次将桶中数值输出，即可以得到一个有序的序列。而且可以很容易的得到100分有***人，501分有***人。
实际上，桶排序对数据的条件有特殊要求，如果上面的分数不是从100-900，而是从0-2亿，那么分配2亿个桶显然是不可能的。所以桶排序有其局限性，适合元素值集合并不大的情况。
*/

// 冒泡排序
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)// 外层循环控制排序的趟数
        for (i = 0; i < n - 1 - j; i++)// 内层循环控制每一趟排序多少次
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}

// 归并排序
//https://www.cnblogs.com/skywang12345/p/3602369.html
// python 代码的实现
def merge(lfrom, lto, low, mid, high):
    i, j, k = low, m, high
    while i<mid and j<high:   # 反复复制两分段首记录中较小的
        if lfrom[i].key <= lfrom[j].key:
            lto[k] = lfrom[i]
            i += 1
        else:
            lto[k] = lfrom[j]
            j += 1
        k += 1
    while i < mid:    # 复制第一段剩余记录
        lto[k] = lfrom[i]
        i += 1
        k += 1
    while j<high:    # 复制第二段剩余记录
        lto[k] = lfrom[j]
        j += 1
        k += 1
def merge_pass(lfrom, lto, llen, slen):
    i = 0
    while i+2*slen < llen:    # 归并长slen的两段
        merge(lfrom, lto, i, i+slen, i+2*slen)
        i += 2*slen
    if i+slen < llen   # 剩下两段， 后段长度小于slen
        merge(lfrom, lto, i, i+slen, llen)
    else:              # 只剩下一段， 复制到表lto
        for j in range(i, llen):
            lto[j] = lfrom[j]


def merge_sort(lst):
    slen, llen = 1, len(lst)
    templst = [None] * llen
    while slen < llen 
        merge_pass(lst, templst, llen, slen)
        slen *= 2
        merge_pass(templst, lst, llen, slen)  # 结果存回原位
        slen *= 2
