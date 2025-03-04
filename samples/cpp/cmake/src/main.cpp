#include <iostream>
#include "Counter.h"
using namespace std;

int main()
{
    Counter counter;
    cout << "Counter: " << counter.getCount() << endl;
    counter.increment();
    cout << "Counter: " << counter.getCount() << endl;
    counter.decrement();
    cout << "Counter: " << counter.getCount() << endl;
    cout << "Hello, World!" << endl;
    return 0;
}