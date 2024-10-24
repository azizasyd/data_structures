#include <bits/stdc++.h>

//8
//((
//((()
//))()
//(((())
//)()())
//((()()
//))(())
//()((()

//()
//()()
//()()
//()(())
//(()())
//()()()
//()(())
//()()()

void solve() {
    int t; // num of queries
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;

        size_t n = s.size();
        std::stack<int> stack;

        int imbalance_ind = -1;

        // find where the imbalance is
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (!stack.empty()) {
                    stack.pop();
                } else {
                    imbalance_ind = i;
                }
            }
        }

        // imbalance is from unclosed '('
        if (!stack.empty()) {
            imbalance_ind = stack.top();
        }

        // correct imbalance
        if (imbalance_ind != -1) {
            s[imbalance_ind] = (s[imbalance_ind] == '(') ? ')' : '(';
        }

        std::cout << s << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf
    std::cin.tie(NULL); // turn off sync between cin and cout
    solve();
    return 0;
}
