// Nao passou, foi preciso o python

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, t; cin >> n >> t;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll display = 1;
    for (int i = 0; i < n; i++){
        display *= arr[i];
        ll temp = display;
        int count = 0;
        while (temp > 0){
            count++;
            temp /= 10;
        }
        if (count > t || temp < 0 || display == 0) display = 1;
    }

    cout << display << "\n";
}
