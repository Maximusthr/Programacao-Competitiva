#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> s(n);
    for (auto &i : s) cin >> i;

    vector<int> t(m);
    for (auto &i : t) cin >> i;

    vector<vector<int>> lcs(n+1, vector<int> (m+1));

    for (int i = n-1; i >= 0; i--){
        for (int j = m-1; j >= 0; j--){
            if (s[i] == t[j]){
                lcs[i][j] = 1 + lcs[i+1][j+1];
            }
            else {
                lcs[i][j] = max(lcs[i+1][j], lcs[i][j+1]);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << lcs[i][j] << " \n"[j == m-1];
    //     }
    // }

    vector<int> ans;
    int i = 0, j = 0;
    while(i < n && j < m){
        if (s[i] == t[j]){
            ans.push_back(s[i]);
            i++, j++;
        }
        else if (lcs[i+1][j] >= lcs[i][j+1]){
            i++;
        }
        else j++;
    }

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}