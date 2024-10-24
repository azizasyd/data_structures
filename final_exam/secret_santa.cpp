#include <bits/stdc++.h>

// i to Pi (Pi = i)
// Qi

void solve(){
    int n; // 7
    std::cin >> n;

    std::vector<int> P(n + 1);
    std::vector<int> Q(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> P[i];
    }

    for (int i = 1; i <= n; ++i) {
        Q[P[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << Q[i] << " ";
    }

}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}