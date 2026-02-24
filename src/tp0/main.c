#include <stdio.h>

int increase(int number)
{
    return number + 1;
}

int main(int argc, char **argv)
{
    int a = 1;
    a = a + 1;
    printf("a = %d\n", a);

    a = increase(a);

    return 0;
}
