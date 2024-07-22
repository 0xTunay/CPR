#include "../include/cli.h"
#include "../include/repository.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    load_repository();

    char buffer[100];
    char pkg_name[MAX_NAME_LENGTH];
    char *command;
    char d[] = " ";

    if (argc < 2) {
        printf("Write cmd:\n");
        fgets(buffer, sizeof(buffer), stdin);

        int leng = strlen(buffer);
        if (buffer[leng - 1] == '\n')
            buffer[leng - 1] = '\0';

        command = (char*)malloc((leng + 1) * sizeof(char));
        if (command == NULL) {
            perror("memory allocation");
            return 1;
        }
        strcpy(command, buffer);

        char *cmd1 = strtok(command, d);
        char *cmd2 = strtok(NULL, d);
        char *cmd3 = strtok(NULL, d);

        if (cmd3) {
            strncpy(pkg_name, cmd3, MAX_NAME_LENGTH - 1);
            pkg_name[MAX_NAME_LENGTH - 1] = '\0';

            PkgInfo *pkg = get_pkg_info(pkg_name);
            if (pkg) {
                printf("Package found: %s\n", pkg->name);
                printf("Package URL: %s\n", pkg->url);

                char *new_argv[3];
                new_argv[0] = argv[0];
                new_argv[1] = cmd1;
                new_argv[2] = pkg_name;

                int new_argc = 3;

                parse_command(new_argc, new_argv);
            } else {
                printf("Package %s not found\n", pkg_name);
            }
        } else {
            printf("No package name provided in the command.\n");
        }

        free(command);
    } else {
        strncpy(pkg_name, argv[1], MAX_NAME_LENGTH - 1);
        pkg_name[MAX_NAME_LENGTH - 1] = '\0';

        PkgInfo *pkg = get_pkg_info(pkg_name);
        if (pkg) {
            printf("Package found: %s\n", pkg->name);
            printf("Package URL: %s\n", pkg->url);

            parse_command(argc, argv);
        } else {
            printf("Package %s not found\n", pkg_name);
        }
    }

    return 0;
}
