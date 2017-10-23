//Name: Tynyshov Arslanbek
//Group: 04B

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[]){
    char* a = argv[1];
    char* b = argv[2];
    for (int i = 0; i < 4; i++){
	int smth = fork();
	if (smth == 0){
	    char* arr[5];
	    switch(i){
		case 0:
		    arr[0] = "python";
		    arr[1] = "add.py";
		    arr[2] = a;
		    arr[3] = b;
		    arr[4] = NULL;
		    execvp (arr[0], arr);
		    break;
		case 1:
		    arr[0] = "java";
		    arr[1] = "sub";
		    arr[2] = a;
		    arr[3] = b;
		    arr[4] = NULL;
		    execvp (arr[0], arr);
		    break;
		case 2:
		    arr[0] = "node";
		    arr[1] = "mult";
		    arr[2] = a;
		    arr[3] = b;
		    arr[4] = NULL;
		    execvp (arr[0], arr);
		    break;
		case 3:
		    arr[0] = "bash";
		    arr[1] = "div.sh";
		    arr[2] = a;
		    arr[3] = b;
		    arr[4] = NULL;
		    execvp (arr[0], arr);
		    break;
	    }
	}
	else if( smth > 0){
	    wait(NULL);
	}
    }
    printf("parent: done\n");

    return 0;
}
