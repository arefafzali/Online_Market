#include "store.h"

void Stores::Add_User(vector<Buyer>& buyers,vector<Seller>& sellers){
	float money;
	bool buyer_tekrari,seller_tekrari;
	string firstname,lastname,username,phonenumber,persontype;
	cin>>firstname>>lastname>>username>>phonenumber>>money>>persontype;
	for(int i=0;i<buyers.size();i++)
		buyer_tekrari=buyers[i].Buyer_Tekrari(username);
	for(int i=0;i<sellers.size();i++)
		seller_tekrari=sellers[i].Seller_Tekrari(username);
	if(!seller_tekrari && !buyer_tekrari){
		if(persontype=="buyer"){
			Buyer buyer(firstname,lastname,username,phonenumber,money);
			buyers.push_back(buyer);
			cout<<"Command OK"<<endl;
			for(int i=0;i<buyers.size();i++){

			}
		}
		else if(persontype=="seller"){
			Seller seller(firstname,lastname,username,phonenumber,money);
			sellers.push_back(seller);
			cout<<"Command OK"<<endl;
		}
	}
	else{
		cout<<"Command Failed"<<endl;
	}
}
void Stores::Add_Goods(vector<Seller>& sellers,vector<Goods>& othergoods){
	int c=1;
	bool tekrari=false;
	float goods_price;
	double goods_count;
	string name ,goods_name;
	cin>>name>>goods_name>>goods_price>>goods_count;
	for(int i=0;i<sellers.size();i++){
		if(sellers[i].Seller_Tekrari(name)){
			c=i;
			tekrari=true;
		}
	}
	if(tekrari){
		Goods goods(goods_name,goods_price,goods_count);
		othergoods.push_back(goods);
		sellers[c].Set_Goods(goods);
		cout<<"Command OK"<<endl;
	}
	else{
		cout<<"Command Failed"<<endl;
	}
}
void Stores::Search(vector<Seller>& sellers){
	string goods_name;
	int c=0;
	double goods_count;
	cin>>goods_name>>goods_count;
	for(int i=0;i<sellers.size();i++){
		sellers[i].Search_Goods(goods_name,goods_count,c);
	}
}
void Stores::Buy(vector<Buyer>& buyers,vector<Seller>& sellers, int& c){
	string buyerusername;
	bool tekrari=false,failed=false;
	int x;
	cin>>buyerusername;
	for(int i=0;i<buyers.size();i++){
		if(buyers[i].Buyer_Tekrari(buyerusername)){
			x=i;
			tekrari=true;
		}
	}
	if(tekrari){
		buyers[x].Buying_Prosess(failed,sellers,c);
		if(failed){
			cout<<"Command Failed"<<endl;
		}
	}
	else{
		cout<<"Command Failed"<<endl;
	}
}
void Stores::Discount(vector<Buyer>& buyers,vector<Seller>& sellers){
	string buyerusername,goods_name,seller_username;
	int c=0;
	bool tekrari=false;
	cin>>buyerusername>>goods_name>>seller_username;
	for(int i=0;i<buyers.size();i++){
		if(buyers[i].Buyer_Tekrari(buyerusername)){
			c=i;
			tekrari=true;
		}
	}
	if(tekrari){
		buyers[c].Set_Discount_Goods(sellers,goods_name,seller_username);
	}
	else{
		cout<<"Command Failed"<<endl;
	}
}
void Stores::Add_Money(vector<Buyer>& buyers){
	string name;
	bool exist=false;
	cin>>name;
	for(int i=0;i<buyers.size();i++){
		if(Check_Strings(name,buyers[i].Pass_Username())){
			buyers[i].Add_Money();
			exist=true;
			break;
		}
	}
	if(exist)
		cout<<"Command Ok"<<endl;
	else
		cout<<"Command Failed"<<endl;
}
void Stores::Add_Special(vector<Seller>& sellers){
	string seller_username,goods_name;
	double goods_counts;
	cin>>seller_username>>goods_name>>goods_counts;
	bool exist=false;
	for(int i=0;i<sellers.size();i++){
		if(sellers[i].Seller_Tekrari(seller_username)){
			sellers[i].Add_Special(goods_name,goods_counts);
			exist=true;
		}
	}
	if(!exist)
		cout<<"Command Failed"<<endl;
}
void Stores::Remove_Special(vector<Seller>& sellers){
	string seller_username,goods_name;
	double goods_counts;
	cin>>seller_username>>goods_name>>goods_counts;
	bool exist=false;
	for(int i=0;i<sellers.size();i++){
		if(sellers[i].Seller_Tekrari(seller_username)){
			sellers[i].Remove_Special(goods_name,goods_counts);
			exist=true;
		}
	}
	if(!exist)
		cout<<"Command Failed"<<endl;	
}
void Stores::Search_Best_Seller(vector<Seller>& sellers){
	int c=0;
	for(int i=0;i<sellers.size();i++){
		sellers[i].Search_Best_Seller(c);
	}
}
void Stores::Search_Sale(vector<Seller>& sellers){
	int c=0;
	for(int i=0;i<sellers.size();i++){
		sellers[i].Search_Sale(c);
	}
}
void Stores::Print_Factor(vector<Buyer>& buyers){
	string buyername;
	bool exist=false;
	cin>>buyername;
	for(int i=0;i<buyers.size();i++){
		if(Check_Strings(buyername,buyers[i].Pass_Username())){
			buyers[i].Print_Factor();
			exist=true;
		}
	}
	if(!exist){
		cout<<"Command Failed"<<endl;
	}
}
void Stores::Check_Best_Seller_Store(vector<Seller>& sellers){
	for(int i=0;i<sellers.size();i++){
		sellers[i].Check_Best_Seller();
	}
}
void Stores::Requests(vector<Request>& requests){
	string requestname;
	bool exist=false;
	cin>>requestname;
	for(int i=0;i<requests.size();i++){
		if(requests[i].Check_Name_Request(requestname)){
			exist=true;
		}
	}
	if(!exist){
		Request request(requestname);
		requests.push_back(request);
		requests[requests.size()-1].Get_Info_Request();
		cout<<"Command Ok"<<endl;
	}
	else
		cout<<"Command Failed"<<endl;
}