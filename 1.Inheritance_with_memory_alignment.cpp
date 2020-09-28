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