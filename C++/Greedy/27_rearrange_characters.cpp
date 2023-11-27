/*
Idea:
sorting the string on basis of frequency of each character.
iterating the original string, and placing characters on even places, then on odd places.
(rechecking if any adjacent characters are same, and return false)
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution {
public:
    // Function to rearrange characters in a string based on frequency and lexicographical order
    string rearrangeString(string str)
    {
        int m[26] = { 0 }; // Array to store the frequency of each character

        // Count the frequency of each character in the input string
        for (int i = 0; str[i]; i++)
            m[str[i] - 'a']++;

        // Sort the string based on frequency and lexicographical order
        sort(str.begin(), str.end(), [&m](char a, char b) {
            return m[a - 'a'] > m[b - 'a'] || (m[a - 'a'] == m[b - 'a'] && a < b);
            });

        // Initialize the result string with spaces
        string ans(str.size(), ' ');
        int index = 0, i = 0;

        // Fill the result string by placing characters at even positions
        while (index < str.size())
        {
            if (i >= str.size())
                i = 1;
            ans[i] = str[index];
            i += 2;
            index++;
        }

        // Check for adjacent repeated characters
        for (int i = 1; ans[i]; i++)
            if (ans[i - 1] == ans[i])
                return "-1";

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = { 0 };
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = { 0 };
            int b[26] = { 0 };
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0;i < str1.length();i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
// } Driver Code Ends