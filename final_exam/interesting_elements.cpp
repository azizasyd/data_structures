#include <bits/stdc++.h>

// ai interesting if (i * ai) % 720 == 0
void solve(){
    int n; // 7
    std::cin >> n;

    std::vector<int> A(n);

    for(int i = 0; i < n; ++i){
        std::cin >> A[i];
    }

    std::vector<int> results;
    for(int i = 0; i < n; ++i){
        long long product = (long long)(i + 1) * A[i];
        if (product % 720 == 0) {
            results.push_back(i + 1);
        }
    }


    std::cout << results.size() << "\n";
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