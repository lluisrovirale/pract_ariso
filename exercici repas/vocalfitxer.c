#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <fcntl.h>

#define M 100

int main(int argc, char *argv[]){
	int fd, len, i, j, vocals;
	char f[M];
	char c;
	
	assert(argc == 2);
	i = 0;
	j = 0;

	if ((fd=open(argv[1], O_RDONLY)) < 0) { printf("ERROR open\n"); exit(-1); }
	
	while (len=read(fd,&c,sizeof(char)) > 0){
		if (c == '\n'){
			f[i] = '\0';
			j++;
			i = 0;
			switch (fork()){
				case -1: printf("ERROR fork\n"); exit(-1);
				case 0:
					execl("./contavocals","./contavocals", f, NULL);
				default:
					wait(&vocals);
					vocals = WEXITSTATUS(vocals);
					printf("En aquesta línia hi ha: %d vocals\n", vocals);
					break;
			}
		}
		else{
			f[i] = c;
			i++;
		}	
	}
}
