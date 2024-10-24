#include <bits/stdc++.h>

// 7 4

// 2 3
// 5 1
// 3 1
// 6 2

// 2 2 2 3 5 6 6

void solve(){
    int n, k; // 7 4
    std::cin >> n >> k;

    std::vector<int> results;

    for(int i = 0; i < k; ++i){
        int Xj, cj; // 2 3
        std::cin >> Xj >> cj;

        for(int j = 0; j < cj; ++j){
            results.push_back(Xj);
        }
    }

    std::sort(results.begin(), results.end());

    for(int i = 0; i < results.size(); ++i){
        std::cout << results[i] << " ";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}