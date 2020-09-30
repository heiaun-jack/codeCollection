//
// Created by 何嘉俊 on 9/28/20.
//

// future::wait
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

void doprint()
{
    std::cout << "Hello," << " World!\n";
}

int main ()
{
    // call function asynchronously:
    std::future<void> fut = std::async (doprint);

    //do something
    std::cout << "checking...\n";

    // block untill ready
    fut.get();

    return 0;
}