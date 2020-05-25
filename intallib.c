#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "intal.h"


static int myatoi(char a){
    return a - '0';
}
static char myitoa(int b){
    return b + '0';
}

static char* destroy_zero(char* given_string)
{
    int i;
	int n = strlen(given_string);
	// Counting the zero before 
	for(i = 0; i < n; i++)
	{
		if(given_string[i]!='0')
        {
			break;
        }
	}
	for(int j = i; j < n; j++)
    {	
		given_string[j-i] = given_string[j];
    }
    given_string[n-i] = '\0';
	return given_string;
}

// Returns the sum of two intals.                        // done this one before 
char* intal_add(const char* intal1, const char* intal2){
   
	if(strcmp(intal1, "0") ==0 && strcmp(intal2, "0")==0)
	{
		char* result = malloc(sizeof(char)*2);
		strcpy(result, "0");
		return result;
	}
	int len1 = strlen(intal1); 
    int len2 = strlen(intal2);
	int max = len1>len2 ? len1:len2;
	char* result = (char*)malloc(sizeof(char)*(max+2));
	for(int i = 0; i< max+2; i++)
    {
		result[i]='0';
    }
    result[max+1]='\0';

	int r = max, carry = 0,i, tell, j;
	for(i = len1-1, j = len2-1; i >= 0 && j >= 0; i--, j--)
	{
		tell = (intal1[i]-'0')+(intal2[j]-'0')+carry;
		result[r--] = (char)(tell %10+'0');
		carry = tell/10;
	}
	if(i==-1 && j!=-1)
	{
		while(r != 0)
		{
			tell = (intal2[j--] -'0') + carry;
			result[r--] = (char)( tell %10+'0');
			carry = tell/10;
		}
	}
	else if(j==-1 && i!=-1)
	{
		while(r!=0)
		{
			tell = (intal1[i--]-'0') + carry;
			result[r--] = (char)(tell%10+'0');
			carry = tell/10;
		}
	}
	if(carry!=0)
		result[0]=( (result[0]-'0')+ carry)+'0';
	result = destroy_zero(result);
	return result;
}

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* intal1, const char* intal2)   // done this too
{
    int a;
    int b;
    a = strlen(intal1);
    b = strlen(intal2);
    if(a > b)
    {
        return 1;
    }
    else if(b > a)
    {
      return -1;
    }
    else
    {
        for(int i = 0;i < a ; i++)
        {
            if(intal1[i] > intal2[i])
            {
               return 1;
            } 
            else if(intal1[i] < intal2[i])
            { 
                return -1;
            }
        }
        return 0;
    }
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* intal1, const char* intal2)        // done this also
{
	char* borrow=malloc(2*sizeof(char));
	strcpy(borrow, "0");
	
    
    int a = strlen(intal1);
    int b = strlen(intal2);
	
    int max = a > b ? a : b;
	int r = max-1;
	
    int comp = intal_compare(intal1, intal2);
	if(comp == 0)
		return borrow;
	free(borrow);
	char* result = malloc(sizeof(int)*(max+1));
	char* num1=malloc(a*sizeof(char));
	char* num2 = malloc(b*sizeof(char));
	strcpy(num1, intal1);
	strcpy(num2, intal2);
	result[max]='\0';
	if(comp==1) //intal1 > intal2
	{	
		int i;
        int j;
		for(i= a-1, j=b-1; i>=0 && j>=0; i--, j--)
		{
			if(num1[i] >= num2[j])
				result[r--] = num1[i] - num2[j] + '0';
			else
			{
				if(num1[i-1]!='0') 
					num1[i-1]-=1;
				else
				{
					int key=i-1;
					while(num1[key]=='0')
					{
						num1[key]='9';
						key--;
					}
					num1[key]-=1;
				}
				result[r--] = (10 + (num1[i]-'0')) - (num2[j] -'0') + '0';
			}
		}
		if(i!=-1)
		{
			for(int k=i; k>=0; k--)
				result[k] = num1[k];
		}
		free(num1);
		free(num2);
		result = destroy_zero(result);
		return result;
	}
	else
	{
		int i;
        int j;
		for(i=b-1, j=a-1; i>=0 && j>=0; --i, --j)
		{
			if(num2[i] >= num1[j])
				result[r--] = num2[i] - num1[j] + '0';
			else
			{
				if(num2[i-1]!='0') 
					num2[i-1]-=1;
				else
				{
					int key=i-1;
					while(num2[key]=='0')
					{
						num2[key]='9';
						key--;
					}
					num2[key]-=1;
				}
				result[r--] = (10 + (num2[i]-'0')) - (num1[j] -'0') + '0';
			}
		}
		if(i!=-1)
		{
			for(int k=i; k>=0; k--)
				result[k] = num2[k];
		}
		free(num1);
		free(num2);
		result = destroy_zero(result);
		return result;
	}
}

