#include <bits/stdc++.h>

//           1
//      2         3
//   4     5     6 7
//  8 9  10 11

void RLV(int vertex, int n, std::vector<int> &results) {

    // if right child exists
    if (2 * vertex + 1 <= n) { // 3
        RLV(2 * vertex + 1, n, results);
    }

    // if left child exists
    if (2 * vertex <= n) {
        RLV(2 * vertex, n, results);
    }

    // Visit the vertex itself
    results.push_back(vertex);
}


int main() {
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    int n; // 11
    std::cin >> n;

    std::vector<int> results;
    RLV(1, n, results);

    for (int i = 0; i < results.size(); ++i) {
        if (i > 0){
            std::cout << " ";
        }
        std::cout << results.at(i);
    }
    std::cout << "\n";

    return 0;
}


