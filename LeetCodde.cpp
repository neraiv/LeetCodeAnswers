#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s[0] == NULL) return 0;
        if (s.length() == 1) return 1;  // My algorithm doesnt work when less then 2 chars

        uint32_t last_index = 0;        // Last start index before same char catch
        string usedChars = "";          // String to keep differnt chars
        usedChars.push_back(s[0]);      // Add first element of the given string to impelemnt for loop
        int longest_sub = 0;            // Answer
        
        for (uint32_t i = 1; i < s.length(); i++) {
            bool same = false;          // Same char flag
            for (uint32_t k = 0; k < usedChars.length(); k++) { // Check if the char same
                if (s[i] == usedChars[k]) {                     // if not add it into usedChars
                    same = true;                                // if same check if this one is the longest one and reset                       
                    if((i - last_index) > longest_sub) longest_sub = i - last_index;
                    last_index += 1;
                    i = last_index;
                    usedChars = "";
                    usedChars.push_back(s[last_index]);
                    break;
                }
                else {
                    
                    same = false;
                }
            }
            if (same == false) usedChars.push_back(s[i]);
            if (i == s.length() - 1 && (i -last_index +1)> longest_sub) longest_sub = i - last_index +1; // Since the above 2 loops works when diffrent char found
            // loops fail when code didnt catch any chars like "aab" or "au" etc. 
        }
        return longest_sub;
    }
};
int main()
{
    Solution sol;
    cout << "Length of the string: " << sol.lengthOfLongestSubstring("aab") << endl;
};

