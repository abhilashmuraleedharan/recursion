/*
 * Recursive Function that calculates sum of n natural numbers
 *
 * @author
 *   Abhilash Muraleedharan<amuraleedharan13@gmail.com>
 *
 */
#include <iostream>
 
/*
 * There is already a formula to calculate sum of n natural numbers which is
 * n * (n + 1) / 2
 * That is the most optimized solution for this problem since the time and space
 * complexity of the function implementing the formula would be O(1).
 *
 * We can also implement below function using a 'for loop' with an additional variable sum
 * to add all numbers as the i value increases from 1 to n.
 * The time complexity of this function would be O(n) and space complexity would be O(1).
 *
 * So recursive approach is the less efficient approach to solve this problem. However, the 
 * recursive approach is the natural outcome of the mathematical analysis of this problem as 
 * illustrated below. 
 *
 * Sum of n natural numbers can be written as
 *    Sum(n) = 1 + 2 + 3 + 4 + ...... + n
 * => Sum(n) = 1 + 2 + 3 + 4 + .... + (n - 1) + n
 * => Sum(n) = Sum(n - 1) + n 
 *
 * So if n > 0, Sum(n) = Sum(n - 1) + n
 * and if n == 0, Sum(0) = 0 
 *
 * Above mathematical approach can be directly converted to a recursive function as shown below
 */

/* 
 * Recursive Function 
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */ 
int recursiveSum(int n) {
   if (n == 0) {
      return 0;
   } else {
      return recursiveSum(n - 1) + n;
   }
}

/* 
 * Iterative Function
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 */
int iterativeSum(int n) {
   int sum = 0;
   for (int i = 1; i <= n; i++) {
      sum += i;
   }
   return sum;
}

int main() {
   std::cout << "Sum of natural numbers upto 10 using recursion = " << recursiveSum(10) << std::endl;
   std::cout << "Sum of natural numbers upto 10 using iteration = " << iterativeSum(10) << std::endl;
}
