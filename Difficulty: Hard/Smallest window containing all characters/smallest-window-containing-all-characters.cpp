class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> freqP(26, 0), freqS(26, 0);
        for (char c : p) freqP[c - 'a']++;

        int required = p.size(); // total characters needed (including duplicates)
        int formed = 0;          // total characters matched
        int left = 0, minLen = INT_MAX, startIdx = -1;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            freqS[c - 'a']++;

            // If adding this character contributes to matching requirement
            if (freqS[c - 'a'] <= freqP[c - 'a']) {
                formed++;
            }

            // Try to shrink window when valid
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Shrink from left
                char leftChar = s[left];
                freqS[leftChar - 'a']--;
                if (freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                    formed--; // lost a needed char
                }
                left++;
            }
        }

        if (startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};
