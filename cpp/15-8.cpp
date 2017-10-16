// CS-132 HW 15-8
// KIT WONG
// 5-4-2015
// used 40 min

#include<iostream>
#include<string>
using namespace std;

void inputCheck(double& n, double min){
	while(n < min){
		cout << "Invalid input, enter again: ";
		cin >> n;
	}
}
class PersonData{
	private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip;
	string phone;
	public:
	PersonData(string="",string="",string="",string="",string="",string="",string="");
	string getLastName(){return lastName;}
	string getFirstName(){return firstName;}
	string getAddress(){return address;}
	string getCity(){return city;}
	string getState(){return state;}
	string getZip(){return zip;}
	string getPhone(){return phone;}
	void setLastName(string ln=""){lastName = ln;}
	void setFirstName(string fn=""){firstName = fn;}
	void setAddress(string ad=""){address = ad;}
	void setCity(string c=""){city = c;}
	void setState(string s=""){state = s;}
	void setZip(string z=""){zip = z;}
	void setPhone(string p=0){phone = p;}
};
PersonData::PersonData(string ln, string fn, string ad,string c, string s, string z, string p){
	lastName = ln;
	firstName = fn;
	address = ad;
	city = c;
	state = s;
	zip = z;
	phone = p;
}
class CustomerData: public PersonData{
	private:
	string customerNumber;
	bool mailingList;
	public:
	CustomerData(string="",string="",string="",string="",string="",string="",string="",string=0,bool=true);
	string getCustomerNumber(){return customerNumber;}
	bool getMailingList(){return mailingList;}
	void setCustomerNumber(string cNum=0){customerNumber = cNum;}
	void setMailingList(bool mList){mailingList = mList;}
};
CustomerData::CustomerData(string ln, string fn, string ad,string c, string s, string z, string p,string cNum, bool mList):PersonData(ln, fn, ad, c, s, z, p){
	customerNumber = cNum;
	mailingList = mList;
}
class PreferredCustomer: public CustomerData{
	private:
	double purchasesAmount;
	double discountLevel;
	double discountCal(){
		if(purchasesAmount >= 2000) return 10;
		else if(purchasesAmount >= 1500) return 7;
		else if(purchasesAmount >= 1000) return 6;
		else if(purchasesAmount >= 500) return 5;
		else return 0;
	}
	public:
	PreferredCustomer(string="",string="",string="",string="",string="",string="",string="",string=0,bool=true,double=0);
	double getPurchasesAmount(){return purchasesAmount;}
	double getDiscountLevel(){return discountLevel;}
	void setDiscountLevel(double d){
			discountLevel = d;
			inputCheck(d,0);
	}
	void setPurchasesAmount(double a){
		purchasesAmount = a;
		inputCheck(a,0);
		setDiscountLevel(discountCal());
	}
	void addAmount(double n){
		purchasesAmount += n;
		setDiscountLevel(discountCal());
	}
};
PreferredCustomer::PreferredCustomer(string ln, string fn, string ad, string c, string s,string z, string p, string cNum, bool mList, double a):CustomerData(ln, fn, ad, c, s, z, p, cNum, mList){
	setPurchasesAmount(a);
}


int main(){
	double dTemp;
	bool yn=1;
	PreferredCustomer vip("Wong", "Yeung Kit", "12110 SE 312th St", "Auburn", "WA", "98092", "2535613074", "844915794", true, 0);
	cout << "First name: " << vip.getFirstName() << endl;
	cout << "Last name: " << vip.getLastName() << endl;
	cout << "Address: " << vip.getAddress() << endl;
	cout << "City: " << vip.getCity() << endl;
	cout << "Sate: " << vip.getState() << endl;
	cout << "Zip code: " << vip.getZip() << endl;
	cout << "Phone number: " << vip.getPhone() << endl;
	cout << "Customer number: " << vip.getCustomerNumber() << endl;
	if(vip.getMailingList())
		cout << "Receive mail: yes" << endl;
	else cout << "Receive mail: no" << endl;
	while(yn){
		cout << "Enter the purchases amount: $";
		cin >> dTemp;
		vip.addAmount(dTemp);
		cout << "Current total purchases amount: $" << vip.getPurchasesAmount() << endl;
		cout << "Current discount level: " << vip.getDiscountLevel() << "%" << endl;
		cout << "More amount?\nEnter 0 for no, otherwise yes: ";
		cin >> yn; cin.clear();
	}
	return 0;
}
