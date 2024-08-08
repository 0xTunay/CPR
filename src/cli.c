#include "../include/cli.h"
#include "../include/repository.h"
#include <stdio.h>
#include <string.h>

choice get_command_type(const char *command) {
  if (strcmp(command, "install") == 0) {
    return INSTALL;
  } else if (strcmp(command, "remove") == 0) {
    return REMOVE;
  } else if (strcmp(command, "updateall") == 0) {
    return UPDATEALL;
  } else {
    return UNKNOWN; 
  }
}

void parse_command(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: packman <command> [options]\n");
    return;
  }

  choice command_type = get_command_type(argv[1]);
  CommandFunction command_function = get_command_function(command_type);

  if (command_function == NULL) {
    printf("Unknown command: %s\n", argv[1]);
    printf("Available commands: install, remove, updateall\n");
    return;
  }

  if (argc < 3) {
    printf("Usage: packman %s <package_name>\n", argv[1]);
  } else {
    command_function(argv[2]);
  }
}
