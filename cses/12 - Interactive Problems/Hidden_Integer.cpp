#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int l = 1, r = 1e9;
    while(l < r){
        int mid = l + (r-l)/2;

        cout << "? " << mid << "\n";
        cout.flush();
        
        string s; cin >> s;
        if (s == "YES"){
            l = mid+1;
        }
        else {
            r = mid;
        }
    }

    cout << "! " << l << "\n";
    cout.flush();
}