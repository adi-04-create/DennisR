#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
int print_file_info(const char *filename) {
        struct stat fileStat;
 
        if (stat(filename, &fileStat) < 0) {
                perror("stat");
                return 0;
        }
 
        printf("File: %s\n", filename);
 
        printf("Size: %ld bytes\n", fileStat.st_size);
 
        printf("Inode: %lu\n", fileStat.st_ino);
        printf("Permissions: ");
        printf((S_ISDIR(fileStat.st_mode))?"d":"-");
        printf((fileStat.st_mode & S_IRUSR)?"r":"-");
        printf((fileStat.st_mode & S_IWUSR)?"w":"-");
        printf((fileStat.st_mode & S_IXUSR)?"x":"-");
        printf((fileStat.st_mode & S_IRGRP)?"r":"-");
        printf((fileStat.st_mode & S_IWGRP)?"w":"-");
        printf((fileStat.st_mode & S_IXGRP)?"x":"-");
        printf((fileStat.st_mode & S_IROTH)?"r":"-");
        printf((fileStat.st_mode & S_IWOTH)?"w":"-");
        printf((fileStat.st_mode & S_IXOTH)?"x":"-");
        printf("\n");
	
	
	//printf("Last Access: %s", ctime(&fileStat.st_atime));
	//printf("Last Modify: %s", ctime(&fileStat.st_mtime));
	//printf("Last Change: %s", ctime(&fileStat.st_ctime));
 
        printf("\nSpecial Attributes: ");
        char command[256];
        snprintf(command, sizeof(command), "lsattr %s", filename);
        system(command);
 
        printf("\n");
}
int main(int argc, char *argv[]) {
        if (argc < 2) {
                printf("Usage: %s <filename>\n", argv[0]);
                return 1;
        }
        print_file_info(argv[1]);
        return 0;
}
