/*
 * Recursive function that calculates e^x value using below Taylor's Series
 * e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ..... + x^n/n!
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#include <iostream>

/*
 * If you observe how the recursive functions for sum of n numbers, factorial and 
 * exponent are implemented, you will see the sum or product is calculated when we
 * are returning from each function call.
 * If we go with the same recursive approach here and call say e(x,4) where
 * 4 is the highest order of x so that 
 * e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! 
 * then as we return from each function we would need to do it like below 
 * e(x,0) returns 1
 * e(x,1) returns 1 + x/1
 * e(x,2) returns 1 + x/1 + x^2/2!
 * e(x,3) returns 1 + x/1 + x^2/2! + x^3/3!
 * e(x,4) returns 1 + x/1 + x^2/2! + x^3/3! + x^4/4!
 *
 * Looking at the above example you can see each time we are adding to the 
 * return value of function a new term p/f where
 * p = p*x and f = f*n where n is the order of x.
 *
 * Using this logic we can write a recursive function to calculate e^x as follows
 */

/*
 * Returns e power x value as per Taylor Series
 * @parameters
 *   @param1 x => power of e
 *   @param2 n => highest order in the series
 *
 * Number of Multiplication operations performed = O(n^2)
 */
double e(int x, int n) {
   static double p = 1;  // To store power. Setting it to 1 initially for x^0
   static double f = 1;  // To store factorial. Setting it to 1 initially for 0!
   double r;  // To store result

   if (n == 0) {
      return 1;
   } else {
      r = e(x, n-1);
      p = p*x;
      f = f*n;
      return r + p/f;
   }   
} 

/*
 * Improved e function that performs only O(n) multiplication 
 * operation based on Horner's rule.
 */
double e1(int x, int n) {
   static double s = 1;
   if (n == 0) 
      return s;

   s = 1 + (x*s)/n;
   return e1(x, n-1);
}

int main() {
   std::cout << "e^1 upto order 10 is equal to " << e(1, 10) << std::endl;
   std::cout << "e^1 upto order 10 (using less multiplication operations) is equal to " << e1(1, 10) << std::endl;
}
