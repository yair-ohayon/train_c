#include <stdio.h>
#include <stdlib.h>

char* num2str(int num){
    char* str = (char*)malloc(10*sizeof(char));

    for (int i = 0 ; i <10 ; i++){
        if (num > 0){
            sprintf(str+i,"%d",num%10);
            num = num/10;
        } 
    }
    return str;


}

enum week { Mon, Tue, Wed, Thur, Fri, Sat, Sun };

//Write a program to convert a number to a string with the help of sprintf() function in the C library.
int main2 (){
//    printf("%s",num2str(450));

    enum week day;
    day = Wed;
    printf("%d", day);
    if (day == Wed){
        printf("%d",day);
    }
    return 0;


}

int  fibonacci_recursive(int n ){
    if (n <= 0) {
        //printf("0 ");
        return 0;
    }
    if (n==1  ){

        //printf("1 ");
        return 1;
    }

    int res = fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    printf("%d ",res);

    return res;
}

void print_fibonacci(int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
}
int main (){
    //    printf("%s",num2str(450));
    print_fibonacci(7);
        // enum week day;
        // day = Wed;
        // printf("%d", day);
        // if (day == Wed){
        //     printf("%d",day);
        // }
        // return 0;
    
    
    }