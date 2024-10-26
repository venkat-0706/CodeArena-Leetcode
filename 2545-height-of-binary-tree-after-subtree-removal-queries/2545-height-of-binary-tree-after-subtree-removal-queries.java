/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer, Integer> mp1 = new HashMap<>(), mp2 = new HashMap<>(), sz = new HashMap<>();
    int id = 0;
    public int[] treeQueries(TreeNode root, int[] q) {
        int[] ans = new int[q.length];
        dfs(root, 0);
        
        int[] left = new int[id];
        int[] right = new int[id];
        for (int i = 0; i < id; i++) {
            left[i] = mp2.get(i);
            if (i > 0) left[i] = Math.max(left[i - 1], left[i]);
        }
        
        for (int i = id - 1; i >= 0; i--) {
            right[i] = mp2.get(i);
            if (i + 1 < id) right[i] = Math.max(right[i], right[i + 1]);
        }
        
        for (int i = 0; i < q.length; i++) {
            int nodeId = mp1.get(q[i]);
            int l = nodeId, r = l + sz.get(nodeId) - 1;
            int h = 0;
            if (l > 0) h = Math.max(h, left[l - 1]);
            if (r + 1 < id) h = Math.max(h, right[r + 1]);
            ans[i] = h;
        }
        return ans;
    }
    
    private int dfs(TreeNode root, int h) {
        if (root == null) {
            return 0;
        }
        mp1.put(root.val, id);
        mp2.put(id, h);
        id++;
        int lz = dfs(root.left, h + 1);
        int rz = dfs(root.right, h + 1);
        sz.put(mp1.get(root.val), 1 + lz + rz);
        return 1 + lz + rz;
    }
}