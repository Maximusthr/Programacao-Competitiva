#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int winner(char a, char b){
    if ((a == 'G' && b == 'C') ||
        (a == 'C' && b == 'P') ||
        (a == 'P' && b == 'G')) return 1;

    if ((a == 'G' && b == 'P') ||
        (a == 'C' && b == 'G') ||
        (a == 'P' && b == 'C')) return 2;

    return 0;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> players(2*n);
    for (int j = 0; j < 2*n; j++){
        for (int i = 0; i < m; i++){
            char c; cin >> c;

            players[j].push_back(c);
        }   
    }

    auto comp = [&](pair<int, int> &x, pair<int, int> &y) -> bool { 
        if (x.second != y.second) return x.second > y.second;
        return x.first < y.first;
    };

    vector<pair<int, int>> rank(2*n);
    for (int i = 0; i < 2*n; i++){
        rank[i] = {i, 0};
    }

    // G stands for rock, C stands for scissors, and P stands for paper
    // G > C
    // C > P
    // P > G

    // G < P
    // C < G
    // P < C

    for (int i = 0; i < m; i++){
        for (int j = 0; j < 2*n; j+= 2){
            auto &u = rank[j];
            auto &v = rank[j+1];

            if (winner(players[u.first][i], players[v.first][i]) == 1){
                u.second++;
            }
            else if (winner(players[u.first][i], players[v.first][i]) == 2){
                v.second++;
            }
        }
        sort(rank.begin(), rank.end(), comp);
    }

    for (int i = 0; i < 2*n; i++){
        cout << rank[i].first + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}