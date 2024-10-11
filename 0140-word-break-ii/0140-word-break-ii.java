class Solution {
  int n;
  Set<String> dict = new HashSet<>();
  List<String> res = new ArrayList<>();

  private void backTrack(String s, int i, String l) {
    if (i == n) {
      res.add(l.substring(0, l.length() - 1));
      return;
    }
    for (var j=i; j<n; j++) {
      var sub = s.substring(i, j+1);
      if (!dict.contains(sub)) continue;

      backTrack(s, j+1, l + sub + " ");
    }
  }

  public List<String> wordBreak(String s, List<String> wordDict) {
    n = s.length();
    for (var word : wordDict) dict.add(word);

    backTrack(s, 0, "");

    return res;
  }
}