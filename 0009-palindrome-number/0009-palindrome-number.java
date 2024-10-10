class Solution {
    public boolean isPalindrome(int x) {
        int val = x;
        int car = 0;
        while(x>0){
            int temp = x%10;
            car = car * 10 + temp;
            x= x/10;
        }
        return (val == car);
        
    }
}