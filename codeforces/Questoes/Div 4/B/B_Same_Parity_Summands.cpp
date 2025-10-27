#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (n % 2 && k % 2 == 0){
        cout << "NO" << "\n";
        return;
    }

    if (n % 2){
        int v = n-k+1;
        if (v > 0 && v % 2){
            cout << "YES" << "\n";
            cout << n - k + 1 << " ";
            for (int i = 0; i < k-1; i++){
                cout << 1 << " \n"[i == k-2];
            }
            return;
        }
        cout << "NO" << "\n";
        return;
    }
    else if (n % 2 == 0){
        int v = n - (k-1)*2;
        if (v > 0 && v % 2 == 0){
            cout << "YES" << "\n";
            cout << n - (k-1)*2 << " ";
            for (int i = 0; i < k-1; i++){
                cout << 2 << " \n"[i==k-2];
            }
            return;
        }
        v = n-k+1;
        if (v > 0 && v % 2){
            cout << "YES" << "\n";
            cout << n - k + 1 << " ";
            for (int i = 0; i < k-1; i++){
                cout << 1 << " \n"[i == k-2];
            }
            return;
        }
        cout << "NO" << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}