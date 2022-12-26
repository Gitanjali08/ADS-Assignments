#include <iostream>
using namespace std;
int min_(int a, int b, int c){
   if (a < b)
      return (a < c) ? a : c;
   else
      return (b < c) ? b : c;
}
int minCost(int cost[4][4], int m, int n){
   int i, j;
   int tCost[4][4];
   tCost[0][0] = cost[0][0];
   for (i = 1; i <= m; i++)
   tCost[i][0] = tCost[i - 1][0] + cost[i][0];
   for (j = 1; j <= n; j++)
      tCost[0][j] = tCost[0][j - 1] + cost[0][j];
   for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++)
         tCost[i][j] = min_(tCost[i - 1][j - 1], tCost[i - 1][j], tCost[i][j - 1]) + cost[i][j];
      return tCost[m][n];
}
int main(){
   int cost[4][4] = {
      { 9, 9, 4 },
      { 8, 0, 9 },
      {1, 2, 8}
   };
   cout<<" The minimum cost is "<<minCost(cost, 2, 0);
   return 0;
}
