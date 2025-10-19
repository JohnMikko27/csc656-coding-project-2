#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

#include "sums.h"

void 
setup(int64_t N, int64_t A[])
{
   // printf(" inside sum_indirect problem_setup, N=%lld \n", N);

   // create a random device to seed the random number generator
   std::random_device rd;
   // create a Mersenne Twister engine, seeded with the random device
   std::mt19937 gen(rd());
   // sets the range of random number to be 0 to N-1
   std::uniform_int_distribution<> distrib(0, N-1);
   for (int i = 0; i < N; i++) {
      // generates random number and stores in A[i]
      A[i] = distrib(gen);
   } 

}

int64_t
sum(int64_t N, int64_t A[])
{
   // printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t sum = 0;
   int64_t index = A[0];
   for (int i = 0; i < N; i++) {
      index = A[index];
      sum += A[index];
   }

   return sum;
}

