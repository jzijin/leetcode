#include <stdio.h>

int romanToInt(char *s)
{
    int nums = 0;
    while (*s)
    {
        switch (*s)
        {
        case 'I':
            nums += 1;
            break;
        case 'V':
            nums += 5;
            break;
        case 'X':
            nums += 10;
            break;
        case 'L':
            nums += 50;
            break;
        case 'C':
            nums += 100;
            break;
        case 'D':
            nums += 500;
            break;
        case 'M':
            nums += 1000;
            break;
        }
        s += 1;
        if ((*s == 'V' || *s == 'X') && *(s - 1) == 'I')
        {
            nums = nums - 2 * 1;
        }
        if ((*s == 'L' || *s == 'C') && *(s - 1) == 'X')
        {
            nums = nums - 2 * 10;
        }
        if ((*s == 'D' || *s == 'M') && *(s - 1) == 'C')
        {
            nums = nums - 2 * 100;
        }
    }
    return nums;
}

int main()
{
    char s[] = {'I', 'X'};
    int nums = romanToInt(s);
    printf("%d\n", nums);

    return 0;
}