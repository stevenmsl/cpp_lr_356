#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
using namespace sol356;
using namespace std;

/*takeaways
  - we need to do better than O(n^2)
  - create a map to group together the coordinates that
    have the same x and different y values
  - since the points are reflecting along a line
    that is parallel to y-axis so for every
    (x1,y1) we can find (x2, y2) where y1=y2
    and distance(x1,midpoint)=distance(x2,midpoint)
  - to simply the process of checking if a counter
    part of a given point exist we can do the following:
    - find the minimum (xmin) and maximum (xmax) of the
      x-coordinates among all the points
    - given an point (x,y) and its reflected counter part
      (xr,y). The distance from the xmax to one of the
      point's x should be the same as the distance from
      the other point's x to xmin
      xmax - x = xr - xmin => xr = xmax + xmin - x
      where (xmax - x) >= 0 and (xr - xmin) >= 0
      by definition
    - the other way around is the same:
      xmax - xr = x - xmin => xr = xmax + xmin - x
      where (xmax - xr) >= 0 and (x - xmin) >= 0
      by definition

*/
bool Solution::exists(vector<pair<int, int>> &points)
{
  /* coordinates wit same x but different y's
     - you can do it the other way around. Just
       have to adjust the logic accordingly
  */
  auto xys = unordered_map<int, set<int>>();
  int xmin = INT_MAX, xmax = INT_MIN;
  /* find the min and max of x coordinate
     among points
  */
  for (auto &[x, y] : points)
  {
    xmin = min(xmin, x), xmax = max(xmax, x);
    xys[x].insert(y);
  }

  for (auto &[x, y] : points)
  {
    /* x coordinate of reflected point */
    auto xr = (xmax - x) + xmin;
    /* the y needs to be the same as the
       point we are examining right now
    */
    if (!xys.count(xr) || !xys[xr].count(y))
      return false;
  }

  return true;
}