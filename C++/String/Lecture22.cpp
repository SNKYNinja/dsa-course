#include <iostream>
using namespace std;

int getLength(char str[])
{
    int count = 0;
    // Iterate till we reach the null character which represents the end of the string
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char str[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}
// This function will not work for special characters and numbers
// To make it work, use the "isalpha" function before as a check whether the input is an alphabet or not
char toLowerCase(char ch)
{
    if (!isalpha(ch))
        return ch;
    else if (ch >= 'a' && ch <= 'z')
        return ch;
    else
    {
        // If the character is uppercase
        // For example: 'C' -> 67 (Ascii)
        // 'C' - 'A' + 'a' == 67 - 65 + 97
        // 'c' == 99
        char temp = ch - 'A' + 'a';
        return temp;
        // 1. Subtracting 'A' tells us by how much forward is the character compared to A
        // 2. Adding 'a' pushes the ascii value of the lowercase range
    }
}

bool checkPalidrone(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        // isalnum function checks if the character is alphanumeric (digit or letter) or not
        char ch1 = isalnum(tolower(str[s]));
        char ch2 = isalnum(tolower(str[e]));
        if (!ch1)
        {
            s++;
        }
        else if (!ch2)
        {
            e--;
        }
        else if (tolower(str[s]) != tolower(str[e]))
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }

    return true;
}

int main()
{
    char a = 'Z';

    // String -> char type array
    char ch[10];

    // String input?
    char name[20];
    cin >> name;
    cout << "Your name: " << name << endl;

    // Using null character to stop execution b/w string
    // name[2] = '\0';
    // cout << "First two letters: " << name << endl;

    // String terminator -> '\0'
    char love[4];
    // love -> { l, o, v, e, \0 }

    // Find length of the string;
    cout << "Length: " << getLength(name) << endl;

    // Reverse a string;
    reverse(name, getLength(name));
    cout << "Reverse: " << name << endl;

    cout << "Lowercase: " << toLowerCase('0') << endl;
    cout << "Lowercase: " << toLowerCase('a') << endl;

    // Questions

    // 1. Reverse a string
    // https://leetcode.com/problems/reverse-string/submissions/1237473732/

    // 2. Palindrone
    // https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633
    // It will use "toLowerCase" and "checkPalindrone" functions
}