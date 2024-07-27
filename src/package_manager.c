#include "../include/package_manager.h"
#include "../include/repository.h"
#include <stdio.h>

void install_package(const char *package_name) {
    PkgInfo *pkg = get_pkg_info(package_name);
    if (pkg) {
        printf("Installing package %s version %s\n", pkg->name, pkg->version);
        // добавить код для копирования файлов пакета
    } else {
        printf("Package %s not found\n", package_name);
    }
}

void remove_package(const char *package_name) {
    PkgInfo *pkg = get_pkg_info(package_name);
    if (pkg) {
        printf("Removing package %s version %s\n", pkg->name, pkg->version);
        // добавить код для удаления файлов пакета
    } else {
        printf("Package %s not found\n", package_name);
    }
}

void update_package(const char *package_name) {
    PkgInfo *pkg = get_pkg_info(package_name);
    if (pkg) {
        printf("Updating package %s to version %s\n", pkg->name, pkg->version);
        // добавить кодыы для обновления файлов пакета
    } else {
        printf("Package %s not found\n", package_name);
    }
}

void initialize() {
    // PkgInfo information = get_pkg_info(url);
    // Инициавввлизация
    load_repository();
}

void cleanup() {
    // Очистка
}
