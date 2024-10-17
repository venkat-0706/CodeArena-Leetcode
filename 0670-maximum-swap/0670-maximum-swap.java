class Solution {
    public int maximumSwap(int num) {
        String s=String.valueOf(num);
        char a[]=s.toCharArray();
        int f[]=new int[s.length()];
        int i=s.length()-1;
        f[i]=i;
        for(int k=s.length()-2;k>=0;k--){
            if(a[i]<a[k])
                i=k;
            f[k]=i;
        }
        for(int j=0;j<s.length();j++){
            if(a[j]<a[f[j]]){
                char t=a[j];
                a[j]=a[f[j]];
                a[f[j]]=t;
                break;
            }
        }
        
        return Integer.parseInt(new String(a));
    
    }
}