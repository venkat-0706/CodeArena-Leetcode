int trap(int* height, int n) {
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=height[0];
    for(int i=1;i<n;i++){
        lmax[i]=fmax(height[i],lmax[i-1]);
    }
    rmax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=fmax(height[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++){
        res = res+(fmin(lmax[i],rmax[i])-height[i]);
    }
    return res;
}