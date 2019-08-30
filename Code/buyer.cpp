#include "buyer.h"

bool Buyer::Buyer_Tekrari(string name){
	if(name==username)
		return true;
	else
		return false;
}
void Buyer::Buying_Prosess(bool& failed,vector<Seller>& sellers,int& n){
	vector<buyingGoodsInfo> info;
	char x;
	float allmoney=0;
	do{
		buyingGoodsInfo lineinfo;
		cin>>lineinfo.goods_name>>lineinfo.goods_count>>lineinfo.seller_username;
		x=lineinfo.seller_username[lineinfo.seller_username.size()-1];
		lineinfo.seller_username.erase(lineinfo.seller_username.size()-1);
		info.push_back(lineinfo);
	}while(x!=';');
	for(int i=0;i<sellers.size();i++){
		for(int j=0;j<info.size();j++){
			if(Check_Strings( sellers[i].Pass_Username() ,info[j].seller_username)){
				sellers[i].Buying(info[j].goods_count,info[j].goods_name,failed,allmoney);
			}
		}
	}
	if(allmoney>money)
		failed=true;
	else{
		if(!failed){
			money-=allmoney;
			storemoney+=allmoney/21;
			//print factor
			Factor factor(sellers,info);
			factor.Print_Factor(firstname,lastname,username,phonenumber,n,true);
			factors.push_back(factor);
		}
	}
}
void Buyer::Set_Discount_Goods(vector<Seller>& sellers,string goods_name,string seller_username){
	bool failed=true;
	for(int i=0;i<sellers.size();i++){
		if( sellers[i].Seller_Tekrari(seller_username)){
			if(sellers[i].Check_Sales(goods_name)){
				failed=false;
			}
		}
	}
	if(failed){
		cout<<"Command Faileeeed"<<endl;
	}
	else{
		cout<<"Command OK"<<endl;
	}
}
void Buyer::Add_Money(){
	float addmoney;
	cin>>addmoney;
	money+=addmoney;
}
void Buyer::Print_Factor(){
	int n=0;
	for(int i=0;i<factors.size();i++){
		factors[i].Print_Factor(firstname,lastname,username,phonenumber,n,false);
	}
}