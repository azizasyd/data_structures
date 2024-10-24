#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::cin >> s;
    std::stack<char> stk;

    int count = 0;
    for(char c : s){
        if(!stk.empty() && c == stk.top()){
            stk.pop();
            count++;
        } else {
            stk.push(c);
        }
    }

    if(count % 2 == 0){
        std::cout << "No";
    } else {
        std::cout << "Yes";
    }
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}