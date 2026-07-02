#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    struct side {
        int l_z = 0, l_o = 0;
        int r_z = 0, r_o = 0;
    };

    side x;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') x.r_o++;
        else x.r_z++;
    }

    int ans = INF;
    double atual = INF;
    for (int i = 0; i <= n; i++){
        if (i > 0){
            if (s[i-1] == '1'){
                x.l_o++;
                x.r_o--;
            }
            else {
                x.l_z++;
                x.r_z--;
            }
        }

        int left = x.l_o + x.l_z;
        int right = x.r_o + x.r_z;

        if (x.l_z >= (left+1)/2 && x.r_o >= (right + 1)/2){
            double v = abs((double)n/2 - i);
            if (v < atual){
                atual = v;
                ans = i;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}