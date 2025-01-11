class Solution {
    public boolean canConstruct(String s, int k) {
        int odd = 0;
        int n = s.length();
        int[] arr = new int[26];
    
        //count number of odd chars
        for (char c : s.toCharArray()) {
            arr[c - 'a']++;
        }
    
        for (int i : arr) {
            if (i % 2 == 1) odd++;
        }
    
        return odd <= k && k <= n;
}
}