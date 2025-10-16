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
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);

   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distrib(0, N-1);
   for (int i = 0; i < N; i++) {
      A[i] = distrib(gen);
   } 

}

int64_t
sum(int64_t N, int64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t sum = 0;
   int64_t index = 0;
   for (int i = 0; i < N; i++) {
      index = A[index];
      sum += A[index];
   }
   
   return sum;
}

