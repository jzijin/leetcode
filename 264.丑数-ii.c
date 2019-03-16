/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (39.69%)
 * Total Accepted:    3.3K
 * Total Submissions: 8.3K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */
int getmin(int a, int b, int c)
{
    if(a>b)
    {
        return b<c?b:c;
            
    }
        return a<c ? a:c;
    
}
int nthUglyNumber(int n) {
    // TODO: 可得好好想想
    /*
    笔记】三指针法。一部分是丑数数组，另一部分是权重2，3，5。下一个丑数，定义为丑数数组中的数乘以权重，所得的最小值。

那么，2该乘以谁？3该乘以谁？5该乘以谁？

其一，使用三个指针idx[3]，告诉它们。比如，2应该乘以ugly[idx[0]]，即数组中的第idx[0]个值。（权重2，3，5分别对应指针，idx[0],idx[1],idx[2]）

其二，当命中下一个丑数时，说明该指针指向的丑数 乘以对应权重所得积最小。此时，指针应该指向下一个丑数。（idx[]中保存的是丑数数组下标）

其三，要使用三个并列的if让指针指向一个更大的数，不能用if-else。因为有这种情况：

丑数6，可能由于丑数2乘以权重3产生；也可能由于丑数3乘以权重2产生。

丑数10，... 等等。

(C++)简单地说，就是从一个基准数1开始，算1*2、1*3、1*5的最小值，得出结果1*2最小，再讲对应Index++即可。 PS： 效率堪忧。。。
    */
    int *res = (int *)malloc(sizeof(int)*n);
    res[0] = 1;
    int indx2=0, indx3 =0, indx5=0, i=0;
    for(i=1; i<n; i++)
    {
        res[i] = getmin(res[indx2]*2, res[indx3]*3, res[indx5]*5);
        // printf("%d ", res[i]);
        if (res[i] == res[indx2]*2)
        {
            indx2++;
        }
            
        if (res[i] == res[indx3]*3)
        {
            indx3++;
        }
            
        if (res[i] == res[indx5]*5)
        {
            indx5++;
        }
            
    }
    return res[n-1];
}

