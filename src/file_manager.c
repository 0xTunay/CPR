#include "../include/file_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void download_file(const char *url, char *dest) {
    char DownloadPath[MAX_PATH_LENGTH];
    
    size_t lenght = sizeof(DownloadPath) / sizeof(DownloadPath[0]);

    puts("enter path ");
    fgets(DownloadPath,sizeof(DownloadPath),stdin);

        DownloadPath[strcspn(DownloadPath, "\n")] = 0;

    dest = (char*)malloc((lenght +1 ) * sizeof(char));
    if(dest == NULL) {
     fprintf(stderr, "error memory\n");
        exit(1);
    }
    strcpy(dest, DownloadPath);


  printf("Downloading file from %s to %s...\n", url, dest);

  free(dest);
  exit(0);
}

void extract_file(const char *file_path, char *dest) {
  
  //  exstract file to directory
  printf("Extracting file %s to %s...\n", file_path, dest);
  // add code for extracting to directory
}

void remove_files(const char *package_name) {
  // deleted packeg files 
  printf("Removing files for package %s...\n", package_name);
  //  add code for deleted to directory
}
