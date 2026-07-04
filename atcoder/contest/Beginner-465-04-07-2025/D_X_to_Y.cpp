#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll X, Y, K; cin >> X >> Y >> K;

    int count = 0;
    
    map<ll, ll> freq;
    freq[X] = 0;
    while(X > 0){
        X /= K;
        count++;
        freq[X] = count;
    }
    
    if (freq.count(Y)){
        cout << freq[Y] << "\n";
        return;
    }
    
    count = 0;
    while(Y > 0){
        Y /= K;
        count++;
        if (freq.count(Y)){
            cout << freq[Y] + count << "\n";
            return;
        }
        freq[Y] += count;
    }

    cout << freq[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}