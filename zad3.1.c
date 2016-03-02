#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct wezel
{
       int w;
       struct wezel* lsyn;
       struct wezel* psyn;
};
typedef struct wezel wezel;



bool Wiekszy_Kodr (wezel *d, int i, int A[], int n, bool wieksze, int dlugosc, int pocz)			/* dodane 2 zmienne do deklaracji */
{
	bool lewy, prawy;

	if (d)
	{
		if (pocz == i) dlugosc = i;				/* warunek na omijanie poczatkowych 0 */
		if (i == n) 
		{
			if (i == pocz) return false;
			else return true;
		}
		else 
		{
			if ( i == n - 1)
			{
				if ( d->lsyn || d->psyn)  
				{
					return true;
				}
				else 
				{
					if (wieksze) 
						{
							return true;
						}
					else 
					{
						if (dlugosc  > n - 1) 			/*warunek na dlugosc liczby */
							{
								return true;
							}
						else 
						{
							return false;
						}
					}
				}
			}
			else 
			{
				if (A[i] == 1)
				{
					prawy = Wiekszy_Kodr(d->psyn, i+1, A, n, wieksze, dlugosc+1, pocz);
					lewy = Wiekszy_Kodr(d->lsyn, i , A, n, wieksze, dlugosc + 1, pocz);		
				}
				else
				{
					if (wieksze) prawy = Wiekszy_Kodr(d->psyn, i+1, A, n, wieksze, dlugosc+1, pocz);
					else prawy = Wiekszy_Kodr(d->psyn, i+1, A, n, !wieksze, dlugosc+1, pocz);
					lewy = Wiekszy_Kodr(d->lsyn, i+1, A, n, wieksze, dlugosc+1, pocz);
				}

				if (prawy) return prawy;
				else return lewy;
			}

		}
	}
	else if (dlugosc == n + 2) return true;
		else return false;			
}


bool Wiekszy_Kod (wezel *d, int n, int A[])
{
	bool jest;
	int i = 0;
	if (n>0)
	{
		while (i < n && A[i] == 0)
		{
			i++;
		}

		jest = Wiekszy_Kodr(d, i, A, n+1, false, i, i);				/* wywołanie z n + 1 */
		return jest;
	}
	else return false;
}

