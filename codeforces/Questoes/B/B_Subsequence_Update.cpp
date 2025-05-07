#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, l, r; cin >> n >> l >> r;
        l--, r--;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        vector<int> left; 
        vector<int> right;
        bool rig = 0;
        for (int i = 0; i < n; i++){
            if (i == l) {
                i = r;
                rig = true;
            }
            else if (!rig) {
                left.push_back(arr[i]);
            }
            else right.push_back(arr[i]);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());


        vector<int> range;
        for (int i = l; i <= r; i++){
            range.push_back(arr[i]);
        }

        sort(range.begin(), range.end(), greater<int> ());

        vector<int> copy = range;

        for (int i = 0, j = 0; i < (int)range.size(); i++){
            if (j == (int)left.size()) break;
            if (range[i] > left[j]){
                range[i] = left[j];
                j++;
            }
        }
        ll sum = accumulate(range.begin(), range.end(), 0LL);

        // usando copy
        for (int i = 0, j = 0; i < (int)range.size(); i++){
            if (j == (int)right.size()) break;
            if (copy[i] > right[j]){
                copy[i] = right[j];
                j++;
            }
        }
        ll sum_aux = accumulate(copy.begin(), copy.end(), 0LL);

        cout << min(sum_aux, sum) << "\n";
    }
}
