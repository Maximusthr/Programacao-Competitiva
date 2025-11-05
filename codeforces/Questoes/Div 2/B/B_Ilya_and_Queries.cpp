#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int n = (int)s.size();

    vector<int> dp(n+1);

    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]) dp[i]++;
    }

    vector<int> prefix(n+1);
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + dp[i];
    }

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;

        cout << prefix[y] - prefix[x] << "\n";
    }
}