// Solution 10x to Stanimir Petrov
#include <iostream>
#include <list>
#include <string>
#include <string_view>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <charconv>
#include <system_error>
#include <limits>
#include <algorithm>
#include <iterator>
#include <ranges>

class Tree {
    int value;
    std::list<std::unique_ptr<Tree>> children;

    static void trimLeft(std::string_view &sv) {
        sv.remove_prefix(std::min(sv.find_first_not_of(' '), sv.size()));
    }

    static void requireConditionAndTrim(bool cond, std::string_view &sv, std::size_t trimCnt, const char *msg) {
        if (!cond) throw std::invalid_argument(std::string("invalid tree representation: ") + msg);
        sv.remove_prefix(trimCnt);
        trimLeft(sv);
    }

    Tree(std::string_view &str) {
        trimLeft(str);
        requireConditionAndTrim(!str.empty() && str[0] == '(', str, 1, "( expected"); // beginning of tree
        auto [numberEnd, ec] = std::from_chars(str.begin(), str.end(), value);
        requireConditionAndTrim(ec == std::errc{}, str, numberEnd - str.begin(), "bad number or number out of range");
        requireConditionAndTrim(!str.empty() && str[0] == '(', str, 1, "( expected"); // beginning of subtree list
        bool subtreeRequired = !str.empty() && str[0] != ')';
        while (subtreeRequired) // while there exist more subtrees in the list
        {
            children.emplace_back(new Tree(str)); // parse next subtree recursively
            subtreeRequired = !str.empty() && str[0] == ','; // if there is ',' character, there must be more subtrees
            if (subtreeRequired) requireConditionAndTrim(true, str, 1, ""); // if the next character is ',' - remove it
        }
        requireConditionAndTrim(!str.empty() && str[0] == ')', str, 1, ") expected"); // end of subtree list
        requireConditionAndTrim(!str.empty() && str[0] == ')', str, 1, ") expected"); // end of tree
    }

    Tree(const std::string &str, std::string_view view) try: Tree(view) {
        if (!view.empty())
            throw std::invalid_argument("invalid tree representation: bad characters after end");
    }
    catch (const std::invalid_argument &e) {
        throw std::invalid_argument(std::string(e.what()) + ":\n" + str + '\n' +
                                    std::string(view.data() - str.data(), '-') + '^' +
                                    std::string(view.size() + view.empty() - 1, '-'));
    }

public:
    Tree(const std::string &str) : Tree(str, str) {}

    int pathMaxSum() const {
        if (children.empty())
            return value;
        int max = std::numeric_limits<int>::min();
        for (const std::unique_ptr<Tree> &child: children)
            if (int s = child->pathMaxSum(); max < s)
                max = s;
        return value + max;
    }

    static Tree readFromFile(const char *filename) {
        std::ifstream ifs(filename);
        if (!ifs) throw std::runtime_error("failed to open \"" + std::string(filename) + '"');
        std::string treeStr(std::istreambuf_iterator<char>{ifs},
                            std::istreambuf_iterator<char>{}); // reading the whole file is required: Функцията да прочита съдържанието на файла, [...]
        if (treeStr.empty() || treeStr.find('\n') != treeStr.size() - 1)
            throw std::invalid_argument("invalid tree representation: the file must contain exactly 1 line");
        treeStr.pop_back(); // remove trailing newline character
        return {treeStr};
    }

    friend std::ostream &operator<<(std::ostream &os, const Tree &t) // not needed for this task
    {
        os << '(' << t.value << " (";
        if (!t.children.empty())
            os << *t.children.front();
        for (const std::unique_ptr<Tree> &child: t.children | std::views::drop(1))
            os << ", " << *child;
        return os << "))";
    }
};

void solve(const char *filename) try {
    std::cerr << "Opening \"" << filename << "\"... ";
    Tree t = Tree::readFromFile(filename);
    std::cout << t.pathMaxSum() << '\n';
}
catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
}

#include <filesystem>

int main() try {
    for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator{"examples"})
        if (entry.is_regular_file())
            solve(entry.path().c_str());
}
catch (const std::filesystem::filesystem_error &e) {
    std::cerr << e.what() << '\n';
}
