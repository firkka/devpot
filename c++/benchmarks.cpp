/*
  What C++ code should you tune?
    Mesure first, tune what matters
  
  Micro Benchmarking
    Benchmarks for isolated system
    Where performance matters, but it is very small in scale
    library : github.com/google/benchmark
  
  Tools
    perf
      perf stat   :: to show the basic performance statistics of a run
      perf record :: More traditional profiling run
        user -g flag to get call information
      perf report :: creates a nice report for performance statistics
        we can use the same -g flag to get call information
      
      -g flag
        Interrupts your program periodically using signal
        Looks your current state of your call stack of the thread it is running

      

*/

