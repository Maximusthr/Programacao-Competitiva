#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    if (s[0] == s[n-1]){
        if (s[0] == 'B') cout << "Bob" << "\n";
        else cout << "Alice" << "\n";
        return;
    }

    vector<int> pos_B, pos_A;
    for (int i = 0; i < n; i++){
        if (s[i] == 'B') pos_B.push_back(i);
        else pos_A.push_back(i);
    }
    
    if (s[n-1] == 'A'){
        if (pos_A.size() == 1){
            cout << "Bob" << "\n";
        }
        else if (s[0] == 'B'){
            if (s[n-2] == 'A'){
                cout << "Alice" << "\n";
            }
            else {
                cout << "Bob" << "\n";
            }
        }
        
    }
    else {
        if (pos_B.size() == 1){
            cout << "Alice" << "\n";
        }
        else {
            cout << "Bob" << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}