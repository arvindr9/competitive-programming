/**
 * Bitwise operations
 * **/

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19 zeroes at the beginning of the number
cout << __builtin_ctz(x) << "\n"; // 4 zeroes at the end of the number
cout << __builtin_popcount(x) << "\n"; // 5 ones
cout << __builtin_parity(x) << "\n"; // 1

//Append ll to the end for this to apply to long longs.

// Set operations:
// a & b: intersection
// a | b: union
// ~a: complement
// a & (~b): difference

//ordered set

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

indexed_set s;
s.insert(2);
s.insert(3);
s.insert(7);
s.insert(9);

auto x = s.find_by_order(2);
cout << *x << "\n"; // 7

//And the function order_of_key returns the position of a given element:

cout << s.order_of_key(7) << "\n"; // 2

//If the element does not appear in the set, we get the position that the element
//would have in the set:

cout << s.order_of_key(6) << "\n"; // 2
cout << s.order_of_key(8) << "\n"; // 3

//Converting from int to string

int n = 1;
string result;
ostringstream oss;
oss << n;
result = oss.str();

// or simply:
result = to_string(n);


//string to int

string text = "456";
int num;
istringstream iss(text);
if(!(iss >> num)) {
    num = 0;
}

//Process words from a line (useful when the length of a line is not specified beforehand)
string s;
getline(cin, s);
stringstream ss;
ss << s;
string s2;
while(ss >> s2) {
    //process s2
}

//randomization (source: https://codeforces.com/blog/entry/61587)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> distrib1(1, n);
int x = distrib1(rng);
//can change to mt19937_64 for long longs



// pragmas:
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
