#include <stdio.h>
#include <stdlib.h>
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int *arr, int start, int end)
{
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end)
    {
        if (son + 1 <= end && arr[son] < arr[son + 1])
        {
            son++; // 两个孩子中挑选最大的孩子出来
        }
        if (arr[dad] > arr[son]) // 如果父节点值已经大于子节点了 那么不用调整 直接跳出循环
        {
            return;
        }
        else   //否则交换父子内容再继续子节点和孙节点比较
        {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}
void heap_sort(int *arr, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, i, len - 1);
    }
    for (int i = len - 1; i >= 0; i--)
    {
        // 先将第一个元素与最后一个元素交换在调整堆结构
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}