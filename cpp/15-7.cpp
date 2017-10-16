// CS-132 HW 15-7
// KIT WONG
// 5-3-2015
// used 30 min

#include<iostream>
#include<string>
using namespace std;

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
PersonData::PersonData(string ln, string fn, string ad, string c, string s, string z, string p){
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
CustomerData::CustomerData(string ln, string fn, string ad, string c, string s, string z, string p, string cNum, bool mList):PersonData(ln, fn, ad, c, s, z, p){
	customerNumber = cNum;
	mailingList = mList;
}

int main(){
	CustomerData x("Yeung Kit", "Wong", "12110 SE 312th St", "Auburn", "WA", "98092", "2535613074", "9012251830", true);
	cout << "First name: " << x.getFirstName() << endl;
	cout << "Last name: " << x.getLastName() << endl;
	cout << "Address: " << x.getAddress() << endl;
	cout << "City: " << x.getCity() << endl;
	cout << "Sate: " << x.getState() << endl;
	cout << "Zip code: " << x.getZip() << endl;
	cout << "Phone number: " << x.getPhone() << endl;
	cout << "Customer number: " << x.getCustomerNumber() << endl;
	if(x.getMailingList())
		cout << "Receive mail: yes" << endl;
	else cout << "Receive mail: no" << endl;
	return 0;
}
