#include <bits/stdc++.h>

// 3 1 4 2 3
// 1 4 2 3(1)
// 4 2 3(1)
// 2 3(1) 4(2)
// 3(1) 4(2)
// 4

void solve() {
    int n, m; // 5 2
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::queue<int> q; // indexes

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // 1 3 1 4 2
        q.push(i); // 0 1 2 3 4
    }

    int lastChild = -1;
    while(q.size() > 0){
        int current = q.front();
        q.pop();
        a[current] -= m;
        if (a[current] > 0) {
            q.push(current);
        } else {
            lastChild = current;
        }
    }
    std::cout << lastChild + 1 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}