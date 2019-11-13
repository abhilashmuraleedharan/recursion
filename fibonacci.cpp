/*
 * Recursive function to calculate the nth term in a fibonacci sequence
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#include <iostream>

/*
 * Fibonacci Sequence:
 * 0 1 1 2 3 5 8 13 21 34 . . . 
 *
 * After the first and second term, next terms are determined by 
 * the sum of the previous 2 terms.
 * So we can say,
 * fib(n) = 0     ; if n=0
 *        = 1     ; if n=1
 *        = fib(n-2) + fib(n-1) ; if n>1
 *
 * Above recursive relation can be directly mapped to a recursive
 * function as shown below
 */

/*
 * Example of an excessive recursive function
 */
int fib(int n) {
   if (n<=1) 
      return n; 
   
   return fib(n-2) + fib(n-1);
}
/*
 * The above function is called an excessive recursive function
 * because, function calls itself for same value of n more than once.
 * For example fib(2) will be called more than once in the left subtree of recursion 
 * trace tree as well as in the right subtree for calculating say, the 6th term in the sequence.
 * This results in a time complexity of O(2^n).
 */

/*
 * Memoization technique
 *
 * Technique of using a static or global memory to store the return values of the 
 * recursive function so that we can avoid redundant calls.
 *
 * For example, if we store the fib(2) value, next time we encounter a fib(2)
 * call, we don't need to call the function, we can just use the stored value 
 * thereby saving time and memory.
 *
 * Below is an improved recursive function using Memoization technique.
 * The time complexity of this functon is O(n), same complexity that we would
 * get if we were to use a loop to implement this function.
 */
int fib1(int n) {
   // Use a static array to hold the return values
   static int arr[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };  
   
   if (n <= 1) {
      arr[n] = n;
      return n;
   }

   if (arr[n-2] == -1) {
      // We need to store the value
      arr[n-2] = fib1(n-2);
   }
   if (arr[n-1] == -1) {
      // We need to store the value
      arr[n-1] = fib1(n-1);
   }
   arr[n] = arr[n-2] + arr[n-1];
   return arr[n]; 
}

/*
 * Iterative approach
 * Time Complexity: O(n)
 */
int fib2(int n) {
   int t0=0, t1=1, s=0, i;
   
   if (n <= 1)
      return n;

   for (i=2; i<=n; i++) {
      s = t0 + t1;
      t0 = t1;
      t1 = s;
   }
   return s;
}

// To print the fibonacci sequence
void print(int n) { // n is the length of the sequence
   int t0=0, t1=1, s=0;

   if (n <= 0) {
      return;
   } else if (n == 1) {
      std::cout << "0" << std::endl;
      return;
   } else if (n == 2) {
      std::cout << "0 1" << std::endl;
      return;
   }

   // n is greater than 2, print the first 2 terms
   std::cout << "0 1 ";
   for (int i=2; i<=n; i++) {
      s = t0 + t1;
      t0 = t1;
      t1 = s;
      std::cout << s << " ";
   }
   // Print a new line
   std::cout << std::endl;
}   

int main() {
   int n;
   std::cout << "Finds the term in the nth index of the Fibonacci sequence:" << std::endl;
   // Print the sequence
   print(10); 
   std::cout << "Enter the value of n:";
   std::cin >> n;
   if (n<0) {
      std::cout << "Invalid n value" << std::endl;
      return 0;
   } else if(n>10) {
      std::cout << "Index out of bounds!!" << std::endl;
      return 0;
   }
   std::cout << "Using excessive recursive function: " << fib(n) << std::endl; 
   std::cout << "Using improved function: " << fib1(n) << std::endl; 
   std::cout << "Using iterative function: " << fib2(n) << std::endl; 
}  
