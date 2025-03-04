#pragma once

class Counter {
private:
    int count;

public:
    Counter(int initialCount = 0);
    void increment();
    void decrement();
    int getCount() const;
};
