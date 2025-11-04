#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    if (s == "first"){
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        string alf = "abcdefghijklmnopqrstuvwxyz";

        string ans;
        for (int i = 0; i < n; i++){
            ans += alf[arr[i]-1];
        }

        cout << ans << "\n";
    }
    else {
        string ans; cin >> ans;

        int n = ans.size();
        vector<int> num;

        for (int i = 0; i < n; i++){
            num.push_back((ans[i]-'a'));
        }

        cout << n << "\n";
        for (auto &i : num) cout << i+1 << " ";
        cout << "\n";
    }
}