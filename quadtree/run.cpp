#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LEN 1000

using namespace std;

int testcase = 0;

string reverse(string::iterator &it)
{
    char head = *(it++);
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
    cin >> testcase;

    for (int tc = 0; tc < testcase; tc++)
    {
        string input;
        cin >> input;
        string::iterator it = input.begin();
        cout << reverse(it) << endl;
    }
    return 0;
}