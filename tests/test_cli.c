#include "../include/cli.h"
#include "../include/repository.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    load_repository();
    char buffer[100];
    char pkg_name[MAX_NAME_LENGTH];
    char *command[MAX_NAME_LENGTH];
    char d[] = " ";

    if (argc < 2) {
        for (int i = 0; i < 1; i++)
        {
            printf("Write cmd:\n");
            fgets(buffer,sizeof(buffer),stdin);

            int leng = strlen(buffer);
            if(buffer[leng - 1] == '\0')
                buffer[leng - 1] = '\n';
            command[i] = (char*)malloc(sizeof(leng));
			if(command[i] == NULL){
				perror("memory alloceter");
				return 1;
			}
            strcpy(command[i],buffer);
        
        
        PkgInfo *pkg = get_pkg_info(pkg_name);
        if (pkg) {
            printf("Package found: %s\n", pkg->name);
            printf("Package URL: %s\n",pkg->url);

            char *cmd1 = strtok(command[i],d);
            char *cmd2 = strtok(NULL,d);
            char *cmd3 = strtok(NULL,d);

            char *new_argv[3];

            new_argv[0] = cmd1;
            new_argv[1] = cmd2;
            new_argv[2] = cmd3;

            new_argv[0] = argv[0];
            new_argv[1] = *command;
            new_argv[2] = pkg_name;
            int new_argc = 3;

            parse_command(new_argc, new_argv);
        } else {
            printf("Package %s not found\n", pkg_name);
        }
    }
}
    return 0;
}
