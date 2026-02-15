// NO SINGLETON

/*#include <iostream>

using namespace std;

class NoSingleton
{
public:
    NoSingleton()
    {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main()
{
    NoSingleton *s1 = new NoSingleton();
    NoSingleton *s2 = new NoSingleton();

    cout << (s1 == s2) << endl;
}*/

// Simple Singelton Implementation : not thread safe

/*#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}*/

// Thread Safe Singleton Implementation

#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;

    Singleton()
    {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}

// Thread Safe Singleton Implementation with Double-Checked Locking

/*#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;

    Singleton()
    {
        cout << "Singleton Constructor Called!" << endl;
    }

public:
    // Double check locking..
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {                                // First check (no locking)
            lock_guard<mutex> lock(mtx); // Lock only if needed
            if (instance == nullptr)
            { // Second check (after acquiring lock)
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}*/
