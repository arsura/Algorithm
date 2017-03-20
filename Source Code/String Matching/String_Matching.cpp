#include <iostream>
#include <string>
#include <vector>

using namespace std;


int stringMatching(string text, string pattern)
{
    int index;
    for (int i = 0; i < text.length(); i++) {
        if (pattern[0] == text[i]) {
            index = i;
            for (int j = 0; j < pattern.length(); j++) {
                if (pattern[j] != text[i + j]) {
                    j = pattern.length();
                }
                if (j == pattern.length() - 1) {
                    return index;
                }
            }
        }
    }
    return -1;
}

int main()
{
    cout << "er, she == (0)" << " : " << stringMatching("she", "er") << endl;
    cout << "re, naresuan university == (2)" << " : " << stringMatching("naresuan university", "re") << endl;
    cout << "n , naresuan university == (7)" << " : " << stringMatching("naresuan university", "n ") << endl;
    cout << " u, naresuan university == (8)" << " : " << stringMatching("naresuan university", " u") << endl;
    cout << "_a, naresuan university == (-1)" << " : " << stringMatching("naresuan university", "_a") << endl;
    cout << "tyy, naresuan university == (-1)" << " : " << stringMatching("naresuan university", "tyy") << endl;
    cout << "naa, naresuan university == (-1)" << " : " << stringMatching("naresuan university", "naa") << endl;
    cout << "is, naresuan university == (-1)" << " : " << stringMatching("naresuan university", "naa") << endl;
}
