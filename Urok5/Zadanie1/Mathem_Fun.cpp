#include "Mathem_Fun.h"

double Sloshenie(double* cis1, double* cis2)
{
	return *cis1 + *cis2;
}

double Vychitanie(double* cis1, double* cis2)
{
	return *cis1 - *cis2;
}

double Umnoshenie(double* cis1, double* cis2)
{
	return *cis1 * *cis2;
}

double Delenie(double* cis1, double* cis2)
{
	return *cis1 / *cis2;
}

double Stepen(double* cis1, double* cis2)
{
	double cislo3 = 1;
	for (int i = 0; i < *cis2; i++)
	{
		cislo3 *= *cis1;
	}
	return cislo3;
}