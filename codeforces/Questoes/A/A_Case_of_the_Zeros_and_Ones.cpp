#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    string x; cin >> x;
    
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == '1') ones++;
        else zeros++;
    }

    cout << abs(ones-zeros) << "\n";
}
