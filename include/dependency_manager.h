#ifndef DEPENDENCY_MANAGER_H
#define DEPENDENCY_MANAGER_H

#define MAX_COMMAND_LINE 128

void check_dependencies(const char *pkg_name);
void resolve_dependencies(const char *pkg_name);

#endif // DEPENDENCY_MANAGER_H
