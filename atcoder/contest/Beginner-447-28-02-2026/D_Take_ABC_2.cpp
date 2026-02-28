#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    vector<int> a, b, c;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'A') a.push_back(i);
        else if (s[i] == 'B') b.push_back(i);
        else c.push_back(i);
    }

    int n = a.size(), m = b.size(), o = c.size();

    int ans = 0;

    bool ok = false;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < o){
        while (j < m && a[i] > b[j]){
            j++;
        }
        while(k < o && b[j] > c[k]){
            k++;
        }
        if (a[i] < b[j] && b[j] < c[k]){
            ans++;
            i++, j++, k++;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}