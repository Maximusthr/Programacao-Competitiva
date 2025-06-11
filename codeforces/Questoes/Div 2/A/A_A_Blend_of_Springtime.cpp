#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int n = s.size();
    
    bool ok = false;
    for (int i = 1; i < n-1; i++){
        if (s[i] != '.'){
            if (s[i] == 'B' && s[i-1] == 'A' && s[i+1] == 'C') {
                ok = true;
                break;
            }
            if (s[i] == 'B' && s[i-1] == 'C' && s[i+1] == 'A') {
                ok = true;
                break;
            }
            if (s[i] == 'A' && s[i-1] == 'B' && s[i+1] == 'C') {
                ok = true;
                break;
            }
            if (s[i] == 'A' && s[i-1] == 'C' && s[i+1] == 'B') {
                ok = true;
                break;
            }
            if (s[i] == 'C' && s[i-1] == 'A' && s[i+1] == 'B') {
                ok = true;
                break;
            }
            if (s[i] == 'C' && s[i-1] == 'B' && s[i+1] == 'A') {
                ok = true;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
}