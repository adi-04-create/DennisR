#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void list_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return;
    }

    printf("Contents of directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void read_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filepath);
        return;
    }

    printf("\nContents of file '%s':\n", filepath);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    printf("\nFile closed successfully.\n");
}

int main() {
    char dir_path[256];
    char file_name[256];

    printf("Enter directory path: ");
    scanf("%255s", dir_path);

    list_directory(dir_path);

    printf("\nEnter file name to open: ");
    scanf("%255s", file_name);

    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, file_name);

    read_file(full_path);

    return 0;
}

