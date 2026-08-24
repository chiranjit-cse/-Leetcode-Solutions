  #include<iostream>
  #include <vector>
   using namespace std;
   class solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>nums3;
        nums3.reserve(m + n);
        int i=0,j=0;
        while(i<m && j<n){
          if (nums1[i] < nums2[j]) {
            nums3.push_back(nums1[i++]);
          } else {
            nums3.push_back(nums2[j++]);
          }
        }

        while (i < m) nums3.push_back(nums1[i++]);
        while (j < n) nums3.push_back(nums2[j++]);

        int total = nums3.size();
        if (total % 2 == 1) return nums3[total / 2];
        return (nums3[total / 2 - 1] + nums3[total / 2]) / 2.0;
    }
};
int main() {
    vector<int>nums1={1,3};
    vector<int>nums2={2,4};
    solution obj;
    double median = obj.findMedianSortedArrays(nums1,nums2);
    cout<<"Median="<< median << endl;

    return 0;

}