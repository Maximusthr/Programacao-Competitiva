#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int l = 1, r = 1'000'000;

    while (l < r){
        int mid = l + (r-l+1)/2;

        cout << mid << "\n";
        cout.flush();

        string x; cin >> x;

        if (x == ">="){
            l = mid;
        }
        else r = mid-1;
    }
    
    cout << "! " << r << "\n";
    cout.flush();
}
