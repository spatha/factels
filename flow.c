#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 20


double acc[N]; double vel[N]; double x[N]; double y[N];
double cutRad=0.5;
double epsilon=1.0;
int i,j,k; // for use in loops

inline double sqr ( double x ) {
	return x * x;
}

inline range( int i, int j ) {
	return sqrt( sqr(x[i]-x[j]) + sqr(y[i]-y[j])  );
}

inline double field ( double r ) {
	return epsilon * ( pow(r,-14) - pow(r,-7) );
}

bool isNear(int i, int j)
{
	if ( range(i,j) < cutRad ) {
	return true; }
	else { return false; }
}

int init()
{
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
	double U;
	double r;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (isNear(i,j)) {
				r = range(i,j);
				U += field(r);
			}
		}
	}
	return 0;
}

int main()
{
	init();
	return 0;
}

