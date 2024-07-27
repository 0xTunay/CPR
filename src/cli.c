#include "../include/cli.h"
#include "../include/package_manager.h"
#include "../include/repository.h"
#include <stdio.h>
#include <string.h>

cmd get_command_type(const char *command) {
    if (strcmp(command, "install") == 0) {
        return INSTALL;
    } else if (strcmp(command, "remove") == 0) {
        return REMOVE;
    } else if (strcmp(command, "updateall") == 0) {
        return UPDATEALL;
    } else {
        return 1; 
    }
}

void parse_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: packman <command> [options]\n");
        return;
    }

    cmd command_type = get_command_type(argv[1]);

    switch (command_type) {
        case INSTALL:
            if (argc < 3) {
                printf("Usage: packman install <package_name>\n");
            } else {
                install_package(argv[2]);
            }
            break;

        case REMOVE:
            if (argc < 3) {
                printf("Usage: packman remove <package_name>\n");
            } else {
                remove_pkg(argv[2]);
            }
            break;
        case UPDATEALL:
            if (argc < 3) {
                printf("Usage: packman updateall <package_name>\n");
            } else {
                update_package(argv[2]);
            }
            break;
        default:
            printf("Unknown command: %s\n", argv[1]);
            printf("Available commands: install, remove, updateall\n");
            break;
    }
}