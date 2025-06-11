#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        vector<int> b;
        
        for (int i = 0; i < n; i++){
            cout << n - arr[i] + 1<< " ";
        }

        cout << "\n";
    }
}
