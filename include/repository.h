#ifndef REPOSITORY_H
#define REPOSITORY_H

#define MAX_NAME_LINE 100
extern char pkg_name[MAX_NAME_LINE];

typedef struct {
    char name[256];
    char version[256];
    char description[1024];
    char author[256];
    char dependencies[1024];
    char files[1024];
} PkgInfo;

void load_repository();
PkgInfo *get_pkg_info(const char *pkg_name);
void add_pkg(const PkgInfo *pkg);
void remove_pkg(const char *pkg_name);

#endif // REPOSITORY_H
