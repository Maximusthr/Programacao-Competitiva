#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    char c = 'a';

    int j = 0;
    for (int i = 0; i < a.size(); i++){
        if (j == b.size() && a[i] == '?'){
            a[i] = c;
        }
        if (j < b.size()){
            if (a[i] == '?'){
                a[i] = b[j];
                j++;
            }
            else if (a[i] == b[j]){
                j++;
            }
        }
    }

    if (j != b.size()){
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        cout << a << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}