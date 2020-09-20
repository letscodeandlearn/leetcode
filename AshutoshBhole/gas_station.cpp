class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
        vector<int> bal;
        queue<int> idQueue; //stores indices
        int len = gas.size();
        
        for(int i = 0; i < gas.size(); i++){
           bal.push_back(gas[i]-cost[i]);
            
            if(bal[i]>=0) {
                idQueue.push(i);    
            }
        }
        
        while(!idQueue.empty()) {
            int startId = idQueue.front();
            //cout << startId << "\t";
            idQueue.pop();
            int remBal = bal[startId];
            int current = (startId+1) % (len);
            
            while(current != startId) {
                
                remBal = remBal + bal[current];
                if(remBal < 0){
                    break;
                }
                
                current = (current+1) % (len);
                
            }
            
            if(current == startId) {
                remBal = remBal + bal[current];
                
                if(remBal >= 0) {
                    return current;
                } 
            }
        }
        
        return -1;
    }
};