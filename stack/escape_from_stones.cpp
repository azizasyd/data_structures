#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    std::stack<int> left, right, middle;

    int n = s.size();

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'l') {
            left.push(i + 1);
        } else if (s[i] == 'r') {
            right.push(i + 1);
        }
    }

    while (!right.empty()) {
        middle.push(right.top());
        right.pop();
    }

    while (!middle.empty()) {
        std::cout << middle.top() << "\n";
        middle.pop();
    }

    while (!left.empty()) {
        std::cout << left.top() << "\n";
        left.pop();
    }
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}
