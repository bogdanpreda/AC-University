#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int nr, baza_nr, baza,p,n2;
    nr = 4672;
    baza_nr = 8;
    baza = 10;

    n2 = 0;
    p = 1;

    do
    {
        n2 = n2+(nr%10)*p;
        p*=baza_nr;
        nr = nr/10;
    } while(nr);
    printf("%d", n2);
}

