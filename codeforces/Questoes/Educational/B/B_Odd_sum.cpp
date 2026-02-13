#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> odd, even; 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }

    sort(odd.begin(), odd.end(), greater<int> ());
    sort(even.begin(), even.end(), greater<int> ());

    int sum = 0;
    for (int i = 0; i < even.size(); i++){
        if (even[i] < 0) break;
        sum += even[i];
    }

    if (odd.front() < 0){
        sum += odd.front();
        cout << sum << "\n";
        return;
    }
    
    int i = 0;
    int count = 0;
    int sum_2 = 0;
    while(i < odd.size() && odd[i] > 0){
        sum_2 += odd[i++];
        count++;
    }
    if (count & 1){
        cout << sum + sum_2 << "\n";
    }
    else {
        int neg = 0;
        if (i < odd.size()){
            neg = odd[i];
        }

        if (neg < 0){
            neg = max(-odd[count-1], neg);
        }

        if (neg == 0) neg = -odd[count-1];

        cout << sum + sum_2 + neg << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}