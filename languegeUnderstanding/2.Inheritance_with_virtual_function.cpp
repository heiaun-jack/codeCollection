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


/*

*** Dumping AST Record Layout
         0 | class A
         0 |   (A vtable pointer)
         8 |   int a
           | [sizeof=16, dsize=12, align=8,
           |  nvsize=12, nvalign=8]


*** Dumping AST Record Layout
         0 | class B
         0 |   (B vtable pointer)
         8 |   class A (virtual base)
         8 |     (A vtable pointer)
        16 |     int a
           | [sizeof=24, dsize=20, align=8,
           |  nvsize=8, nvalign=8]

*** Dumping AST Record Layout
         0 | class B1
         0 |   (B1 vtable pointer)
         8 |   class A (virtual base)
         8 |     (A vtable pointer)
        16 |     int a
           | [sizeof=24, dsize=20, align=8,
           |  nvsize=8, nvalign=8]


*** Dumping AST Record Layout
         0 | class B2
         0 |   class A (primary base)
         0 |     (A vtable pointer)
         8 |     int a
           | [sizeof=16, dsize=12, align=8,
           |  nvsize=12, nvalign=8]


*** Dumping AST Record Layout
         0 | class B3
         0 |   class B (primary base)
         0 |     (B vtable pointer)
         8 |   class A (virtual base)
         8 |     (A vtable pointer)
        16 |     int a
           | [sizeof=24, dsize=20, align=8,
           |  nvsize=8, nvalign=8]

*** Dumping AST Record Layout
         0 | class D
         0 |   class B (primary base)
         0 |     (B vtable pointer)
         8 |   class B1 (base)
         8 |     (B1 vtable pointer)
        16 |   class A (virtual base)
        16 |     (A vtable pointer)
        24 |     int a
           | [sizeof=32, dsize=28, align=8,
           |  nvsize=16, nvalign=8]

*** Dumping AST Record Layout
         0 | class D1
         0 |   class B (primary base)
         0 |     (B vtable pointer)
         8 |   class B1 (base)
         8 |     (B1 vtable pointer)
        16 |   class A (virtual base)
        16 |     (A vtable pointer)
        24 |     int a
           | [sizeof=32, dsize=28, align=8,
           |  nvsize=16, nvalign=8]

*/