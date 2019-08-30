#include "seller.h"

bool Seller::Seller_Tekrari(string name){
	if(Check_Strings(name,username))
		return true;
	else
		return false;
}
void Seller::Set_Goods(Goods name){
	goods.push_back(name);
}
void Seller::Search_Goods(string name,double counts, int& c){
	bool failed=true;
	for(int i=0;i<goods.size();i++){
		if(Check_Strings(name,goods[i].Pass_GoodsName())){
			if(goods[i].Check_Counts(counts)){
				c++;
				cout<<c<<". "<<goods[i].Pass_GoodsName()<<" "<<goods[i].Pass_Count()<<" "<<goods[i].Pass_Price()<<" "<<username<<endl;
			}
			else{
				cout<<"Command Failed"<<endl;
			}
			failed=false;
		}
	}
	if(failed){
		cout<<"Command Failed"<<endl;
	}
}
void Seller::Buying(double goods_counts,string goods_name, bool& failed,float& allmoney){
	bool cfailed=false;
	float price;
	bool exist=false;
	for(int i=0;i<goods.size();i++){
		if(!exist){
			if(Check_Strings(goods[i].Pass_GoodsName(),goods_name)){
				price=goods[i].Pass_Price();
				exist=true;
				cfailed!=goods[i].Check_Counts(goods_counts);
				if(!cfailed){
					if(goods[i].End_Of_Counts(goods_counts))
						goods.erase(goods.begin()+i);
				}
			}
		}
	}
	if(!exist)
		failed=true;
	if(cfailed)
		failed=true;
	allmoney+=(goods_counts)*price;
}
bool Seller::Check_Sales(string goods_name){
	bool failed=true;
	for(int i=0;i<goods.size();i++){
		if(Check_Strings(goods[i].Pass_GoodsName(),goods_name)){
			if(!goods[i].Check_Sales()){
				if(!goods[i].Rise_Number_Of_Sales()){
					goods[i].Sale_Goods();
				}
				return true;
			}
			else{
				return false;
			}
		}
	}
	return false;
}
void Seller::Print_Buying_Factor(int& c,string goods_name,double goods_counts){
	float Sum=0;
	for(int i=0;i<goods.size();i++){
		if(Check_Strings(goods[i].Pass_GoodsName(),goods_name)){
			c++;
			float sum=0;
			sum=(goods_counts*goods[i].Pass_Price());
			cout<<c<<". "<<goods_name<<" | "<<goods_counts<<" | "<<goods[i].Pass_Price()<<" | "<<username<<" | "<< sum*100/105<<endl;
			Sum+=sum;
		}
	}
	cout<<"Goods Sum = "<<Sum*100/105<<endl<<"Total Sum = "<<Sum<<endl;
}
void Seller::Add_Special(string goods_name,double goods_counts){
	bool exist=false;
	for(int i=0;i<goods.size();i++){
		if(Check_Strings(goods[i].Pass_GoodsName(),goods_name)){
			goods[i].Special_Sale(goods_counts);
			exist=true;
		}
	}
	if(!exist)
		cout<<"Command Failed"<<endl;
	else
		cout<<"Command Ok"<<endl;
}
void Seller::Remove_Special(string goods_name,double goods_counts){
	bool exist=false;
	for(int i=0;i<goods.size();i++){
		if(Check_Strings(goods[i].Pass_GoodsName(),goods_name)){
			goods[i].Special_Sale_Off(goods_counts);
			exist=true;
		}
	}
	if(!exist)
		cout<<"Command Failed"<<endl;
	else
		cout<<"Command Ok"<<endl;	
}
void Seller::Check_Best_Seller(){
	for(int i=0;i<goods.size();i++){
		goods[i].Check_Best_Seller_Goods();
	}
}
void Seller::Search_Best_Seller(int& c){
	for(int i=0;i<goods.size();i++){
		if(goods[i].Best_Seller()){
			c++;
			cout<<c<<". "<<goods[i].Pass_GoodsName()<<" "<<goods[i].Pass_Count()<<" "<<goods[i].Pass_Price()<<" "<<username<<endl;
		}
	}
}
void Seller::Search_Sale(int& c){
	for(int i=0;i<goods.size();i++){
		if(goods[i].Check_Sales()){
			c++;
			cout<<c<<". "<<goods[i].Pass_GoodsName()<<" "<<goods[i].Pass_Count()<<" "<<goods[i].Pass_Price()<<" "<<username<<endl;
		}
	}
}