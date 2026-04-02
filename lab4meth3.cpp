#include <bits/stdc++.h>
using namespace std;
int main()
{
    string text = "PROGRAMMING";
    string target = "gain";
    string temp1 = "";
    string temp2 = "";
    for (char i : text)
    {
        temp1 = temp1 + (char)tolower((unsigned char)i);
    }

    for (char i : target)
    {
        temp2 = temp2 + (char)tolower((unsigned char)i);
    }
    unordered_map<char, int> freq;
    for (int i = 0; i < temp1.size(); i++)
    {
        freq[temp1[i]] = i;
    }
    for (int i = 0; i < temp2.size() - 1; i++)
    {
        if (freq[temp2[i]] > freq[temp2[i + 1]])
        {
            cout << "False" << endl;
            break;
            return 0;
        }
    }
    cout << "True" << endl;
    return 0;
}