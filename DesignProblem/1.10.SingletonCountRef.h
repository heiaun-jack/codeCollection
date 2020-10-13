#ifndef SINGLETON_H
#define SINGLETON_H
///////////////////////////////////////////////////////////////
// Singleton.h - share single instance                       //
//                                                           //
// Platform:    Visual Studio 2013, Dell XPS 2720            //
// Application: Support for class Projects                   //
//              CSE687 - Object Oriented Design, Spring 2014 //
// Author:      Jim Fawcett, CST 4-187, Syracuse University  //
//              jfawcett@twcny.rr.com, 315 443-3948          //
///////////////////////////////////////////////////////////////
/*

  reference https://ecs.syr.edu/faculty/fawcett/handouts/CoreTechnologies/cpp/code/Singleton/ 
  
   Package Operations:
   -------------------
   This package provides a Singleton template class that provides
   access to a single instance of the type declared by the template
   parameter.

   Singleton holds a static reference to the single instance, so
   any instance of the Singleton class, declared in any scope will
   provide access to the same shared instance.

   Global access supports sharing across scopes, but the shared
   instance must be thread-safe if shared between two or more 
   threads that run concurrently.  The Singleton does not ensure
   that.

   Required Files:
   ---------------
   - Singleton.h and Singleton.cpp to run the test stub.
   - Applications only require Singleton.h

   Build Process:
   --------------
   devenv Singleton.sln /rebuild debug

   Maintenance History:
   --------------------
   Ver 1.0 : 24 Feb 2014
   - first release
 */
#include <thread>
#include <mutex>
#include <atomic>

template <typename T>
class Singleton 
{
public:
  Singleton() { ++refCnt; }
  ~Singleton() { 
    std::lock_guard<std::mutex> guard(mtx);
    if (--refCnt == 0)
      delete pInstance;  
  }
  T* instance();
private:
  static T* pInstance;
  static std::atomic<size_t> refCnt;
  std::mutex mtx;
};

template <typename T>
T* Singleton<T>::pInstance = 0;

template <typename T>
std::atomic<size_t> Singleton<T>::refCnt = 0;

template <typename T>
T* Singleton<T>::instance()
{
  std::lock_guard<std::mutex> guard(mtx);
  if (pInstance == 0)
    pInstance = new T();
  return pInstance;
}

#endif