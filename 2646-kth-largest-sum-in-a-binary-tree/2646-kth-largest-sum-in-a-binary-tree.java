
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        // List to store the sum of each level
        List<Long> levelSums = new ArrayList<>();

        // If the tree is empty, return -1
        if (root == null)
            return -1;

        // Queue for level-order traversal
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        int currentLevel = 1;
        while (!q.isEmpty()) {
            // Variable to store the sum of the current level
            long levelSum = 0;

            // Number of nodes at the current level
            int pending = q.size();
            for (int i = 0; i < pending; i++) {
                // Process each node at the current level
                TreeNode node = q.poll();

                // Add the node's value to the level sum
                levelSum += node.val;

                // Add child nodes to the queue for the next level
                if (node.left != null)
                    q.offer(node.left);
                if (node.right != null)
                    q.offer(node.right);
            }

            // Add the sum of the current level to the list
            levelSums.add(levelSum);

            // Move to the next level
            currentLevel++;
        }

        // If there are fewer levels than k, return -1
        if (levelSums.size() < k)
            return -1;

        // Sort the list in descending order
        Collections.sort(levelSums, Collections.reverseOrder());

        // Return the kth largest level sum
        return levelSums.get(k - 1);
    }
}