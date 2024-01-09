class Solution {
 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<optional<bool>>>> mem(
        m, vector<vector<optional<bool>>>(n, vector<optional<bool>>(m + n)));
    return hasValidPath(grid, 0, 0, 0, mem);
  }

 private:
  // Returns true if there's a path from grid[i][j] to grid[m - 1][n - 1], where
  // the number of '(' - the number of ')' == k.
  bool hasValidPath(const vector<vector<char>>& grid, int i, int j, int k,
                    vector<vector<vector<optional<bool>>>>& mem) {
    if (i == grid.size() || j == grid[0].size())
      return false;
    k += grid[i][j] == '(' ? 1 : -1;
    if (k < 0)
      return false;
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
      return k == 0;
    if (mem[i][j][k].has_value())
      return mem[i][j][k].value();
    mem[i][j][k] = hasValidPath(grid, i + 1, j, k, mem) |
                   hasValidPath(grid, i, j + 1, k, mem);
    return mem[i][j][k].value();
  }
};
