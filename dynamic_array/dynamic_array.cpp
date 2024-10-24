#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    std::vector<T> data;

public:
    DynamicArray() {}

    size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    void push_back(const T& val) {
        data.push_back(val);
    }

    void pop_back() {
        if (data.empty()) {
            throw std::out_of_range("Array is empty");
        }
        data.pop_back();
    }

    void insert(size_t pos, const T& val) {
        if (pos > data.size()) {
            throw std::out_of_range("Position out of range");
        }
        data.insert(data.begin() + pos, val);
    }

    void erase(size_t pos) {
        if (pos >= data.size()) {
            throw std::out_of_range("Position out of range");
        }
        data.erase(data.begin() + pos);
    }

    size_t find(const T& val) const {
        auto it = std::find(data.begin(), data.end(), val);
        if (it != data.end()) {
            return std::distance(data.begin(), it);
        }
        return data.size();
    }

    T& at(size_t pos) {
        if (pos >= data.size()) {
            throw std::out_of_range("Position out of range");
        }
        return data.at(pos);
    }

    const T& at(size_t pos) const {
        if (pos >= data.size()) {
            throw std::out_of_range("Position out of range");
        }
        return data.at(pos);
    }

    T& back() {
        if (data.empty()) {
            throw std::out_of_range("Array is empty");
        }
        return data.back();
    }

    const T& back() const {
        if (data.empty()) {
            throw std::out_of_range("Array is empty");
        }
        return data.back();
    }
};

int main() {
    int q;
    std::cin >> q;

    DynamicArray<int> dynamic_array;
    const int PUSH_BACK = 1, POP_BACK = 2, INSERT = 3, ERASE = 4, FIND = 5, AT = 6;

    std::vector<int> results;

    for (int _ = 0; _ < q; ++_) {
        int type;
        std::cin >> type;

        if (PUSH_BACK == type) {
            int v;
            std::cin >> v;
            dynamic_array.push_back(v);
        }

        if (POP_BACK == type) {
            if (dynamic_array.empty()) {
                results.push_back(-1);
            } else {
                results.push_back(dynamic_array.back());
                dynamic_array.pop_back();
            }
        }

        if (INSERT == type) {
            int pos, v;
            std::cin >> pos >> v;
            dynamic_array.insert(pos - 1, v);
        }

        if (ERASE == type) {
            int pos;
            std::cin >> pos;
            if (pos - 1 >= dynamic_array.size()) {
                results.push_back(-1);
            } else {
                results.push_back(dynamic_array.at(pos - 1));
                dynamic_array.erase(pos - 1);
            }
        }

        if (FIND == type) {
            int v;
            std::cin >> v;
            size_t index = dynamic_array.find(v);
            if (index == dynamic_array.size()) {
                results.push_back(-1);
            } else {
                results.push_back(index + 1);
            }
        }

        if (AT == type) {
            int pos;
            std::cin >> pos;
            if (pos - 1 >= dynamic_array.size()) {
                results.push_back(-1);
            } else {
                results.push_back(dynamic_array.at(pos - 1));
            }
        }
    }

    for (int result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}
