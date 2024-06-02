#include "cli.h"
#include "package_manager.h"
#include <stdio.h>
#include <string.h>

void parse_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: packman <command> [options]\n");
        return;
    }

    if (strcmp(argv[1], "install") == 0) {
        if (argc < 3) {
            printf("Usage: packman install <package_name>\n");
            return;
        }
        install_package(argv[2]);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc < 3) {
            printf("Usage: packman remove <package_name>\n");
            return;
        }
        remove_package(argv[2]);
    } else if (strcmp(argv[1], "update") == 0) {
        if (argc < 3) {
            printf("Usage: packman update <package_name>\n");
            return;
        }
        update_package(argv[2]);
    } else if (strcmp(argv[1], "update-all") == 0) {
        update_package(argv[2]);
    } else {
        printf("Unknown command: %s\n", argv[1]);
    }
}
