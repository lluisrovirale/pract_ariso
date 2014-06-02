#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int vocals, retorn, i;
	vocals = 0;
	assert(argc == 2);
	for(i=0; argv[1][i] != '\0'; i++){
		switch(fork()){
			case -1: printf("ERROR fork\n"); exit(-1);
			case 0:
				if (execl("./vocalconsonant","./vocalconsonant", &argv[1][i], NULL) < 0){
					printf("ERROR exec\n");
					exit(-1);
				}
			default:
				wait(&retorn);
				vocals += WEXITSTATUS(retorn);	
				break;
		}
	}
//	printf("Hi ha %d vocals\n", vocals);
	exit(vocals);
}
