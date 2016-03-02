#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct wezel
{
       int w;
       bool jest;
       struct wezel* lsyn;
       struct wezel* psyn;
};
typedef struct wezel Twezel;


void maks (Twezel* d, Twezel**indeks, int *wys, int poz)
{
    if (d)
    {
	   	printf("d = %d, poz = %d\n", d->w, poz);
        int x;
	    if (*wys < poz)
        {
            *wys = poz;
            *indeks = d;
        }
      
	   	maks (d->psyn, indeks, wys, poz+1);
        maks (d->lsyn, indeks, wys, poz+1);
        
    }
}

Twezel* maksymalny (Twezel* d)
{
        Twezel* indeks = NULL;
        int wys = 0;
        maks (d, &indeks, &wys, 0);
        return indeks;
}

int main (void)
{
    
    Twezel* d = malloc(sizeof(Twezel));
    Twezel* d1 = malloc(sizeof(Twezel));
    Twezel* d2 = malloc (sizeof(Twezel));
    Twezel* d3 = malloc (sizeof(Twezel));
    Twezel* d4 = malloc (sizeof(Twezel));
    Twezel* d5 = malloc(sizeof(Twezel*));
    Twezel* d6 = malloc (sizeof(Twezel*));
    
    d->w = 7;
    d1->w = 6;
    d2->w = 8;
    d3->w = 5;
    d4->w = 3;
    d5->w = 1;
    d6->w = 2;
    
    d->jest = true;
    d2->jest = false;
    d3->jest = true;
    d4->jest = 

    
    d->lsyn = d1;
    d->psyn = d2;
    d1->lsyn = d3;
    d1->psyn = d4;
    d2->lsyn = NULL;
    d2->psyn = NULL;
    d3->lsyn = NULL;
    d3->psyn = NULL;
    d4->lsyn = NULL;
    d4->psyn = NULL;
    /*d5->lsyn = NULL;
    d5->psyn = NULL;
    d6->lsyn = NULL;
    d6->psyn = NULL;*/
    
    Twezel* mx = maksymalny (d);
    printf("%d\n", mx->w);
    
    system("Pause");
    return 0;
}
