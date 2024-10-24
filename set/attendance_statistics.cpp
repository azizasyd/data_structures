#include <bits/stdc++.h>

// 6
// +abc +def -abc +ijk -def +abc

// 2

void solve() {
    int n; // 6
    std::cin >> n;

    std::unordered_set<std::string> curr_visitors;
    int max_visitors = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        std::string rec;
        std::cin >> rec;

        if (rec[0] == '+') {
            std::string name = rec.substr(1);
            curr_visitors.insert(name);
            count++;
        } else if (rec[0] == '-') {
            std::string name = rec.substr(1);
            curr_visitors.erase(name);
            count--;
        }
        if (count > max_visitors) {
            max_visitors = count;
        }
    }
    std::cout << max_visitors << "\n";
}

int main() {
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}
