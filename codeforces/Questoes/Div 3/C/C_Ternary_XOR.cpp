#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;
    string a, b; 

    bool foi = false;
    // a > b
    for (int i = 0; i < n; i++){
        if (foi && s[i] == '2'){
            a += '0';
            b += '2';
        }
        else if (s[i] == '2'){
            a += '1';
            b += '1';
        }
        else if (s[i] == '1' && !foi){
            a += '1';
            b += '0';
        }
        else if (s[i] == '1'){
            a += '0';
            b += '1';
        }
        else {
            a += '0';
            b += '0';
        }

        if (s[i] == '1') foi = true;
    }

    cout << a << "\n" << b << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}