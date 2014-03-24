/* 7ymedio.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n,i;
    int result,total=0;

    if (argc != 2) {
	    fprintf(stderr, "USO: %s N\n",argv[0]);
	    exit(0);
    }
    n=atoi(argv[1]);

    printf("\n***Inicio del juego con %d partidas***\n\n", n);

   for (i=0;i<n;i++){
	//hpid=fork();
	switch(fork()){
	case -1: 
		printf("ERROR");
		exit(-1);
	break;
	case 0:
		execl("./partida","",NULL);
	break;
	default:
		wait(&result);
		total=total+WEXITSTATUS(result);
	break;
	}
   }
   printf("\n\nEl croupier ha ganado: %d partidas de las %d jugadas\n\n",total,n);
   exit(0);
}
