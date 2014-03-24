/* 7ymedio.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;

    if (argc != 2) {
	    fprintf(stderr, "USO: %s N\n",argv[0]);
	    exit(0);
    }
    n=atoi(argv[1]);

    printf("\n***Inicio del juego con %d partidas***\n\n", n);
}
