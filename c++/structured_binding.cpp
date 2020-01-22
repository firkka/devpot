#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <tuple>
#include <map>


void tuples_as_params(std::tuple<int*, int*> &mems)
{
    auto [smem, dmem] = mems;

    *smem = 100;
    *dmem= 300;

    printf("tuple %d %d", *smem, *dmem);
}

void init_is_array()
{
    double myArray[3] = { 1.0, 2.0, 3.0 };  
    auto [a, b, c] = myArray;
}

void init_is_tuple()
{
    auto tupl = std::make_tuple(1, 2);
    auto [a, b] = tupl; // binds myPair.first/second

    auto& [c, d] = tupl;
}


void init_is_map()
{
    std::map<int, int> m = {{1, 2}, {3, 4}};
    // supports loops!
    for (const auto & [k, v] : m) 
    {  
        // k - key
        // v - value
    } 
}


int main()
{
    int a;
    int b;

    a = 3;
    b = 4;

    auto tupl = std::make_tuple(&a, &b);

    tuples_as_params(tupl);

    printf("\nmain %d %d", a, b);

    return 0;
}
