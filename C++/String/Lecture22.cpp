#include <iostream>
#include <vector>
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
        if (ch == ' ')
        {
            str.replace(i, 1, "@40");
            i += 2;
        }
    }
}

string removeOccurences(string s, string part)
{
    // First condition ensures whether the string isn't empty after each iteration
    // Second condition will not run the loop if the part isn't found
    // s.find() returns "npos" constant value if the substring is not found, thus the second condition is required
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }

    return s;
}

// This function is created to check the two counters equality in checkInlcusion() -> Line 180
bool checkQual(int arr1[26], int arr2[26])
{
    for (int i = 0; i < 27; i++)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }

    return 1;
}

// Find if any permuation of s1 exists in s2
bool checkInclusion(string s1, string s2)
{
    // This is counter for counting the chars of the s1
    int count1[26] = {0};
    // Counter for counting the chars of each "window" of s2
    int count2[26] = {0};
    // The two counters will be compared every iteration so that we can compare each window of s2 with s1 string
    // Counting strategy is used here so as to not worry about the permuation of s1

    // Incrementing the counter 1 for s1
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // Starting with first window manually
    int i = 0;
    int windowSize = s1.length();
    // This will create a window of size s1.length() in s2
    // Second condition ensures the first window does not exceed the s2 string length
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // We can just return true directly if the first window passes the test
    if (checkQual(count1, count2))
        return 1;

    // Now doing it for the rest of the windows
    while (i < s2.length())
    {
        char oldChar = s2[i - windowSize];
        int oldIndex = oldChar - 'a';
        // This removes the old character from the counter
        // This is done to remove the old element from the window
        count2[oldIndex]--;

        // After every iteration, the value of "i" is shifted to the next window's new character
        char newChar = s2[i];
        int newIndex = newChar - 'a';
        // This adds the new element to the window
        count2[newIndex]++;

        i++;

        if (checkQual(count1, count2))
            return 1;
    }

    return 0;
}

string removeDuplicates(string s)
{
    string temp = "";
    int i = 0;

    while (i < s.length())
    {
        if (temp.empty() || s[i] != temp.back())
        {
            temp.push_back(s[i]);
        }
        else
        {
            temp.pop_back();
        }

        i++;
    }

    return temp;
}

int compress(vector<char> &chars)
{
    // Pointer to traverse the vector
    int i = 0;
    // Keeps track of the index
    int ansIndex = 0;
    int n = chars.size();

    while (i < n)
    {
        // We traverse with another loop from the next element either till the end of the vector or until a new character appears
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        // We add the character to the answer vector first
        chars[ansIndex++] = chars[i];
        // This will calculate the count of characters
        int count = j - i;

        if (count > 1)
        {
            // Converts the count to string and appends it to the vector
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }

        // Now "j" will have the index of the new character
        // So we will assign "i" the value of j
        i = j;
    }

    // Returning the "ansIndex" or chars.size() will be same since we need the new length of the vector
    return ansIndex;
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
    // Solution: checkPalindrone() -> Line 56

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
    // Solution: removeOccurences() -> Line 154

    // Permutation in String
    // https://leetcode.com/problems/permutation-in-string/description/
    // Solution: checkInclusion() -> Line 180

    // Remmove all adjacent duplicate
    // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
    // Solution: removeDuplicates() -> Line 236

    // String Compression
    // https://leetcode.com/problems/string-compression/description/
    // Solution: compress() -> Line 259
}