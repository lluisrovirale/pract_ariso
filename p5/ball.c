#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int main (int argc, char *argv[]){
	int ph[2],hp[2];
	int pelota=0,num;
	assert(argc==2);
	if((num=atoi(argv[1]))==-1){
		printf("Error al convertir numero\n");
		exit(-1);
	}
	if(pipe(ph)<0){
		printf("Error al crear la pipe\n");
		exit(-1);
	}
	if(pipe(hp)<0){
		printf("Error al crear la pipe\n");
		exit(-1);
	}
	switch (fork()){
		case -1: printf("Error\n");
			 exit(-1);
		case 0: //HIJO
			
		break;
		default: //PADRE
		break;		
	}
				
}
