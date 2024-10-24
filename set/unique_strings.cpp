#include <bits/stdc++.h>

void solve() {
    int n; // 6
    std::cin >> n;

    std::unordered_set<std::string> us;
    std::vector<std::string> results;

    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        results.push_back(str);
    }
    for (auto str : results) {
        std::cout << str << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}
