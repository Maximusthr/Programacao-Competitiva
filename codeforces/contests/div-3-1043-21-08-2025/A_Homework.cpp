#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    deque<char> a; 
    string x; cin >> x;
    for (int i = 0; i < x.size(); i++){
        a.push_back(x[i]);
    }

    int m; cin >> m;
    string b, c; cin >> b >> c;

    
    for (int i = 0, j = b.size()-1, k = 0; i < c.size(); i++){
        if (c[i] == 'D') {
            a.push_back(b[k]);
            k++;
        }
        else {
            a.push_front(b[k]);
            k++;
        }
    }

    for (auto i : a) cout << i;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}