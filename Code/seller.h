#include "goods.h"

class Seller{
public:
	Seller(string fname,string lname,string uname,string pnumber,float moneys):
		firstname(fname), lastname(lname), username(uname), phonenumber(pnumber), money(moneys){}
	bool Seller_Tekrari(string name);
	void Set_Goods(Goods name);
	void Search_Goods(string name,double counts, int& c);
	string Pass_Username(){return username;}
	void Buying(double goods_counts,string goods_name, bool& failed,float& allmoney);
	bool Check_Sales(string goods_name);
	void Print_Buying_Factor(int& c,string goods_name,double goods_counts);
	void Add_Special(string goods_name,double goods_counts);
	void Remove_Special(string goods_name,double goods_counts);
	void Check_Best_Seller();
	void Search_Best_Seller(int& c);
	void Search_Sale(int& c);
protected:
	string firstname;
	string lastname;
	string username;
	string phonenumber;
	float money;
	vector<Goods> goods;
};