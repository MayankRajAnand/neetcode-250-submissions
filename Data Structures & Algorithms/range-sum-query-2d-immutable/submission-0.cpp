class NumMatrix {
public:
    int n;
    int m;
    vector<vector<int>>sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        sumMat.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sumMat[i+1][j+1]= matrix[i][j]+sumMat[i+1][j]+sumMat[i][j+1]-sumMat[i][j];
            }
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<sumMat[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMat[row2 + 1][col2 + 1]
             - sumMat[row1][col2 + 1]
             - sumMat[row2 + 1][col1]
             + sumMat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */