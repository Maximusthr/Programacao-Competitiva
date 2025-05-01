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

        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i] % 2) sum -= arr[i];
            else sum += arr[i];
        }

        if (sum > 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}