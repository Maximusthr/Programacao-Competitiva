#include <bits/stdc++.h>

using namespace std;

bool ok(int mid, vector<int> &arr){

    int i = mid;
    int j = arr.size()-1;

    vector<int> val;
    int k = 0;

    while (i <= j){
        int menor = min(arr[i], arr[j]);
        if (k > 0){
            if (menor < val[k-1]) return false;
        }
        val.push_back(menor);
        if (menor == arr[i]) i++;
        else j--;
        k++;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);

        for (auto &i : arr) cin >> i;

        int l = 0;
        int r = n-1;
        while (l < r){
            int mid = l + (r-l)/2;

            if (ok(mid, arr)){
                r = mid;
            }
            else l = mid+1;
        }

        cout << r << "\n";
    }
}
