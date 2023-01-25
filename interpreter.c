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

    long int i = 0;
    char c;
    do {
        fseek(file, i++, SEEK_SET);
        c = fgetc(file);

        printf("%C", c);
        /*
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
                if (*p == 0) {
                    // enter loop
                } else {
                    // skip to end of loop
                    while (fseek(file, i++, SEEK_SET) != ']') { // todo: what if we reach the end of the file?
                        // skip
                        printf("skip1");
                    }
                }
                break;
            case ']':
                // skip backwards to start of loop
                i--;
                while (fseek(file, --i, SEEK_SET) != '[') { // todo: what if we reach the end of the file?
                    // skip
                        printf("skip2");
                }
                break;
            case ',':
                *p = getchar();
                break;
            case '.':
                putchar(*p);
                break;
        }
        */
    } while (c != EOF);

    return 0;
}
