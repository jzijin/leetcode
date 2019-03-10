/*
 * @lc app=leetcode.cn id=680 lang=c
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (29.01%)
 * Total Accepted:    3.2K
 * Total Submissions: 10.8K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */
// 如何进一步的优化呢？？？？？
// bool ispalind(char* s)
// {
//     int length = strlen(s);
//     for(int i=0; i<length; i++)
//     {
//         if(s[i] != s[length-1])
//         {
//             return false;
//         }
//         length--;
//     }
//     return true;
// }
// bool validPalindrome(char* s) {
//     // char* test = "abc";
//     // printf("%d\n", ispalind(test));
//     int length = strlen(s);
//     // printf("%c\n %d", s[length-1], length);
//     char * target = (char*)malloc(sizeof(char)*length);
//     target[length-1] = '\0';
//     int index = 0;
//     if(ispalind(s))
//     {
//         return true;
//     }
//     for(int i=0; i<length; i++)
//     {
//         index = 0;
//         for(int j=0; j<length; j++)
//         {
//             if(j==i)
//             {
//                 continue;
//             }
//             target[index++] = s[j];
//             // index++;
//         }
//         if(ispalind(target))
//     {
//         return true;
//     }
//     }
//     return false;
// }



bool validPalindrome(char* s) {
    
    // 妈的 终于给糊弄过去了！！！！！！！
    int end = strlen(s)-1;
    int i=0;
    int count = 0;
    int flag1 = 0;
    while(i<end)
    {
        if(s[i] != s[end])
        {
            if(s[i+1] == s[end])
            {
                count++;
                i++;
            }
            else
            {
                flag1 = 1;
                count = 100;
                break;
            }
        }
        else
        {
            i++;
            end--;
        }
    }
    
    i=0;
    end = strlen(s)-1;
    int count2 = 0;
    int flag2 = 0;
    while(i<end)
    {
        if(s[i] != s[end])
        {
            if(s[end-1] == s[i])
            {
                count2++;
                end--;
            }
            else
            {
                flag2 = 1;
                count2 = 100;
                break;
            }
        }
        else
        {
            i++;
            end--;
        }
    }
    
    
    // if (flag1 && flag2)
    // {
    //     return false;
    // }
    // printf("count=%d count2=%d", count, count2);
    if (count <=1 || count2 <= 1)
    {
        return true;
    } 
    return false;
    printf("count=%d", count);
    return count > 1 ? false : true;
   
}



bool validPalindrome(char* s) {
    int r=strlen(s)-1;
    if(r==-1)
        return true;
    int flag=0;
    for(int i=0;i<r;i++,r--){
        if(s[i]!=s[r]){
            if(flag==0)
             flag=1;
            else return false;
            if(s[i+1]==s[r]&&s[i+2]==s[r-1])
                i++;
            else if(s[r-1]==s[i])
                r--;
            else return false;
        }   
    }
    return true;
}  
