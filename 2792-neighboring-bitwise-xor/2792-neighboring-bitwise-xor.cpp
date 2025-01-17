class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Create an original array initialized with 0.
        vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        // Store the validation results in checkForZero and checkForOne
        // respectively.
        bool checkForZero = (original[0] == original[original.size() - 1]);
        original = {1};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        bool checkForOne = (original[0] == original[original.size() - 1]);

        return checkForZero | checkForOne;
    }
};