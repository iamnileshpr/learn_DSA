class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        int index=0;
    if(m*n != r*c)
    return mat;
    vector<vector<int>>result(r,vector<int>(c,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int newR=index/c;
            int newCol=index%c;

            result[newR][newCol]=mat[i][j];
            index++;
        }
    }
    return result;


    }
};