#include <stdio.h>
#include <dirent.h>
struct linked_list{
        char *p;
        struct linked_list *ptr;
};
int main() {
 
        struct dirent *entry;
	DIR *dir = opendir("/home/bhavik_23");
 
        if (dir == NULL) {
                perror("Unable to open directory");
                return 1;
        }
        int i = 0;
        printf("Files in current directory:\n");
        while ((entry = readdir(dir)) != NULL) {
                i++;
                //printf("%s\n", entry->d_name);
        }
        struct linked_list arr[i];
        rewinddir(dir);
        int k = 0;
        while ((entry = readdir(dir)) != NULL) {
                arr[k].p = entry->d_name;
                if ( k == 0)
                        arr[k].ptr = NULL;
                else if ( k == i)
                        arr[k].ptr = NULL;
                else
                        arr[k].ptr = &arr[k-1];
                //printf("%s\n", arr[k].p);
                k++;
        }
        i = 0;
        for (i = 0; i < k - 1; i++) {
                for (int j = 0; j < k - i - 1; j++) {
                        if (*arr[j].p > *arr[j + 1].p)
                        {
                                int *temp = arr[j].p;
                                arr[j].p = arr[j + 1].p;
                                arr[j + 1].p = temp;
                        }
                }
        }
        i = 0;
        while ( i < k) {
                printf("%s\n", arr[i].p);
                i++;
        }
        closedir(dir);
        return 0;
}
