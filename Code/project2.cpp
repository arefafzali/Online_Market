
#include <iostream>
#include <vector>
#include <string>

using namespace std;

float storemoney=0;

struct buyingGoodsInfo{
	string goods_name;
	double goods_count;
	string seller_username;
};
struct requestInfo{
	string goods_name;
	double goods_count;
	string seller_username;
};

bool Check_Strings(string fname,string sname){
	if(fname.size()==sname.size()){
		for(int i=0;i<fname.size();i++){
			if(fname[i]!=sname[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Request{
public:
	Request(string requestname):request_name(requestname){}
	void Get_Info_Request();
	bool Check_Name_Request(string requestname);
	string Pass_Buyer_Username(){return buyer_username;}
protected:
	vector<requestInfo> requestinfo;
	string request_name;
	string buyer_username;
};
void Request::Get_Info_Request(){
	char x;
	cin>>buyer_username;
	do{
		requestInfo lineinfo;
		cin>>lineinfo.goods_name>>lineinfo.goods_count>>lineinfo.seller_username;
		x=lineinfo.seller_username[lineinfo.seller_username.size()-1];
		lineinfo.seller_username.erase(lineinfo.seller_username.size()-1);
		requestinfo.push_back(lineinfo);
	}while(x!=';');
}
bool Request::Check_Name_Request(string requestname){
	if(Check_Strings(requestname,request_name))
		return true;
	else
		return false;
}
//bool Request::Check_Sellers_Name(Seller seller){
//	if(Check_Strings())
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
//void Seller::Check_Request(Request request){

//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
