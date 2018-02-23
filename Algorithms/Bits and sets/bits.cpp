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
