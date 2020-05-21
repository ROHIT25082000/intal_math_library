#include<stdio.h>
#include<stdlib.h>
int main(){
    char* buffer = (char *)malloc(sizeof(10));
    int value = 4564;
    sprintf(buffer, "%d", value);
    printf("%s is the value now ",buffer);
}