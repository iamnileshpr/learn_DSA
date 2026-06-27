class Solution {
public:

bool valid(int i,int j,int n,int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

void dfs(vector<vector<char>>& board,int n,int m,int i,int j){

    board[i][j]='#';

    for(int k=0;k<4;k++){

        int row=i+x[k];
        int col=j+y[k];

        if(valid(row,col,n,m) &&
           board[row][col]=='O'){

            dfs(board,n,m,row,col);
        }
    }
}

void solve(vector<vector<char>>& board) {

    int n=board.size();

    if(n==0) return;

    int m=board[0].size();

    // top
    for(int i=0;i<m;i++)
        if(board[0][i]=='O')
            dfs(board,n,m,0,i);

    // bottom
    for(int i=0;i<m;i++)
        if(board[n-1][i]=='O')
            dfs(board,n,m,n-1,i);

    // left
    for(int j=0;j<n;j++)
        if(board[j][0]=='O')
            dfs(board,n,m,j,0);

    // right
    for(int j=0;j<n;j++)
        if(board[j][m-1]=='O')
            dfs(board,n,m,j,m-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(board[i][j]=='#')
                board[i][j]='O';

            else if(board[i][j]=='O')
                board[i][j]='X';
        }
    }
}
};