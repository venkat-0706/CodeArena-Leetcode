class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int val=  num;
        while(num > 0){
            int temp = num % 10;
            if(val % temp == 0){
                count ++;
            }
            num /= 10;
        }
        return count;
    }
};