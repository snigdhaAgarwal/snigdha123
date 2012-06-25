#include <iostream>
#include <cstdio>
class Base
{
public:
    virtual void test(int value=10)
    {
        printf("%d\n",value);
    }
};

class DerivedChangeDefault : public Base
{
public:
    void test(int value=20)
    {
        printf("DerivedChangeDefault: %d\n",value);
    }
};

class DerivedChangeProtection : public Base
{
protected:
    void test(int value=10)
    {
        printf("Derived: %d\n",value);
    }
};

int main()
{
    Base* b1 = new DerivedChangeDefault;
    Base* b2 = new DerivedChangeProtection;

    b1->test();
    b2->test();

    ((DerivedChangeDefault*)b1)->test();
#if 0
    ((DerivedChangeProtection*)b2)->test();
#endif

    return 0;
}
