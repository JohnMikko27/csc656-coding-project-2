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
   printf(" inside sum_vector problem_setup, N=%lld \n", N);
   // store numbers in range 0 to N-1 (inclusive) in A
   for (int i = 0; i < N; i++) {
      A[i] = i;
   }
}

int64_t
sum(int64_t N, int64_t A[])
{
   printf(" inside sum_vector perform_sum, N=%lld \n", N);

   int64_t sum = 0;
   for (int i = 0; i < N; i++) {
      sum += A[i];
   }

   return sum;
}

