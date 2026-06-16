#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> num(n);
    for (int i = 0; i < n; i++){
        cin >> num[i].first >> num[i].second;
        if (num[i].first == num[i].second){
            cout << "Y" << "\n";
            return;
        }
    }

    vector<vector<int>> grundy(101, vector<int> (101));
    
    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; j++){
            if (i == j) continue;
            
            vector<bool> mex(350);
            
            for (int k = 1; k < i; k++){
                if (k == j) continue;
                mex[grundy[k][j]] = 1;
            }
            for (int k = 1; k < j; k++){
                if (k == i) continue;
                mex[grundy[i][k]] = 1;
            }
            for (int k = 1; k < min(i, j); k++){
                mex[grundy[i-k][j-k]] = 1;
            }
            
            int v = 0;
            while(mex[v]) v++;
            grundy[i][j] = v;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans ^= grundy[num[i].first][num[i].second];
    }

    cout << (ans ? "Y" : "N") << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}