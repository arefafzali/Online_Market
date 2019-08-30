//#ifndef Headers_H
//#define Headers_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

float storemoney=0;

struct buyingGoodsInfo{
	string goods_name;
	double goods_count;
	string seller_username;
};
struct requestInfo{
	string goods_name;
	double goods_count;
	string seller_username;
};

bool Check_Strings(string fname,string sname){
	if(fname.size()==sname.size()){
		for(int i=0;i<fname.size();i++){
			if(fname[i]!=sname[i])
				return false;
		}
		return true;
	}
	else
		return false;
}


//#endif