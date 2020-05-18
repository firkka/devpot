template <class T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

    Singleton()  = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

template <class T>
class Instance : public Base
{
    friend class Singleton<Instance<T>>;

public:
    Instance(const Instance&) = delete;
    Instance& operator=(const Instance&) = delete;

private:
    Instance() = default;
};


class Base
{
public:
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;

    void clear()
    {
        for (u32 i = 0; i < MAX_NUM_DIM_1; i++)
        {
            for (u32 j = 0; j < MAX_NUM_DIM_2; j++)
            {
                data[i][j] = UNDEF;
            }
        }
  }

protected:
    Base()
    {
        for (u32 i = 0; i < MAX_NUM_DIM_1; i++)
        {
            for (u32 j = 0; j < MAX_NUM_DIM_2; j++)
            {
                data[i][j] = UNDEF;
            }
        }
    }
    ~Base() { clear(); }
    Entry data[][];
};
