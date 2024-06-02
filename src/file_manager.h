#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

// Функции для работы с файлами пакетов
void download_file(const char *url, const char *dest);
void extract_file(const char *file_path, const char *dest);
void remove_files(const char *package_name);

#endif // FILE_MANAGER_H
