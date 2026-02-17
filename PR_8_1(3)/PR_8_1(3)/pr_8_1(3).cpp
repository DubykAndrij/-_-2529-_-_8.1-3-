#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool ContainsPairs(char* s)
{
    if (strstr(s, "no") != NULL || strstr(s, "on") != NULL)
        return true;
    else
        return false;
}

char* Change(char* s)
{
    char* t = new char[strlen(s) * 3 / 2 + 1];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    t[0] = '\0';

    while (p = strstr(s + pos1, "no"))
    {
        pos2 = p - s;

        strncat(t, s + pos1, pos2 - pos1);

        strcat(t, "***");

        pos1 = pos2 + 2;
    }

    strcat(t, s + pos1);

    strcpy(s, t);

    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (ContainsPairs(str))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String does not contain 'no' or 'on'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}