#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isPowerOfTwo(int n);
void swap(int *a, int *b){
    printf("%d %d\n",*a ,*b);
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("%d %d\n",*a ,*b);
}



int countOnes(int n) {
    int count = 0;
    while (n) {
        printf("%d\n" , n);
        n &= (n - 1);

        count++;
    }
    printf("%d %d" , n,count);
    return count;
}

struct Flags {
    unsigned char ready   : 1;
    unsigned char error   : 1;
    unsigned char power   : 1;
    unsigned char mode    : 2;
};
int main(){
    int c = 12;
    int b =5;

    int a  =2;

    int res = (a << 4) -a-a-a-a;
    printf("%f",log2(64 & -64));
    printf("Size of Flags struct: %zu bytes\n", sizeof(struct Flags));
    return 0;

}
