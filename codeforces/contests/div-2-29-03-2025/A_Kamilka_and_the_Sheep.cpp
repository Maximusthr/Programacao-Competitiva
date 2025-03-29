#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        vector<long long> arr(x);
        for (auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        cout << arr[(int)arr.size()-1] - arr[0] << "\n";
    }
}