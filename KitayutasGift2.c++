#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

bool iterate(char *b, char *e, char *bb, char *ee, unsigned lvl) {

    while ((e > b) && (*e == *b)) {
        *(bb++) = *(b++);
        *(ee--) = *(e--);
    }

    if (e <= b) {
        *bb = *e;
        *ee = *e;
        return true;
    } else if (lvl > 0) {
        return false;
    } else {
        if (iterate(b+1, e, bb+1, ee-1, lvl+1)) {
            *bb = *b;
            *ee = *b;
        } else if (iterate(b, e-1, bb+1, ee-1, lvl+1)) {
            *bb = *e;
            *ee = *e;
        } else {
            return false;
        }
        return true;
    }

    assert(0);
}

int main(void) {
    char s[15], t[15];

    cin >> s;

    unsigned l = strlen(s);

    if (l <= 2) {

        switch(l) {
        case 1:
            cout << s << s << endl;
            break;
        case 2:
            cout << s << *s << endl;
            break;
        default:
            assert(0);
        }

    } else if (iterate(s, s+l-1, t, t+l, 0)) {

        t[l+1] = '\0';
        cout << t << endl;

    } else {

        cout << "NA" << endl;
    }

    return 0;
}
