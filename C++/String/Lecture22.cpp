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
        // 2. Adding 'a' pushes the ascii value to the lowercase range
    }
}

bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch >= '0' && ch <= '9')
    {
        return 1;
    }
    else
        return 0;
}

bool checkPalidrone(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        // isalnum function checks if the character is alphanumeric (digit or letter) or not
        // can also check the "valid" function to remove non alphanumeric characters
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

void reverseArr(string ch)
{
    int n = ch.length();

    int s = 0;
    int e = 0;
    // Have taken n+1 here because we want to iterate till the null character
    // getLength() returns the size of the char array which excludes the null terminator
    for (int i = 0; i < n + 1; i++)
    {
        if (ch[i] == ' ' || ch[i] == '\0')
        {
            e = i - 1;
            while (s < e)
            {
                swap(ch[s++], ch[e--]);
            }
            s = i + 1;
        }
    }
}

char getMaxOccCharacter(string s)
{
    // 26 Alphabets
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int num = ch - 'a';
        arr[num]++;
    }

    // This loop traverse through the alphabet array which stores occurrences based on the index assigned to a char
    // A -> 0    B -> 1    C -> 2 ...etc.
    // maxOcc stores the number of occurrences of a character
    // ans stores the index of the highest occuring character
    int maxOcc = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxOcc < arr[i])
        {
            ans = i;
            maxOcc = arr[i];
        }
    }

    // Number to character
    return 'a' + ans;
}

void replaceSpaces(string &str)
{

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        cout << ch << endl;
        if (ch == ' ')
        {
            str.replace(i, 1, "@40");
            i += 3;
        }
    }
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
    char love[4] = {'l', 'o', 'v', 'e'};
    // love -> { l, o, v, e, \0 }

    // Find length of the string;
    cout << "Length: " << getLength(name) << endl;

    // Reverse a string;
    reverse(name, getLength(name));
    cout << "Reverse: " << name << endl;

    cout << "Lowercase: " << toLowerCase('0') << endl;
    cout << "Lowercase: " << toLowerCase('a') << endl;

    // String
    // string str = "Hello";
    // Stores data just like char array but does allow access of null terminator
    // str.size();
    // str.push_back('W');
    // str.pop_back();

    // NOTE: To avoid "cin" stopping execution at "space", "tab" and "newline" use:
    // char hello[20];
    // cin.getline(hello, 20);
    // cout << hello << endl;

    string str = "Hello Ji  Kese Ho Sare";
    replaceSpaces(str);
    cout << str << endl;

    // Questions

    // 1. Reverse a string
    // https://leetcode.com/problems/reverse-string/submissions/1237473732/

    // 2. Palindrone
    // https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633
    // Solution: checkPalindrone() -> Line 55

    // 3. Valid Palindrone
    // https://leetcode.com/problems/valid-palindrome/description/

    // 4. Reverse a words in a string
    // https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
    // Solution: reverseArr() -> Line 88

    // 5. Maximum occuring character
    // https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
    // Solution: getMaxOccCharacter() -> Line 110

    // 6. Replace spaces
    // https://www.naukri.com/code360/problems/replace-spaces_1172172
    // Solution: replaceSpaces() -> Line 139

    // Remove All Occurrences of a Substring
    // https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
    // Solution:
}