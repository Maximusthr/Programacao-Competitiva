#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (m));

    int maior = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            maior = max(maior, arr[i][j]);
        }
    }

    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == maior) pos.push_back({i, j});
        }
    }   

    map<int, int> ocor_i, ocor_j;
    for (int i = 0; i < pos.size(); i++){
        ocor_i[pos[i].first]++;
        ocor_j[pos[i].second]++;
    }

    int maior_i = 0, maior_j = 0;
    int temp_i = 0;
    for (auto [x, y] : ocor_i){
        temp_i = max(temp_i, y);
        if (y == temp_i) maior_i = x;
    }
    int temp_j = 0;
    for (auto [x, y] : ocor_j){
        temp_j = max(temp_j, y);
        if (y == temp_j) maior_j = x;
    }   

    for (int i = 0; i < pos.size(); i++){
        if (pos[i].first == maior_i || pos[i].second == maior_j) continue;
        if (ocor_i[pos[i].first] == temp_i) maior_i = pos[i].first;
        else if (ocor_j[pos[i].second] == temp_j) maior_j = pos[i].second;
    }

    for (int i = 0; i < pos.size(); i++){
        if (pos[i].first == maior_i || pos[i].second == maior_j) arr[pos[i].first][pos[i].second]--;
    }

    int elem = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            elem = max(elem, arr[i][j]);
        }
    }

    cout << elem << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}