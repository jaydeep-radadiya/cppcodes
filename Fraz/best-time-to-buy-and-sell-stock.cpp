// first method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]-prices[i]>maxpro)
                    maxpro = prices[j]-prices[i];
            }
        }
        
        return maxpro;
    }
};

// second method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        int minprice = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            minprice = min(minprice,prices[i]);
            maxpro = max(maxpro,prices[i]-minprice);
        }
        
        return maxpro;
    }
};