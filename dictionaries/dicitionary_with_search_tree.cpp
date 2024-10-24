#include <bits/stdc++.h>

void solve() {
    int q;
    std::cin >> q;

    std::map<int, int> dict;

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int k, v;
            std::cin >> k >> v;
            dict[k] = v;
        } else if (type == 2) {
            int k;
            std::cin >> k;
            dict.erase(k);
        } else if (type == 3) {
            int k;
            std::string s;
            std::cin >> k >> s;

            auto it = dict.end();

            if (s == "ls") {
                it = dict.lower_bound(k);
                if (it == dict.begin()) {
                    it = dict.end();
                } else {
                    --it;
                    if (it->first >= k) {
                        it = dict.end();
                    }
                }
            } else if (s == "le") {
                it = dict.upper_bound(k);
                if (it == dict.begin()) {
                    it = dict.end();
                } else {
                    --it;
                    if (it->first > k) {
                        it = dict.end();
                    }
                }
            } else if (s == "ge") {
                it = dict.lower_bound(k);
                if (it == dict.end() || it->first < k) {
                    it = dict.end();
                }
            } else if (s == "gs") {
                it = dict.upper_bound(k);
                if (it == dict.end()) {
                    it = dict.end();
                }
            }

            if (it == dict.end()) {
                std::cout << -1 << " " << -1 << "\n";
            } else {
                std::cout << it->first << " " << it->second << "\n";
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}

