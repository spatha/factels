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
double sigma=0.1;
int i,j,k; // for use in loops
double dt=0.01;


inline double sqr ( double x ) {
	return x * x;
}

inline range( int i, int j ) {
	return sqrt( sqr(x[i]-x[j]) + sqr(y[i]-y[j])  );
}

inline double field ( double r ) {
	return epsilon * ( pow(r/sigma,-14) - pow(r/sigma,-7) );
}

inline double force ( double r ) {
	return epsilon * ( -14/sigma * pow(r/sigma,-15) - (-7)/sigma * pow(r/sigma,-8) );
}

bool isNear(int i, int j)
{
	if (i==j) return false;
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
		y[i]=( log(N)-log(i) )/log(N);
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
				Fx += force(r) * (x[i]-x[j])/r;
				Fy += force(r) * (y[i]-y[j])/r;
				
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

int correct()
{
	for(i=0;i<N;i++) {
		if (x[i]>1)
			x[i]--;
		if (x[i]<0)
			x[i]++;
		if (y[i]>1)
			y[i]--;
		if (y[i]<0)
			y[i]++;
	}
	return 0;
}

int printout()
{
	for(i=0;i<5;i++) {
		printf("x[%d]= %f ",i,x[i]);
	}
	printf("\n");
	return 0;
}

int main()
{
	init();
	int iter=0;
	for(iter=0;iter<10;iter++) {
		domove();
		printout();
	}
	return 0;
}

