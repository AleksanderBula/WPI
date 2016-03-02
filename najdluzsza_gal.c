#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct wezel
{
       int w;
       struct wezel* lsyn;
       struct wezel* psyn;
};
typedef struct wezel Twezel;


int max (int a, int b)
{
	if ( a > b) return a;
	else return b;
}

int znajdz_wysokosc (Twezel *d, int wysokosc)
{
	int lewa_wys, prawa_wys;

	if (d)
	{
		lewa_wys = znajdz_wysokosc(d->lsyn, wysokosc+1);
		prawa_wys = znajdz_wysokosc(d->psyn, wysokosc+1);
		return max(lewa_wys, prawa_wys) + 1;
	}
	return -1;
}


void main ()
{
    
    Twezel *d = malloc(sizeof(Twezel));
    Twezel *d1 = malloc(sizeof(Twezel));
    Twezel *d2 = malloc (sizeof(Twezel));
    Twezel *d3 = malloc (sizeof(Twezel));
    Twezel *d4 = malloc (sizeof(Twezel));
    Twezel *d5 = malloc(sizeof(Twezel));
    Twezel *d6 = malloc (sizeof(Twezel));
    
    d->w = 5;
    d1->w = 6;
    d2->w = 4;
    d3->w = 7;
    d4->w = 3;
    d5->w = 1;
    d6->w = 2;


    d->lsyn = d1;
    d->psyn = d2;
    d1->lsyn = d3;
    d1->psyn = d4;
    d2->lsyn = d5;
    d2->psyn = d6;
    d3->lsyn = NULL;
    d3->psyn = NULL;
    d4->lsyn = NULL;
    d4->psyn = NULL;
    d5->lsyn = NULL;
    d5->psyn = NULL;
    d6->lsyn = NULL;
    d6->psyn = NULL;


    int wys = znajdz_wysokosc(&d, 0);
    printf("%d\n",wys );
}