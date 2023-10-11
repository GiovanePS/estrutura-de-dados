#include <memory>

using std::shared_ptr;

struct Node
{
private:
    int value;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;

public:
    Node(int value) : value(value), next(nullptr), prev(nullptr) {}

    int get_value()
    {
        return this->value;
    }

    void set_value(int value)
    {
        this->value = value;
    }

    shared_ptr<Node> get_next()
    {
        return this->next;
    }

    void set_next(shared_ptr<Node> n)
    {
        this->next = n;
    }

    shared_ptr<Node> get_prev()
    {
        return this->prev;
    }

    void set_prev(shared_ptr<Node> n)
    {
        this->prev = n;
    }
};