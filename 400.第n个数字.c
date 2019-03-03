/*
 * @lc app=leetcode.cn id=400 lang=c
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.31%)
 * Total Accepted:    2.2K
 * Total Submissions: 7.1K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 231)。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */

// TODO: 还没想明白
// int base = 9;
//         long digits = 1;
//         while (n - base * digits > 0) {
//             n -= base * digits;
//             base *= 10;
//             digits++;
//         }
        
//         int index = (n - 1) % digits;
//         int offset = (n - 1) / digits;
//         long start = pow(10, digits - 1);
//         return to_string(start + offset)[index] - '0';
int My_pow(int a, int b)
{
    int sum = 1;
    while(b)
    {
        sum *= a;
        b--;
    }
    return sum;
}
int findNthDigit(int n) {
    // printf("%d\n", pow(10，2));
    // printf("%d\n", My_pow(2, 2));
    
    
    if (n < 10) return n;
    
    long int x = 9;
    int i = 1;
    long int j = 1;
    while(n>x) {
        n -= x;
        i++;
        j = j * 10;
        x = i*j*9;
    }
        
    if (n%i == 0) {
        n /= i;
        int ans;
        ans = n%10;
        if (ans==0) return 9;
        return ans-1;
    }
    
    long int num;
    
    num = j+(n/i);
    
    int d = n%i;
    
    int p = pow(10,(d-1));
    return (num/(j/p))%10;  
    
//     int base = 9;
//         long digits = 1;
//         while (n - base * digits > 0) {
//             n -= base * digits;
//             base *= 10;
//             digits++;
//         }
        
//         int index = (n - 1) % digits;
//         int offset = (n - 1) / digits;
//         long start = pow(10, digits - 1);
//         return to_string(start + offset)[index] - '0';
    
    
    
    
    
//     int sum[2] = {0};
//     if(n<10)
//     {
//         return n;
//     }
//     int i=1;
//     while(1)
//     {
//         sum[1] += (pow(10, i) - pow(10, i-1))*i;
//         if(sum[1] > n)
//         {
//             break;
//         }
//         sum[0] = sum[1];
                
//         i++;
//     }
//     // printf("%d\n", i);
//     // printf("%d\n", sum[0]);
// //     int tmp = sum[1] - sum[0];
// //     int wei = tmp/i;
// //         printf("%d\n", tmp);

// //     printf("%d\n", wei);
// //     int yu = tmp % i;
//     int wei = (n-sum[0])/i;
//     int yu = (n-sum[0]) %i;
//     int target = pow(10, i-1) - 1 + wei;
//     // printf("%d\n", target);
//     // printf("%d\n", yu);
//     if(yu == 0)
//     {
//         return target % 10;
//     }
//     target += 1;
//     target /= pow(10, i-yu);
//     // printf("%d\n", target);
//     return target % 10;
    
    
    
    
    
//     printf("%d\n", wei);

 
//     printf("%d\n", sum[0] + wei);
    
    
    
    
    
    // for(int i=1; i<n; i++)
    // {
    //     sum += (My_pow(10, i) - 1 - My_pow(10, i-1))*i;
    // }
    // return 1;
}

