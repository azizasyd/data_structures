#include <bits/stdc++.h>

void solve() {
    int s, n;
    std::cin >> s >> n;

    std::vector<std::pair<int, int>> dragons(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> dragons[i].first >> dragons[i].second;
    }

    std::sort(dragons.begin(), dragons.end());

    for (auto d : dragons) {
        if (s > d.first) {
            s += d.second;
        } else {
            std::cout << "NO" << "\n";
            return;
        }
    }

    std::cout << "YES" << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}
