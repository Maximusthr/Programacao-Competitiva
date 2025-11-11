#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    vector<ll> arr(n);

    for (auto &i : arr) cin >> i;

    if (n == 1){
        cout << 0 << "\n";
        return 0;
    }

    int i = 0, j = n-1;
    ll left = arr[i], right = arr[j];
    ll ans = 0;
    while(i < j){
        if (left == right) {
            ans = max(ans, left);
            i++, j--;
            left += arr[i];
            right += arr[j];
            continue;
        }

        if (left > right){
            j--;
            right += arr[j]; 
        }
        else {
            i++;
            left += arr[i];
        }
    }

    cout << ans << "\n";
}