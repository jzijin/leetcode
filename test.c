#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char dog[8] = {'a','b',1,2,3,4,7,8,9};
    printf("%d\n", sizeof(dog));
    printf("%d\n", strlen(dog));
}