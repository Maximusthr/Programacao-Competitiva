#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int func (string &s, int team){
    int qtd = 0;
    int qtd2 = 0;
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 0){
            if (!team){
                if (s[i] == '1' || s[i] == '?') qtd++;
            }
            else if (s[i] == '1') qtd2++;
        }
        else {
            if (team){
                if (s[i] == '1' || s[i] == '?') qtd++;
            }
            else if (s[i] == '1') qtd2++;
        }
        int f = 10 - i - 1;
        if (!team && (f+1)/2 + qtd2 < qtd) return (i+1);
        else if (team && f/2 + qtd2 < qtd) return (i+1);
    }
    return 10;
}

void solve(){
    string s; cin >> s;

    cout << min(func(s, 0), func(s, 1)) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}