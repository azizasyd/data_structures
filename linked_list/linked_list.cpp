#include <bits/stdc++.h>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node* prev;

        Node() : value(T()), next(nullptr), prev(nullptr) {}
        Node(const T& value) : value(value), next(nullptr), prev(nullptr) {}
    };

    Node* _head;
    size_t _size;

    Node* first_node() const
    {
        return _head->next;
    }

    Node* last_node() const
    {
        return _head->prev;
    }

public:
    LinkedList() : _size(0)
    {
        _head = new Node();
        _head->prev = _head;
        _head->next = _head;
    }

    ~LinkedList()
    {
        while (!empty())
        {
            pop_back();
        }
        delete _head;
    }

    bool empty() const
    {
        return _size == 0;
    }

    size_t size() const
    {
        return _size;
    }

    const T& front() const
    {
        return first_node()->value;
    }

    T& front()
    {
        return first_node()->value;
    }

    const T& back() const
    {
        return last_node()->value;
    }

    T& back()
    {
        return last_node()->value;
    }

    void push_front(const T& value)
    {
        insert_value_before(value, first_node());
    }

    void pop_front()
    {
        if (!empty())
        {
            erase_value(first_node());
        }
    }

    void push_back(const T& value)
    {
        insert_value_before(value, _head);
    }

    void pop_back()
    {
        if (!empty())
        {
            erase_value(last_node());
        }
    }

    class Iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Node* node;

        Iterator(Node* node) : node(node) {}

        const T& operator*() const
        {
            return node->value;
        }

        Iterator& operator++()
        {
            node = node->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            node = node->next;
            return temp;
        }

        Iterator& operator--()
        {
            node = node->prev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            node = node->prev;
            return temp;
        }

        Iterator& operator+=(int offset)
        {
            for (int i = 0; i < offset; ++i)
            {
                node = node->next;
            }
            return *this;
        }

        Iterator operator+(int offset)
        {
            Iterator temp = *this;
            return temp += offset;
        }

        bool operator!=(const Iterator& other) const
        {
            return node != other.node;
        }

        bool operator==(const Iterator& other) const
        {
            return node == other.node;
        }

        difference_type operator-(const Iterator& other) const
        {
            difference_type distance = 0;
            for (Node* current = other.node; current != node; current = current->next)
            {
                ++distance;
            }
            return distance;
        }
    };

    Iterator begin()
    {
        return Iterator(first_node());
    }

    Iterator end()
    {
        return Iterator(_head);
    }

    void insert(const Iterator& it_before, const T& value)
    {
        insert_value_before(value, it_before.node);
    }

    void erase(const Iterator& it)
    {
        erase_value(it.node);
    }

private:
    void insert_node_before(Node* node, Node* next_node)
    {
        node->next = next_node;
        node->prev = next_node->prev;
        next_node->prev->next = node;
        next_node->prev = node;
    }

    void insert_value_before(const T& value, Node* before_node)
    {
        Node* new_node = new Node(value);
        insert_node_before(new_node, before_node);
        ++_size;
    }

    void erase_node(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void erase_value(Node* node)
    {
        erase_node(node);
        delete node;
        --_size;
    }
};

void solve()
{
    int q;
    std::cin >> q;

    LinkedList<int> linked_list;
    std::vector<int> results;
    const int PUSH = 1, POP = 2, INSERT = 3, ERASE = 4, FIND = 5, AT = 6;

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;

        if (PUSH == type) {
            char s;
            int v;
            std::cin >> s >> v;

            if (s == 'f') {
                linked_list.push_front(v);
            } else if (s == 'b') {
                linked_list.push_back(v);
            }
        }

        if (POP == type) {
            char s;
            std::cin >> s;
            if (linked_list.empty()) {
                results.push_back(-1);
            } else {
                if (s == 'f') {
                    results.push_back(linked_list.front());
                    linked_list.pop_front();
                } else if (s == 'b') {
                    results.push_back(linked_list.back());
                    linked_list.pop_back();
                }
            }
        }

        if (INSERT == type) {
            int pos, v;
            std::cin >> pos >> v;
            auto it = linked_list.begin();
            std::advance(it, pos - 1);
            linked_list.insert(it, v);
        }

        if (ERASE == type) {
            int pos;
            std::cin >> pos;

            if (!linked_list.empty()) {
                auto it = linked_list.begin();
                std::advance(it, pos - 1);
                results.push_back(*it);
                linked_list.erase(it);
            } else {
                results.push_back(-1);
            }
        }

        if (FIND == type) {
            int v;
            std::cin >> v;
            auto it = std::find(linked_list.begin(), linked_list.end(), v);
            if (it != linked_list.end()) {
                results.push_back(std::distance(linked_list.begin(), it) + 1);
            } else {
                results.push_back(-1);
            }
        }

        if (AT == type) {
            int pos;
            std::cin >> pos;
            if (pos - 1 >= linked_list.size()) {
                results.push_back(-1);
            } else {
                auto it = linked_list.begin();
                std::advance(it, pos - 1);
                results.push_back(*it);
            }
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results.at(i) << " ";
    }
    std::cout << "\n";
}

int main()
{
    solve();
    return 0;
}
