/*
 * Recursive function to calculate nCr 
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 */
#include <iostream>

// Declaration for factorial function
int fact(int n);

/*
 * nCr implies the mathematical operation called Combination 
 * which tells us how many ways we can select r items from a 
 * set of n items.
 * 
 * So for example, if we need to find out how many ways can we 
 * select 3 alphabets from a set of seven alphabets, say
 * A B C D E F G
 * then different combinations available are
 * ABC, ABD, DEF, .. and so on.
 * Note that ABC and ACB are same selections and cannot be 
 * counted as 2 distinct combinations since order doesn't matter.
 * Order matters only in permutations.
 *
 * We can calculate nCr value using below formula
 * nCr = n! / ((n-r)! * r!)
 *
 * However to write a recursive function, we can make use of 
 * the concept of Pascal's triangle.
 */

/*
 * Recursive function
 */
int nCr(int n, int r) {
   if (r == 0 || n == r)
      return 1;

   return nCr(n-1, r-1) + nCr(n-1, r); 
}

/*
 * Using nCr formula
 */
int NCR(int n, int r) {
   int num, den;
   num = fact(n);
   den = fact(r) * fact(n-r);
   return num/den;
}

int main() {
   int n, r;
   std::cout << "Calculates the mathematical combination nCr value" << std::endl;
   std::cout << "Enter the value of n: ";
   std::cin >> n;
   std::cout << "Enter the value of r: ";
   std::cin >> r;
   std::cout << "nCr value using recursion: " << nCr(n, r) << std::endl;
   std::cout << "nCr value using formula: " << NCR(n, r) << std::endl;
   return 0;
}

int fact(int n) {
   if (n == 0)
      return 1;

   return fact(n-1) * n;
}
