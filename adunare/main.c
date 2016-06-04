#include <stdio.h>
#include <stdlib.h>

int conversie_int(int nr, int baza)
{

    int p, r, nr2;
    nr2=0;
    p = 1;
    while(nr)
    {
        r = nr%baza;
        nr2 = nr2+r*p;
        p*=10;
        nr = nr/baza;
    }
    return nr2;
}


int main()
{
    int a,b,tr_a,tr_b,s=0,i,k1=0,k2=0,k3=0,va[100],vb[100],vs[100],a2,b2,transport=0;
    printf("a= b=");
    scanf("%d %d",&a,&b);

    a2=a;
    b2=b;
    while(a2)
    {
        va[k1++]=a2%2;
        a2 = a2/2;
    }
    while(b2)
    {
        vb[k2++]=b2%2;
        b2 = b2/2;
    }

    if(k1<k2)
    {
        for(i=k1; i<k2; i++)
        {
            va[k1++]=0;

        }
    }
    else if(k2<k1)
    {
        for(i=k2; i<k1; i++)
        {
            vb[k2++]=0;
        }
    }
    printf("\n");

    for(i=0; i<k1; i++)
        printf("%d",va[i]);

    printf("\n");

    for(i=0; i<k2; i++)
        printf("%d",vb[i]);

    for(i=0; i<k1; i++)
    {
        vs[k3++]=va[i]+vb[i];
        if(va[i]+vb[b]>1)
        {

            if(transport==1)
            {
                vs[i]=transport;
                transport=1;
            }else
            {
                transport=1;
                vs[i]=0;
            }

        } else if(va[i]+vb[i]<=1)
        {
            if(transport=1)
                vs[i]=1;
            else
                vs[i]=0;
        }

    }vs[k3++]=transport;
    printf("\n");
    for(i=0; i<k3; i++)
        printf("%d",vs[i]);
    return 0;
}

