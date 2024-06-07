// main.c
#include "cli.h"
#include "repository.h"
#include <stdio.h>
#define MAX_NAME_LINE 100

int main(int argc, char *argv[]) {
    load_repository();

    char pkg_name[MAX_NAME_LINE];
    scanf("%s",pkg_name);

    PkgInfo *pkg = get_pkg_info(pkg_name);
    if (pkg) {
        printf("Package found: %s\n", pkg->name);
        printf("Version: %s\n", pkg->version);
        printf("Description: %s\n", pkg->description);
        printf("Author: %s\n", pkg->author);
        printf("Dependencies: %s\n", pkg->dependencies);
        printf("Files: %s\n", pkg->files);
    } else {
        printf("Package %s not found\n",pkg_name);
    }

    parse_command(argc, argv);
    return 0;
}
