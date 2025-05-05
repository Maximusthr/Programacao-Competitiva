// CS in contest
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        vector<int> copy = arr;
        sort(copy.begin(), copy.end(), greater<int> ());

        vector<int> a, b;

        a.push_back(copy[0]);
        for (int i = 1; i < (int)copy.size(); i++){
            if (copy[i] == a[0]) a.push_back(copy[i]);
            else b.push_back(copy[i]);
        }
        
        if (b.empty()) cout << "No" << "\n";
        else {
            cout << "Yes" << "\n";
            for (int i = 0; i < n; i++){
                if (find(a.begin(), a.end(), arr[i]) != a.end()) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << "\n";
        }
    }
}
