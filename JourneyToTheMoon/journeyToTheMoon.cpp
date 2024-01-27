/**
 * @file journeyToTheMoon.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 * @link https://www.hackerrank.com/challenges/journey-to-the-moon/problem?isFullScreen=false
 */

#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
  int count = 1;
  visited[node] = true;
  for (int i = 0; i < adj[node].size(); i++)
  {
    if (!visited[adj[node][i]])
    {
      count += dfs(adj[node][i], adj, visited);
    }
  }
  return count;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut)
{
  vector<vector<int>> adj(n);
  for (int i = 0; i < astronaut.size(); i++)
  {
    adj[astronaut[i][0]].push_back(astronaut[i][1]);
    adj[astronaut[i][1]].push_back(astronaut[i][0]);
  }
  vector<bool> visited(n, false);
  vector<int> countries;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      countries.push_back(dfs(i, adj, visited));
    }
  }
  long long sum = 0;
  long long result = 0;
  for (int i = 0; i < countries.size(); i++)
  {
    result += sum * countries[i];
    sum += countries[i];
  }
  return result;
}

int main() {
  int n, p;
  cin >> n >> p;

  vector<vector<int>> astronaut(p, vector<int>(2));

  for (int i = 0; i < p; i++) {
    cin >> astronaut[i][0] >> astronaut[i][1];
  }

  long long result = journeyToMoon(n, astronaut);

  cout << result << endl;

  return 0;
}