#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int moves = 0;
    int last = 0;
    int l = 0, r = n-1;
    bool mov = false;
    int alice = 0, bob = 0;
    while(l <= r){
        moves++;
        int aux = 0;

        if (!mov){
            while(l <= r && aux <= last){
                aux += arr[l];
                l++;
            }
            alice += aux;
            last = aux;
            mov ^= 1;
        }
        else {
            while(l <= r && aux <= last){
                aux += arr[r];
                r--;
            }
            bob += aux;
            last = aux;
            mov ^= 1;
        }
    }

    cout << moves << " " << alice << " " << bob << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}