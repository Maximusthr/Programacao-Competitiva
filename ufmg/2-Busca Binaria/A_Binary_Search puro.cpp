#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k; cin >> n >> k;

    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;

    vector<long long> q(k);
    for (auto &i : q) cin >> i;

    for (int i = 0; i < (int)q.size(); i++){
        long long aux = q[i];

        long long l = 0;
        long long r = (int)arr.size()-1;

        bool ok = false;
        while(l <= r){
            long long mid = r - (r-l)/2;

            if (arr[mid] == aux){
                ok = true;
                break;
            }
            else if (arr[mid] > aux){
                r = mid-1;
            }
            else l = mid+1;
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
