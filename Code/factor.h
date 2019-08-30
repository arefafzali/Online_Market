#include "seller.h"

class Factor{
public:
	Factor(vector<Seller> seller,vector<buyingGoodsInfo> infoo): sellers(seller),info(infoo){}
	void Print_Factor(string firstname,string lastname,string username,string phonenumber,int& n,bool printflag);
protected:
	vector<Seller> sellers;
	vector<buyingGoodsInfo> info;
};
void Factor::Print_Factor(string firstname,string lastname,string username,string phonenumber,int& n,bool printflag){
	int c=0;
	n++;
	cout<<"Factor number "<<n<<endl;
	cout<<firstname<<" "<<lastname<<" "<<username<<" "<<phonenumber<<endl;
	if(printflag)
		cout<<"#. Goods Name  | Goods Count | Goods Price | Seller Username | Sum (count * price ) "<<endl;
	for(int i=0;i<sellers.size();i++){
		for(int j=0;j<info.size();j++){
			if(Check_Strings( sellers[i].Pass_Username() ,info[j].seller_username)){
				sellers[i].Print_Buying_Factor(c,info[j].goods_name,info[j].goods_count);
			}
		}
	}
}