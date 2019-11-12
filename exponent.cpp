/*
 * Recursive Exponent Function
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#include <iostream>

/*
 * m raised to n => m is multiplied n times when n > 1
 * If n = 0, answer is 1 since any number raised to power 0 is 1.
 *
 * e.g. 5 raised to 3 => 5 * 5 * 5 = 125
 * 
 * Hence we can write power(m,n) as
 * power(m, n) => m * m * m * .. upto n times
 *             => m * m * m * .. (n - 1) times * m
 *             
 * Therefore, power(m, n) = power(m, n-1) * m  ; if n>0
 *                        = 1                  ; if n=0
 */

/*
 * Recursive Function
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int power(int m, int n) {
   if (n == 0)
      return 1;
   else
      return power(m, n - 1) * m;
}

/*
 * You can improve the above function by reducing the number of multiplication operations
 * required to calculate the power thereby making it faster.
 * Consider below logic,
 * 2 ^ 8 can be written as (2*2) ^ 4.
 * So just by doing 1 extra multiplcation, the exponent got reduced by half.
 * Following this logic, we can implement the above function as follows
 * if n=0, return 1
 * If n>0, check if n is odd or even.
 * If n is even, instead of returning the product power(m, n-1) * m,
 * return power(m*m, n/2).
 * And if n is odd, return the product m * power(m*m, (n-1)/2)
 */
int quickPower(int m, int n) {
   if (n == 0) {
      return 1;
   } else if (n > 0) {
      if (n % 2 == 0) {
         return quickPower(m * m, n/2);
      } else {
         return m * quickPower(m * m, (n-1)/2);
      }
   } else {
      throw std::runtime_error("Negative power is not currently handled. Please enter a positive power.");
   }
}

int main() {
   int base, exponent = 0;
   std::cout << "This program calculates the value of a given number(base) raised to a given power(exponent)." << std::endl;
   std::cout << "For example, if you give base as 5 and exponent as 2, the program returns the value 25 which is 5^2." << std::endl;
   std::cout << "Enter the base value:";
   std::cin >> base;
   if (base < 0) {
      std::cout << "Negative base values are currently not handled." << std::endl;
      return 0;
   }
   std::cout << "Enter the exponent value:";
   std::cin >> exponent;
   if (exponent < 0) {
      std::cout << "Negative exponent values are currently not handled." << std::endl;
      return 0;
   }
   std::cout << base << " raised to the power " << exponent << " is equal to " << quickPower(base, exponent) << "." << std::endl;  
}
