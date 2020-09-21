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

int main(void)
{
    MyClass j(1);

    MyClass k(1.0);

    printf("\n j : %d\n", j.m_type);
    printf("\n k : %d\n", k.m_type);

    return 0;
}
