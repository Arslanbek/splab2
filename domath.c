//Name: Tynyshov Arslanbek
//Group: 04B

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void arithmetics(int, int, int);
int main(int argc, char* argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    for (int i = 0; i < 4; i++){
	int smth = fork();
	if(smth == 0){
	    arithmetics(i, a, b);
	    exit(0);
	}
    }
    for (int i = 0; i < 4; i++){
	wait(NULL);
    }
    printf("parent: done\n");

    return 0;
}

void arithmetics(int k, int a, int b){
    switch (k){
	case 0:
	    printf("child1: %d+%d=%d\n", a, b, a + b);
	    break;
	case 1:
	    printf("child2: %d*%d=%d\n", a, b, a*b);
	    break;
	case 2:
	    printf("child3: %d-%d=%d\n", a, b, a - b);
	    break;
	case 3:
	    printf("child4: %d/%d=%d\n", a, b, a/b);
	    break;
    }
}
