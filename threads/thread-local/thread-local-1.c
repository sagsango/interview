#include <stdio.h>

__thread int threadVar = 0;
__thread int hello = 0;
__thread int hi = 1;
__thread int bye = 2;

__thread int ola;
__thread int namaste;

void functionA() {
    printf("In functionA, threadVar = %d\n", threadVar);
    threadVar = 10;
    printf("In functionA after modification, threadVar = %d\n", threadVar);
}

void functionB() {
    printf("In functionB, threadVar = %d\n", threadVar);
    threadVar = 20;
    printf("In functionB after modification, threadVar = %d\n", threadVar);
}

void func() {
	threadVar = 1;
	hello = 2;
	hi = 3;
	bye = 4;
	ola = 5;
	namaste = 6;
}

int main() {

    func();
    printf("In main, threadVar = %d\n", threadVar);
    functionA();
    functionB();
    printf("Back in main, threadVar = %d\n", threadVar);
    return 0;
}

