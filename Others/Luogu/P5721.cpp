#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int counter = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            if (counter < 10) {
                cout << '0' << counter;
            } else {
                cout << counter;
            }
            ++counter;
        }
        cout << '\n';
    }

    return 0;
}