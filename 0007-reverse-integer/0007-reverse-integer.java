class Solution {
    public int reverse(int x) {
        int num = Math.abs(x);  // Original number ka absolute value nikala
        
        int rev = 0;  // Reversed number
        
        while (num != 0) {
            int ld = num % 10;  // Last digit nikala
            
            // Overflow check
            if (rev > (Integer.MAX_VALUE - ld) / 10) {
                return 0;  // Agar overflow hua, toh 0 return kardo
            }
            
            rev = rev * 10 + ld;  // Reverse mein digit ko add kiya
            num = num / 10;  // Last digit hata diya, next iteration ke liye
        }
        
        return (x < 0) ? (-rev) : rev;  // Original number ke sign ke hisaab se result diya
    }
}