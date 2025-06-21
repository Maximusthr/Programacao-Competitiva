#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<bool> A(MAX);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        A[a] = 1;
    }
    
    vector<bool> B(MAX);
    for (int i = 0; i < m; i++){
        int b; cin >> b;
        B[b] = 1;
    }

    int half_a = 0, half_b = 0;

    vector<int> rep;

    for (int i = 1; i <= k; i++){
        if (A[i] && !B[i]) half_a++;
        else if(!A[i] && B[i]) half_b++;
        else if (A[i] && B[i]) rep.push_back(i);
        else {
            cout << "NO" << "\n";
            return;
        }
    }

    if (half_a > (k+1)/2 || half_b > (k+1)/2) {
        cout << "NO" << "\n";
        return;
    }

    int rest_a = (k+1)/2 - half_a;
    int rest_b = (k+1)/2 - half_b;

    if (rest_a + rest_b == rep.size()){
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}