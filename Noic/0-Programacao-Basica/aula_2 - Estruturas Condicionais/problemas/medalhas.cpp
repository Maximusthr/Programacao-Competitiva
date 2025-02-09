#include <iostream>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    if (x > y && y > z){
        cout << "3" << "\n";
        cout << "2" << "\n";
        cout << "1" << "\n";
    } else if (x > z && z > y){
        cout << "2" << "\n";
        cout << "3" << "\n";
        cout << "1" << "\n";
    } else if (y > x && x > z){
        cout << "3" << "\n";
        cout << "1" << "\n";
        cout << "2" << "\n";
    } else if (y > z && z > x){
        cout << "1" << "\n";
        cout << "3" << "\n";
        cout << "2" << "\n";
    } else if (z > x && x > y){
        cout << "2" << "\n";
        cout << "1" << "\n";
        cout << "3" << "\n";
    } else { // z > y && y > x
        cout << "1" << "\n";
        cout << "2" << "\n";
        cout << "3" << "\n";
    }
}