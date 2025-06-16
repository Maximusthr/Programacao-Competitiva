#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m, q; cin >> n >> m >> q;

        vector<int> arr(m);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        int loc; cin >> loc;

        // antes dos dois professores
        if (loc < arr[0]){
            cout << arr[0] - 1 << "\n";
        }
        else if (loc > arr[1]){
            cout << n - arr[1] << "\n";
        }
        else {
            cout << (arr[1] - arr[0]) / 2 << "\n";
        }

    }
}