// Returns the product of two intals.

char* intal_multiply(const char* intal1, const char* intal2)    // done this one too
{

    if(*intal1=='0' || *intal2=='0') 
        return "0";
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);
    int len = len1+len2;
    int *arr = (int*)malloc(sizeof(int)*len); //the number of digits of the result - len is the top;
    memset(arr, 0, sizeof(int)*len); //this is critical;
    for(int i=len1-1; i > -1; i--){
        
        for(int j=len2-1; j > -1; j--){
        
            arr[i+j+1] += (intal1[i]-'0')*(intal2[j]-'0');
        
        }
    }                                               //collect result of each position;
    for(int i=len-1; i > 0; i--) //restore the carry for each position and get the final result;
    {
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    char *s = (char*)malloc(sizeof(char)*(len+1)); //converting the digits result to string;
    int index = 0;
    int i = 0;
    if(arr[i]==0) 
        i++; //in case the zero position has no carry, if it does, ignore it;
    while(i < len)
        s[index++] = arr[i++]+'0';
    s[index] = '\0';
    free(arr);
    return s;
}



static char* changes(char* intal1,char* intal2)
{
    char* add_borrow;
	char* cal_change=intal2;
	char* string=(char*)malloc(sizeof(char)*1001);
	strcpy(string,intal1);
	while(intal_compare(string,cal_change)!=-1)
	{						
		add_borrow = intal_diff(string,cal_change);
		strcpy( string, add_borrow);
		free(add_borrow);		
	}
	return string;
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

char* intal_mod(const char* intal1, const char* intal2)
{    
    char* num1=(char*)malloc(sizeof(char)*1001);
	char* num2=(char*)malloc(sizeof(char)*1001);
	
    strcpy(num1,intal1);		
	strcpy(num2,intal2);
	
    char* calculator=(char*)malloc(sizeof(char)*1001);	
	
    calculator[0]='0';
    calculator[1]='\0';		
	
    if(strcmp(intal1,"0")==0)
	{
		free(num1);
		free(num2);
	    return calculator;
	}
	
    char *one;
    char *two;
	for(int i=0;i<strlen(intal1);i++)	
	{	
		char* first = (char*)malloc(sizeof(char)*1001);
		char* second = (char*)malloc(sizeof(char)*1001);
		char* t = (char*)malloc(sizeof(char)*2);
		t[0] = intal1[i];		
		t[1] = '\0';
		strcpy(first,calculator);			
		if(strcmp(first,"0")!=0)
        {
			strcat(first,"0");			
        }
        one = intal_add(first,t);
		
        strcpy(second,one);
		
        two = changes(second,num2);
	
        
        strcpy(calculator,two);
		free(one);
		free(two);
		free(first);
		free(second);
		free(t);
		if(strcmp(calculator,num2)==0)
        {
			strcpy(calculator,"0");
        }
	}
	free(num1);	
	free(num2);	
	return calculator;	
}

// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
// Implement a O(log n) intal multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.

char* intal_pow(const char* intal1, unsigned int n)
{
    if(n%2 == 1)
    {
        if(n == 1)
        {
            char * res = (char *)malloc(sizeof(char)*(strlen(intal1)+1));
            strcpy(res,intal1);
            return res;
        }
        else
        {
            char * res = intal_pow(intal1,n/2);
            return intal_multiply(intal_multiply(res,res),intal1);
        }
    }
    else 
    {
        if(n == 1)
        {
            char * res = (char *)malloc(sizeof(char)*(strlen(intal1)+1));
            strcpy(res,intal1);
            return res;
        }
        else 
        {
            char * res = intal_pow(intal1,n/2);
            return intal_multiply(res,res);
        }
    }
}

// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(const char* intal1, const char* intal2)
{
    
	char* num2=(char*)malloc(sizeof(char)*1001);
	char* num1=(char*)malloc(sizeof(char)*1001);
	strcpy(num2,intal2);	
	strcpy(num1,intal1);
	char* add;
	while((!strcmp(num2,"0")) == 0)
	{
		add=intal_mod(num1,num2);	
		strcpy(num1,num2);		
		strcpy(num2,add);		
		free(add);	
	}
	free(num2);
	return num1;
}

// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".


char* intal_fibonacci(unsigned int n)
{
    if(n==0 || n==1)
    {
        if(n == 0)
        {
            return "0";
        }
        else if(n == 1)
        {
            return "1";
        }
    }
    char ** arr = (char **)malloc(sizeof(char *)*(n+1));
    arr[0] = (char *)malloc(sizeof(char)*2);
    strcpy(arr[0],"0");
    arr[1] = (char *)malloc(sizeof(char)*2);
    strcpy(arr[1],"1");
    for(unsigned int i = 2; i <= n; i++)
    {   
        arr[i] = intal_add(arr[i-1],arr[i-2]);
    }
    return arr[n];
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n)
{
    char * result = (char *)malloc(sizeof(char)*2);
    strcpy(result,"1");
    char * buffer = (char *)malloc(sizeof(char)*1000);
    for(unsigned int i = 2; i <= n; i++)
    {
        sprintf(buffer,"%d",i);
        char * temp = intal_multiply(result,buffer);
        free(result);
        result  = temp;
    }
    return result;
}

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k)
{    
    char* calculator;
    char **my_arr = (char **)calloc(k+1,sizeof(char *));
    if(n-k < k) 
    {
        k = n-k;
    }
    for(unsigned int i = 0; i< k+1 ;i++)
    {
        my_arr[i] = (char *)calloc(1000, sizeof(char));
    }
    my_arr[0][0] = '1';
    for(unsigned int i = 1; i < k+1 ; i++)
    {
        my_arr[i][0] = '0';
    }
    for (unsigned int i = 1; i <= n; i++) 
    { 
        for (unsigned int j = i < k ? i : k; j >=1; j--) 
        {
            calculator = intal_add(my_arr[j],my_arr[j-1]);
            free(my_arr[j]);
            my_arr[j] = calculator;
        }            
    } 
    char *result = (char *)malloc(1000);
    strcpy(result,my_arr[k]);
    for(int i=0;i<k+1;i++)
    {
        free(my_arr[i]);
    }
    
    free(my_arr);
    return result;
}

// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
    int max = 0;
    for(int i = 0; i <n; i++)
    {
        if(intal_compare(arr[i],arr[max])==1)
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

static void merge_array(char**arr,int l,int r,int m,int n)
{
    char ** L = (char **)malloc(sizeof( char *)*1001);
    for(int i = 0;i < 1000 ; i++)
    {
        L[i] = (char* )malloc(sizeof(char*)*1001);
        memset(L[i],'0',1000);
        L[i][1000] = '\0';
    }
    char**R = (char **)malloc(sizeof(char*) * 1001);
    for(int i=0;i<1000;i++)
    {
        R[i] = (char *)malloc(sizeof(char*)*1001);
        memset(R[i],'0',1000);
        R[i][1000] = '\0';
    }
    for(int i = 0 ; i < m - l +1 ;i++)
    {
        strcpy(L[i] ,arr[l+i]);
    }
    for(int j = 0 ;j < r-m ;j++)
    {
        strcpy(R[j], arr[m+j+1]);
    }
    int i_merger=0;
    int j_merger=0;
    int k_merger=l;
    while(i_merger < m - l + 1 && j_merger < r - m)
    {
        if(intal_compare(L[i_merger],R[j_merger])==-1)
        {
            strcpy(arr[k_merger],L[i_merger]);
            k_merger+=1;
            i_merger+=1;
        }
        else
        {
              strcpy(arr[k_merger],R[j_merger]);
              j_merger+=1;
              k_merger+=1;
        }
    }
    if(i_merger < m-l+1)
    {
        while(i_merger < m - l +1)
        {
            strcpy(arr[k_merger],L[i_merger]);
            k_merger+=1;
            i_merger+=1;
        }
    }
    if(j_merger < r - m)
    {
        while( j_merger < r - m)
        {
            strcpy(arr[k_merger], R[j_merger]);
            k_merger+=1;
            j_merger+=1;
        }
    }
    for(int i=0;i<1000;i++)
    {
        free(R[i]);
        free(L[i]);
    }
    free(R);
    free(L);
}

static void mergeSort(char**arr,int l,int r,int n)
{
    if( l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m+1, r, n);
        merge_array(arr, l, r, m, n);
    }
}
void intal_sort(char **arr, int n)
{
    mergeSort(arr,0,n-1,n);
}
// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25


char* coin_row_problem(char **arr, int n)
{
    char* reference1 = (char*)calloc(1001, sizeof(char));
    char* reference2 = (char*)calloc(1001, sizeof(char));
    char* reference4 = (char*)calloc(1001, sizeof(char));
    char* reference5 = (char*)calloc(1001, sizeof(char));

    strcpy(reference1,"0");
    strcpy(reference4,*(arr));

    for(int i=2;i<=n;i++)
    {
        if(intal_compare(intal_add(*(arr+i-1),reference1),reference4)==1)
            strcpy(reference5,intal_add(*(arr+i-1),reference1));
        else
            strcpy(reference5,reference4);
        strcpy(reference2,reference5);
        strcpy(reference1,reference4);
        strcpy(reference4,reference2);
    }
    free(reference1);
    free(reference5);
    free(reference2);
    return reference4;
}


