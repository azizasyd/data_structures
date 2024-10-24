#include <bits/stdc++.h>

//2 10000000000
//2 1

//2

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> powers(n);
    std::queue<int> players;
    for (int i = 0; i < n; ++i) {
        std::cin >> powers[i];
        players.push(i);
    }

    if (k >= n - 1) {
        int max_power = powers[0];
        for (int i = 0; i < n; ++i) {
            if (powers[i] > max_power) {
                max_power = powers[i];
            }
        }
        std::cout << max_power << std::endl;
        return;
    }

    int curr_winner = players.front();
    players.pop();
    int win_streak = 0;

    while (win_streak < k) {
        int challenger = players.front();
        players.pop();

        if (powers[curr_winner] > powers[challenger]) {
            // curr.winner wins
            win_streak++;
            players.push(challenger);
        } else {
            // challenger
            players.push(curr_winner);
            curr_winner = challenger;
            win_streak = 1;
        }
    }
    std::cout << powers[curr_winner] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
