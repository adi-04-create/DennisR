#include <stdio.h>
int mysterious(int x) {
    static int count = 0; 
    return (count++ == 0) ? x : x * count;
}
int main() {
    printf("%d, %d, %d, %d\n", mysterious(5), mysterious(3), mysterious(2), mysterious(1));
    return 0;
}

