#include "../include/cli.h"
#include "../include/repository.h"
#include <stdio.h>
#include <string.h>

choice get_command_type(const char *command) {
    return (strcmp(command, "install") == 0) ? INSTALL :
           (strcmp(command, "remove") == 0) ? REMOVE :
           (strcmp(command, "updateall") == 0) ? UPDATEALL :
           UNKNOWN;
}

void parse_command(int argc, char *argv[]) {
  
  choice command_type = get_command_type(argv[1]);
  command_function command_function = get_command_function(command_type);

  if (argc < 2)
  {
    puts("Usage: packman <command> [options]");
    return;
  }

  if (command_function == NULL) 
  {
    printf("Unknown command: %s\n", argv[1]);
    puts("Available commands: install, remove, updateall");
    return;
  }

  if (argc < 3) 
  {
    printf("Usage: packman %s <package_name>\n", argv[1]);
  } else {
    command_function(argv[2]);
  }
}