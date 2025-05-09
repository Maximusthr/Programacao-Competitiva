#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<ll> odd;
        vector<ll> even;

        ll maior = -1;
        ll maior_even = -1;

        for (int i = 0; i < n; i++){
            ll x; cin >> x;
            if (x % 2) {
                odd.push_back(x);
                maior = max(maior, x);
            }
            else {
                even.push_back(x);
                maior_even = max(maior_even, x);
            }
        }

        if (even.empty()){
            cout << maior << "\n";
        }
        else if (odd.empty()){
            cout << maior_even << "\n";
        }
        else {
            ll sum_even = accumulate(even.begin(), even.end(), 0LL);

            ll sum_odd = accumulate(odd.begin(), odd.end(), 0LL);
            sum_odd -= maior;
            sum_odd -= odd.size()-1;

            cout << maior + sum_even + sum_odd << "\n";
        }
    }
}
