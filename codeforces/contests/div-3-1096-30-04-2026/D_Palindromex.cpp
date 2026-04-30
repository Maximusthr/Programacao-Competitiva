#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<bool> freq(2*n);

    pair<int, int> zero = {-1, -1};
    vector<int> num;
    for (int i = 0; i < 2*n; i++){
        int x; cin >> x;
        num.push_back(x);
        if (x == 0 && zero.first == -1) zero.first = i;
        else if (x == 0) zero.second = i;

    }

    auto mex = [&]() -> int {
        int x = 0;
        while(freq[x]) x++;
        return x;
    };

    int first = zero.first;
    freq[0] = true;

    int l = first-1, r = first+1;
    while(l >= 0 && r < 2*n){
        if (num[l] == num[r]){
            freq[num[l]] = true;
            l--;
            r++;
        }
        else break;
    }

    int ans = 0;
    ans = max(ans, mex());
    freq.assign(n, 0);

    int second = zero.second;
    freq[0] = true;
    l = second-1, r = second+1;
    while(l >= 0 && r < 2*n){
        if (num[l] == num[r]){
            freq[num[l]] = true;
            l--;
            r++;
        }
        else break;
    }
    ans = max(ans, mex());
    freq.assign(n, 0);

    l = first+1;
    r = second-1;
    freq[0] = true;
    bool flag = true;
    while(l <= r){
        if (num[l] == num[r]){
            freq[num[l]] = true;
            l++, r--;
        }
        else {
            flag = false;
            break;
        }
    }
    if (!flag){
        cout << ans << "\n";
        return;
    }

    l = first-1;
    r = second+1;
    while(l >= 0 && r < 2*n){
        if (num[l] == num[r]){
            freq[num[l]] = true;
            l--;
            r++;
        }
        else break;
    }
    ans = max(ans, mex());
    
    cout << ans << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}