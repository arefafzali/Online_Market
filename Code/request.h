#include "header.h"


class Request{
public:
	Request(string requestname):request_name(requestname){}
	void Get_Info_Request();
	bool Check_Name_Request(string requestname);
	string Pass_Buyer_Username(){return buyer_username;}
protected:
	vector<requestInfo> requestinfo;
	string request_name;
	string buyer_username;
};
void Request::Get_Info_Request(){
	char x;
	cin>>buyer_username;
	do{
		requestInfo lineinfo;
		cin>>lineinfo.goods_name>>lineinfo.goods_count>>lineinfo.seller_username;
		x=lineinfo.seller_username[lineinfo.seller_username.size()-1];
		lineinfo.seller_username.erase(lineinfo.seller_username.size()-1);
		requestinfo.push_back(lineinfo);
	}while(x!=';');
}
bool Request::Check_Name_Request(string requestname){
	if(Check_Strings(requestname,request_name))
		return true;
	else
		return false;
}