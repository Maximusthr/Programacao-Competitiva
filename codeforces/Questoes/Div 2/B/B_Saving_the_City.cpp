#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b; cin >> a >> b;

    string s; cin >> s;
    int n = s.size();

    int c = 0;
    bool flag = 0;
    int idx = -1;
    for (int i = 0; i < n; i++){
        if (flag){
            if (s[i] == '0') flag = 0;
            continue;
        }
        if (s[i] == '1' && !flag){
            c += a;
            flag = true;
            if (idx == -1){
                idx = i;
            }
        }
    }

    if (idx == -1){
        cout << 0 << "\n";
        return;
    }
    
    int v2 = 0;
    for (int i = idx; i < n; i++){
        while(i < n && s[i] == '1'){
            i++;
        }
        while(i < n && s[i] == '0'){
            v2 += b;
            i++;
        }
        if (i == n) break;
        
        if (v2 < a){
            c -= a;
            c += v2;
        }
        v2 = 0;
    }

    cout << c << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}