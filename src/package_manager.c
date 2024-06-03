#include "package_manager.h"
#include <stdio.h>
#include <stdlib.h>

void install_pkg(const char *pkg_name) 
{
    char command[256];
    snprintf(command,sizeof(command),"sudo pacman -S %s",pkg_name);
    printf("Executing %s\n",command);
    system(command);
}

void remove_pkg(const char *pkg_name)
{   
    char command[256];
    snprintf(command,sizeof(command),"sudo pacman -R %s",pkg_name);
    printf("Executing %s\n",command);
    system(command);
}

void update_package(const char *pkg_name) {
    char command[256];
    snprintf(command,sizeof(command),"sudo pacman -Syu %s",pkg_name);
    printf("Executing %s\n",command);
    system(command);
}

void initialize() {
    // Инициализация системы (например, загрузка бд)
    printf("Initializing package manager...\n");
}

void cleanup() {
    // Очистка ресурсов перед завершением программы
    printf("Cleaning up...\n");
}
