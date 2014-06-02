#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	assert(argc == 2);

	if((argv[1][0]=='a') || (argv[1][0]=='e') || (argv[1][0]=='i')||(argv[1][0]=='o') || (argv[1][0]=='u')) {
		exit(1);
	} else {
		exit(0);
	}
}
	
