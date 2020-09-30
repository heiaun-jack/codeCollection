//
// Created by 何嘉俊 on 9/29/20.
//

// future::wait
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds
#include <string>
#include <thread>

using namespace std;

class foo {
public:
    void fn(string s) {
        cout << s;
    }

    foo() {
        //cout << "constructor\n";
    }

    ~foo() {
        cout << "destructor\n";
    }
};


int main ()
{
    foo f;

    // call function asynchronously:
    std::future<void> fut = std::async (&foo::fn,&f, "test\n");
    // & or ref depends on compiler, reference or copy related to race condition, the same as thread

    //"race condition issue" - https://stackoverflow.com/questions/18359864/passing-arguments-to-stdasync-by-reference-fails
    //"ref issue with gcc" - https://gcc.gnu.org/bugzilla/show_bug.cgi?id=59768

    /*
        thread t(&foo::fn,ref(f), "test\n");
        if(t.joinable())
        t.join();

    */
    //do something
    std::cout << "checking...\n";

    // block untill ready
    fut.get();

    return 0;
}