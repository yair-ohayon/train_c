#include <stdio.h>
#include <stdlib.h>


int is_prime(int num){
    if (num % 2 == 0 ) return 0;
    int devider = 3;

    while(devider < num){
        if (num % devider == 0) return 0;
        devider += 2; 

    }
    return 1;
}

int factorial(int n){
    if (n == 1 ){
        return 1;
    }
    return n * factorial(n-1);
}

int is_armtrong(int n){
    int res[20] ;
    int index=0;

    while(n >0){
        res[index] = (n%10);
        n = n/10;
        index++;
    }

    for (int i =0 ; i++ ;i +=1)
    return res;



}

int main(){
    printf("%d",is_armtrong(153));
}