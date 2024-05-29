#ifdef  PACKAGE_MANAGER_H
#define PACKAGE_MANAGER_H

void install_pkg(const char *pkg_name);
void remove_pkg(const char *pkg_name);
void update_pkg(const char *pkg_name);


void initialize();
void cleanup();
#endif