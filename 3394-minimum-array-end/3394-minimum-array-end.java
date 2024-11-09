class Solution {
    public long minEnd(int n, int x) {
	String str = Integer.toBinaryString(x);
	String strn = Integer.toBinaryString(n-1);

	int i=str.length()-1, j=strn.length()-1;
	long res = 0, curr=1;

	while(i >= 0 && j>=0) {
		char ch1 = str.charAt(i--);
		char ch2 = strn.charAt(j);
		if(ch1 == '1') {
			res += curr;
		} else {
			if(ch2 == '1') {
				res += curr;
			}
			j--;
		}
		curr += curr;
	}

	while(i >= 0) {
		char ch = str.charAt(i--);
		if(ch == '1') {
			res += curr;
		}
		curr += curr;
	}

	while(j >= 0) {
		char ch = strn.charAt(j--);
		if(ch == '1') {
			res += curr;
		}
		curr += curr;
	}

	return res;
}
}