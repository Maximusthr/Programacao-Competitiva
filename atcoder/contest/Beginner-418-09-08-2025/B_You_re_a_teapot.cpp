#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    
    string s; cin >> s;

    int n = (int)s.size();

    int qtd = 0;
    int first_pos = 0;
    int last_pos = 0;
    bool ok = false;
    for (int i = 0; i < n; i++){
        
        if (!ok && s[i] == 't'){
            ok = true;
            first_pos = i;
            qtd++;
        }
        else if (s[i] == 't'){
            ok = true;
            qtd++;
            last_pos = i;
        }
    }

    cout << fixed << setprecision(15);

    double ans = 0;

    if (qtd < 2){
        cout << ans << "\n";
        return;
    }

    for (int i = first_pos; i <= last_pos; i++){
        double carac = 0;
        double ts = 0;
        for (int j = i; j <= last_pos; j++){
            carac++;
            if (s[j] == 't') ts++;

            if (ts >= 3) ans = max(ans, (ts-2)/(carac-2));
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}