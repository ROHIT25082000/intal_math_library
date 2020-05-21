#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myatoi(char a){
    return a - '0';
}
char myitoa(int b){
    return b + '0';
}

char* intal_add(const char* intal1, const char* intal2){
    const char * num1 = intal1;
    const char * num2 = intal2;
    while((*num1) == '0')
        num1++;
    while((*num2) == '0')
        num2++;
    int len_intal1 = strlen(num1);
    int len_intal2 = strlen(num2);
    int result_len = len_intal1 > len_intal2 ? len_intal1 : len_intal2;
    
    char * result = (char *)malloc(sizeof(char)*(result_len+2));
    char * res_flag = result - 1;
    result = result + (result_len+1);
    *result = '\0';
    result--;
    const char * flag1 = num1-1;
    const char * flag2 = num2-1;
    
    num1 = num1 + len_intal1 - 1;
    num2 = num2 + len_intal2 - 1;
    int carry = 0;
    while(num1 != flag1 && num2 != flag2){
        int temp =  (myatoi(*num1)+myatoi(*num2)+carry);
        carry = temp / 10;
        int digit = temp % 10;
        *result = myitoa(digit);
        result--;
        num1--;
        num2--;
    }
    while(num1!=flag1){
        int temp =  (myatoi(*num1)+carry);
        carry = temp / 10;
        int digit = temp % 10;
        *result = myitoa(digit);
        result--;
        num1--;  
    }
    while(num2!=flag2){
        int temp =  (myatoi(*num2)+carry);
        carry = temp / 10;
        int digit = temp % 10;
        *result = myitoa(digit);
        result--;
        num2--;
    }
    char * actual = result + 1;
    while(result!= res_flag){
        result--;
    }
    actual;
    while(*actual == '0'){
            actual++;
        }
    int act_len = strlen(actual);
    char * final = (char*)malloc(sizeof(char)*(act_len+1));
    strcpy(final,actual);
    free(result+1);
    return final;
}


int main(){

   char a[20] = "526230000";
   char b[20] = "59680000";
   printf("The product of 526230000 and 59680000 is %s",intal_multiply(a,b));
}