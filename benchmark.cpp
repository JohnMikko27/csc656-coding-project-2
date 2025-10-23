//
// (C) 2022-2023, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

#include "sums.h"

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(10);

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
   std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};
   
   int64_t *A = (int64_t *)malloc(sizeof(int64_t) * MAX_PROBLEM_SIZE);

   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      int64_t t;
      // invoke user code to set up the problem
      setup(n, &A[0]);

      // get start time of the call to sum
      std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
      
      // invoke method to perform the sum
      t = sum(n, &A[0]);
      
      // get the end time of the call to sum
      std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
      // get and print elapsed time
      std::chrono::duration<double> elapsed_time = end_time - start_time;
      std::cout << " Elapsed time is : " << elapsed_time.count() << " seconds" << std::endl;

      // NOTE: I calculated the different runtimes in this cpp file and printed them out.
      // Then I just copy-pasted them into the appropriate .csv files for plotting

      // get and print MFLOPS (ops/time)
      double mflops = 1 * n / float(1000000) / elapsed_time.count();
      std::cout << "MFLOPS: " << mflops << std::endl;

      // Get and print % of memory bandwidth utilized (bytes/time) / (capacity)
      // Note: system theoretical GB/s = 204.8 GB/s
      // Ignore memory bandwidth for sum_direct since it doesn't access any memory
      // Using integer 8 because int64_t is 8 bytes
      double sum_vector_memory_bandwidth = 8 * n / double(1000000000) / elapsed_time.count() / 204.8 * 100;
      std::cout << "sum_vector_memory_bandwidth: " << sum_vector_memory_bandwidth << std::endl;
      double sum_indirect_memory_bandwidth = 8 * 2 * n / double(1000000000) / elapsed_time.count() / 204.8 * 100;
      std::cout << "sum_indirect_memory_bandwidth: " << sum_indirect_memory_bandwidth << std::endl;

      // Get and print memory latency (time/accesses)
      // Ignore memory latency for sum_direct since it doesn't access any memory
      double sum_vector_memory_latency = elapsed_time.count() / n * 1000000000;
      std::cout << "sum_vector_memory_latency: " << sum_vector_memory_latency << std::endl;
      double sum_indirect_memory_latency = elapsed_time.count() / 2 / n * 1000000000;
      std::cout << "sum_indirect_memory_latency: " << sum_indirect_memory_latency << std::endl;
      

      // changed format type to ld from lf 
      // because variable t is type int64_t which corresponds with ld
      printf(" Sum result = %ld \n",t);

   } // end loop over problem sizes
}

// EOF
