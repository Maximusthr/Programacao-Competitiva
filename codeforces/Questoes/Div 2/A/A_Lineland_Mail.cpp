#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    vector<int> arr(t);

    for (int &i: arr) cin >> i;

    long long aux_min;
    long long aux_max;
    for (int i = 0; i < t; i++){
        if (i == 0) {
            aux_min = arr[i+1] - arr[i];
            aux_max = arr[t-1] - arr[i];
        }
        else if (i == t-1){
            aux_min = arr[i] - arr[i-1];
            aux_max = arr[i] - arr[0];
        }
        else {
            aux_min = min(arr[i] - arr[i-1], arr[i+1] - arr[i]);
            aux_max = max(arr[t-1] - arr[i], arr[i] - arr[0]);
        }

        cout << aux_min << " " << aux_max << "\n";
    }
}
