#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    int angleRot = 2;
    int angleFlip = 1;
    
    bool flipped = false;
    int direction = 0;
    while (m--) {
        int type, deg;
        cin >> type >> deg;

        switch (type) {
            case 1: // rotator
                direction = (direction + deg*angleRot);
                break;
            case 2: // flipper
                direction += 2*(deg*angleFlip - direction) + 2*n;
                flipped = !flipped;
                break;
            default:
                break;
        }
        
        direction %= 2*n;
    }

    if (flipped) {
        if (direction % angleRot)
            cout << 1 << " " << (2*n - direction) << endl;

        cout << 2 << " " << direction / 2 << endl;
    }
    else
        cout << 1 << " " << (2*n - direction)/angleRot << endl;

    return 0;
}
