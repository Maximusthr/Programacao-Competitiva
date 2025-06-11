#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        reverse(arr.begin(), arr.end());

        int temp = k/2;
        for (int i = 0; i < n; i++){
            if (k > temp){
                swap(arr[i], arr[k]);
                k--;
            }
        }

        for (int &i : arr) cout << i << " ";
        cout << "\n";
    }
}