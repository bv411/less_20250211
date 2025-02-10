#include <iostream>

using namespace std;

void hanoi(int n, int i, int k) {

    if (n == 1)
        cout << "Move disk " << n << " from " << i << " to " << k << endl;
    else {
        int temp = 6 - i - k;
        hanoi(n - 1, i, temp);
        cout << "Move disk " << n << " from " << i << " to " << k << endl;
        hanoi(n - 1, temp, k);
    }
}

int main() {

    hanoi(2, 1, 2);
    return 0;
}