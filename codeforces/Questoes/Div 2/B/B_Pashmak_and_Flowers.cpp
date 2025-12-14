#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int v_max = *max_element(arr.begin(), arr.end());
    int v_min = *min_element(arr.begin(), arr.end());

    ll maior = count(arr.begin(), arr.end(), v_max);
    ll menor = count(arr.begin(), arr.end(), v_min);

    ll ans = 1ll*maior*menor;

    if (v_max == v_min){
        maior--;
        ans = maior * (maior + 1) / 2;
    }

    cout << v_max - v_min << " " << ans << "\n";
}