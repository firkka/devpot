#include <iostream>

class MyClass
{
public:
    enum { int_t,float_t } m_type;

    template <typename Int,
              std::enable_if_t<std::is_integral<Int>::value, int> = 0>
    MyClass(Int) : m_type(int_t)
    {
    }
 
    template <typename Fp,
              std::enable_if_t<std::is_floating_point<Fp>::value, int> = 0>
    MyClass(Fp) : m_type(float_t)
    {
    }
};

template<typename T>
std::enable_if_t<std::is_same<int, T>::value, void> foo() {
    std::cout << "foo int\n";
}

template<typename T>
std::enable_if_t<std::is_same<float, T>::value, void> foo() {
    std::cout << "foo float\n";
}

int main(void)
{
    MyClass j(1);

    MyClass k(1.0);

    printf("\n j : %d, k : %d ", j.m_type, k.m_type); // j : 0, k : 1 

    int w1 = std::is_floating_point<float>::value;
    int w2 = std::is_floating_point<int>::value;

    printf("\n w1 %d: w2 %d\n", w1, w2); // w1 1: w2 0

    int w = std::enable_if_t<std::is_integral<int>::value, int>();
    if (w) printf("w defined\n");

    int r = std::enable_if_t<std::is_integral<int>::value, int>(1.0);
    if (r) printf("r defined %d \n", r); // defined as int

    foo<int>();
    foo<float>();
    //foo<double>(); error: no matching function for call to 'foo<double>()'

    return 0;
}
