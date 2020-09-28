//#include <stdio.h>

//reference
//https://blog.csdn.net/Poo_Chai/article/details/100316040

class A
{
public:
    int a;
    virtual ~A(void){}
};

class B : virtual public A
{
};

class B1 : virtual public A
{
    virtual void FuncC(void) {}
};

class B2 : public A
{
    virtual void FuncC(void) {}
};

class B3 : public B
{
    virtual void FuncC(void) {}
};


class D : public B, public B1
{
};

class D1 : public B, public B1
{
    virtual void FuncE(void) {}
};

int main(int argc, char** argv)
{
    A a;
    B b;
    B1 c;
    B2 f;
    B3 g;
    D d;
    D1 e;


    return 0;
}
