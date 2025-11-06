#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    int ans = b.size();

    for (int i = 0; i < b.size(); i++){
        int j = i;

        for (int k = 0; k < a.size(); k++){
            if (j < b.size() && b[j] == a[k]) j++;
        }

        ans = min(ans, i + (int)b.size() - j);

    }

    cout << ans + a.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}