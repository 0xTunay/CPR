#include <stdio.h>
#include "cli.h"

int main(int argc, char *argv[]) {
 //   initialize();
    // cleanup();
        parse_command(argc, argv);

}


void parse_command(int argc, char *argv[]) {

    printf("argc будет равно %d, потому что есть %d аргумента: ", argc, argc);
    for (int i = 0; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(", ");
        }
    }
    printf(".\n");

    printf("argv будет массивом строк:\n");
    for (int i = 0; i < argc; i++) {
        printf("    argv[%d] = \"%s\"\n", i, argv[i]);
    }
    printf("    argv[%d] = NULL (указывает на конец массива)\n", argc);

}