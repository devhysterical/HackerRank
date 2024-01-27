/**
 * @file timeConversion.cpp
 * @author Kiet Lam Tuan (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 * @link https://www.hackerrank.com/domains/algorithms?filters%5Bstatus%5D%5B%5D=unsolved&badge_type=problem-solving
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
  string hour = s.substr(0, 2);
  string minute = s.substr(3, 2);
  string second = s.substr(6, 2);
  string ampm = s.substr(8, 2);
  if (ampm == "PM")
  {
    if (hour != "12")
    {
      hour = to_string(stoi(hour) + 12);
    }
  }
  else
  {
    if (hour == "12")
    {
      hour = "00";
    }
  }
  return hour + ":" + minute + ":" + second;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
