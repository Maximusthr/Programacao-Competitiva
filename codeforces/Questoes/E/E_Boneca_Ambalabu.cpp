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
        
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        vector<int> bits(31);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 31; j++){
                if (arr[i] & (1 << j)){
                    bits[j]++;
                }
            }
        }

        vector<ll> sum(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 31; j++){
                if (arr[i] & (1 << j)){
                    sum[i] += 1LL * (1 << j) * (n - bits[j]);
                }
                else sum[i] += 1LL * (1 << j) * (bits[j]);
            }
        }

        cout << *max_element(sum.begin(), sum.end()) << "\n";
    }
}
