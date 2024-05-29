#include "cli.h"
#include "package_manager.h"

int main(int argc, char *argv[]) {
    // Инициализация системы
    initialize();

    // Парсинг команд
    parse_command(argc, argv);

    // Очистка ресурсов перед завершением
    cleanup();

    return 0;
}
