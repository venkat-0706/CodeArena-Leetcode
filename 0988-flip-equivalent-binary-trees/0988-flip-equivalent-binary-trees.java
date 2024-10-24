class Solution {
  public boolean flipEquiv(TreeNode node1, TreeNode node2) {
    if (node1 == null && node2 == null)
      return true;

    if (node1 == null || node2 == null || node1.val != node2.val)
      return false;

    return (flipEquiv(node1.left, node2.left) && flipEquiv(node1.right, node2.right)) ||
        (flipEquiv(node1.left, node2.right) && flipEquiv(node1.right, node2.left));
  }
}