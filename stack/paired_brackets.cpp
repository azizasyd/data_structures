#include <bits/stdc++.h> // ALL standard includes;  may not work in Clang and MS VS

void solve()
{
    // n длина строки
    int t;
    std::cin >> t;

    for (int test = 0; test < t; ++test) {

        std::string s;
        std::cin >> s;

        size_t n = s.size();

        std::vector<int> closed(n, -1);
        std::stack<int> stack;

        for(size_t i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                stack.push(i);
            } else {
                int open_p = stack.top();
                stack.pop();

                closed[open_p] = i;
            }
        }
        for (int i = 0; i < n; ++i){
            if(closed[i] != -1){
                std::cout << (i + 1) << ' ' << closed[i] + 1 << '\n';
            }
        }
    }

}

void fast_io()
{
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout
}

int main()
{
    fast_io();
    solve();
    return 0;
}

