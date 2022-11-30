#include <stdexcept>

using std::runtime_error;

class EmptyStackException : public runtime_error {
public:
    EmptyStackException() : runtime_error("Cannot perform peek on empty stack") {}
};
