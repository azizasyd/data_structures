#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::string> strs(n);
    std::unordered_set<std::string> unique_strs;
    std::vector<int> results(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> strs[i];
        unique_strs.insert(strs[i]);
        results[i] = unique_strs.size();
        std::cout << results[i] << " ";
    }
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}