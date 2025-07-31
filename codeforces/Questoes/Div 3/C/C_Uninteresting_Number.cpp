#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();

    int sum  = 0;
    int dois = 0, tres = 0;
    for (int i = 0; i < n; i++){
        sum += (s[i]-'0');
        if (s[i] == '2') dois++;
        else if (s[i] == '3') tres++;
    }

    if (sum % 9 == 0){
        cout << "YES" << "\n";
        return;
    }

    for (int i = 0; i <= (tres > 8 ? 8 : tres); i++){
        for (int j = 0; j <= (dois > 8 ? 8 : dois); j++){
            sum += (6*i + 2*j);
            if (sum % 9 == 0){
                cout << "YES" << "\n";
                return;
            }
            sum -= (6*i + 2*j);
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}