class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>pq;

        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string res= "";
        while(!pq.empty()){
            int currCnt = pq.top().first;
            char currChar = pq.top().second;

            pq.pop();

            if(res.length()>=2 && res[res.length()-1]==currChar && res[res.length()-2] == currChar){

                if(pq.empty()){
                    break;
                }

                int nextCnt = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                res.push_back(nextChar);
                nextCnt--;
                if(nextCnt>0){
                    pq.push({nextCnt,nextChar});
                }
            }else{
                res.push_back(currChar);
                currCnt--;
            }
                if(currCnt>0)pq.push({currCnt,currChar});
        }
        return res;
    }
};