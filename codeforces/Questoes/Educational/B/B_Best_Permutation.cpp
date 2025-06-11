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
        iota(arr.begin(), arr.end(), 1);

        if (n % 2 == 0) reverse(arr.begin(), arr.end()-2);
        else {
            for (int i = 1; i < n-2; i += 2) swap(arr[i], arr[i+1]);
        }
        
        for (int &i : arr) cout << i << " ";
        cout << "\n";
    }
}
