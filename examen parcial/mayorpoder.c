#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>

#define FINCAD NULL
#define CABEZA 'D'
#define CUERPO '='

int main (int argc, char*argv[]){
	int i,k,max=-1;
	assert(argc==2);
	for (i =0;argv[1][i]!=FINCAD;i++)
		if(argv[1][i]==CABEZA){
			for(k=i-1;k>=0 && argv[1][k]==CUERPO;k--);
			if(i-k>max) max=i-k;
		}
	//printf("poder = %i\n",max);
	if(max==-1)	exit(0);
	else { exit(max);	}
}			
