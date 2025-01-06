#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


#define MAX_PATH_LENGTH 256

// // function for wotking with package files
void download_file(const char *url, char *dest);
void extract_file(const char *file_path, char *dest);
void remove_files(const char *package_name);

#endif // FILE_MANAGER_H
