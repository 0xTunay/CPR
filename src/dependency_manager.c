#include "../include/dependency_manager.h"
#include <stdlib.h>
#include <stdio.h>

void check_dependencies(const char *dependecies_name) 
{
    char command[128];
    snprintf(command, sizeof(command), "%s --version\n", dependecies_name);

    int cmd = system(command);

    if (cmd == 0) {
        puts("Dependency is installed");
    } else {
        resolve_dependencies(dependecies_name);
    }
}

void resolve_dependencies(const char *pkg_name){
    
    printf("Resolving dependencies for %s...\n", pkg_name);

    char command[128];
    snprintf(command, sizeof(command), "sudo pacman -S %s", pkg_name);

    int cmd_result = system(command);
    if (cmd_result == 0) {
        printf("Package %s installed successfully.\n", pkg_name);
    } else {
        printf("Failed to install package %s.\n", pkg_name);
    }

}
