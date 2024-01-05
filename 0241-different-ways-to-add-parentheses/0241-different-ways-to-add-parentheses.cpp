class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        bool flag = true;
        vector<int> res;
        for(int i = 0; i < expression.length(); ++i){
            if(!isdigit(expression[i])){
                flag = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for(int j = 0; j < left.size(); ++j){
                    for(int k = 0; k < right.size(); ++k){
                        if(expression[i] == '+')
                            res.push_back(left[j]+right[k]);
                        if(expression[i] == '-')
                            res.push_back(left[j]-right[k]);
                        if(expression[i] == '*')
                            res.push_back(left[j]*right[k]);
                    }
                }
            }
        }
        if(flag)
            return {stoi(expression)};
        return res;
    }
};