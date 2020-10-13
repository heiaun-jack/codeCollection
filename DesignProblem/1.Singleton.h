/*
State-of-art version --(1)

HISTORY:

    plain static member 
        Polymorphysm issue [unverified]

    => Starving-mode, 
        Static Initialization Order "fiasco" issue

    => (1)

        - Solved Construct-Before-Construct issue
        - Solved Deconstruct-After-Deconstruct issue 
        - After C++11, solved Thread Security issue [unverified]

*/

template <typename T> class Singleton{
public:
    T* getInstance(){
        static T* s = new Singleton();

        return *s;
    }

private:
    Singleton();
    Singleton(const T & s);
    T& operator=(const Singleton & s);
};