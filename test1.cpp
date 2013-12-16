#include <stdio.h>
class A
{
public:
    A(){printf("A\n");}
    virtual ~A(){printf("~A\n");}
    virtual void print(){printf("in A\n");}
};
class B : virtual public A
{
public:
    B(){printf("B\n");}
};

class C : virtual public A
{
public:
    C(){printf("C\n");}
    virtual void print(){printf("in C\n");}
};

class D : public C, public B
{
public:
    D(){printf("D\n");}
};

int main(int argc, char** argv)
{
    D* d = new D;
    d->print();
    return 0;
}
