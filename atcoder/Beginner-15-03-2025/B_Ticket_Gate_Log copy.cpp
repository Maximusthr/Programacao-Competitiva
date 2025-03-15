#include <bits/stdc++.h>

using namespace std;

// this one got accepted. But in test case 'i' it should be 1, but is 0.

int main(){
    string x; cin >> x;

    int ans = 0;

    // starting with i
    for (int i = 0; i < (int)x.size() - 1; i++){
        if (x[i] == 'i' && x[i+1] != 'o') ans++;
        if (i == (int)x.size()-2 && x[(int)x.size()-1] == 'i') ans++;
    }

    for (int i = 0; i < (int)x.size(); i++){
        if (i == 0 && x[0] == 'o') ans++;
        else if (x[i] == 'o' && x[i-1] != 'i') ans++;
    }


    cout << ans << "\n";

}

