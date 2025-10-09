#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> diff(n+2);
    for (int i = 0; i <= n; i++){
        diff[freq[i]]++;
        diff[n-i+1]--; // giro

        if (!freq[i]) break;
    }

    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }

    for (int i = 0; i <= n; i++){
        cout << diff[i] << " \n"[i==n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}