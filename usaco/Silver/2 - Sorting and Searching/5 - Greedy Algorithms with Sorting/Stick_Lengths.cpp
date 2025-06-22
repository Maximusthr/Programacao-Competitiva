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

    sort(arr.begin(), arr.end());

    ll alvo = arr[(n+1)/2 - 1];

    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum += abs(arr[i] - alvo);
    }

    cout << sum << "\n";
}