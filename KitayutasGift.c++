#include <iostream>
#include <cstring>

using namespace std;

void form_palindrome(char *s) {

    unsigned l = strlen(s);

    switch(l) {
    case 1:
	cout << s << s << endl;
	return;
    case 2:
	cout << s << *s << endl;
	return;
    case 3: 
	if (*s == *(s+1)) {
	    cout << *(s+2) << s << endl;
	} else if (*s == *(s+2)) {
	    cout << *s << *(s+1) << *(s+1) << *(s+2) << endl;
	} else if (*(s+1) == *(s+2)) {
	    cout << s << *s << endl;
	} else {
	    cout << "NA" << endl;
	}
	return;

    default: {

	bool mismatch = false;
	char t[15];
	char *b = s;
	char *e = s + l - 1;
	char *bb = t;
	char *ee = t + l;

	while (e >= b) {

	    if (*e == *b) {

		*(bb++) = *(b++);
		*(ee--) = *(e--);

	    } else if (mismatch) {
		cout << "NA" << endl;
		return;

	    } else if ((*e == *(b+1)) && (*(e-1) == *(b+2))) {

		*(bb++) = *b; 
		*(bb++) = *e; 
		*(bb++) = *(e-1); 
		*(ee--) = *b;
		*(ee--) = *e;
		*(ee--) = *(e-1);
		e -= 2;
		b += 3;
		mismatch = true;

	    } else if ((*(e-1) == *b) && (*(e-2) == *(b+1))) {

		*(bb++) = *e;
		*(bb++) = *b; 
		*(bb++) = *(b+1); 
		*(ee--) = *e;
		*(ee--) = *b;
		*(ee--) = *(b+1);
		e -= 3;
		b += 2;
		mismatch = true;

	    } else {
		cout << "NA" << endl;
		return;
	    }		
	}
	
	if (!mismatch && (l % 2 == 0)) {
	    *(t + (l>>1)) = 'z';
	}

	*(t + l + 1) = 0;

	cout << t << endl;
	}
    }
}

int main(void) {
    char s[15];
    cin >> s;
    form_palindrome(s);
    return 0;
}
