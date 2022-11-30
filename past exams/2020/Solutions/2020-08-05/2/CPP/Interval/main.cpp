#include <iostream>

class Interval {
protected:
    int a;
    int k;
    int current;
public:
    Interval(int a, int k) {
        if (k < 0) {
            k = 0;
        }

        current = a;
        this->a = a;
        this->k = k;
    }

    virtual int operator*() {
        return current;
    }

    Interval &operator++() { // prefix
        if (!last()) {
            current++;
        }
        return *this;
    }

    Interval operator++(int b) { // postfix
        if (!last()) {
            Interval previousCopy(*this);;
            current++;
            return previousCopy;
        }

        return *this;
    }

    void reset() {
        current = a;
    }

    bool last() const {
        return current == a + k;
    }
};

class SquaredInterval : public Interval {
public:
    SquaredInterval(int a, int k) : Interval(a, k) {}

    int operator*() {
        return current * current;
    }

    int upperLimit() const {
        return (a + k) * (a + k);
    }

    bool operator<(const SquaredInterval &otherInterval) const {
        return this->upperLimit() < otherInterval.upperLimit();
    }
};

void sortSquaredIntervals(SquaredInterval *intervals, size_t n) {
    std::sort(intervals, intervals + n);
}


int main() {
    Interval i(0, 10);

    std::cout << *i << std::endl;
    do {
        ++i;
        std::cout << *i << std::endl;
    } while (!i.last());

    std::cout << std::endl;
    i.reset();

    SquaredInterval si(0, 10);

    std::cout << *si << std::endl;
    do {
        ++si;
        std::cout << *si << std::endl;
    } while (!si.last());

    std::cout << std::endl;
    si.reset();

    SquaredInterval arr[5] = {
            SquaredInterval(5, 5),
            SquaredInterval(10, 4),
            SquaredInterval(3, 10),
            SquaredInterval(15, -3),
            SquaredInterval(1, 5)
    };

    sortSquaredIntervals(arr, sizeof arr / sizeof(SquaredInterval));

    for (SquaredInterval &in: arr) {
        std::cout << in.upperLimit() << std::endl;
    }

    return 0;
}
