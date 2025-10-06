#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int ans;

    cout << "digit" << endl;
    cin >> ans;
    cout << "digit" << endl;
    cin >> ans;
    cout << "add -8" << endl;
    cin >> ans;
    cout << "add -4" << endl;
    cin >> ans;
    cout << "add -2" << endl;
    cin >> ans;
    cout << "add -1" << endl;
    cin >> ans;
    cout << "add " << n-1 << endl;
    cin >> ans;
    cout << "!" << endl;
    cin >> ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}