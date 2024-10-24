#include <bits/stdc++.h>

#include <iostream>
#include <stdexcept>

using min_stack = std::stack<std::pair<int, int>>;
int get_min(min_stack& stack, int neutral){
    if(stack.empty()){
        return neutral;
    } else {
        return stack.top().second;
    }
}


void solve()
{
    int q;
    std::cin >> q;
    min_stack stack;
    std::vector<int> results;
    const int PUSH = 1, POP = 2, INSERT = 3, ERASE = 4, FIND = 5, AT = 6;

    int pos_inf = 1e9;

    for (int _ = 0; _ < q; ++_) {
        int type;
        std::cin >> type;

        if (PUSH == type) {
            int v;
            std::cin >> v;

            int min_v = std::min(v, get_min(stack, pos_inf));
            stack.emplace(v, min_v);
        } else if (type == 2) {
            if (stack.empty()) {
            } else {
                stack.pop();
            }
        }
        std::cout << get_min(stack,-1) << " ";
    }
//
//    for (size_t i = 0; i < results.size(); ++i) {
//        std::cout << results.at(i) << " ";
//    }
//    std::cout << std::endl;
}


int main(){
    solve();
    return 0;
}