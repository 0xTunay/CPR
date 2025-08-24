#ifndef REPOSITORY_H
#define REPOSITORY_H

#define MAX_NAME_LENGTH         64
#define MAX_VERSION_LENGTH      32
#define MAX_DESCRIPTION_LENGTH  256
#define MAX_AUTHOR_LENGTH       64
#define MAX_DEPENDENCIES        256
#define MAX_URL_ADDRESS         256
#define MAX_BUFFER_SIZE         128
#define MAX_PKG                 128
#define MAX_LINE_LENGTH         256
#define MAX_PATH_LENGTH         256

typedef enum {
    INSTALL,
    REMOVE,
    UPDATEALL,
    UNKNOWN
} choice;

typedef void (*command_function)(const char *pkg_name);

typedef struct {
    char name[MAX_NAME_LENGTH];
    char version[MAX_VERSION_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char dependencies[MAX_DEPENDENCIES];
    char url[MAX_URL_ADDRESS];
} PkgInfo;

PkgInfo *get_pkg_info(const char *pkg_name);
command_function get_command_function(choice cmd); 
void load_repository();
void add_pkg(const PkgInfo *package);
void remove_pkg(const char *pkg_name);

#endif // REPOSITORY_H