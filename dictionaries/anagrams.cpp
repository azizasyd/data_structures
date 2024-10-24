#include <bits/stdc++.h>
#include <string>

void solve(){
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<std::string, std::vector<int>> positions;

    for(int i = 0; i < n; ++i){
        std::string s_copy = a[i];
        sort(s_copy.begin(), s_copy.end());
        positions[s_copy].push_back(i);
    }

    std::cout << positions.size() << "\n";
    for(auto& [s_key, s_positions] : positions){
        std::cout << s_positions.size() << "\n";
        for(int pos : s_positions) {
            std::cout << pos + 1 << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}