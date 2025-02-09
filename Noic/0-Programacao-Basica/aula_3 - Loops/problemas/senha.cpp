#include <iostream>

using namespace std;

int main(){
    int count = 0;
    while (true) {
        int x;
        cin >> x;
        if (x != 2018) count++;
        else break;
    }
    cout << count << "\n";
}