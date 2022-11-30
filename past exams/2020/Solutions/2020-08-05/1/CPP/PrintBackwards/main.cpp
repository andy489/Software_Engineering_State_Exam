#include <iostream>

static const int BOUND = 32;

void print_word(const char *s, const char *e) {
    if (s == e) {
        std::cout << ' ';
        return;
    }

    std::cout << *s;
    print_word(s + 1, e);
}

const char *find_start(const char *b, const char *e) {
    if (b == e) {
        return e;
    }

    return *b > BOUND ? b : find_start(b + 1, e);
}

const char *find_end(const char *b, const char *e) {
    if (b == e) {
        return e;
    }
    return *b <= BOUND ? b : find_end(b + 1, e);
}

void print_backwards(const char *begin, const char *end) {
    assert(begin && end && begin < end);
    const char *start = find_start(begin, end);
    if (start < end) {
        const char *we = find_end(start, end);
        print_backwards(we, end);
        print_word(start, we);
    }
}

int main() {
    char txt1[] = "I\tneed a\n break!  ";
    char txt2[] = "\r  I   need some break!  ";
    char txt3[] = "\rbitch give me a\tbreak... ";

    print_backwards(txt1, txt1 + strlen(txt1));
    std::cout << std::endl;
    print_backwards(txt2, txt2 + strlen(txt2));
    std::cout << std::endl;
    print_backwards(txt3, txt3 + strlen(txt3));
    std::cout << std::endl;

    return 0;
}