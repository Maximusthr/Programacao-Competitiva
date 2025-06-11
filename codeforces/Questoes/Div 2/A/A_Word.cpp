#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    int low = 0, up = 0;

    char z = 'Z';

    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] <= 90) up++;
        else low++;
    }

    if (up > low)
        transform(x.begin(), x.end(), x.begin(), ::toupper);
    else  transform(x.begin(), x.end(), x.begin(), ::tolower);

    cout << x << "\n";
}
