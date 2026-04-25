class Solution {
public:
    bool isValid(int rs,int re,int cs, int ce,vector<vector<char>>& board){
        unordered_set<char>st;
        for(int i=rs;i<=re;i++){
            for(int j=cs;j<=ce;j++){
                if(board[i][j]!='.' and  st.find(board[i][j])!=st.end())return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char>st;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' and  st.find(board[i][j])!=st.end())return false;
                st.insert(board[i][j]);
            }
        }

        for(int j=0;j<9;j++){
            unordered_set<char>st;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.' and  st.find(board[i][j])!=st.end())return false;
                st.insert(board[i][j]);
            }
        }

        for(int i=0;i<9;i+=3){
            int rs=i;
            int re=i+2;
            for(int j=0;j<9;j+=3){
                int cs=j;
                int ce=j+2;

                if(!isValid(rs,re,cs,ce,board))return false;
            }
        }
        return true;

    }
};
