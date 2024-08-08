#include "../include/repository.h"
#include "../include/package_manager.h"
#include <stdio.h>

command_function get_command_function(choice cmd) {
  switch (cmd) {
    case INSTALL:
      return install_package;
    case REMOVE:
      return remove_pkg;
    case UPDATEALL:
      return update_package;
    default:
      return 0; 
  }
}

void install_package(const char *pkg_name) {
    printf("Installing package: %s\n", pkg_name);
}

void update_package(const char *pkg_name) {
    printf("Updating package: %s\n", pkg_name);
}