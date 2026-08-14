class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int> wordWeight;
        string ans;

        for(auto word : words)
        {
            int weight=0;
            for(char ch : word)
            {
                weight+= weights[ch-'a'];
            }
            wordWeight.push_back(weight);
        }

        for(int i : wordWeight)
        {
            char ch='z' - i%26;
            ans+= ch;
        }

        return ans;
    }
};