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

        arr[0] = 1;
        arr[n-1] = 2;
        iota(arr.begin()+1, arr.end()-1, 3);
        reverse(arr.begin()+1, arr.end()-1);

        for (auto &i : arr) cout << i << " ";
        cout << "\n";
    }
}