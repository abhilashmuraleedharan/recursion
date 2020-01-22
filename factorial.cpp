/*
 * Recursive funtion to calculate factorial of a number
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#include <iostream>

/*
 * Factorial of a number can be represented as 
 * n! = 1 * 2 * 3 * 4 * 5 * ... * n
 * So, 5! = 1 * 2 * 3 * 4 * 5 = 120.
 * Also, 0! = 1
 * Hence we can write,
 * fact(n) = 1 * 2 * 3 * 4 * ... * (n - 1) * n
 * => fact(n) = fact(n - 1) * n  ;if n > 0
 *            = 1                ;if n = 1
 */

/*
 * Recursive function
 * Space complexity: O(n)
 * Time complexity: O(n)
 */
int recursiveFactorial(int n) {
   if (n == 0)
      return 1;
   else
      return recursiveFactorial(n - 1) * n;
}

/*
 * Tail Recursive Function
 * Why Tail Recursive? 
 * Because compiler optimizes tail recursive function 
 */
int tailRecFactorial(int n, int fact=1) {
   // Base Case
   if (n<=1) { return fact; }
   // else
   return tailRecFactorial(n-1,n*fact);
}

/*
 * Iterative function
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 */
int iterativeFactorial(int n) {
   int fact = 1;
   if (n == 0)
      return 1;

   for (int i = 1; i <= n; i++) {
      fact *= i;
   }
   return fact;
}  

int main() {
   std::cout << "5! using recursion: " << recursiveFactorial(5) << std::endl;
   std::cout << "5! using iteration: " << iterativeFactorial(5) << std::endl;
   std::cout << "5! using tail recursion: " << tailRecFactorial(5) << std::endl;
}
