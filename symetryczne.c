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


bool symetryczne(Twezel *d1, Twezel *d2)
{
	bool lewy, prawy, calosc;
	if (d1 && d2)
	{
		lewy = symetryczne(d1->lsyn, d2->psyn);
		prawy = symetryczne(d1->psyn, d2->lsyn);
		calosc = prawy&&lewy;
		return calosc;
	}
	else
	{
		if (d1 || d2) return false;
		else return true;
	}
}