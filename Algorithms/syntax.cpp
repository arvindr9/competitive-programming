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

//Converting from int to string

int n = 1;
string result;
ostringstream oss;
oss << n;
result = oss.str();

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
