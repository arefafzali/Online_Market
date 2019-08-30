#include "buyer.h"

class Stores{
public:
	void Add_User(vector<Buyer>& buyers,vector<Seller>& sellers);
	void Add_Goods(vector<Seller>& sellers,vector<Goods>& othergoods);
	void Search(vector<Seller>& sellers);
	void Buy(vector<Buyer>& buyers,vector<Seller>& sellers, int& c);
	void Discount(vector<Buyer>& buyers,vector<Seller>& sellers);
	void Add_Money(vector<Buyer>& buyers);
	void Add_Special(vector<Seller>& sellers);
	void Remove_Special(vector<Seller>& sellers);
	void Search_Best_Seller(vector<Seller>& sellers);
	void Search_Sale(vector<Seller>& sellers);
	void Print_Factor(vector<Buyer>& buyers);
	void Check_Best_Seller_Store(vector<Seller>& sellers);
	void Requests(vector<Request>& requests);
};
