
#include "Counter.h"

Counter::Counter(int initialCount) : count(initialCount) {}

void Counter::increment() {
    count++;
}

void Counter::decrement() {
    count--;
}

int Counter::getCount() const {
    return count;
}
