#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<std::vector<int>> positions(1000*1000+1);


    for(int i = 0; i < n; ++i){
        int v = a[i];
        positions[v].push_back(i);
    }


    for(int v = 0; v < positions.size(); ++v){
        auto& v_pos = positions[v];
        if(v_pos.size() > 0) {
            std::cout << v << " " << v_pos.size() << "\n";
            for (int pos: v_pos) {
                std::cout << pos + 1 << " ";
            }

            std::cout << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}