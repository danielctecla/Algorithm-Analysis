#include <bits/stdc++.h>

using namespace std;

const int MaxA = 1e5;

void worstCase(vector<int> &nums){
    for(int i=0;i<101;i++)
        nums.push_back(i);
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result ={};
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((nums[i]+nums[j])==target){
                result.push_back(i);
                result.push_back(j);

                return result;
            }
        }
    }
    return result;
}
vector<int> twoSumL(vector<int>& nums, int target, int n,int *a) {
        unordered_map<int,int> hashM;(*a)++;
        int resta;(*a)++;
        (*a)++;
        for(int i=0;i<n;i++){
            (*a)++;
            resta = target-nums[i];(*a)++;
            (*a)++;
            if(hashM.count(resta)>0){
                (*a)++;
                return {hashM[resta],i};
            }else{
                (*a)++;
                hashM[nums[i]]=i;
            }
            (*a)++;
        }
        (*a)++;
        (*a)++;
        return {};
}

vector<int> twoSumW(vector<int>& nums, int target,int n,int *a) {
    vector<int> result ={};(*a)++;

    (*a)++;
    for(int i=0;i<n-1;i++){
        (*a)++;
        (*a)++;
        for(int j=i+1;j<n;j++){
            (*a)++;
            (*a)++;
            if((nums[i]+nums[j])==target){
                result.push_back(i);(*a)++;
                result.push_back(j);(*a)++;

                (*a)++;
                return result;
            }
            (*a)++;
        }
        (*a)++;
        (*a)++;
    }
    (*a)++;
    (*a)++;
    return result;
}

int main(){
    vector<int> nums,rest;
    int a;
    /*worstCase(nums);
    char excel[]="TwoSumLB.csv";
    FILE *pSalida = fopen(excel,"w");

    for(int i=3;i<101;i++){
        a = 0;
        rest = twoSumL(nums,1,i,&a);
        fprintf(pSalida,"%d,%d\n",i,a);
        cout<<"[";
        for(int j=0;j<rest.size();j++){
            cout<<rest[j];
        }
        cout<<"]"<<endl;
    }
    pSalida = fopen(excel,"r");
    fclose(pSalida);*/
    /*char excel[]="TwoSumB.csv";
    FILE *pSalida = fopen(excel,"w");

    for(int i=3;i<101;i++){
        a = 0;
        rest = twoSumW(nums,1,i,&a);
        fprintf(pSalida,"%d,%d\n",i,a);
        cout<<"[";
        for(int j=0;j<rest.size();j++){
            cout<<rest[j];
            if (j < rest.size() - 1)
                cout << ",";
        }
        cout<<"]"<<endl;
    }
    pSalida = fopen(excel,"r");
    fclose(pSalida);*/
    nums = {2,7,11,15};
    int target;
    target = 9;
    cout<<"Input: nums[";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout<<"], target = "<<target<<endl;
    rest = twoSum(nums,target);

    cout<<"Output: [";
    for(int j=0;j<rest.size();j++){
        cout<<rest[j];
        if (j < rest.size() - 1)
            cout << ",";
    }
    cout<<"]"<<endl;

    nums = {3,2,4};
    target = 6;
    cout<<"Input: nums[";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout<<"], target = "<<target<<endl;
    rest = twoSum(nums,target);

    cout<<"Output: [";
    for(int j=0;j<rest.size();j++){
        cout<<rest[j];
        if (j < rest.size() - 1)
            cout << ",";
    }
    cout<<"]"<<endl;

    nums = {3,3};
    target = 6;
    cout<<"Input: nums[";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout<<"], target = "<<target<<endl;
    rest = twoSum(nums,target);

    cout<<"Output: [";
    for(int j=0;j<rest.size();j++){
        cout<<rest[j];
        if (j < rest.size() - 1)
            cout << ",";
    }
    cout<<"]"<<endl;
}