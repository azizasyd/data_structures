#include <bits/stdc++.h>

void solve()
{
    int q;
    std::cin >> q;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> rpq;

    std::vector<int> results;
    const int ADD = 1, POP = 2, REMOVE = 3;

    for (int _ = 0; _ < q; ++_) {
        int type;
        std::cin >> type;

        if (ADD == type) {
            int v;
            std::cin >> v;
            pq.push(v);
        } else if (POP == type) {
            // if(!pq.empty() pq.pop()
            if (pq.empty()) {
            } else {
                pq.pop();
            }
        } else if (REMOVE == type) {
            int v;
            std::cin >> v;
            rpq.push(v);
        }


        while(pq.size() && rpq.size() && pq.top() == rpq.top()){
            pq.pop();
            rpq.pop();
        }

        if(pq.empty()){
            results.push_back(-1);
        } else{
            results.push_back(pq.top());
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