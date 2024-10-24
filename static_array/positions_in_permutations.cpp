#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::unordered_map<int, int> position;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        position[a[i]] = i;
    }

    int q;
    std::cin >> q;

    for(int i = 0; i < q; ++i){
        int a,b;
        std::cin >> a >> b;
        if(position[a] < position[b]){
            std::cout << "First" << "\n";
        } else {
            std::cout << "Second" << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}