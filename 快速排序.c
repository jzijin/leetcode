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
