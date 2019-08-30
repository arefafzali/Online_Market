
double CtoD(char n){
	double x;
	switch(n){
		case '0':
			x=0;
			break;
		case '1':
			x=1;
			break;
		case '2':
			x=2;
			break;
		case '3':
			x=3;
			break;
		case '4':
			x=4;
			break;
		case '5':
			x=5;
			break;
		case '6':
			x=6;
			break;
		case '7':
			x=7;
			break;
		case '8':
			x=8;
			break;
		case '9':
			x=9;
			break;
	}
	return x;
}
double StoD(string money){
	double x;
	for(int i;i<money.size();i++){
		x+=CtoD(money[i]);
		x*=10;
	}
	x=x/10;
	return x;
}