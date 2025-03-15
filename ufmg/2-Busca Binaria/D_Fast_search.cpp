#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int q; cin >> q;

    while(q--){
        int x, y; cin >> x >> y;

        // lowerbound
        int l = 0;
        int r = (int)arr.size()-1;
        int pos_lower = arr.size();
        while(l <= r){
            int mid = l + (r-l)/2;

            if (arr[mid] >= x){
                r = mid - 1;
                pos_lower = mid;
            }
            else l = mid + 1;
        }

        //upperbound
        l = 0;
        r = (int)arr.size()-1;
        int pos_bigger = -1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if (arr[mid] <= y){
                l = mid+1;
                pos_bigger = mid;
            }
            else r = mid-1;
        }
        
        
        if (pos_bigger < pos_lower) cout << 0 << " ";
        else cout << (pos_bigger - pos_lower + 1) << " ";
    }
}
