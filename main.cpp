#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol356;

/*
  Example 1:
 Given points = [[1,1],[-1,1]], return true.
*/
tuple<vector<pair<int, int>>, bool> testFixture1()
{
  return make_tuple(vector<pair<int, int>>{{1, 1}, {-1, 1}}, true);
}

/*
 Example 2:
 Given points = [[1,1],[-1,-1]], return false.
*/
tuple<vector<pair<int, int>>, bool> testFixture2()
{
  return make_tuple(vector<pair<int, int>>{{1, 1}, {-1, -1}}, false);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;
  cout << to_string(sol.exists(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Test 2 - expect to see " << to_string(get<1>(f)) << endl;
  cout << to_string(sol.exists(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}