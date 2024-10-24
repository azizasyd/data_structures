#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;

    vector<string> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        if(a[i].length() % 2 == 0){
            cout << a[i] << " ";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}