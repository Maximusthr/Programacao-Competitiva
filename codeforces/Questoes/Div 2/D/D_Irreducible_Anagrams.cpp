#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int n = s.size();

    vector<vector<int>> prefix(n+1, vector<int> (26));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 26; j++){
            prefix[i][j] = prefix[i-1][j];
        }
        prefix[i][s[i-1] - 'a']++;
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        int dif = 0;

        for (int i = 0; i < 26; i++){
            dif += (prefix[r][i] - prefix[l-1][i] > 0);
        }

        if (l == r || s[r-1] != s[l-1] || dif >= 3){
            cout << "Yes" << "\n";
        }
        else cout << "No" << "\n";
    }
}