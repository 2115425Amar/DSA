 bool kPangram(string str, int k) {
        // code here
        str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
        int n = str.size();
        //cout<<n;
        if(n<26){
            return false;
        }
        
        map<char,int>mpp;
        for(char ch ='a'; ch<='z'; ch++){
            mpp[ch]=0;
        }
        // for(auto &it : mpp){
        //     cout<<it.first<<it.second;
        // }
        for(int i=0;i<n;i++){
            if(mpp.find(str[i])!=mpp.end()){
                mpp[str[i]]++;
            }else{
                return false;
            }
        }
        int zero = 0;
        for(auto &it : mpp){
            if(it.second ==0 ){
                zero++;
            }
        }
        if(zero <=k){
            return true;
        }
        return false;
        
    }