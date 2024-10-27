class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> dp(cols, 0);
        int totalSquares = 0;
        int topLeft = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int currentTop = dp[j];
                
                dp[j] = matrix[i][j] == 1 
                    ? (j == 0
                        ? 1 
                        : 1 + min({dp[j], dp[j - 1], topLeft})
                       ) 
                    : 0;
                
                totalSquares += dp[j];
                
                topLeft = currentTop;
            }
        }
        
        return totalSquares;
    }
};
