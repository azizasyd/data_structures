#include <bits/stdc++.h>

void solve() {
    std::string s; // [<}){}
    std::cin >> s;
    std::stack<char> stk;
    int replaced = 0;

    if (s.length() % 2 != 0) {
        std::cout << "Impossible" << "\n";
        return;
    }

    std::unordered_map<char, char> match = {
            {')', '('},
            {'}', '{'},
            {']', '['},
            {'>', '<'}
    };

    std::unordered_map<char, char> open = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
            {'<', '>'}
    };

    for (char c : s) {
        if (open.count(c)) {
            stk.push(c);
        } else {
            if (stk.empty()) {
                std::cout << "Impossible" << "\n";
                return;
            }
            char top = stk.top();
            stk.pop();
            if (match[c] != top) {
                replaced++;
            }
        }
    }
    if (!stk.empty()) {
        std::cout << "Impossible" << "\n";
        return;
    }
    std::cout << replaced << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
