class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically so parent folders come before their subfolders
        sort(folder.begin(), folder.end());

        // Initialize result vector with the first folder
        vector<string> ans;
        ans.push_back(folder[0]);

        // Iterate through remaining folders starting from index 1
        for(int i = 1; i < folder.size(); i++) {
            // Get the last added folder path and add a trailing slash
            // This helps in comparing if current folder is a subfolder
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            // Compare current folder with last added folder
            // compare(0, lastFolder.size(), lastFolder) checks if folder[i] starts with lastFolder
            // If it doesn't start with lastFolder (returns != 0), then it's not a subfolder
            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                // If not a subfolder, add to result
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};