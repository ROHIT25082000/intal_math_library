#include<stdio.h>
#include<stdlib.h>
#include "intal.h"


int myatoi(char a){
    return a - '0';
}
char myitoa(int b){
    return b + '0';
}


// Returns the sum of two intals.                   // done this one 
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

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* intal1, const char* intal2)   // done this too
{
    const char * num1 = intal1;
	const char * num2 = intal2;
	while((*num1) == '0')
	    num1++;
	while((*num2) == '0')
	    num2++;
    int len_intal1 = strlen(num1);
	int len_intal2 = strlen(num2);
	if(len_intal1 > len_intal2){
        return 1;
    }
    else if(len_intal1 < len_intal2){
        return -1;
    }
    else if(strcmp(num1,num2)==0){
        return 0;
    }
    else{   // numbers are of same length
        for(int i = 0; i < len_intal1 ; i++){
            if(myatoi(*num1) > myatoi(*num2))
                return 1;
            else if(myatoi(*num1) < myatoi(*num2)){
                return -1;
            }
            num1++;
            num2++;
        }
        return 0;
    }
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* intal1, const char* intal2)        // done this also
{
    int x = intal_compare(intal1,intal2);
    if(x == 0){
        char * result = (char*)malloc(sizeof(char)*2);
        strcpy(result,"0");
        return result;
    }
    else if(x == -1)
    {
        char * temp = intal1;
        intal1 = intal2;
        intal2 = temp;
        char * swap_result = intal_diff(intal1,intal2);
        return swap_result;
    }
    else
    {
        const char * num1 = intal1;
	    const char * num2 = intal2;
	    while((*num1) == '0')
	        num1++;
	    while((*num2) == '0')
	        num2++;
        int len_intal1 = strlen(num1);
        int len_intal2 = strlen(num2);

        int result_len = len_intal1 > len_intal2 ? len_intal1 : len_intal2;

        char * result = (char*)malloc(sizeof(char)*(result_len+1));
        char * res_flag = result - 1;
        result = result + result_len;
        *result = '\0';
        result--;

        const char * flag1 = num1-1;
	    const char * flag2 = num2-1;
        int borrow = 0;
	    num1 = num1 + len_intal1 - 1;
	    num2 = num2 + len_intal2 - 1;
        while(num1 != flag1 && num2 != flag2)
        {
            int digit;
            if(myatoi(*num1) - myatoi(*num2) + borrow >= 0){
                digit = (myatoi(*num1) - myatoi(*num2))+borrow;
                borrow = 0;
            }
            else if(myatoi(*num1) - myatoi(*num2) + borrow < 0)
            {
                digit = 10 + myatoi(*num1) - myatoi(*num2) + borrow;
                borrow = -1;
            }
            *result = myitoa(digit);
            result--;
            num1--;
            num2--;
        }
        while(num1!=flag1)
        {
            int digit;
            if(myatoi(*num1) + borrow >= 0){
                digit = (myatoi(*num1) + borrow);
                borrow = 0;
            }
            else if(myatoi(*num1) + borrow < 0)
            {
                digit = 10 + myatoi(*num1) + borrow;
                borrow = -1;
            }
            *result = myitoa(digit);
            result--;
            num1--;
        }
        while(num2!=flag2)
        {
            int digit;
            if(myatoi(*num2) + borrow >= 0){
                digit = (myatoi(*num1) + borrow);
                borrow = 0;
            }
            else if(myatoi(*num2) + borrow < 0)
            {
                digit = 10 + myatoi(*num2) + borrow;
                borrow = -1;
            }
            *result = myitoa(digit);
            result--;
            num2--;
        }
        char * actual = result + 1;
        while(result!=res_flag)
        {
            result--;
        }
        while(*actual == '0'){
            actual++;
        }
        int act_len = strlen(actual);
        char * final = (char*)malloc(sizeof(char)*(act_len+1));
        strcpy(final,actual);
        free(result+1);
        return final;
    }
}

// Returns the product of two intals.

