#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct particles *Particles;

struct particles {
	double (* rad)[N];
	int n;
};


Particles * create_particles()
{
	int n = N;
//	double * p[20];
	void * p;
	p = malloc(n * sizeof(double));
	return 0;
}

int free_particles( struct particles *P )
{
	free(P->rad);
	return 0;
}

int move()
{
	return 0;
}

int main()
{
	Particles * p;
	p = create_particles();
	free_particles(p);
	return 0;
}

