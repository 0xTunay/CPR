#define _DEFAULT_SOURCE // for DT_REG stackoverflow

#include "../include/repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

static PkgInfo packages[MAX_PKG];
static int pkg_count = 0;

void load_repository() {
  printf("Loading repository...\n");

  DIR *dir;
  struct dirent *entry;

  dir = opendir("web/date");
  if (dir == NULL) {
    perror("Unable to open directory");
    return;
  }

  while ((entry = readdir(dir)) != NULL) {
    // Check if entry is a regular file and has .txt extension
    if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt")) {
      char filepath[MAX_PATH_LENGTH];
      snprintf(filepath, sizeof(filepath), "db/%s", entry->d_name);

      FILE *file = fopen(filepath, "r");
      if (file) {
        char line[MAX_LINE_LENGTH];
        PkgInfo pkg;
        memset(&pkg, 0, sizeof(PkgInfo));

        while (fgets(line, sizeof(line), file)) {
          char *key = strtok(line, "=");
          char *value = strtok(NULL, "\n");

          if (strcmp(key, "name") == 0) {
            strcpy(pkg.name, value);
          } else if (strcmp(key, "version") == 0) {
            strcpy(pkg.version, value);
          } else if (strcmp(key, "description") == 0) {
            strcpy(pkg.description, value);
          } else if (strcmp(key, "author") == 0) {
            strcpy(pkg.author, value);
          } else if (strcmp(key, "dependencies") == 0) {
            strncpy(pkg.dependencies, value, sizeof(pkg.dependencies) - 1);
          } else if(strcmp(key,"url") == 0){
            strcpy(pkg.url, value);
          }
        }
        packages[pkg_count++] = pkg;
        fclose(file);
      }
    }
  }
  closedir(dir);
}

PkgInfo *get_pkg_info(const char *pkg_name) {
  for (int i = 0; i < pkg_count; i++) {
    if (strcmp(packages[i].name, pkg_name) == 0) {
      return &packages[i];
    }
  }
  return NULL;
}
// ??????????????????????????????????????????????????????????????????
void add_pkg(const PkgInfo *package) {
  if (pkg_count < MAX_PKG) {
    packages[pkg_count++] = *package;
    printf("Package %s added\n", package->name);
  } else {
    printf("Repository is full\n");
  }
}

void remove_pkg(const char *pkg_name) {
  for (int i = 0; i < pkg_count; i++) {
    if (strcmp(packages[i].name, pkg_name) == 0) {
      for (int j = i; j < pkg_count - 1; j++) {
        packages[j] = packages[j + 1];
      }
      pkg_count--;
      printf("Package %s removed.\n", pkg_name);
      return;
    }
  }
  printf("Package %s not found\n", pkg_name);
}
// ??????????????????????????????????????????????????????????????????
