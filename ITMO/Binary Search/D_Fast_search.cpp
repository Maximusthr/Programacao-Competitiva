#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;
    int arr[n];

    map<int, int> values;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        values[arr[i]]++;
    }

    sort(arr, arr+n);

    int k; cin >> k;
    while(k--){
        int x, y; cin >> x >> y;

        int l = 0;
        int r = n-1;

        int index_x = -1;
        int index_y = -1;

        //lowerbound em x
        while(l <= r){
            // int mid = r - (r-l)/2;
            int mid = l + (r-l)/2;

            if (arr[mid] >= x){
                index_x = mid;
                r = mid - 1;
            }
            else {
                //index_x = mid;
                l = mid + 1;
            }
        }

        l = 0;
        r = n-1;
        //upperbound em y;
        while (l <= r){
            int mid = l + (r-l)/2;

            if (arr[mid] <= y){
                index_y = mid;
                l = mid + 1;
            }
            else {
                //index_y = mid;
                r = mid - 1;
            }
        }

        bool ok = false;
        if (index_x >= 0 && values[arr[index_x]] > 1){
            index_x += values[arr[index_x]] - 1;
            ok = true;
        }
        if (index_y < n && values[arr[index_y]] > 1){
            index_y += values[arr[index_y]] - 1;
            ok = true;
        }

        if (index_x == index_y && arr[index_x] == x) cout << 1 << " ";
        else if (index_x >= index_y && arr[index_x] != x) cout << 0 << " ";
        else if (index_x != 0 && ok) cout << index_y - index_x << " ";
        else if (!ok) cout << index_y - index_x + 1 << " ";
        else cout << index_y << " ";

        ok = false;
    }

    cout << "\n";
}
