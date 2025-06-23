#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);

    int n, t; cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 1, r = n;
    int ans = n;

    while(l < r){
        int mid = l + (r-l)/2;

        int size = 0, j = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        while(size < mid && j < n){
            pq.push(arr[j]);
            size++;
            j++;
        }
        
        int time = 0;
        while(!pq.empty()){
            time = pq.top();
            pq.pop();
            if (j < n){
                pq.push(arr[j] + time);
                j++;
            }
        }


        if (time > t) l = mid + 1;
        else {
            r = mid;
            ans = min(ans, mid);
        }
    }

    cout << ans << "\n";
}