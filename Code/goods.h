#include "request.h"

class Goods{
public:
	Goods(string name,float prices,double goodscount):goodsname(name),price(prices),count(goodscount){}
	double Pass_Count();
	string Pass_GoodsName();
	float Pass_Price();
	bool Check_Counts(double x);
	bool End_Of_Counts(double goods_counts);
	bool Rise_Number_Of_Sales();
	bool Check_Sales();
	void Sale_Goods();
	void Special_Sale(double goods_counts);
	void Special_Sale_Off(double goods_counts);
	void Check_Best_Seller_Goods();
	bool Best_Seller();
protected:
	string goodsname;
	double count;
	float price;
	bool discount=false;//discount
	int discountnum=0;//discount numbers
	double discountedcount=0;
	bool bestseller=false;
	int bestsellernum=0;
};