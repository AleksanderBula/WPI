#include<stdio.h>

int Fib (int N)
{
    int F[44];
    int sF[44];
    F[0] = 1;
    F[1] = 1;
    int i = 2;
    while (i < 44)
    {
        F[i] = F[i-1]+F[i-2];
        i++;
    }
    i = 0;
    int s = 0;
    while (i<44)
    {
          s += F[i];
         sF[i] = s;
         i++;
    } 
    
    i = 0;
    while (i < 44 && F[i] <= N)
          i++;
    i--;
    int Fmax = F[i];
    

    return szukaj (F, sF, N, i, 0);    
}

int szukaj (int F[], int sF[], int N, int i)
{
    int c = 0;
    if (i >= 0)
    {
        if (N >= F[i])
        {
           c += szukaj(F, sF, N-F[i], i-1);
        }
         c += szukaj(F, sF, N, i-1);
         return c;   
    }
    else
    {
        if (N == 0)
           return 1;
        else return 0;
    }
}

int main (void)
{
    int i = Fib(1);
    
    printf("%d\n", i);
    
    system("Pause");
    return 0;
}
