#include "../include/cli.h"
#include "../include/repository.h"
#include "../include/dependency_manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  load_repository();

  char buffer[MAX_BUFFER_SIZE];
  char pkg_name[MAX_NAME_LENGTH];
  char *command;
  char space[] = " ";

  while (1) {
    if (argc < 2) {
      puts("enter cmd:");
      if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        perror("fgets failed");
        return 1;
      }

      int leng = strlen(buffer);
      if (buffer[leng - 1] == '\n') {
        buffer[leng - 1] = '\0';
      }

      command = (char *)malloc((leng + 1) * sizeof(char));
      if (command == NULL) {
        perror("memory allocation");
        return 1;
      }
      strcpy(command, buffer);
      char *cmd1 = strtok(command, space);
      char *cmd2 = strtok(NULL, space);
      char *pkgname = strtok(NULL, space);

      PkgInfo *pkg = malloc(sizeof(PkgInfo));

      if (pkgname) {
        strcpy(pkg_name, pkgname);
        PkgInfo *pkg = get_pkg_info(pkg_name);

        if (pkg) {
          printf("Package found: %s\n", pkg->name);
          printf("Package URL: %s\n", pkg->url);
          printf("Dependecy: %s\n",pkg->dependencies);

          char *dependencies = pkg->dependencies;
          if(dependencies == NULL )
          {
            puts("Nothing dependency");
            continue;

          } else {
            check_dependencies(dependencies);
          }
          char *argv_new[3] = {cmd1, cmd2, pkgname};
          int argc_new = 3;
          parse_command(argc_new, argv_new);
          free(command);
          break; 
        } else {
          printf("Package %s not found\n", pkg_name);
        }
      } else {
        puts("No package name provided in the command.\n");
      }

      free(command); 
    }
}
  return 0;
}
