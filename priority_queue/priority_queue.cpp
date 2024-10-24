#include <bits/stdc++.h>

template <typename T>
class priority_queue
{
private:
    std::vector<T> values;

    void up(int pos) {
        while (pos > 0 && values[pos] < values[(pos - 1) / 2]) {
            std::swap(values[pos], values[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }

    void down(int pos) {
        int n = values.size();
        while (2 * pos + 1 < n) {
            int j = 2 * pos + 1;
            if (j + 1 < n && values[j + 1] < values[j]) {
                j++;
            }
            if (values[pos] <= values[j]) {
                break;
            }
            std::swap(values[pos], values[j]);
            pos = j;
        }
    }

public:
    int size() const {
        return values.size();
    }

    // return min element
    const T& top() const {
        if (values.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return values.front();
    }

    // removes min element
    void pop() {
        if (values.empty()) {
            throw std::out_of_range("Queue is empty");
        }
        values[0] = values.back();
        values.pop_back();
        if (!values.empty()) {
            down(0);
        }
    }

    // inserts element
    void push(const T& value) {
        values.push_back(value);
        up(values.size() - 1);
    }
};

void solve()
{
    int q; // num of queries
    std::cin >> q;
    priority_queue<int> pq;

    std::vector<int> results;
    const int ADD = 1, REMOVE = 2;

    for (int _ = 0; _ < q; ++_) {
        int type; // 1st num type
        std::cin >> type;

        // add to end
        if (ADD == type) {
            int v; // 2nd num
            std::cin >> v;
            pq.push(v);
            // remove from front
        } else if (REMOVE == type) {
            if (pq.size() == 0) {
            } else {
                pq.pop();
            }
        }

        // if queue empty, then -1
        if (pq.size() == 0) {
            results.push_back(-1);
        } else {
            results.push_back(pq.top());
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results.at(i) << " ";
    }
    std::cout << "\n";
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}
