#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;
    k--;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int sum = 0;
    int aux = k;
    int pos_l = k-1;
    int pos_r = k+1;
    for (int i = 0; i < n; i++){
        if (i == 0 && arr[aux] == 1) {
            sum++;
            continue;
        }
        else if (i == 0) continue; // the first "if" didn't pass through

        if (pos_l >= 0 && arr[pos_l] && pos_r < n && arr[pos_r]){ // both 1
            sum += 2;
        } 
        else if (pos_l < 0 && pos_r < n && arr[pos_r]) sum++;
        else if (pos_l >= 0 && pos_r >= n && arr[pos_l]) sum++;

        pos_l--;
        pos_r++;
    }

    cout << sum << "\n";
}
