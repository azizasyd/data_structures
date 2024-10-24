#include <bits/stdc++.h>

void solve()
{
    int q;
    std::cin >> q;
    std::unordered_map<int, int> dict;
    std::vector<int> results;
    const int SET = 1, REMOVE = 2, GET = 3;

    for (int _ = 0; _ < q; ++_) {
        int type;
        std::cin >> type;

        if (SET == type) {
            int k, v;
            std::cin >> k >> v;
            // if found
            if (dict.find(k) != dict.end()) {
                results.push_back(dict[k]);
            } else {
                results.push_back(-1);
            }
            dict[k] = v;

        } else if (REMOVE == type) {
            int k;
            std::cin >> k;
            if (dict.find(k) != dict.end()) {
                results.push_back(dict[k]);
                dict.erase(k);
            } else {
                results.push_back(-1);
            }

        } else if (GET == type) {
            int k;
            std::cin >> k;
            if(dict.find(k) != dict.end()){
                results.push_back(dict[k]);
            } else {
                results.push_back(-1);
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