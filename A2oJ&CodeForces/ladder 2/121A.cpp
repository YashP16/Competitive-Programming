#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
using namespace std;
ll luckyNum[2046]={ 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477, 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747, 77774, 77777, 444444, 444447, 444474, 444477, 444744, 444747, 444774, 444777, 447444, 447447, 447474, 447477, 447744, 447747, 447774, 447777, 474444, 474447, 474474, 474477, 474744, 474747, 474774, 474777, 477444, 477447, 477474, 477477, 477744, 477747, 477774, 477777, 744444, 744447, 744474, 744477, 744744, 744747, 744774, 744777, 747444, 747447, 747474, 747477, 747744, 747747, 747774, 747777, 774444, 774447, 774474, 774477, 774744, 774747, 774774, 774777, 777444, 777447, 777474, 777477, 777744, 777747, 777774, 777777, 4444444, 4444447, 4444474, 4444477, 4444744, 4444747, 4444774, 4444777, 4447444, 4447447, 4447474, 4447477, 4447744, 4447747, 4447774, 4447777, 4474444, 4474447, 4474474, 4474477, 4474744, 4474747, 4474774, 4474777, 4477444, 4477447, 4477474, 4477477, 4477744, 4477747, 4477774, 4477777, 4744444, 4744447, 4744474, 4744477, 4744744, 4744747, 4744774, 4744777, 4747444, 4747447, 4747474, 4747477, 4747744, 4747747, 4747774, 4747777, 4774444, 4774447, 4774474, 4774477, 4774744, 4774747, 4774774, 4774777, 4777444, 4777447, 4777474, 4777477, 4777744, 4777747, 4777774, 4777777, 7444444, 7444447, 7444474, 7444477, 7444744, 7444747, 7444774, 7444777, 7447444, 7447447, 7447474, 7447477, 7447744, 7447747, 7447774, 7447777, 7474444, 7474447, 7474474, 7474477, 7474744, 7474747, 7474774, 7474777, 7477444, 7477447, 7477474, 7477477, 7477744, 7477747, 7477774, 7477777, 7744444, 7744447, 7744474, 7744477, 7744744, 7744747, 7744774, 7744777, 7747444, 7747447, 7747474, 7747477, 7747744, 7747747, 7747774, 7747777, 7774444, 7774447, 7774474, 7774477, 7774744, 7774747, 7774774, 7774777, 7777444, 7777447, 7777474, 7777477, 7777744, 7777747, 7777774, 7777777, 44444444, 44444447, 44444474, 44444477, 44444744, 44444747, 44444774, 44444777, 44447444, 44447447, 44447474, 44447477, 44447744, 44447747, 44447774, 44447777, 44474444, 44474447, 44474474, 44474477, 44474744, 44474747, 44474774, 44474777, 44477444, 44477447, 44477474, 44477477, 44477744, 44477747, 44477774, 44477777, 44744444, 44744447, 44744474, 44744477, 44744744, 44744747, 44744774, 44744777, 44747444, 44747447, 44747474, 44747477, 44747744, 44747747, 44747774, 44747777, 44774444, 44774447, 44774474, 44774477, 44774744, 44774747, 44774774, 44774777, 44777444, 44777447, 44777474, 44777477, 44777744, 44777747, 44777774, 44777777, 47444444, 47444447, 47444474, 47444477, 47444744, 47444747, 47444774, 47444777, 47447444, 47447447, 47447474, 47447477, 47447744, 47447747, 47447774, 47447777, 47474444, 47474447, 47474474, 47474477, 47474744, 47474747, 47474774, 47474777, 47477444, 47477447, 47477474, 47477477, 47477744, 47477747, 47477774, 47477777, 47744444, 47744447, 47744474, 47744477, 47744744, 47744747, 47744774, 47744777, 47747444, 47747447, 47747474, 47747477, 47747744, 47747747, 47747774, 47747777, 47774444, 47774447, 47774474, 47774477, 47774744, 47774747, 47774774, 47774777, 47777444, 47777447, 47777474, 47777477, 47777744, 47777747, 47777774, 47777777, 74444444, 74444447, 74444474, 74444477, 74444744, 74444747, 74444774, 74444777, 74447444, 74447447, 74447474, 74447477, 74447744, 74447747, 74447774, 74447777, 74474444, 74474447, 74474474, 74474477, 74474744, 74474747, 74474774, 74474777, 74477444, 74477447, 74477474, 74477477, 74477744, 74477747, 74477774, 74477777, 74744444, 74744447, 74744474, 74744477, 74744744, 74744747, 74744774, 74744777, 74747444, 74747447, 74747474, 74747477, 74747744, 74747747, 74747774, 74747777, 74774444, 74774447, 74774474, 74774477, 74774744, 74774747, 74774774, 74774777, 74777444, 74777447, 74777474, 74777477, 74777744, 74777747, 74777774, 74777777, 77444444, 77444447, 77444474, 77444477, 77444744, 77444747, 77444774, 77444777, 77447444, 77447447, 77447474, 77447477, 77447744, 77447747, 77447774, 77447777, 77474444, 77474447, 77474474, 77474477, 77474744, 77474747, 77474774, 77474777, 77477444, 77477447, 77477474, 77477477, 77477744, 77477747, 77477774, 77477777, 77744444, 77744447, 77744474, 77744477, 77744744, 77744747, 77744774, 77744777, 77747444, 77747447, 77747474, 77747477, 77747744, 77747747, 77747774, 77747777, 77774444, 77774447, 77774474, 77774477, 77774744, 77774747, 77774774, 77774777, 77777444, 77777447, 77777474, 77777477, 77777744, 77777747, 77777774, 77777777, 444444444, 444444447, 444444474, 444444477, 444444744, 444444747, 444444774, 444444777, 444447444, 444447447, 444447474, 444447477, 444447744, 444447747, 444447774, 444447777, 444474444, 444474447, 444474474, 444474477, 444474744, 444474747, 444474774, 444474777, 444477444, 444477447, 444477474, 444477477, 444477744, 444477747, 444477774, 444477777, 444744444, 444744447, 444744474, 444744477, 444744744, 444744747, 444744774, 444744777, 444747444, 444747447, 444747474, 444747477, 444747744, 444747747, 444747774, 444747777, 444774444, 444774447, 444774474, 444774477, 444774744, 444774747, 444774774, 444774777, 444777444, 444777447, 444777474, 444777477, 444777744, 444777747, 444777774, 444777777, 447444444, 447444447, 447444474, 447444477, 447444744, 447444747, 447444774, 447444777, 447447444, 447447447, 447447474, 447447477, 447447744, 447447747, 447447774, 447447777, 447474444, 447474447, 447474474, 447474477, 447474744, 447474747, 447474774, 447474777, 447477444, 447477447, 447477474, 447477477, 447477744, 447477747, 447477774, 447477777, 447744444, 447744447, 447744474, 447744477, 447744744, 447744747, 447744774, 447744777, 447747444, 447747447, 447747474, 447747477, 447747744, 447747747, 447747774, 447747777, 447774444, 447774447, 447774474, 447774477, 447774744, 447774747, 447774774, 447774777, 447777444, 447777447, 447777474, 447777477, 447777744, 447777747, 447777774, 447777777, 474444444, 474444447, 474444474, 474444477, 474444744, 474444747, 474444774, 474444777, 474447444, 474447447, 474447474, 474447477, 474447744, 474447747, 474447774, 474447777, 474474444, 474474447, 474474474, 474474477, 474474744, 474474747, 474474774, 474474777, 474477444, 474477447, 474477474, 474477477, 474477744, 474477747, 474477774, 474477777, 474744444, 474744447, 474744474, 474744477, 474744744, 474744747, 474744774, 474744777, 474747444, 474747447, 474747474, 474747477, 474747744, 474747747, 474747774, 474747777, 474774444, 474774447, 474774474, 474774477, 474774744, 474774747, 474774774, 474774777, 474777444, 474777447, 474777474, 474777477, 474777744, 474777747, 474777774, 474777777, 477444444, 477444447, 477444474, 477444477, 477444744, 477444747, 477444774, 477444777, 477447444, 477447447, 477447474, 477447477, 477447744, 477447747, 477447774, 477447777, 477474444, 477474447, 477474474, 477474477, 477474744, 477474747, 477474774, 477474777, 477477444, 477477447, 477477474, 477477477, 477477744, 477477747, 477477774, 477477777, 477744444, 477744447, 477744474, 477744477, 477744744, 477744747, 477744774, 477744777, 477747444, 477747447, 477747474, 477747477, 477747744, 477747747, 477747774, 477747777, 477774444, 477774447, 477774474, 477774477, 477774744, 477774747, 477774774, 477774777, 477777444, 477777447, 477777474, 477777477, 477777744, 477777747, 477777774, 477777777, 744444444, 744444447, 744444474, 744444477, 744444744, 744444747, 744444774, 744444777, 744447444, 744447447, 744447474, 744447477, 744447744, 744447747, 744447774, 744447777, 744474444, 744474447, 744474474, 744474477, 744474744, 744474747, 744474774, 744474777, 744477444, 744477447, 744477474, 744477477, 744477744, 744477747, 744477774, 744477777, 744744444, 744744447, 744744474, 744744477, 744744744, 744744747, 744744774, 744744777, 744747444, 744747447, 744747474, 744747477, 744747744, 744747747, 744747774, 744747777, 744774444, 744774447, 744774474, 744774477, 744774744, 744774747, 744774774, 744774777, 744777444, 744777447, 744777474, 744777477, 744777744, 744777747, 744777774, 744777777, 747444444, 747444447, 747444474, 747444477, 747444744, 747444747, 747444774, 747444777, 747447444, 747447447, 747447474, 747447477, 747447744, 747447747, 747447774, 747447777, 747474444, 747474447, 747474474, 747474477, 747474744, 747474747, 747474774, 747474777, 747477444, 747477447, 747477474, 747477477, 747477744, 747477747, 747477774, 747477777, 747744444, 747744447, 747744474, 747744477, 747744744, 747744747, 747744774, 747744777, 747747444, 747747447, 747747474, 747747477, 747747744, 747747747, 747747774, 747747777, 747774444, 747774447, 747774474, 747774477, 747774744, 747774747, 747774774, 747774777, 747777444, 747777447, 747777474, 747777477, 747777744, 747777747, 747777774, 747777777, 774444444, 774444447, 774444474, 774444477, 774444744, 774444747, 774444774, 774444777, 774447444, 774447447, 774447474, 774447477, 774447744, 774447747, 774447774, 774447777, 774474444, 774474447, 774474474, 774474477, 774474744, 774474747, 774474774, 774474777, 774477444, 774477447, 774477474, 774477477, 774477744, 774477747, 774477774, 774477777, 774744444, 774744447, 774744474, 774744477, 774744744, 774744747, 774744774, 774744777, 774747444, 774747447, 774747474, 774747477, 774747744, 774747747, 774747774, 774747777, 774774444, 774774447, 774774474, 774774477, 774774744, 774774747, 774774774, 774774777, 774777444, 774777447, 774777474, 774777477, 774777744, 774777747, 774777774, 774777777, 777444444, 777444447, 777444474, 777444477, 777444744, 777444747, 777444774, 777444777, 777447444, 777447447, 777447474, 777447477, 777447744, 777447747, 777447774, 777447777, 777474444, 777474447, 777474474, 777474477, 777474744, 777474747, 777474774, 777474777, 777477444, 777477447, 777477474, 777477477, 777477744, 777477747, 777477774, 777477777, 777744444, 777744447, 777744474, 777744477, 777744744, 777744747, 777744774, 777744777, 777747444, 777747447, 777747474, 777747477, 777747744, 777747747, 777747774, 777747777, 777774444, 777774447, 777774474, 777774477, 777774744, 777774747, 777774774, 777774777, 777777444, 777777447, 777777474, 777777477, 777777744, 777777747, 777777774, 777777777, 4444444444, 4444444447, 4444444474, 4444444477, 4444444744, 4444444747, 4444444774, 4444444777, 4444447444, 4444447447, 4444447474, 4444447477, 4444447744, 4444447747, 4444447774, 4444447777, 4444474444, 4444474447, 4444474474, 4444474477, 4444474744, 4444474747, 4444474774, 4444474777, 4444477444, 4444477447, 4444477474, 4444477477, 4444477744, 4444477747, 4444477774, 4444477777, 4444744444, 4444744447, 4444744474, 4444744477, 4444744744, 4444744747, 4444744774, 4444744777, 4444747444, 4444747447, 4444747474, 4444747477, 4444747744, 4444747747, 4444747774, 4444747777, 4444774444, 4444774447, 4444774474, 4444774477, 4444774744, 4444774747, 4444774774, 4444774777, 4444777444, 4444777447, 4444777474, 4444777477, 4444777744, 4444777747, 4444777774, 4444777777, 4447444444, 4447444447, 4447444474, 4447444477, 4447444744, 4447444747, 4447444774, 4447444777, 4447447444, 4447447447, 4447447474, 4447447477, 4447447744, 4447447747, 4447447774, 4447447777, 4447474444, 4447474447, 4447474474, 4447474477, 4447474744, 4447474747, 4447474774, 4447474777, 4447477444, 4447477447, 4447477474, 4447477477, 4447477744, 4447477747, 4447477774, 4447477777, 4447744444, 4447744447, 4447744474, 4447744477, 4447744744, 4447744747, 4447744774, 4447744777, 4447747444, 4447747447, 4447747474, 4447747477, 4447747744, 4447747747, 4447747774, 4447747777, 4447774444, 4447774447, 4447774474, 4447774477, 4447774744, 4447774747, 4447774774, 4447774777, 4447777444, 4447777447, 4447777474, 4447777477, 4447777744, 4447777747, 4447777774, 4447777777, 4474444444, 4474444447, 4474444474, 4474444477, 4474444744, 4474444747, 4474444774, 4474444777, 4474447444, 4474447447, 4474447474, 4474447477, 4474447744, 4474447747, 4474447774, 4474447777, 4474474444, 4474474447, 4474474474, 4474474477, 4474474744, 4474474747, 4474474774, 4474474777, 4474477444, 4474477447, 4474477474, 4474477477, 4474477744, 4474477747, 4474477774, 4474477777, 4474744444, 4474744447, 4474744474, 4474744477, 4474744744, 4474744747, 4474744774, 4474744777, 4474747444, 4474747447, 4474747474, 4474747477, 4474747744, 4474747747, 4474747774, 4474747777, 4474774444, 4474774447, 4474774474, 4474774477, 4474774744, 4474774747, 4474774774, 4474774777, 4474777444, 4474777447, 4474777474, 4474777477, 4474777744, 4474777747, 4474777774, 4474777777, 4477444444, 4477444447, 4477444474, 4477444477, 4477444744, 4477444747, 4477444774, 4477444777, 4477447444, 4477447447, 4477447474, 4477447477, 4477447744, 4477447747, 4477447774, 4477447777, 4477474444, 4477474447, 4477474474, 4477474477, 4477474744, 4477474747, 4477474774, 4477474777, 4477477444, 4477477447, 4477477474, 4477477477, 4477477744, 4477477747, 4477477774, 4477477777, 4477744444, 4477744447, 4477744474, 4477744477, 4477744744, 4477744747, 4477744774, 4477744777, 4477747444, 4477747447, 4477747474, 4477747477, 4477747744, 4477747747, 4477747774, 4477747777, 4477774444, 4477774447, 4477774474, 4477774477, 4477774744, 4477774747, 4477774774, 4477774777, 4477777444, 4477777447, 4477777474, 4477777477, 4477777744, 4477777747, 4477777774, 4477777777, 4744444444, 4744444447, 4744444474, 4744444477, 4744444744, 4744444747, 4744444774, 4744444777, 4744447444, 4744447447, 4744447474, 4744447477, 4744447744, 4744447747, 4744447774, 4744447777, 4744474444, 4744474447, 4744474474, 4744474477, 4744474744, 4744474747, 4744474774, 4744474777, 4744477444, 4744477447, 4744477474, 4744477477, 4744477744, 4744477747, 4744477774, 4744477777, 4744744444, 4744744447, 4744744474, 4744744477, 4744744744, 4744744747, 4744744774, 4744744777, 4744747444, 4744747447, 4744747474, 4744747477, 4744747744, 4744747747, 4744747774, 4744747777, 4744774444, 4744774447, 4744774474, 4744774477, 4744774744, 4744774747, 4744774774, 4744774777, 4744777444, 4744777447, 4744777474, 4744777477, 4744777744, 4744777747, 4744777774, 4744777777, 4747444444, 4747444447, 4747444474, 4747444477, 4747444744, 4747444747, 4747444774, 4747444777, 4747447444, 4747447447, 4747447474, 4747447477, 4747447744, 4747447747, 4747447774, 4747447777, 4747474444, 4747474447, 4747474474, 4747474477, 4747474744, 4747474747, 4747474774, 4747474777, 4747477444, 4747477447, 4747477474, 4747477477, 4747477744, 4747477747, 4747477774, 4747477777, 4747744444, 4747744447, 4747744474, 4747744477, 4747744744, 4747744747, 4747744774, 4747744777, 4747747444, 4747747447, 4747747474, 4747747477, 4747747744, 4747747747, 4747747774, 4747747777, 4747774444, 4747774447, 4747774474, 4747774477, 4747774744, 4747774747, 4747774774, 4747774777, 4747777444, 4747777447, 4747777474, 4747777477, 4747777744, 4747777747, 4747777774, 4747777777, 4774444444, 4774444447, 4774444474, 4774444477, 4774444744, 4774444747, 4774444774, 4774444777, 4774447444, 4774447447, 4774447474, 4774447477, 4774447744, 4774447747, 4774447774, 4774447777, 4774474444, 4774474447, 4774474474, 4774474477, 4774474744, 4774474747, 4774474774, 4774474777, 4774477444, 4774477447, 4774477474, 4774477477, 4774477744, 4774477747, 4774477774, 4774477777, 4774744444, 4774744447, 4774744474, 4774744477, 4774744744, 4774744747, 4774744774, 4774744777, 4774747444, 4774747447, 4774747474, 4774747477, 4774747744, 4774747747, 4774747774, 4774747777, 4774774444, 4774774447, 4774774474, 4774774477, 4774774744, 4774774747, 4774774774, 4774774777, 4774777444, 4774777447, 4774777474, 4774777477, 4774777744, 4774777747, 4774777774, 4774777777, 4777444444, 4777444447, 4777444474, 4777444477, 4777444744, 4777444747, 4777444774, 4777444777, 4777447444, 4777447447, 4777447474, 4777447477, 4777447744, 4777447747, 4777447774, 4777447777, 4777474444, 4777474447, 4777474474, 4777474477, 4777474744, 4777474747, 4777474774, 4777474777, 4777477444, 4777477447, 4777477474, 4777477477, 4777477744, 4777477747, 4777477774, 4777477777, 4777744444, 4777744447, 4777744474, 4777744477, 4777744744, 4777744747, 4777744774, 4777744777, 4777747444, 4777747447, 4777747474, 4777747477, 4777747744, 4777747747, 4777747774, 4777747777, 4777774444, 4777774447, 4777774474, 4777774477, 4777774744, 4777774747, 4777774774, 4777774777, 4777777444, 4777777447, 4777777474, 4777777477, 4777777744, 4777777747, 4777777774, 4777777777, 7444444444, 7444444447, 7444444474, 7444444477, 7444444744, 7444444747, 7444444774, 7444444777, 7444447444, 7444447447, 7444447474, 7444447477, 7444447744, 7444447747, 7444447774, 7444447777, 7444474444, 7444474447, 7444474474, 7444474477, 7444474744, 7444474747, 7444474774, 7444474777, 7444477444, 7444477447, 7444477474, 7444477477, 7444477744, 7444477747, 7444477774, 7444477777, 7444744444, 7444744447, 7444744474, 7444744477, 7444744744, 7444744747, 7444744774, 7444744777, 7444747444, 7444747447, 7444747474, 7444747477, 7444747744, 7444747747, 7444747774, 7444747777, 7444774444, 7444774447, 7444774474, 7444774477, 7444774744, 7444774747, 7444774774, 7444774777, 7444777444, 7444777447, 7444777474, 7444777477, 7444777744, 7444777747, 7444777774, 7444777777, 7447444444, 7447444447, 7447444474, 7447444477, 7447444744, 7447444747, 7447444774, 7447444777, 7447447444, 7447447447, 7447447474, 7447447477, 7447447744, 7447447747, 7447447774, 7447447777, 7447474444, 7447474447, 7447474474, 7447474477, 7447474744, 7447474747, 7447474774, 7447474777, 7447477444, 7447477447, 7447477474, 7447477477, 7447477744, 7447477747, 7447477774, 7447477777, 7447744444, 7447744447, 7447744474, 7447744477, 7447744744, 7447744747, 7447744774, 7447744777, 7447747444, 7447747447, 7447747474, 7447747477, 7447747744, 7447747747, 7447747774, 7447747777, 7447774444, 7447774447, 7447774474, 7447774477, 7447774744, 7447774747, 7447774774, 7447774777, 7447777444, 7447777447, 7447777474, 7447777477, 7447777744, 7447777747, 7447777774, 7447777777, 7474444444, 7474444447, 7474444474, 7474444477, 7474444744, 7474444747, 7474444774, 7474444777, 7474447444, 7474447447, 7474447474, 7474447477, 7474447744, 7474447747, 7474447774, 7474447777, 7474474444, 7474474447, 7474474474, 7474474477, 7474474744, 7474474747, 7474474774, 7474474777, 7474477444, 7474477447, 7474477474, 7474477477, 7474477744, 7474477747, 7474477774, 7474477777, 7474744444, 7474744447, 7474744474, 7474744477, 7474744744, 7474744747, 7474744774, 7474744777, 7474747444, 7474747447, 7474747474, 7474747477, 7474747744, 7474747747, 7474747774, 7474747777, 7474774444, 7474774447, 7474774474, 7474774477, 7474774744, 7474774747, 7474774774, 7474774777, 7474777444, 7474777447, 7474777474, 7474777477, 7474777744, 7474777747, 7474777774, 7474777777, 7477444444, 7477444447, 7477444474, 7477444477, 7477444744, 7477444747, 7477444774, 7477444777, 7477447444, 7477447447, 7477447474, 7477447477, 7477447744, 7477447747, 7477447774, 7477447777, 7477474444, 7477474447, 7477474474, 7477474477, 7477474744, 7477474747, 7477474774, 7477474777, 7477477444, 7477477447, 7477477474, 7477477477, 7477477744, 7477477747, 7477477774, 7477477777, 7477744444, 7477744447, 7477744474, 7477744477, 7477744744, 7477744747, 7477744774, 7477744777, 7477747444, 7477747447, 7477747474, 7477747477, 7477747744, 7477747747, 7477747774, 7477747777, 7477774444, 7477774447, 7477774474, 7477774477, 7477774744, 7477774747, 7477774774, 7477774777, 7477777444, 7477777447, 7477777474, 7477777477, 7477777744, 7477777747, 7477777774, 7477777777, 7744444444, 7744444447, 7744444474, 7744444477, 7744444744, 7744444747, 7744444774, 7744444777, 7744447444, 7744447447, 7744447474, 7744447477, 7744447744, 7744447747, 7744447774, 7744447777, 7744474444, 7744474447, 7744474474, 7744474477, 7744474744, 7744474747, 7744474774, 7744474777, 7744477444, 7744477447, 7744477474, 7744477477, 7744477744, 7744477747, 7744477774, 7744477777, 7744744444, 7744744447, 7744744474, 7744744477, 7744744744, 7744744747, 7744744774, 7744744777, 7744747444, 7744747447, 7744747474, 7744747477, 7744747744, 7744747747, 7744747774, 7744747777, 7744774444, 7744774447, 7744774474, 7744774477, 7744774744, 7744774747, 7744774774, 7744774777, 7744777444, 7744777447, 7744777474, 7744777477, 7744777744, 7744777747, 7744777774, 7744777777, 7747444444, 7747444447, 7747444474, 7747444477, 7747444744, 7747444747, 7747444774, 7747444777, 7747447444, 7747447447, 7747447474, 7747447477, 7747447744, 7747447747, 7747447774, 7747447777, 7747474444, 7747474447, 7747474474, 7747474477, 7747474744, 7747474747, 7747474774, 7747474777, 7747477444, 7747477447, 7747477474, 7747477477, 7747477744, 7747477747, 7747477774, 7747477777, 7747744444, 7747744447, 7747744474, 7747744477, 7747744744, 7747744747, 7747744774, 7747744777, 7747747444, 7747747447, 7747747474, 7747747477, 7747747744, 7747747747, 7747747774, 7747747777, 7747774444, 7747774447, 7747774474, 7747774477, 7747774744, 7747774747, 7747774774, 7747774777, 7747777444, 7747777447, 7747777474, 7747777477, 7747777744, 7747777747, 7747777774, 7747777777, 7774444444, 7774444447, 7774444474, 7774444477, 7774444744, 7774444747, 7774444774, 7774444777, 7774447444, 7774447447, 7774447474, 7774447477, 7774447744, 7774447747, 7774447774, 7774447777, 7774474444, 7774474447, 7774474474, 7774474477, 7774474744, 7774474747, 7774474774, 7774474777, 7774477444, 7774477447, 7774477474, 7774477477, 7774477744, 7774477747, 7774477774, 7774477777, 7774744444, 7774744447, 7774744474, 7774744477, 7774744744, 7774744747, 7774744774, 7774744777, 7774747444, 7774747447, 7774747474, 7774747477, 7774747744, 7774747747, 7774747774, 7774747777, 7774774444, 7774774447, 7774774474, 7774774477, 7774774744, 7774774747, 7774774774, 7774774777, 7774777444, 7774777447, 7774777474, 7774777477, 7774777744, 7774777747, 7774777774, 7774777777, 7777444444, 7777444447, 7777444474, 7777444477, 7777444744, 7777444747, 7777444774, 7777444777, 7777447444, 7777447447, 7777447474, 7777447477, 7777447744, 7777447747, 7777447774, 7777447777, 7777474444, 7777474447, 7777474474, 7777474477, 7777474744, 7777474747, 7777474774, 7777474777, 7777477444, 7777477447, 7777477474, 7777477477, 7777477744, 7777477747, 7777477774, 7777477777, 7777744444, 7777744447, 7777744474, 7777744477, 7777744744, 7777744747, 7777744774, 7777744777, 7777747444, 7777747447, 7777747474, 7777747477, 7777747744, 7777747747, 7777747774, 7777747777, 7777774444, 7777774447, 7777774474, 7777774477, 7777774744, 7777774747, 7777774774, 7777774777, 7777777444, 7777777447, 7777777474, 7777777477, 7777777744, 7777777747, 7777777774, 7777777777 };
int main(){
	ui l,r;
	cin >> l >> r;
	ui i = l;
	int pointer = 0;
	ll sum =0;
	while(i<=r){
		if(i <= luckyNum[pointer]){
			if(r>=luckyNum[pointer]){
				sum += (luckyNum[pointer]-i+1)*luckyNum[pointer];
				i =luckyNum[pointer]+1;
			} 
			else{ 
				sum+=(r-i+1)*luckyNum[pointer];
				break;
			}
		}
		else {
			pointer++;
		}
	}
	cout << sum;
	return 0;
}