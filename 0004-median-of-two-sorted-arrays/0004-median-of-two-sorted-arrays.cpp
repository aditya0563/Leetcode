class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1=nums1.size();
        const int n2=nums2.size();

        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        int l=0,r=n1;

        while(l<=r){
            const int p1=l+(r-l)/2;
            const int p2=(n1+n2+1)/2-p1;

            const int l1=p1==0 ? INT_MIN:nums1[p1-1];
            const int l2=p2==0 ? INT_MIN:nums2[p2-1];
            const int r1=p1==n1 ? INT_MAX:nums1[p1];
            const int r2=p2==n2 ? INT_MAX:nums2[p2];

            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0) return (max(l1,l2)+min(r1,r2))*0.5;
                else return max(l1,l2);
            }
            else if(l1>r2) r=p1-1;
            else l=p1+1;
        }

        return 0;
    }
};