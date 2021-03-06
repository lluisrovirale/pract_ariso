#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>


#define M 80
#define TON 4.184
#define SALTO_LINEA '\n'

int main (int argc, char* argv[]){
	int fd,a,b,len,poder;
	char m;
	char f[M];
	assert(argc==2);	
	if((fd=open(argv[1],O_RDONLY))<0){printf("ERROR al obrir\n"); exit(-1);}
	a=0;b=0;
	while ((len=read(fd,&m,sizeof(char)))>0){
		if(m==SALTO_LINEA){
			f[a]=NULL; //final de linea
			b=b+1; // sumo +1 al numero de lineas
			len=a; // la longitud de la linia es a
			a=0;
			if(len>=M){printf("Linea més gran del permes\n"); exit(-1);}
			switch(fork()){
				case -1: printf("ERROR amb el fork\n"); exit(-1);
				case 0: execl("./mayorpoder.o","./mayorpoder.o",f,NULL);
				default: //pare
					wait(&poder);
					poder=WEXITSTATUS(poder);
					if(poder==0){
						printf("la linea-%i no tiene ninguna flecha\n",b);
					}else if(poder>0){
						printf("la linea-%i tiene la flecha mas larga de longitud %i y poder %f Gigajulios\n",b,poder,(poder+1)*TON);
					}else{
						printf("ERROR amb mayorpoder.o\n"); exit(-1);
					}
				break;
			}
		}else{
			f[a]=m;
			a++;
		}								
	}
	if (len==0){printf("Final del fitxer\n"); exit(0);}
	if (len==-1){printf("ERROR al llegir\n"); exit(-1);}
}
