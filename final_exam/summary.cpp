#include <bits/stdc++.h>

void solve() {
    int n; // num of prepared pairs of words
    std::cin >> n;

    std::unordered_map<std::string, std::string> words;
    for (int i = 0; i < n; ++i) {
        std::string fw, sw;
        std::cin >> fw >> sw;
        if (fw.length() <= sw.length()) {
            words[fw] = fw; // use word itself if it's shorter or equal in length
        } else {
            words[fw] = sw; // use translation if it's shorter
        }
    }

    int q; // num of words in lecture
    std::cin >> q;
    std::vector<std::string> lw(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> lw[i];
    }


    for (int i = 0; i < q; ++i) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << words[lw[i]];
    }
    std::cout << "\n";
}

int main(){
    std::ios::sync_with_stdio(false); // turn off sync with scanf/printf; needs include <iomanip>
    std::cin.tie(NULL); // turn off sync between cin and cout

    solve();
    return 0;
}
