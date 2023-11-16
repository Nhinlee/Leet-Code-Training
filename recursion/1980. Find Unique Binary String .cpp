#include "../stdc++.h"

class Solution {
private:
    vector<string> options;
public:
    string findDifferentBinaryString(vector<string> &nums) {
        options = vector<string>();
        recursion("", nums.size());

        map<string, bool> numsMap;
        for (auto num: nums) {
            numsMap[num] = true;
        }
        for (auto o: options) {
            if (!numsMap[o]) return o;
        }

        return "";
    }

    void recursion(string binary, int n) {
        if (binary.length() == n) {
            options.push_back(binary);
            return;
        }

        recursion(binary + "0", n);
        recursion(binary + "1", n);
    }

    string findDifferentBinaryStringC2(vector<string>& nums) {
        int n=nums.size();
        string str="";
        for(int i=0;i<n;i++)
        {
            nums[i][i]=='0'?str+='1':str+='0';
        }
        return str;
    }
};