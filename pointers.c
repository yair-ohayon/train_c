
#include <stdio.h>

int main() {
    int* ptrstart, *ptrend;
    int arraysize ;
    int temp;
    
    int a[] = {1,2,3,4,5};
    printf("%ld\n",sizeof(a));
    for (int i=0; i< sizeof(a)/sizeof(int);i++){
        printf("%d ",a[i]);
    }
    ptrstart = a;
   
    arraysize = sizeof(a)/sizeof(int)-1;


    for (int i=0; i< sizeof(a)/sizeof(int)/2;i++){
        temp = *(ptrstart+i);
        *(ptrstart+i) = *(ptrstart+arraysize-i);
        *(ptrstart+arraysize-i) = temp;

    }

    for (int i=0; i< sizeof(a)/sizeof(int);i++){
        printf("%d ",a[i]);
    }



}
