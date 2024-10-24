#include <bits/stdc++.h>

using max_queue = std::queue<int>;
using max_deque = std::deque<int>;

int get_max(const max_deque& deq, int neutral_num) {
    if (deq.empty()) {
        return neutral_num;
    } else {
        // curr max value in deque
        return deq.front();
    }
}

void solve() {
    int q; // num of queries
    std::cin >> q;
    max_queue qu;
    max_deque deq;  // to keep track of max values
    std::vector<int> results;
    const int PUSH = 1, POP = 2;

    for (int _ = 0; _ < q; ++_) {
        int type; // 1st num type
        std::cin >> type;

        // add to end of queue
        if (PUSH == type) {
            int v; // 2nd num
            std::cin >> v;
            qu.push(v);

            // if deque not empty
            while (!deq.empty() && deq.back() < v) {
                deq.pop_back();
            }
            deq.push_back(v);

            // remove from front of queue
        } else if (POP == type) {
            if (!qu.empty()) {
                if (qu.front() == deq.front()) {
                    deq.pop_front();
                }
                qu.pop();
            }
        }
        results.push_back(get_max(deq, -1));
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results.at(i) << " ";
    }
    std::cout << "\n";
}

int main() {
    solve();
    return 0;
}
