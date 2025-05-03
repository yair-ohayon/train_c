#include <stdio.h>

int main(){
    int s = 2;

    printf("%d\n",(~s+1));

        unsigned int x = 0xFFFFFFFF; // 2^32 - 1
        printf("x = %u\n", x);
        x += 1;
        printf("After adding 1, x = %u\n", x); // Wraps around to 0
        return 0;
    

}