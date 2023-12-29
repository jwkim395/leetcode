class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int flag = 0;
        for(int i = 0; i < data.size(); ++i){
            if(flag == 0 && data[i] >> 3 == 30)
                flag += 3;
            else if(flag == 0 && data[i] >> 4 == 14)
                flag += 2;
            else if(flag == 0 && data[i] >> 5 == 6)
                flag++;
            else if(flag > 0 && data[i] >> 6 == 2)
                flag--;
            else if(flag == 0 && data[i] >> 7 == 0)
                continue;
            else
                return false;
        }
        if(flag == 0){
            return true;
        }
        return false;
    }
};