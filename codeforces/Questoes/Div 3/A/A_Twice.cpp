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

        map<int, int> arr;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            arr[x]++;
        }

        int ans = 0;
        for (auto [x, y] : arr){
            y /= 2;
            ans += y;
        }

        cout << ans << "\n";
    }
}