#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>

#define M 100
#define SALTODELINEA '\n'
#define FINALPARAULA '\0' 

int main (int argc, char * argv[]){
	int fd,i=0,lineas=0,estado;
	char c;
	char f[M];
	
	assert(argc==2);/* if(argc != 2){printf("ERROR\n"); exit(-1);}*/
	
	if((fd=open(argv[1],O_RDONLY))<0){printf("ERROR\n"); exit(-1);}
	/* Llegir d'un arxiu -> read(fd,buffer, #bytes que vull llegir); EM RETORNA -1 -ERROR
											#bytes llegits*/
	while(read(fd,&c,sizeof(char))>0){
		if(c != SALTODELINEA){
			f[i]=c;
			i++;
		}else{
			lineas++;
			f[i]=FINALPARAULA;
			i=0;
			switch(fork()){
				case -1: //ERROR
					printf("ERROR\n");
					exit(-1);
				case 0: //FILL
					if(execl("./contavocals.o","./contavocals.o",f,NULL)<0)
						{printf("ERROR\n"); exit(-1);}
				default: //PARE
					wait(&estado);
					estado=WEXITSTATUS(estado);
					printf("A la linia %i hi ha %i vocals\n",lineas,estado);
				break;
			}
		}
	}
	close(fd);
	printf("Hem acabat el fitxer\n");						
}
