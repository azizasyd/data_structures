#include <bits/stdc++.h>

void solve()
{
    int q;
    std::cin >> q;
    std::unordered_set<int> un_set;
    std::vector<int> results;
    const int ADD = 1, REMOVE = 2, CHECK = 3;

    for (int _ = 0; _ < q; ++_) {
        int type, v;
        std::cin >> type >> v;

        if (type == ADD) {
            auto it = un_set.find(v);
            if (it != un_set.end()) {
                // already exists in set
                results.push_back(0);
            } else {
                un_set.insert(v);
                results.push_back(1);
            }

        } else if (REMOVE == type) {
            auto it = un_set.find(v);
            if (it != un_set.end()) {
                un_set.erase(v);
                results.push_back(1);

            } else {
                results.push_back(0);
            }

        } else if (CHECK == type) {
            auto it = un_set.find(v);
            if(it != un_set.end()){
                results.push_back(1);
            } else {
                results.push_back(0);
            }
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results.at(i) << " ";
    }
    std::cout << "\n";
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}