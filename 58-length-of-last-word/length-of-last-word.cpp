class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = std::string(s).find_last_not_of(' ');
        int sIdx = std::string(s).find_last_of(' ', idx);
        return idx - sIdx;
    }
};