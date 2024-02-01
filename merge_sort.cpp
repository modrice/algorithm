
class Solution {
public:



    std::vector<int> sorted;

    void merge(vector<int>& nums, int left, int mid, int right){
    
        int k = left;
        int i = left;
        int j=  mid+1;

        while(i<=mid && j<= right){
            if(nums[i] <= nums[j]){
                sorted[k++] = nums[i++];
            }else{
                sorted[k++] = nums[j++];
            }
        }
        if(i>mid){
            for(int l = j; l<= right; l++){
                sorted[k++] = nums[l];
            }
        }
        if(j>right){
            for(int l  = i ;l<=mid; l++ ){
                sorted[k++] = nums[l];
            }
        }

        for(int l = left; l<=right; l++){
            nums[l] = sorted[l];
        }

    }
    void merge_sort(vector<int>& nums, int left, int right){

        if(left<right){
            int mid = (left+right)/2;
            merge_sort(nums, left,  mid);
            merge_sort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }

    // {5,1,1} /{2,0,0}
    // {5,1}/ {1}/ {2,0} /{0}
    // {5} /{1}/ {1}/ {2}/ {0} /{0} 


    // {1,5} {1} / {0,2} {0}
    // {1,1,5} / {0,0,2}
    // {0,0,1,1,2,5}
    vector<int> sortArray(vector<int>& nums) {
        sorted.resize(nums.size());
        //std::copy(nums.begin(), nums.end(), raw.begin());

        merge_sort(nums, 0, nums.size()-1);
        // for(auto& item : raw){
        //     std::cout<<item <<std::endl;
        // }
        
        return sorted;
    }    
};
