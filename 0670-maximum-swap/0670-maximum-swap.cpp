class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }
        int maxi=0;
        vector<int>temp(digits.size());
        temp[0]=-1;
        for(int i=1;i<digits.size();i++){
            temp[i]=digits[maxi]>digits[i]?maxi:-1;
            if(digits[i]>digits[maxi]){
                maxi=i;
            }
        }

        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]!=-1){
                swap(digits[i],digits[temp[i]]);
                break;
            }
        }
        int mul=pow(10,temp.size()-1);
        int org=0;
        for(int i=digits.size()-1;i>=0;i--){
            org+=(digits[i]*mul);
            mul/=10;
        }

        return org;

        
    }
};