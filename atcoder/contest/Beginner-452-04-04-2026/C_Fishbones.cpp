#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> pos(n);
    for (auto &i : pos){
        cin >> i.first >> i.second;
    }

    // [i] = posições
    // [j] = caracteres
    vector<vector<int>> mat(n, vector<int> (26));

    int m; cin >> m;
    vector<string> names(m);
    for (auto &i : names) cin >> i;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (pos[i].first == names[j].size()){
                mat[i][names[j][pos[i].second-1] - 'a']++;
            }
        }
    }

    for (int i = 0; i < m; i++){
        if (names[i].size() != n){
            cout << "No" << "\n";
            continue;
        }

        string nom = names[i];

        bool flag = true;
        for (int j = 0; j < n; j++){
            if (mat[j][nom[j]-'a'] <= 0){
                cout << "No" << "\n";
                flag = false;
                break;
            }
        }

        if (flag){
            cout << "Yes" << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}