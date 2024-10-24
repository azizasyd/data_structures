#include <bits/stdc++.h>

#include <iostream>
#include <stdexcept>

void solve()
{
    int q;
    std::cin >> q;
    std::stack<int> stack;
    using res_t = long long;
    std::vector<res_t> results;
//    std::vector<long long> results;
    const int PUSH = 1, POP = 2, INSERT = 3, ERASE = 4, FIND = 5, AT = 6;


    for (int _ = 0; _ < q; ++_) {
        int type, v;
        std::cin >> type >> v;

        if (PUSH == type) {
            stack.push(v);
        } else if (type == 2) {
            long long sum = 0;
            int k = v;
            while(k > 0 && stack.size() > 0){
                k--;
                sum += stack.top();
                stack.pop();
            }
            results.push_back(sum);
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results.at(i) << " ";
    }
    std::cout << std::endl;
}

int main(){
    solve();
    return 0;
}