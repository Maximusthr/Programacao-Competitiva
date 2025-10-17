#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> index;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            index.push_back(i+1);
        }
    }

    cout << index.size() << "\n";
    for (auto i : index) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}