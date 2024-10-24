#include <bits/stdc++.h>

//14
//2 3
//1 2
//1 5
//3 4 ls
//3 4 le
//3 4 ge
//3 4 gs
//3 5 ls
//3 5 le
//3 5 ge
//3 5 gs
//2 5
//3 5 le
//3 5 ge

//2 2 5 5 2 5 5 -1 2 -1

void solve() {
    int q;
    std::cin >> q;
    std::set<int> set;
    std::vector<int> results;
    const int ADD = 1, REMOVE = 2, CHECK = 3;

    for (int i = 0; i < q; ++i) {
        int type, v;
        std::cin >> type >> v;

        if (type == ADD) {
            set.insert(v);
        } else if (type == REMOVE) {
            set.erase(v);
        } else if (type == CHECK) {
            std::string s;
            std::cin >> s;
            if (set.empty()) {
                results.push_back(-1);
                continue;
            }

            auto it = set.lower_bound(v);

            if (s == "ls") {
                if (it == set.begin()) {
                    results.push_back(-1);
                } else {
                    --it;
                    results.push_back(*it);
                }
            } else if (s == "le") {
                if (it != set.begin() && (it == set.end() || *it > v)) {
                    --it;
                }
                if (it != set.end() && *it <= v) {
                    results.push_back(*it);
                } else {
                    results.push_back(-1);
                }
            } else if (s == "ge") {
                if (it != set.end()) {
                    results.push_back(*it);
                } else {
                    results.push_back(-1);
                }
            } else if (s == "gs") {
                if (it != set.end() && *it <= v) {
                    ++it;
                }
                if (it != set.end()) {
                    results.push_back(*it);
                } else {
                    results.push_back(-1);
                }
            }
        }
    }

    for (int r : results) {
        std::cout << r << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
    return 0;
}
