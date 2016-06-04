#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int putere(int nr, int putere)
{
    int k,nr2=1;
    for(k=1;k<=putere;k++)
        nr2 = nr2*nr;
    return nr2;
}


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
void conversie_int_10_to_16(int nr, int baza)
{
    int r, i,n ,v[50];
    i=0;
    while(nr)
    {
        r = nr%baza;
        v[i++] = r;
        nr = nr/baza;

    }
    n = i;
    int j,k;
    char h[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char hexa[50];

    k=0;
    for( j=n-1;j>=0;j--)
    {
        hexa[k++]= h[v[j]];
    }
    hexa[k]='\0';
    printf("%s",hexa);
}
int conversie_int_16_to_10(char hexa[],int baza)
{
    int p=1,n2=0,j=0;
    for( j=strlen(hexa)-1;j>=0;j--)
    {
        if(hexa[j]>='0' && hexa[j]<='9')
        {
            n2 = n2+(hexa[j]-'0')*p;
            p*=16;
        } else
        {
            n2 = n2+(hexa[j]-'A'+10)*p;
            p*=16;
        }

    }
    return n2;
}
int conversie_int_to_10(int nr, int baza_nr)
{
    int p,n2;
    n2 = 0;
    p = 1;
    do
    {
        n2 = n2+(nr%10)*p;
        p*=baza_nr;
        nr = nr/10;
    } while(nr);

     return n2;
}
float conversie_fract(float nrf, int baza)
{
    float pf=0;
    float nr_final;
    int c,k=0, pi, p2;

    pf = nrf-(int)nrf;
    pi = (int)nrf;
    nr_final = conversie_int(pi, baza);
    p2 = 1;

    while((int)pf != pf && k<7)
    {
        pf = pf*baza;
        c = (int)pf;

        nr_final = nr_final+0.1*c*1/p2;
        p2*=10;
        pf = pf-(int)pf;
        k++;
    }
    return nr_final;
}
float conversie_fract_from_n_to_10(float numar, int bazanr)
{
    float pf = 0;
    float nr_final=0;
    int p2=1;
    int contor=0;
    while((int)numar !=numar)
    {
        numar*=10;
        contor++;
    }
    while(numar)
    {
        nr_final+=(int)numar%10*p2;
        p2*=bazanr;
        numar/=10;
    }
    return nr_final/putere(bazanr,contor);
}

int main()
{
    float numar;
    int baza, bazanr;

    conversie_int_10_to_16(256,16);
    printf("\n");
    printf("numarul %s in baza %d este: %d\n","7D",10,conversie_int_16_to_10("7D",10));
    printf("Scrie un numar, baza acestuia si baza in care vrei sa fie convertit: \n");

    scanf("%f %d %d", &numar,&bazanr, &baza);

    if(bazanr == 10)
    {
        if((int)numar == numar)
        {
            if(baza!=16)
                printf("numarul intreg %d in baza %d este %d: \n",(int)numar, baza, conversie_int((int)numar, baza));
            else
            {
                printf("numarul intreg %d in baza %d este: ",(int)numar,baza);
                conversie_int_10_to_16((int)numar, baza);
            }
        }
        else
        {

            printf("numarul fractionar %f in baza %d este %.7f: \n",numar, baza, conversie_fract(numar, baza));

        }

    } else
    {
        if((int)numar == numar)
        {
            if(baza!=16)
            {
                int b10 = conversie_int_to_10((int)numar,bazanr);
                printf("numarul intreg %d in baza %d este %d: \n",(int)numar, baza, conversie_int(b10, baza));
            }
        }
        else
        {
            if(baza!=10)
            {
            int b10 = conversie_fract_from_n_to_10(numar,bazanr);
            printf("numarul fractionar %f in baza %d este %.7f: \n",numar, baza, conversie_fract(b10, baza));
            }
            else
            {
                printf("numarul fractionar %f in baza %d este %.7f: \n",numar, baza, conversie_fract_from_n_to_10(numar, bazanr));
            }
        }
    }
    return 0;
}
