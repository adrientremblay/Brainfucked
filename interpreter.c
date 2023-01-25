#include <stdio.h>

/*
 This is a brain fuck interpreter written in C.
 An interpreter is a program that runs and executes source code
 in another language. It can thought of as a sort of pseudo-compiler.
*/
int main(int argc , char* argv[]) {
    if (argc != 2) {
        printf("Please provide ONE argument specifying the Brainfuck source code\n");
    }

    printf(argv[1]);
    printf("\n");

    return 0;
}
