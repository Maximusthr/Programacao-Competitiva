#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

void solve(){

    int n; cin >> n;

    if (n <= 4) {
        cout << -1 << "\n";
        return;
    }

    vector<int> arr(n);

    iota(arr.begin(), arr.end(), 1);

    vector<int> odd;
    vector<int> even;
    for (int i = 0 ; i <n; i++){
        if (arr[i] % 2) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }

    swap(odd[2], odd[odd.size()-1]);

    swap(even[0], even[1]);

    for (auto &i : odd) cout << i << " ";
    for (auto &i : even) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
}