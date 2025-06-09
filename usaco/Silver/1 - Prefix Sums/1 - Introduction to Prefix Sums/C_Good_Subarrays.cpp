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
        string s; cin >> s;

        vector<int> arr(n+1);

        for (int i = 0; i < n; i++){
            arr[i+1] = s[i] - '0';
        }

        map<ll, ll> prefix;
        ll ans = 0, sum = 0;
        
        prefix[0]++;
        for (int i = 1; i <= n; i++){
            sum += arr[i];

            ans += prefix[sum - i];

            prefix[sum-i]++;
        }

        cout << ans << "\n";
    }
}