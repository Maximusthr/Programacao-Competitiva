#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, t; cin >> n >> t;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int i = 0, aux = 0;
    while(i < n && aux + arr[i] <= t){
        aux += arr[i];
        i++;
    }

    cout << i << "\n";
}