char* intal_multiply(const char* intal1, const char* intal2)    // done this one too
{
    char ** addition_chamber = (char **)malloc(sizeof(char*)*2);    // here the addition will be carried out
    addition_chamber[0] = NULL;
    addition_chamber[1] = NULL;

    const char * num1 = intal1;
    const char * num2 = intal2;
    while((*num1) == '0')
        num1++;
    while((*num2) == '0')
        num2++;
    int len_intal1 = strlen(num1);
    int len_intal2 = strlen(num2);
    
    const char * flag1 = num1 - 1;
    const char * flag2 = num2 - 1;

    num1 = num1 + len_intal1 - 1;
    num2 = num2 + len_intal2 - 1;

    const char * multiplicand_flag = num1;
    const char * factor_flag = num2;

    int chamber_index = 0;
    int carry = 0;

    while(num2!=flag2)
    {
        addition_chamber[chamber_index] = (char *)malloc(sizeof(char)*(len_intal1+ 2 + (factor_flag - num2)));
        char * set_zero = addition_chamber[chamber_index]+ (len_intal1 + factor_flag - num2);
        *(set_zero+1) = '\0';
        for(int i = 0; i < factor_flag - num2; i++)
        {
            (*set_zero)= '0';
            set_zero--;
        }
        while(num1!=flag1)
        {
            int digit = (myatoi(*num2) * myatoi(*num1) + carry) %10;
            *set_zero = myitoa(digit);
            carry = (myatoi(*num2) * myatoi(*num1) + carry)/10;
            num1--;
            set_zero--;
        }
        if(carry != 0)
        {
          *set_zero = myitoa(carry);
          set_zero--;
          carry = 0;
        }
        while(set_zero >= addition_chamber[chamber_index])
        {
            *set_zero = '0';
            set_zero--;
        }
        chamber_index++;
        if(chamber_index == 2)
        {
            char * temp = intal_add(addition_chamber[0],addition_chamber[1]);
            free(addition_chamber[0]);
            addition_chamber[0] = NULL;
            free(addition_chamber[1]);
            addition_chamber[1] = NULL;
            
            addition_chamber[0] = temp;
            chamber_index = 1;
        }
        num1 = multiplicand_flag;
        num2--;
    }
    char * result = addition_chamber[0];
    char * result1 = addition_chamber[0];
    while(*result == '0')
    {
        result++;
    }
    char * final = (char *)malloc(sizeof(char)*(strlen(result)+1));
    strcpy(final,result);
    free(result1);
    return final;
}

// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
// intal2 > 1
// Implement a O(log intal1) time taking algorithm.
// O(intal1 / intal2) time taking algorithm may exceed time limit.
// O(intal1 / intal2) algorithm may repeatedly subtract intal2 from intal1.
// That will take intal1/intal2 iterations.
// You need to design a O(log intal1) time taking algorithm.
// Generate your own testcases at https://www.omnicalculator.com/math/modulo
char* intal_mod(const char* intal1, const char* intal2);

// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
// Implement a O(log n) intal multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.
char* intal_pow(const char* intal1, unsigned int n);

// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(const char* intal1, const char* intal2);

// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".




char* intal_fibonacci(unsigned int n)
{
    
}
// Returns the factorial of n.
char* intal_factorial(unsigned int n)
{
}

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k);

// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
    int max = 0;
    for(int i = 0; i <n; i++)
    {
        if(intal_compare(&arr[i],&arr[max])==1)
        {
            max = i;
        }
    }
    return max;
}

// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_min(char **arr, int n)
{
    int min = 0;
    for(int i = 0; i < n; i++)
    {
        if(intal_compare(arr[i],arr[min])== -1)
        {
            min = i;
        }
    }
    return min;
}

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key)
{
    for(int i = 0; i < n; i++)
    {
        if(intal_compare(arr[i],key) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.


int intal_binsearch(char **arr, int n, const char* key)
{
    int l = 0;
    int r = n -1;
    while(l <= r)
    {
        int m = l + (r - 1)/2;
        
        if(intal_compare(arr[m],key)==0)
            return m;
        if(intal_compare(arr[m],key) == -1)
            l = m + 1;
        else if(intal_compare(arr[m],key) == 1)
            r = m - 1; 
    }
    return -1;
}

// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.

int index_partition (char **arr, int low, int high) 
{ 
    char * pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
     
        if (intal_compare(arr[j],pivot) == -1) 
        { 
            i++;    
            char * temp = arr[j];
            arr[j] = pivot;
            pivot = temp;
        } 
    } 
    char * temp1 = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp1;
    return (i + 1); 
} 
void index_intal_sort(char **arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = index_partition(arr, low, high); 
        index_intal_sort(arr, low, pi - 1); 
        index_intal_sort(arr, pi + 1, high); 
    } 
}

void intal_sort(char **arr, int n)
{
    index_intal_sort(arr,0,n-1);
}

// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
char* coin_row_problem(char **arr, int n);


