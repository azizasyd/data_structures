#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<std::string, int> count;
    std::string word;

    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        count[word]++;
    }

    for (auto pair : count) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}


int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}