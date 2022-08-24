#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    int subset_cnt = (1<<n);
    vector<vector<int>> subsets;

    for(int mask=0; mask<subset_cnt; ++mask){
        vector<int> subset;
        for(int j=0; j<n; ++j){
            if((mask & (1<<j))!= 0){
                subset.push_back(nums[j]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;

}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    vector<vector<int>> res = subsets(arr);

    for(auto sub : res){
        for(auto i : sub){
            cout << i << " ";
        }
        cout << endl;
    }




}
