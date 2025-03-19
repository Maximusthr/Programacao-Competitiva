    #include <bits/stdc++.h>

    using namespace std;

    bool isValid(vector<int> &arr){
        int aux = 0;
        for (int i = 0; i < (int)arr.size()-1; i++){
            aux += arr[i] - arr[i+1];
            if (aux < 0) return false;
        }
        return true;
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(NULL);

        int x; cin >> x;

        vector<int> arr(x+1);
        arr[0] = 0;
        for (int i = 1; i < x+1; i++){
            cin >> arr[i];
        }

        int l = 0;
        int r = 1e9;
        int ans = 0;
        while (l <= r){
            int mid = l + (r-l)/2;

            arr[0] = mid;

            if (isValid(arr)){
                r = mid-1;
                ans = mid;
            }
            else {
                l = mid+1;
            }
        }

        cout << ans << "\n";
    }
