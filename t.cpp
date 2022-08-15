#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//passenger class for adding passenger details
class Passenger{
	public:
	
	struct Person{
		string name;
		int age;
		char gen;
		int coach;
		int seat;
		};
		
	struct Person p[300];
	
	
	void addpeople(int i,int s,int c){
		string name;
		int age;
		char g;
		cout<<"Enter Passenger name:";
		cin>>name;
		cout<<"Enter the age:";
		cin>>age;
		cout<<"Enter the Gender(F/M):";
		cin>>g;
		
		p[i].name=name;
		p[i].age=age;
		p[i].gen=g;
		p[i].coach=c;
		p[i].seat=s;
		
	}
};
	
//train class for storing train details
class Train{
	public:
	int id;
	string name;
	string start_loc;
	string end_loc;
	struct coach{
		string coachname;
		int coachfee;
		int seat[100];
		};
	struct coach s2;
	struct coach ac;
	struct coach sl;
};



Train ob1,ob2,ob3;


//creatin train details
void createTrains(){

	
	//Train ob1;
	ob1.id=1;
	ob1.name="Intercity Express";
	ob1.start_loc="Trivandrum";
	ob1.end_loc="Mangalore";
	ob1.s2.coachname="Second sitting";
	ob1.s2.coachfee=100;
	ob1.ac.coachname="AC First class";
	ob1.ac.coachfee=400;
	ob1.sl.coachname="sleeper class";
	ob1.sl.coachfee=400;
	
	//Train ob2;
	ob2.id=2;
	ob2.name="Parasuram Express";
	ob2.start_loc="Mangalore";
	ob2.end_loc="Chennai";
	ob2.s2.coachname="Second sitting";
	ob2.s2.coachfee=100;
	ob2.ac.coachname="AC First class";
	ob2.ac.coachfee=400;
	ob2.sl.coachname="sleeper class";
	ob2.sl.coachfee=400;


	//Train ob3;
	ob3.id=3;
	ob3.name="Mangala Lakshadeep Express";
	ob3.start_loc="Trivandrum";
	ob3.end_loc="Delhi";
	ob3.s2.coachname="Second sitting";
	ob3.s2.coachfee=100;
	ob3.ac.coachname="AC First class";
	ob3.ac.coachfee=400;
	ob3.sl.coachname="sleeper class";
	ob3.sl.coachfee=400;

}

//billing function
int bill(int tid,int c,int n){
	int s;
	if(tid==1)
		s=200;
	if(tid==2)
		s=250;
	if(tid==3)
		s=350;
	if(c==1)
		s=s*1;
	if(c==2)
		s=s*2;
	if(c==3)
		s=s*1.5;
	cout<<"\nAmount to be paid:"<<s*n<<"\n";
	return s*n;	
}


int main(){
	createTrains();
	string from,to,date;
	int id;
	int c;
	int s,k;
	int n;
	
	cout<<"-----------Railway Ticket Booking System-----------"<<endl;
	cout<<"Enter your start position: ";
	cin>>from;
	cout<<"Enter your end position: ";
	cin>>to;
	cout<<"Enter the date: ";
	cin>>date;
	
	cout<<"Enter the Number of people:";
	cin>>n;
	
	Passenger p;
	
	cout<<"---------Available Trains:----------"<<endl;
	if(from==ob1.start_loc && to==ob1.end_loc)
		cout<<ob1.id<<"\t\t"<<ob1.name<<"\t\t\t"<<ob1.start_loc<<"\t\t\t"<<ob1.end_loc<<"\n";
	if(from==ob2.start_loc && to==ob2.end_loc)
		cout<<ob2.id<<"\t\t"<<ob2.name<<"\t\t\t"<<ob2.start_loc<<"\t\t\t"<<ob2.end_loc<<"\n";
	if(from==ob3.start_loc && to==ob3.end_loc)
		cout<<ob3.id<<"\t\t"<<ob3.name<<"\t\t\t"<<ob3.start_loc<<"\t\t\t"<<ob3.end_loc<<"\n";
	cout<<"Enter your Train no: ";
	cin>>id;
	cout<<"Select preferred coach:\n1.Second Sitiing\n2.Sleeper class\n3.AC first class\n\n";
	cin>>c;
	cout<<"select your seat no:\n";
	Train ob;
	if(id==ob1.id)
		ob=ob1;
	if(id==ob2.id)
		ob=ob2;
	if(id==ob3.id)
		ob=ob3;
	switch(c){
		case 1:k=0;
			cout<<"Second Sitiing\n";
			for(int i=0;i<100;i++){
				if(k==12)
				{
					k=0;
					cout<<"\n\n";
				}
				if(k==3 || k==9)
					cout<<"\t";
				if(k==6)
					cout<<"\n";
				if(ob.s2.seat[i]==1)
					cout<<"  ";
				else
					cout<<i<<" ";
				k++;	
			}
			break;
		case 2:k=0;
			cout<<"Sleeper class\n";
			for(int i=0;i<100;i++){
				if(k==12)
				{
					k=0;
					cout<<"\n\n";
				}
				if(k==3 || k==9)
					cout<<"\t";
				if(k==6)
					cout<<"\n";
				if(ob.sl.seat[i]==1)
					cout<<"  ";
				else
					cout<<i<<" ";
				k++;	
			}
			break;
		case 3:k=0;
			cout<<"AC first class\n";
			for(int i=0;i<100;i++){
				if(k==12)
				{
					k=0;
					cout<<"\n\n";
				}
				if(k==3 || k==9)
					cout<<"\t";
				if(k==6)
					cout<<"\n";
				if(ob.ac.seat[i]==1)
					cout<<"  ";
				else
					cout<<i<<" ";
				k++;	
			}
			break;
		default:cout<<"Enter right choice\n";
			break;
		
	
	}
	cout<<"\n";
	
	for(int i=0;i<n;i++){
		cout<<"Enter "<<i+1<<"th seat No:";
		cin>>s;
		p.addpeople(i,s,c);
		switch(c){
		case 1:ob.s2.seat[s]=1;
			break;
		case 2:ob.sl.seat[s]=1;
			break;
		case 3:ob.ac.seat[s]=1;
			break;
		default:cout<<"Enter right choice\n";
		}
	}
	
	int fee=bill(id,c,n);
	
	
	//Generate Ticket
	
	
	cout<<"\n\nYour Ticket booking is confirmed\n\n";
	cout<<"Ticket details are as follows\n\n";
	cout<<"\t\t"<<ob.name<<"\t\t";
	cout<<"\nStarting Location:"<<from<<"\n";
	cout<<"Destination:"<<to<<"\n";
	cout<<"Date:"<<date<<"\n";
	
	cout<<"Passenger details:\n";
	for(int i=0;i<n;i++)
		cout<<"Passenger "<<i+1<<"\n"<<"Name:"<<p.p[i].name<<"\nAge:"<<p.p[i].age<<"\nGender:"<<p.p[i].gen<<"\nSeat Position"<<p.p[i].coach<<" "<<p.p[i].seat<<"\n\n";
	
	cout<<"Payment Information"<<"\nAmount payed:"<<fee<<"\nPayment info:Successful\nThank you\n\n";
	
	return 0;
	
}
