//Converting from int to string

int n = 1;
string result;
ostringstream oss;
oss << n;
result = oss.str();

//Int to string

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
