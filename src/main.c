#include "../include/cli.h"
#include "../include/repository.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    load_repository();

    char pkg_name[MAX_NAME_LENGTH];
    char command[MAX_NAME_LENGTH];

    if (argc < 2) {
        printf("Enter the name of the package: ");
        scanf("%s", pkg_name);

        PkgInfo *pkg = get_pkg_info(pkg_name);
        if (pkg) {
            printf("Package found: %s\n", pkg->name);
            printf("Enter command (install, remove, update, update-all): ");
            scanf("%s", command);

            char *new_argv[3];
            new_argv[0] = argv[0];
            new_argv[1] = command;
            new_argv[2] = pkg_name;
            int new_argc = 3;

            parse_command(new_argc, new_argv);
        } else {
            printf("Package %s not found\n", pkg_name);
        }
    }

    return 0;
}
