#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 20


double ax[N]; double ay[N];
double vx[N]; double vy[N];
double x[N]; double y[N];
double cutRad=0.5;
double epsilon=1.0;
int i,j,k; // for use in loops
double dt=0.01;


inline double sqr ( double x ) {
	return x * x;
}

inline range( int i, int j ) {
	return sqrt( sqr(x[i]-x[j]) + sqr(y[i]-y[j])  );
}

inline double field ( double r ) {
	return epsilon * ( pow(r,-14) - pow(r,-7) );
}

inline double force ( double r ) {
	return epsilon * ( -14 * pow(r,-15) - (-7) * pow(r,-8) );
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
		ax[i]=0;
		ay[i]=0;
		vx[i]=0;
		vy[i]=0;
		x[i]=sqrt(i)/sqrt(N);
		y[i]=1-sqr(i/N);
//		ord[i]=rand()/double(RAND_MAX);
	}
	return 0;
}

int domove()
{
	double Fx=0,Fy=0;
	double r=1;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (isNear(i,j)) {
				r = range(i,j);
				Fx += force(r) * (x[i]-x[j])/range(i,j);
				Fy += force(r) * (y[i]-y[j])/range(i,j);
				
			}
		}
		x[i]+=dt*vx[i];
		y[i]+=dt*vy[i];
		vx[i]+=dt*ax[i];
		vy[i]+=dt*ay[i];
		ax[i]= Fx;
		ay[i]= Fy;
	}
	return 0;
}

int main()
{
	init();
	return 0;
}

