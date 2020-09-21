#include <iostream>

class Jeppis
{
public:
    enum { int_t,float_t } m_type;


    template <typename Integer,
              std::enable_if_t<std::is_integral<Integer>::value, int> = 0>
    Jeppis(Integer) : m_type(int_t)
    {

    }
 
    template <typename Floating,
              std::enable_if_t<std::is_floating_point<Floating>::value, int> = 0>
    Jeppis(Floating) : m_type(float_t)
    {

    }
};

int main(void)
{
    Jeppis j(1);
    Jeppis k(1.0);

    printf("\n j : %d\n", j.m_type); // 0
    printf("\n k : %d\n", k.m_type); // 1

    return 0;
}
