#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

int main() {
    char *dest;
    char downloadPath[MAX_PATH_LENGTH];

    printf("Введите путь для скачивания файла: ");
    fgets(downloadPath, sizeof(downloadPath), stdin);

    downloadPath[strcspn(downloadPath, "\n")] = 0;

    size_t length = strlen(downloadPath);
    dest = (char *)malloc((length + 1) * sizeof(char));
    if (dest == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    strcpy(dest, downloadPath);

    printf("Файл будет скачан в: %s\n", dest);

    free(dest);

    return 0;
}
