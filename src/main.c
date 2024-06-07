// main.c
#include "cli.h"
#include "repository.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    load_repository();

    PkgInfo *pkg = get_pkg_info("example-package");
    if (pkg) {
        printf("Package found: %s\n", pkg->name);
    } else {
        printf("Package example-package not found\n");
    }

    parse_command(argc, argv);
    return 0;
}
