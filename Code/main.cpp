//#ifndef Main_H
//#define Main_H

#include "store.h"

int main()
{
	vector<Buyer> buyers;
	vector<Seller> sellers;
	vector<Goods> goods;
	vector<Request> requests;
	Stores stores;
	string command;
	int factornum=0;
	while(cin>>command){
		if(command=="add_user"){
			stores.Add_User(buyers,sellers);
		}
		else if(command=="add_goods"){
			stores.Add_Goods(sellers,goods);
		}
		else if(command=="search"){
			stores.Search(sellers);
		}
		else if(command=="buy"){
			stores.Buy(buyers,sellers,factornum);
		}
		else if(command=="sale"){
			stores.Discount(buyers,sellers);
		}
		else if(command=="add_special"){
			stores.Add_Special(sellers);
		}
		else if(command=="remove_special"){
			stores.Remove_Special(sellers);
		}
		else if(command=="search_bestseller"){
			stores.Search_Best_Seller(sellers);
		}
		else if(command=="seach_sale"){
			stores.Search_Sale(sellers);
		}
		else if(command=="add_money"){
			stores.Add_Money(buyers);
		}
		else if(command=="print_factor"){
			stores.Print_Factor(buyers);
		}
		else if(command=="request"){
			stores.Requests(requests);
		}
		else{
			string cash;
			getline(cin,cash);
			cout<<"Command Failed"<<endl;
		}
		
		stores.Check_Best_Seller_Store(sellers);


		bool buyerexist=false;
		for(int i=0;i<requests.size();i++){
			for(int j=0;j<buyers.size();j++){
				if(Check_Strings(buyers[j].Pass_Username(),requests[i].Pass_Buyer_Username())){
					buyerexist=true;
				}
			}
		}
		if(buyerexist){
			for(int i=0;i<requests.size();i++){
				for(int j=0;j<sellers.size();j++){
					//requests[i].Check_Sellers_Name(sellers[j]);
				}
			}
		}



		int c=0;
		for(int i=0;i<goods.size();i++){
			for(int j=0;j<goods.size();j++){
				if(Check_Strings(goods[i].Pass_GoodsName(),goods[j].Pass_GoodsName())){
					c++;
				}
			}
			if(c>30){
				goods[i].Sale_Goods();
			}
		}


	}
	return 0;
}

//#endif