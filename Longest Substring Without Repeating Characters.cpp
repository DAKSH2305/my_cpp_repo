// Longest Substring Without Repeating Characters



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxlen = 0;
        int left = 0;
        
        for(int right = 0; right < s.size(); right++) {
            if(m.count(s[right])) {
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};
/*#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        
        unordered_map<char, int> m;
        int len = 1;
        int maxlen = 1;
        m[s[0]] = 1;
        int i = 1;
        
        while(i < s.size()) {
            if(m[s[i]] == 0) {
                len++;
                m[s[i]] = 1;
                i++;
                maxlen = max(maxlen, len);
            }
            else {
                maxlen = max(len, maxlen);
                bool found = false;
                vector<char> keys_to_delete;
                
                // First collect keys to delete
                for(const auto& it : m) {
                    if(!found) {
                        if(it.first == s[i] && it.second == 1) {
                            found = true;
                            // Don't delete this one
                        }
                        else {
                            keys_to_delete.push_back(it.first);
                        }
                    }
                }
                
                // Then delete them
                for(char key : keys_to_delete) {
                    m.erase(key);
                    len--;
                }
                
                // Now add the current character
                m[s[i]]++;
                i++;
                len = m.size(); // Update len to current window size
            }
        }
        
        return max(maxlen, len);
    }
};
*/
