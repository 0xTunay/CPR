// main.c
#include "../include/cli.h"
#include "../include/repository.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char user[MAX_NAME_LINE];
 
 
    printf("what do you want install?\n");
    parse_command(argc,argv);
    scanf("%s",user);
    strcpy(pkg_name,user);

    
/*
    если тру, то дальше продолжать код и вывести repostiroy, а если такого пакета не найдено, то рентун
*/
// сделать чтобы перед этим выводилась инфа о пакете
    printf("Do you want to install %s repository? (Yes/No): ", pkg_name);
    scanf("%s",user);

    if (fgets(user, sizeof(user), stdin) != NULL) {
        user[strcspn(user, "\n")] = '\0';
    }

    if (strcmp(user, "Yes") == 0) {
        parse_command(argc, argv);
    } else {
        printf("Installation aborted.\n");
        return 0;
    }


    return 0;


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
