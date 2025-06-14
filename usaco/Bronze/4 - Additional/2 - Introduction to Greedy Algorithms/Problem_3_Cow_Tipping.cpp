#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool verif(vector<string> &s){
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            if (s[i][j] == '1') {
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n; cin >> n;

    vector<string> s(n);

    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;    
    while(true){
        int mx = -1;
        int my = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (s[i][j] == '1') {
                    mx = i+1;
                    my = j+1;
                }
            }
        }

        for (int i = 0; i < mx; i++){
            for (int j = 0; j < my; j++){
                if (s[i][j] == '1') s[i][j] = '0';
                else if (s[i][j] == '0') s[i][j] = '1';
            }
        }
        
        if (mx != -1 || my != -1) ans++;

        if (verif(s)){
            cout << ans << "\n";
            break;
        }
    }
}
