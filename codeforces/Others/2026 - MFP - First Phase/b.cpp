#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    vector<ll> ada(26), py(26);
    for (int i = 0; i < a.size(); i++){
        ada[a[i]-'a']++;
    }
    for (int i = 0; i < b.size(); i++){
        py[b[i]-'a']++;
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if (x == 3){
            bool foi = false;
            
            int maior = 0;
            for (int i = 0; i < 26; i++){
                if (maior == 1 && py[i] > 0){
                    cout << "ADA" << "\n";
                    foi = true;
                    break;
                }
                else if (maior == 2 && ada[i] > 0){
                    cout << "PY" << "\n";
                    foi = true;
                    break;
                }

                if (!maior && ada[i] > py[i]) maior = 1;
                else if (!maior && ada[i] < py[i]) maior = 2;
            }
            
            if (!foi){
                if (maior == 0) cout << "EMPATE" << "\n";
                else cout << (maior == 1 ? "PY" : "ADA") << "\n";
            }
        }
        else {
            int y; cin >> y;
            string s; cin >> s;

            if (x == 1){
                for (int i = 0; i < s.size(); i++) ada[s[i] - 'a'] += y;
            }
            else {
                for (int i = 0; i < s.size(); i++) py[s[i] - 'a'] += y;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}