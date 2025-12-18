#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int v = 0;
    for (int i = 0; i < n; i++){
        bool passou = false;
        if (s[i] == '0'){
            int dist = 1;
            int j = i+1;
            while(s[j%n] == '0'){
                dist++;
                j++;
                if (j == n) passou = true;
            }
            i = j-1;
            v = max(v, dist);
        }

        if (passou) break;
    }

    cout << v << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}