#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 20


double acc[N]; double vel[N]; double x[N]; double y[N];
double cutRad=0.5;
double epsilon=1.0;


inline double sqr ( double x ) {
	return x * x;
}

inline double field ( double r ) {
	return epsilon * ( pow(r,-14) - pow(r,-7) );
}

bool isNear(int i, int j)
{
	if ( sqr(x[i]-x[j]) + sqr(y[i]-y[j]) < sqr(cutRad) ) {
	return true; }
	else { return false; }
}

int init()
{
	int i;
	for(i=0;i<N;i++) {
		acc[i]=0;
		vel[i]=0;
		x[i]=sqrt(i)/sqrt(N);
		y[i]=1-sqr(i/N);
//		ord[i]=rand()/double(RAND_MAX);
	}
	return 0;
}

int domove()
{

	return 0;
}

int main()
{
	init();
	return 0;
}

