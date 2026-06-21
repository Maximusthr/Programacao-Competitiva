#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    
    int n = s.size();

    vector<vector<char>> mat(n, vector<char> (n));
    vector<vector<int>> dist(n, vector<int> (n));
    for (int i = 0; i < n; i++){
        mat[0][i] = s[i];
        if (mat[0][i] == 'Y') dist[0][i] = 1;
        else dist[0][i] = INF;
    }   

    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            if (mat[i][j] == 'Y') dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++){
        int aux = 0;
        for (int j = 0; j < n; j++){
            if (dist[i][j] == 2) aux++;
        }
        if (aux > ans.second){
            ans = {i, aux};
        }
    }

    cout << ans.first << " " << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}