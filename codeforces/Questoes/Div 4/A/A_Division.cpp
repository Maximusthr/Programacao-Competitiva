#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n >= 1900) cout << "Division 1" << "\n";
    else if (n >= 1600 & n <= 1899) cout<< "Division 2" << "\n";
    else if (n >= 1400 && n <= 1599) cout << "Division 3" << "\n";
    else cout << "Division 4" << "\n";
    /*
    For Division 1: 1900≤rating
    For Division 2: 1600≤rating≤1899
    For Division 3: 1400≤rating≤1599
    For Division 4: rating≤1399
    */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}