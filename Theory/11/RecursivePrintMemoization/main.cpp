// a -> a
// b -> aba
// c -> abacaba
// ...

#include <iostream>
#include <map>

using namespace std;

map<char, string> mem;

string calc(char c) {
    if (!mem.count(c)) {
        string result = calc(c - 1) + c + calc(c - 1);
        mem[c] = result;
    }

    return mem[c];
}

void rec_print_memo(char c) {
    string s = calc(c);
    cout << s;
}

int main() {
    mem['a'] = "a";
    rec_print_memo('a');
    cout << endl;

    rec_print_memo('b');
    cout << endl;

    rec_print_memo('c');
    cout << endl;

    return 0;
}
