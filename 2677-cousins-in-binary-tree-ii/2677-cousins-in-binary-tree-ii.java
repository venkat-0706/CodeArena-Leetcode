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
    public TreeNode replaceValueInTree(TreeNode root) {
        //applying bf
        Queue<TreeNode>queue = new LinkedList<>();
        queue.offer(root);
        root.val=0;
        //root.val=0;
        int sz =1;
        int tf =0;
        while(!queue.isEmpty()){
         HashMap<Integer,Integer>hsh = new HashMap<>();
         int jk = 0; 
         tf=0;
         Queue<TreeNode>we = new LinkedList<>();
         for(int i=0;i<sz;i++){
            TreeNode ed = queue.poll();
            we.offer(ed);
            jk++;
            int sm =0;
            if(ed.left!=null){
                queue.offer(ed.left);
                sm+=ed.left.val;
                tf++;
            }
            if(ed.right!=null){
                queue.offer(ed.right);
                sm+=ed.right.val;
                tf++;
            }
           // sz=tf;
            hsh.put(jk,sm);
         }
          sz=tf;
      ArrayList<Integer>ke = new ArrayList<>(hsh.keySet()); 
      Collections.sort(ke);
      ArrayList<Integer>ans = new ArrayList<>();
      for(int r=0;r<ke.size();r++){
        ans.add(hsh.get(ke.get(r)));
      }

      int[]arr = new int[ans.size()];
      //making a prefix sum 
      int sum = 0;
      for(int j=0;j<ans.size();j++){
        sum+=ans.get(j);
      }

      for(int e=0;e<ans.size();e++){
        int vv = ans.get(e);
        int ter = sum-vv;
        arr[e]=ter;
      }

       int sm = 0; 

      while(!we.isEmpty()){
        TreeNode er = we.poll();
        int uj = arr[sm];
        if(er.left!=null){
            er.left.val=uj;
        }
        if(er.right!=null){
            er.right.val=uj;
        }
        sm++;
      }
}


return root;

    }
}