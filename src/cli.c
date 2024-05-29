#include "cli.h"
#include "package_manager.h"
#include <stdio.h>
#include <string.h>

void parse_cmd(int argc,char argv[]) 
{
    if(argc < 2) {
        printf("usafe: PackMan <command>[options]\n");
    }

    if(strcmp(argv[1],"install ") == 0) {
        install_pkg(argv[2]);
    } else if (strcmp(argv[1],"remove") == 0)
    {
        remove_pkg(argv[2]);
    }else if (strcmp(argv[1],"update")== 0)
    {
        update_pkg(argv[2]);
    } else {
        printf("comand %s\n not found \n",argv[1]);
    }
    
    
}