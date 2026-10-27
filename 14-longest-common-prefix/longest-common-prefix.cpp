class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string shortest = strs[0];
        for (const string& str: strs) {
            if (str.length() < shortest.length()) shortest = str;
        }

        for (int i = 0; i < shortest.length(); i++) {
            for (const string& str : strs) {
                if (str[i] != shortest[i]) return shortest.substr(0, i);
            }
        }

        return shortest;


        /* initial approach to pefrom int count then substring count total
        Expecting undefined behaviour with out-of-bounds access 
        for (int i = 0; i < strs.length(); i++) {
            for (int j = 1; j < strs[0].length(); j++) {
                if (strs[j][i] == strs[0][i]) prefixMatch++;
            }
            if (prefixMatch == strs[i].length - 1) count++;

            prefixMatch = 0;
        }

        return count;
        */
    }
};