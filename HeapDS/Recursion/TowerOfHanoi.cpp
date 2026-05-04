class Solution {
  public:
  void solve (int n, int from, int to, int aux, vector<pair<int,int>> &moves){
      if(n == 1){
          moves.push_back({from, to});
          return;
      }
      
      solve(n-1, from, aux, to, moves);
      moves.push_back({from, to});
      solve(n-1, aux, to, from, moves);
  }

  int towerOfHanoi(int n, int from, int to, int aux) {
      vector<pair<int,int>> moves;
      solve(n, from, to, aux, moves);
      return moves.size();   // ✅ return count
  }
};