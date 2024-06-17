#include "../include/file_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 256

void download_file(const char *url, char *dest) {
    char DownloadPath[MAX_PATH_LENGTH];

    printf("Введите путь\n");
    fgets(DownloadPath,sizeof(DownloadPath),stdin);

        DownloadPath[strcspn(DownloadPath, "\n")] = 0;

    size_t lenght = strlen(DownloadPath);
    dest = (char*)malloc((lenght +1 ) * sizeof(char));
    if(dest == NULL) {
     fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    strcpy(dest, DownloadPath);


  printf("Downloading file from %s to %s...\n", url, dest);

  free(dest);
  exit(0);
}

void extract_file(const char *file_path, char *dest) {
  // Извлечение файла в указанный каталог
  printf("Extracting file %s to %s...\n", file_path, dest);
  // добавить код для извлечения файла
}

void remove_files(const char *package_name) {
  // Удаление файлов пакета
  printf("Removing files for package %s...\n", package_name);
  //  добавить код для удаления файлов пакета
}
