#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int menor = INF;
    pair<int, int> v;
    for (int i = 0; i < n-1; i++){
        int x = arr[i+1] - arr[i];
        if (x < menor){
            menor = x;
            v.first = i;
            v.second = i+1;
        }
    }

    swap(arr[0], arr[v.first]);
    swap(arr.back(), arr[v.second]);

    sort(arr.begin()+1, arr.begin()+n-1);

    // 2 1 2 3 4 2
    // 2 2 1 3 4 2
    // 2 2 3 4 1 2

    int aux = 0;
    for (int i = 1; i < n-1; i++){
        if (arr[i] >= arr[0]) {
            aux = i;
            break;
        }
    }

    if (aux != 0) rotate(arr.begin()+1, arr.begin()+aux, arr.begin()+n-1);

    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}