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
        if (buffer[leng - 1] == '\n') {
            buffer[leng - 1] = '\0';
        }

        command = (char *)malloc((leng + 1) * sizeof(char));
        if (command == NULL) {
            perror("memory allocation");
            return 1;
        }
        strcpy(command, buffer);

        char *cmd1 = strtok(command, d);
        char *cmd2 = strtok(NULL, d);
        char *pkgname = strtok(NULL, d);

        if (pkgname) {
            strcpy(pkg_name, pkgname);
            PkgInfo *pkg = get_pkg_info(pkg_name);
            if (pkg) {
                printf("Package found: %s\n", pkg->name);
                printf("Package URL: %s\n", pkg->url);

                char *argv_new[3];
                argv_new[0] = cmd1;
                argv_new[1] = cmd2;
                argv_new[2] = pkgname;

                int argc_new = 3;

                parse_command(argc_new, argv_new);
            } else {
                printf("Package %s not found\n", pkg_name);
            }
        } else {
            printf("No package name provided in the command.\n");
            free(command);
            return 0;
        }

        free(command);
    } else {
        strcpy(pkg_name, argv[2]);

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
