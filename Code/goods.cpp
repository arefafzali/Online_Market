#include "goods.h"

double Goods::Pass_Count(){
	return count;
}
string Goods::Pass_GoodsName(){
	return goodsname;
}
float Goods::Pass_Price(){
	if(!discount || storemoney<price/10)
		return price*105/100;
	else
		return price*945/1000;
}
bool Goods::Check_Counts(double x){
	if(x>count)
		return false;
	else
		return true;
}
bool Goods::End_Of_Counts(double goods_counts){
	bestsellernum+=goods_counts;
	while(goods_counts!=0){
		if(discountedcount==0){
			if(count!=0){
				count--;
				goods_counts--;
			}
			else{				
				bestsellernum=0;
				return true;
			}
		}
		else{
			discountedcount--;
			count--;
			goods_counts--;
		}
	}
	if(count==0){
		bestsellernum=0;
		return true;
	}
	else{
		return false;
	}
}
bool Goods::Rise_Number_Of_Sales(){
	if(discountnum==10)
		return false;
	else{
		discountnum+=1;
		if(discountnum>10){
			discount=true;
		}
		return true;
	}
}
bool Goods::Check_Sales(){
	if(discount)
		return true;
	else{
		return false;
	}
}
void Goods::Sale_Goods(){
	discount=true;
}
void Goods::Special_Sale(double goods_counts){
	discountedcount+=goods_counts;
}
void Goods::Special_Sale_Off(double goods_counts){
	discountedcount-=goods_counts;
}
void Goods::Check_Best_Seller_Goods(){
	if(bestsellernum>10)
		bestseller=true;
}
bool Goods::Best_Seller(){
	if(bestseller)
		return true;
	else
		return false;
}