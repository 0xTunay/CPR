#include "../include/cli.h"
#include "../include/package_manager.h"
#include "../include/repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char command[256];
    printf("Enter command: ");
if (fgets(command, sizeof(command), stdin) == NULL) {
    printf("Failed to read command\n");
    exit(1);
}
command[strcspn(command, "\n")] = 0;

}
