class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Vector to store the sum of each level
        std::vector<std::int64_t> levelSums;

        // Variables to keep track of maximum sum and its level (not used in this solution)
        int64_t maxSum = std::numeric_limits<int64_t>::min();
        int maxSumLevel = INT_MAX;

        // If the tree is empty, return 0
        if (root == nullptr)
            return 0;

        // Queue for level-order traversal
        std::queue<TreeNode*> q;
        q.push(root);

        int currentLevel = 1;
        while (!q.empty()) {
            // Variable to store the sum of the current level
            int64_t levelSum = 0;

            // Number of nodes at the current level
            auto pending = q.size();
            while (pending--) {
                // Process each node at the current level
                auto* node = q.front();
                q.pop();

                // Add the node's value to the level sum
                levelSum += node->val;

                // Add child nodes to the queue for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Add the sum of the current level to the vector
            levelSums.emplace_back(levelSum);

            // Move to the next level
            ++currentLevel;
        }

        // If there are fewer levels than k, return -1
        if (levelSums.size() < k)
            return -1;

        // Use nth_element to partially sort the vector
        // This places the kth largest element at the correct position
        std::nth_element(
            levelSums.begin(),
            levelSums.begin() + (k - 1),
            levelSums.end(),
            std::greater<>()
        );

        // Return the kth largest level sum
        auto kth = *(levelSums.begin() + k - 1);
        return kth;
    }
};