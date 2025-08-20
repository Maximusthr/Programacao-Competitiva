#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    ll a, b;

    array<ll, 4> sums;

    cout << "and 1 2" << endl;

    cin >> a;

    cout << "or 1 2" << endl;

    cin >> b;

    sums[0] = 2 * (a & b) + ((a & b) ^ (a | b));

    cout << "and 1 3" << endl;

    cin >> a;

    cout << "or 1 3" << endl;

    cin >> b;

    sums[1] = 2 * (a & b) + ((a & b) ^ (a | b));

    cout << "and 2 3" << endl;

    cin >> a;

    cout << "or 2 3" << endl;

    cin >> b;

    sums[2] = 2 * (a & b) + ((a & b) ^ (a | b));

    vector<ll> v(n);

    v[0] = (sums[0] + sums[1] - sums[2])/2;
    v[1] = sums[2] + v[0] - sums[1];
    v[2] = sums[1] - v[0];

    for (int i = 3; i < n; i++){
        cout << "and 1 " << i+1 << endl;
        
        cin >> a;

        cout << "or 1 " << i+1 << endl;

        cin >> b;

        sums[3] = 2 * (a & b) + ((a & b) ^ (a | b));

        v[i] = sums[3] - v[0];
    }

    sort(v.begin(), v.end());

    cout << "finish " << v[k-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}