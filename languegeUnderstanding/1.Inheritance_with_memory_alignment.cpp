#include <iostream>

//reference
//https://blog.csdn.net/longjialin93528/article/details/79874558
using namespace std;
class A1
{
    char a[2];
public:
    virtual void aa() {};
};

class B1 :public A1
{
    char b[2];
    char a[2];
};


int main()
{
    cout << sizeof(A1) <<" "<< sizeof(B1) << endl;
}

/*

*** Dumping AST Record Layout
         0 | class A
         0 |   (A vtable pointer)
         8 |   char [2] a
           | [sizeof=16, dsize=10, align=8,
           |  nvsize=10, nvalign=8]

*** Dumping AST Record Layout
         0 | class B
         0 |   (B vtable pointer)
         8 |   char [2] b
        10 |   char [2] a
        16 |   class A (virtual base)
        16 |     (A vtable pointer)
        24 |     char [2] a
           | [sizeof=32, dsize=26, align=8,
           |  nvsize=12, nvalign=8]

*** Dumping AST Record Layout
         0 | class C
         0 |   (C vtable pointer)
         8 |   char [2] c
        10 |   char [2] b
        12 |   char [2] a
        32 |   class A (virtual base)
        32 |     (A vtable pointer)
        40 |     char [2] a
        16 |   class B (virtual base)
        16 |     (B vtable pointer)
        24 |     char [2] b
        26 |     char [2] a
           | [sizeof=48, dsize=42, align=8,
           |  nvsize=14, nvalign=8]

*/