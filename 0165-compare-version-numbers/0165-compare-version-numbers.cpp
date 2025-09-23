class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int x = 0;
            while (i < version1.size() && version1[i] != '.') {
                x = x * 10 + (version1[i] - '0');
                i++;
            }
            int y = 0;
            while (j < version2.size() && version2[j] != '.') {
                y = y * 10 + (version2[j] - '0');
                j++;
            }
            if (x < y) return -1;
            if (x > y) return 1;
            if (i < version1.size() && version1[i] == '.') i++;
            if (j < version2.size() && version2[j] == '.') j++;
        }
        return 0;
    }
};