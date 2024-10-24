#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> count(1000*1000+1);
    for(int v : a){
        count[v]++;
    }

    for(int v = 0; v < count.size(); ++v){
        if(count[v] > 0){
            std::cout << v << " " << count[v] << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}