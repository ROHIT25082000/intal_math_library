# intal_math_library
  This library allows you to tackle the huge numbers in the scientific calculations 
  just include"intal.h" in your file and 
  complile it in the following way
  
 $ gcc yourFile.c intallib.c 
 $ ./a.out
 
 

1.)char* intal_add(const char* intal1, const char* intal2);

    The main approach for this was do have a function 
    called destroy_zero for removing the zeros before the code integer string and the declare the carry for each 
    value but this by calculating by using the / for carry  and % for digit 
    It completes the value in the for loop frees the extra memory at the end.

2.)char * intal_diff(const char* intal1, const char* intal2);

    This approach in the difference calculation was to have a the integer strings first stripped off with the zeros
    and then substract the two numbers but before actually substracting I compare the numbers and use if else 
    to make sure that the smaller number is substracted from the bigger
    if difference < 0 then I add 10 to  the difference and this when divided by zero gives the digit 
    and then I make the borrow variable on 
    this continues for o(n) to get the difference.

3.)int intal_compare(const char* intal1, const char* intal2);

    First comparision is made on the length of  the strings and if it seen that they are completely non zero then 
    we return 1 and for larger string else -1 
    Next if the length is same then I iterate through the string 
    and we get all  comparision on each digit and thus we get the value zero if every string is same 

4.)char* intal_multiply(const char* intal1, const char* intal2);

    For the intal_multiply function I take the numbers and have the zeros dicarded and also cases where one number is 
    zero I return "0". But if the number is valid then Firstly I create an array and then fill all the values products of
    every digit O(n^2) and then use a for to update the digits in the array 
    I also then take the numbers back to the string form and free the unused memory

5.)char* intal_mod(const char* intal1, const char* intal2);

    In this mod function we calculate the mod value from the given strings using a static method called "changes" which takes the value
    and returns the mod string then divide and calculate the mod value finally free up the memory .

6.)char* intal_pow(const char* intal1, unsigned int n);

    In this pow method I find the value a^n by calculating (a^(n/2))^2 and this becomes the smaller value and then multiply it twice  to square
    it this becomes like a divide and conquer and if the n value some how comes to be odd the then I multiply the value again.
    This takes recursively to find the value in the O(log n)

7.)char* intal_gcd(const char* intal1, const char* intal2);

    This function was implemented by taking the help of the mod function we use the standard euclids algorithm which is very efficient 

8.)char* intal_fibonacci(unsigned int n);

    The intal_fibonacci uses the memoization in the array to get efficient basically uses the recurence relation  
    F(n) = F(n-1) + F(N-2)
    Dynamic programming makes this faster, it internally calls the intal_add to do addition 

9.) char* intal_factorial(unsigned int n);

    The intal_factorial uses the intal_multiply extensively in a for loop it starts off the "1" and goes all the way to the number 
    This also frees the space after the done using the pointer 

10.)char* intal_bincoeff(unsigned int n, unsigned int k);

    This also uses the intal_diff and a bit of Dynamic programming it  uses the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
    and does memoization to get the result

11.)int intal_max(char **arr, int n);
    
    This function uses the simple logic to assume the first offset as the maximum and this changes as it moves in the for loop 
    it updates the value to get the result .

12.)int intal_min(char **arr, int n);
     
    This function uses the simple logic to assume the first offset as the minimun and this changes as it moves in the for loop 
    it updates the value to get the result .

13.) int intal_search(char **arr, int n, const char* key);
    This function uses the linear search  which gets  the number in O(n) by using a for loop.

14.)int intal_binsearch(char **arr, int n, const char* key);

    This function we get a sorted array and we use it to get the value and then applies the divide and conquer strategy to get the 
    result quickly 
    in O(log n)

15.)void intal_sort(char **arr, int n);

This uses the mergesort algorithm by creating the the static functions in the code which in turn do all the spilting of the array and then 
use it  again to merge the final answer in the sorted format 
    in all case it has time complexity = O(n logn) and space complexity O(n)
    
16.)Coin row problem

    This problem could have been solved using the greedy method but Dynamic is more accurate
    We solve it 
    by a for loop 
    and apply  the 
        F(n) = max { C(n) + F(n-2), F(n-1)} 
        recurence relation this solves the problem
