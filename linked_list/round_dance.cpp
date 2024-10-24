#include <bits/stdc++.h>

void solve(){
    size_t n;
    std::cin >> n;

    std::vector<int> p(n+1), prev(n+1), next(n+1);

    for (size_t i = 0; i <= n; ++i) {
        std::cin >> p[i];
    }

    std::vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    size_t head = 0;

    for(size_t i = 0; i <= n; ++i){
        int id = p[i];
        if (i + 1 <= n) next[id] = p[i+1];
        else next[id] = p[0];

        if (i >= 1) prev[id] = p[i-1];
        else prev[id] = p[n];
    }


    for(int id : a){
        int pr = prev[id];
        int nx = next[id];

        prev[nx] = pr;
        next[pr] = nx;


        std::cout << pr << " " << nx << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
