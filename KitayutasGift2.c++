#include <iostream>
#include <cstring>

using namespace std;

bool recursive(char *b, char *e, char *bb, char *ee, unsigned lvl) {

    while ((e > b) && (*e == *b)) {
        *(bb++) = *(b++);
        *(ee--) = *(e--);
    }

    if (e <= b) {
        *bb = *e;
        *ee = *e;
    } else if (lvl > 0) {
        return false;
    } else {
        if (recursive(b+1, e, bb+1, ee-1, lvl+1)) {
            *bb = *b;
            *ee = *b;
        } else if (recursive(b, e-1, bb+1, ee-1, lvl+1)) {
            *bb = *e;
            *ee = *e;
        } else {
            return false;
        }
    }

    return true;
}

int main(void) {
    char s[15], t[15];

    while (cin) {
        cin >> s;

        unsigned l = strlen(s);
        if (l <= 2) {
            cout << s << *s << endl;
        } else if (recursive(s, s+l-1, t, t+l, 0)) {
            t[l+1] = '\0';
            cout << t << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}
