#include "factor.h"


class Buyer{
public:
	Buyer(string fname,string lname,string uname,string pnumber,float moneys):
		firstname(fname), lastname(lname), username(uname), phonenumber(pnumber), money(moneys){}
	bool Buyer_Tekrari(string name);
	void Buying_Prosess(bool& failed,vector<Seller>& sellers,int& n);
	void Set_Discount_Goods(vector<Seller>& sellers,string goods_name,string seller_username);
	string Pass_Username(){return username;}
	void Add_Money();
	void Print_Factor();
protected:
	string firstname;
	string lastname;
	string username;
	string phonenumber;
	float money;
	vector<Goods> salesgoods;
	vector<Factor> factors;
};