#include <stdio.h>

/*
 This is a brain fuck interpreter written in C.
 An interpreter is a program that runs and executes source code
 in another language. It can thought of as a sort of pseudo-compiler.
*/
int main(int argc , char* argv[]) {
    if (argc != 2) {
        printf("Please provide ONE argument specifying the Brainfuck source code\n");
        return 0;
    }

    FILE* file;
    if ((file= fopen(argv[1], "r")) == NULL) {
        printf("The file cannot be opened!");
        return 0;
    }

    unsigned char memory[30000];
    unsigned char* p = memory;

    char c;
    while ((c = fgetc(file)) != EOF) {
        switch(c) {
            case '>':
                p++;
                break;
            case '<':
                p--;
                break;
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '[': // todo: nested loops?
                break;
            case ']':
                break;
            case ',':
                *p = getchar();
                break;
            case '.':
                putchar(*p);
                break;
        }
    }

    return 0;
}
