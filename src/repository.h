#ifndef REPOSITORY_H
#define REPOSITORY_H


typedef struct {
    char name[128];
    char version[32];
    char url[256];
} PkgInfo;

void load_repository();
PkgInfo * get_pkg_info(const char * pkg_name);
void add_pkg(const PkgInfo *pkg);
void remove_pkg(const char *pkg_name);

#endif // REPOSITORY_H