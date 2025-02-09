#include <bits/stdc++.h>

using namespace std;

int f91(int x){
    if (x <= 100) return f91((f91 (x + 11)));
    return x-10;
}

int main(){
    int num;
    while(cin >> num && num){
        cout << "f91(" << num << ") = " << f91(num) << '\n';
    }
}
