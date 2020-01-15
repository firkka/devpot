/******************************************************************************
https://godbolt.org/
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdint.h>

struct A
{
    int a,b,c;
};

struct Buffer
{
    A aa;
};

Buffer b;

Buffer& getBuffer()
{
    return b;
}

void getA_d(A** a)
{
    printf("\n getA addr a : %p \n", a);

    Buffer *b_s = &getBuffer();
    *a =  &b_s->aa;

    printf("\n getA addr a : %p \n", a);

    (*a)->a = 4;

    printf("\n getA addr a : %p \n", a);  
}

void getA(A* a)
{
    printf("\n getA addr a : %p \n", a);

    Buffer *b_s = &getBuffer();
    a =  &b_s->aa;

    printf("\n getA addr a : %p \n", a);

    a->a = 3;

    printf("\n getA addr a : %p \n", a);
}

int main()
{
    printf("a : %d\n", b.aa.a);

    A* a;

    printf("\naddr a : %p \n", a);

    getA(a);

    printf("\naddr b : %p \n", &b);

    printf("\naddr a : %p \n", a);

    getA_d(&a);

    printf("a : %d\n", b.aa.a);

    return 0;
}
