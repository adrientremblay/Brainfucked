#include <stdio.h>

#define MEMORY_SIZE 30000

/*
 This is a Brainfuck interpreter written in C.
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

    unsigned char memory[MEMORY_SIZE];
    unsigned char* p = memory;

    long int i = 0;
    char c;
    do {
        fseek(file, i++, SEEK_SET);
        c = fgetc(file);

        unsigned int hunting;
        char temp_c;
        switch(c) {
            case EOF:
                putchar('\n');
                return 0;
            case '>':
                p++;
                if (p >= memory + MEMORY_SIZE)
                    p = memory;
                break;
            case '<':
                p--;
                if (p <= memory - 1) 
                    p = memory + MEMORY_SIZE - 1;
                break;
            case '+':
                (*p)++;
                break;
            case '-':
                (*p)--;
                break;
            case '[': // todo: nested loops?
                if (*p != 0) {
                    // enter loop
                } else {
                    // skip to end of loop
                    hunting = 1;;
                    do { // todo: what if we reach the end of the file?
                        fseek(file, i++, SEEK_SET);
                        temp_c = fgetc(file);

                        if (temp_c == ']')
                            hunting--;
                        else if (temp_c == '[')
                            hunting++;

                    } while (hunting > 0);
                }
                break;
            case ']':
                // skip backwards to start of loop
                i--;
                hunting = 1;;
                do { // todo: what if we reach the end of the file?
                    fseek(file, --i, SEEK_SET);
                    temp_c = fgetc(file);

                    if (temp_c == ']')
                        hunting++;
                    else if (temp_c == '[')
                        hunting--;

                } while (hunting > 0);
                break;
            case ',':
                *p = getchar();
                break;
            case '.':
                putchar(*p);
                break;
        }
    } while (1);

    return -1;
}
