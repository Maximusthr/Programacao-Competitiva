#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        if (i % 2 == 0) pq.push(arr[i]);
        else {
            if (arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }

    ll sum = 0;
    while (!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << "\n";
}
