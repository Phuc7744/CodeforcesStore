#include <iostream>
using namespace std;

int checkType(string);
string convert1(string);
void convert2(string);
void colStrToNum(string);
string colNumToStr(int);

int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		string str;
		cin>>str;
		if(checkType(str)==1) convert1(str);
		else if (checkType(str)==2) convert2(str);
	}
	return 0;
}

int checkType(string str) {
	//check for the type need to convert to
	//return 1 for RxCy to ABXX, 2 is the other one
	
	//First case: first character alaway aplabet => not 'R' return the 2
	if(str[0]!='R') return 2;
	else {
		//The second character is alphabet, return 2
		if(str[1]<='Z' && str[1]>='A') return 2;
		//If it is int 
		else {
			//Check for the whole string if it have another alphabet, return 2
			for(int j=2; j<str.length(); j++) {
				if (str[j]<='Z' && str[j]>'A') {
					return 1;
				}
			}
			return 2;
		}
	}
}

//use ascii code to convert
//'A' has ascii is 065 and the 'Z' has ascii code is 090

string convert1(string str) {
	int row=0, col=0;
	
	//split to collumn and row
	for (int i=1; i<str.length(); i++) {
		if (str[i]=='C') {
			//minus for 48 because in the ascii code , '0' begin at 48
			for (int j=1; j<i; j++) row = row*10 + ((int)str[j]-48);
			for (int j=i+1; j<str.length(); j++) col = col*10 + ((int)str[j]-48);
			break;
		}	
	}
	
	string result = colNumToStr(col) + row;
	return result;
}


void convert2(string str) {
	int row=0;
	string col="";
	
	//split to collumn and row
	for (int i=0; i<str.length(); i++) {
		if (str[i]<='9' && str[i]>='0') {
			for (int j=0; j<i; j++) col+=str[j];
			for (int j=i; j<str.length(); j++) row = row*10 + ((int)str[j]-48);
			break;
		}
	}

}

void colStrToNum(string str) {
	
}

string colNumToStr(int num) {
	string result;
	
}

