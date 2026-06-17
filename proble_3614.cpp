#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int  processStr(string s)
{
   
    int count=0;
    for (int i = 0; i < s.length(); i++)
    {
        string ans;
        if (islower(s[i]))
        {
            ans += s[i];
        }
        if (s[i] == '#')
        {
            ans = ans.append(ans);
            count++;
        }
        if (s[i] == '*')
        {
            if (!ans.empty())
            {
                ans.pop_back();
            }
        }
        if (s[i] == '%')
        {
            reverse(ans.begin(), ans.end());
        }
    }
    return count;
    
}

int main()
{
    cout<<processStr("asd####");

    return 0;
}