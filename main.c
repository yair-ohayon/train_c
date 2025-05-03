#include <stdio.h>
#include "data.h"




int main(){
    printf("Hello World\n");
    print_something("FF");

}


int print_something(char* msg){
    printf("Message is %s ",msg);
    return 0;
}