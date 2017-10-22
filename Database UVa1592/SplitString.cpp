#include"SplitString.h"
#include<string>
#include<vector>

using namespace std;

vector<string> splitString(const string &str, const string sep) {
	vector<string> v;
	string::size_type pos1 = 0;
	string::size_type pos2 = str.find(sep);
	while (string::npos != pos2) {
		v.push_back(str.substr(pos1, pos2 - pos1));
		pos1 = pos2 + sep.length();
		pos2 = str.find(sep, pos1);
	}
	v.push_back(str.substr(pos1));	// Ñ¹×îºóÒ»×é£¬Ô´×Ö·û´®Îª¿Õ×Ö·û´®Ñ¹¿Õ´®£¬·Ö¸ô·ûÔÚÄ©Î²Ñ¹¿Õ´®
	return v;
}