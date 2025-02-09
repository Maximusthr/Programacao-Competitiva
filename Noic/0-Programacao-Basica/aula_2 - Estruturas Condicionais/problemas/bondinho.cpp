#include <iostream>

using namespace std;

int main(){
    int x, y, sum;

    cin >> x >> y;

    sum = x + y;

    if (sum > 50){
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }
}