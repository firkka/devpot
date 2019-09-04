#include <string>
#include <algorithm>


/*
    gcc.godbolt.org

    Compiler : x86-64 gcc 5.3 -std=c++14 -Wall, Deactivated : 11010, Intel

    string 's' does not exist before magic_static function is called.
    C++11 guarantees that initialization of static variables happens in thread-safe fashion.

    magic_static and magic_static_ref will both return a pointer to the same value, which
    is the 'bob' string.

    Local member variable of type reference copy &s will be initialized,
    when the object of type C is constructed 


    How much overhead there is when accessing a static variable?
        * The question is directed to the fact that every time we call the static function
          magic_static, we must get a lock and check if the string s has been intialized.
        * (1) In main fuction we end up with four distinct function calls that will perfrom
              a thread safe comparison to see if the value 's' has been initialized or not.

              call C::magic_static[abi:cxx11]()
              call C::magic_static[abi:cxx11]()
              call C::magic_static[abi:cxx11]()
              call C::magic_static[abi:cxx11]()

        * (2) In main function we will return a cached reference to the variable 's' that was
              created in our static function.
              Compiler will eliminated all the calls to the magic_static_ref because it knows
              that there is no side effects to the call (a need for lock).

    How to quantify the overhead?
        * (3) Compiling this with optimization level of 03 and executing the code -> returns instanstaneously.
                Use callgrind to count the number of instructions that has been executed.
                    valgrind --tool=callgrind ./a.out
                    /usr/bin/time valgrind --tool=callgrind ./a.out


    Reference:
        Micro benchmarks : C++2015 Code optimisation Chandler Gruth
*/


struct C
{
    // Returns a const ref to the string s
    static const std::string& magic_static()
    {
        static const std::string s = "bob";
        return s;
    }

    // Local reference copy
    const std::string &s = magic_static();

    // Return a reference to the member variable 's'.
    // Note: not declared as static.
    const std::string& magic_static_ref()
    {
        return s;
    }
};

int main()
{
    // (1) Calling static function & static variable

     C::magic_static().size();
     C::magic_static().size();
     C::magic_static().size();
     
    // (2) Calling member function
    
    C c;
    c.magic_static_ref().size();
    c.magic_static_ref().size();
    c.magic_static_ref().size();

    // (3) Quantify the overhead
    
    // (3.1) magic_static_ref (cached reference version) : 350 mil instructions executed.
    size_t total_size = 0;
    C c;
    for (int i = 0; i < 100000000; i++)
    {
        total_size += c.magic_static_ref().size() + i;
    }

    // (3.2) magic_static (non-cached reference version) : 800 mil instructions executed.
    
    size_t total_size = 0;
    C c;
    for (int i = 0; i < 100000000; i++)
    {
        total_size += c.magic_static().size() + i;
    }
    
    return 0;
}
