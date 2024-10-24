#include <bits/stdc++.h>

#include <iostream>
#include <stdexcept>

void solve()
{
    int q;
    std::cin >> q;
    std::deque<int> deque;
    std::vector<int> results;
    const int PUSH = 1, POP = 2, INSERT = 3, ERASE = 4, FIND = 5, AT = 6;
//    const char FRONT = 'f', BACK = 'b';


    for (int _ = 0; _ < q; ++_) {
        char s;
        int type;
        std::cin >> type >> s;

        if (PUSH == type) {
            int v;
            std::cin >> v;

            if(s == 'f'){
                deque.push_front(v);
            } else if (s == 'b'){
                deque.push_back(v);
            }


        } else if (POP == type) {
            if (deque.empty()) {
                results.push_back(-1);
            } else {
                if(s == 'f'){
                    // beginning of queue
                    results.push_back(deque.front());
                    deque.pop_front();
                } else if(s == 'b'){
                    // end of queue
                    results.push_back(deque.back());
                    deque.pop_back();
                }
            }
        }
//
//        if (POP == type) {
//            char s;
//            std::cin >> s;
//            if (stack.empty()) {
//                results.push_back(-1);
//            } else {
//                if(s == 'f'){
//                    results.push_back(stack.front());
//                    stack.pop_front();
//                } else if(s == 'b'){
//                    results.push_back(stack.back());
//                    stack.pop_back();
//                }
//            }
//        }
//
//        if (INSERT == type) {
//            int pos, v;
//            std::cin >> pos >> v;
//            auto it = std::next(stack.begin(), pos - 1);
//            stack.insert(it, v);
//        }
//
//        if (ERASE == type) {
//            int pos;
//            std::cin >> pos;
//
//            if(!stack.empty()){
//                auto it = std::next(stack.begin(), pos-1);
//                results.push_back(*it);
//                stack.erase(it);
//            } else {
//                results.push_back(-1);
//            }
//        }
//
//        if (FIND == type) {
//            int v;
//            std::cin >> v;
//            auto it = std::find(stack.begin(), stack.end(), v);
//            if (it != stack.end()) {
//                results.push_back(std::distance(stack.begin(), it)+1);
//            } else {
//                results.push_back(-1);
//            }
//        }
//
//
//        if (AT == type) {
//            int pos;
//            std::cin >> pos;
//            if (pos - 1 >= stack.size()) {
//                results.push_back(-1);
//            } else {
//                auto it = std::next(stack.begin(), pos-1);
//                results.push_back(*it);
//            }
//        }
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