#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<string>
#include<time.h>

#define ANSI_COLOUR_CYAN "\x1b[36m"
#define ANSI_COLOUR_RESET "\x1b[0m"
#define ANSI_COLOUR_GREEN "\x1b[32m"
#define ANSI_COLOUR_BROWN "\x1b[33m"
#define ANSI_COLOUR_MAGENTA "\x1b[35m"
#define ANSI_COLOUR_RED "\x1b[31m"
#define ANSI_COLOUR_YELLOW "\033[33m"
#define ANSI_COLOUR_ORANGE "\033[38;2;255;165;0m"
using namespace std;
int main();
class hotel
{
int room_no;
string name;
char address[50];
char phone[10];
public:
void main_menu();		//to display the main menu
void add();			//to book a room
void display(); 		//to display the customer record
void rooms();			//to display alloted rooms
void edit();			//to edit the customer record
int check(int);			//to check room status
void modify(int);		//to modify the record
void delete_rec(int);		//to delete the record
void bill(int);                 //for the bill of a record
     };
    //END OF CLASS
//FOR DISPLAYING MAIN MENU
void hotel::main_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
    std::cout << " ___________________________________" << std::endl;
    std::cout << "//                                  \\ "<< std::endl;
    std::cout << "|        [1] BOOK A ROOM            |" << std::endl;
    std::cout << "|        [2] CUSTOMER RECORDS       |" << std::endl;
    std::cout << "|        [3] ROOMS ALLOTTED         |" << std::endl;
    std::cout << "|        [4] EDIT RECORD            |" << std::endl;
    std::cout << "|        [5] EXIT                   |" << std::endl;
    std::cout << "\\__________________________________//" << std::endl;
    cout<<"\n"<<endl;
    std::cout << "         ENTER YOUR CHOICE:         " << std::endl;
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5:
 throw 1;
 break;

default:
{
cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();
}
}
}
}
//END OF MENU FUNCTION
//FUNCTION FOR BOOKING OF ROOM
void hotel::add()
{
system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);
cout<<"\n ENTER CUSTOMER DETAILS";
cout<<"\n ----------------------";
cout<<"\n Total no. of Rooms - 50";
cout<<"\n Ordinary Rooms from 1 - 30";
cout<<"\n Luxury Rooms from 31 - 45";
cout<<"\n Royal Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;
flag=check(r);
if(flag)
cout<<"\n Sorry..!!!Room is already booked";
else
{
    fout.seekp(0,ios::end);
room_no=r;
cout<<" Name: ";
cin.ignore();
getline(cin,name);
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";
}
cout<<"\n Press any key to continue.....!!";
getch();
fout.close();
}
//END OF BOOKING FUNCTION
//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD
void hotel::display()
{
  system("cls");
ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;
while(fin.read((char*)this,sizeof(hotel)))
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
system("cls");
cout<<"\n Customer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";
getch();
fin.close();
}
//END OF DISPLAY FUNCTION
//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED
void hotel::rooms()
{
system("cls");
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";
fin.seekg(0,ios::beg);
while(fin.read((char*)this, sizeof(hotel)))
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();
}
//FUNCTION FOR EDITING RECORDS AND FOR BILL
void hotel::edit()
{
system("cls");
int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Bill Of Customer";
cout<<"\n Enter your choice: ";
cin>>choice;
system("cls");
cout<<"\n Enter room no: " ;
cin>>r;
switch(choice)
{
case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

case 3: bill(r);
break;

default:
cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}


int hotel::check(int r)
{

int flag=0;
ifstream fin("Record.dat",ios::in);
fin.seekg(0,ios::beg);
while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(fin.read((char*)this,sizeof(hotel)))
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n'){
fout.write((char*)this,sizeof(hotel));
flag=2;
}
else
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));
}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";
//cout<<"RECORD NOT DELETED"<<endl;
else if(flag==1)
{
remove("Record.dat");
rename("temp.dat","Record.dat");
}
else{
    cout<<"RECORD NOT DELETED"<<endl;
    remove("Record.dat");
rename("temp.dat","Record.dat");
}

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 2000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 5000" ;

  else
  cout<<"your bill = 7000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}

//END OF BILLING FUNCTION

//START OF MAIN PROGARM

int glob=0; //global variables
int global=10;

class d_booking //class  for domestic booking
{
protected:
    int pnr;
    char f_d[10],toja[7],tojd[7]; //protected members
    long int doj;
    int choice,src,dest;
public://public member functions
    void d_pnr()
    {
        glob++; // increment variable
        pnr=glob;
    }
    int j_detail() // function declaration and definition for domestic journey
    {
        cout << "\nEnter DateOfJourney(DDMMYY)." << "Please enter a valid date." <<  endl;
        cin >> doj;
        cout << "\1.KOLKATA(1) \t\2.MUMBAI(2) \t\3.SHIMLA(3) \t\4.DELHI(4)" << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> src;
        cout << "\tEnter destination" << endl;
        cin >> dest;
        if((src==1 && dest==2) || (src==2 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }

        else if((src==1 && dest==3) || (src==3 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }

        else if((src==1 && dest==4) || (src==4 && dest==1))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.4000\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.4250\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6100\t\tRefundable\n";
        }

        else if((src==2 && dest==3) || (src==3 && dest==2))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5400\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.2500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.2890\t\tRefundable\n";
        }

        else if((src==2 && dest==4) || (src==4 && dest==2))//condition
        {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.4500\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
        }
        else if((src==3 && dest==4) || (src==4 && dest==3))//condition
         {
            cout << "\t \t \tFlights Found" << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Qantas(1)\t08:00\t\t11:05\t\tRs.5800\t\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t17:05\t\tRs.5508\t\tRefundable\n";
            cout << "\3.Go Air(3)\t19:00\t\t22:05\t\tRs.6050\t\tRefundable\n";
        }
        else if(src==dest)//condition
        {
            cout << "\nSource and destination can't be same.\nTry again\n\n\n" << endl;
            return j_detail();
        }
        else
        {
            cout <<"\nWrong input entered\nTry again\n\n\n" << endl;
            return j_detail();
        }

    }

    int  select_flight() //function declaration and definition for selecting flight
    {   cout << "\nEnter your choice" << endl;
        cin >> choice;
        switch(choice) // switch case
        {
          case 1://condition
                cout << "\nFlight selected:"<<endl;
                cout << "Qantas"<<endl;
                strcpy(f_d,"Qantas");//copy to string
                cout << "Departure Time : 08:00"<<endl;
                cout<<"Arrival Time: 11:05"<<endl;
                strcpy(tojd,"8:00"); //copy to string
                strcpy(toja,"11:05");// copy to string
                break;
          case 2://condition
                cout << "\nFlight selected:"<<endl;
                cout << "AIR INDIA"<<endl;
                strcpy(f_d,"AIR INDIA");//copy to string
                cout << "Departure Time : 14:00"<<endl;
                cout<<"Arrival Time: 17:05"<<endl;
                strcpy(tojd,"14:00");//copy to string
                strcpy(toja,"17:05");//copy to string
                break;
          case 3://condition
                cout << "\nFlight selected:" << endl;
                cout << "Go Air" << endl;
                strcpy(f_d,"Go Air");//copy to string
                cout << "Departure Time : 19:00" << endl;
                cout<<"Arrival Time: 22:05" << endl;
                strcpy(tojd,"19:00");//copy to string
                strcpy(toja,"22:05");//copy to string
                break;
          default://condition
                cout << "Wrong input entered.\nTry again" << endl;
                return select_flight();
        }
    }
};

class i_booking//class for international booking
{
protected://protected members
    int pnri;
    char f_i[10],tojai[7],tojdi[7];
    long int doji;
    int srci,desti,choicei;
public://public member functions
    void i_pnr()
    {
        global++;//increment variable
        pnri=global;
    }
    //brought to you by code-projects.org
    int j_detaili()// function declaration and definition for journey details
    {
        cout << "Enter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;;
        cin >> doji;
        cout << "\1.London(1) \2.Dubai(2) \3.Abu Dhabi(3) \4.Singapore(4) \5.NewYork(5) " << endl << endl;
        cout << "\tEnter Source" << endl;
        cin >> srci;
        cout << "\nEnter destination" ;
        cin >> desti;
        cout << "\t \t \tFlights Found" << endl << endl;

        if((srci==1 && desti==3) || (srci==3 && desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25000\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.21500\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24000\tRefundable\n";
        }

        else if((srci==1 && desti==4) || (srci==4 && desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25500\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.21300\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24650\t\tRefundable\n";
        }

        else if((srci==1 && desti==5) || (srci==5 || desti==1))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.52500\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.59420\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.64892\tRefundable\n";
        }

        else if((srci==2 && desti==3) || (srci==3 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.17800\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.14900\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.18700\tRefundable\n";
        }

        else if((srci==2 && desti==4) || (srci==4 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.32000\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.38500\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs41259\tRefundable\n";        }

        else if(srci==2 && desti==5 || (srci==5 && desti==2))//condition
        {
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.82500\tRefundable\n";
            cout << "\2.AIR INDIA(2)\t14:00\t\t18:05\t\tRs.87550\tRefundable\n";
            cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs81478\tRefundable\n";

        }
        else if(srci==desti)//condition
        {
            cout << "wrong input entered.\nTry again\n\n\n"<< endl;
            return j_detaili();
        }
        else//condition
            {
            cout << "Wrong input entered.\nTry again\n\n\n";
            return j_detaili();
        }

    }

    int select_flighti()//function declaration and definition for selecting flight
    {
        cout << "\nEnter your choice" << endl;
        cin >> choicei;
        switch(choicei)//switch case
        {
        case 1://condition
            cout << "\nFlight selected:" <<endl;
            cout << "Vistara" << endl;
            strcpy(f_i,"Vistara");//copy to string
            cout << "Departure Time: 10:00" << endl;
            cout << "Arrival Time: 14:05" << endl;
            strcpy(tojdi,"10:00");//copy to string
            strcpy(tojai,"14:05");//copy to string
            break;
        case 2://condition
               cout << "\nFlight selected:" << endl;
               cout << "AIR INDIA" << endl;
               strcpy(f_i,"AIR INDIA");//copy to string
               cout << "Departure Time: 14:00" << endl;
               cout << "Arrival Time: 18:05" << endl;
               strcpy(tojdi,"14:00");//copy to string
                strcpy(tojai,"18:05");//copy to string
                break;
        case 3://condition
            cout << "\nFlight selected:" << endl;
            cout << "Emirates" << endl;
            strcpy(f_i,"Emirates");//copy to string
            cout << "Departure Time : 18:00" << endl;
            cout << "Arrival Time: 22:05" << endl;
            strcpy(tojdi,"18:00");//copy to string
            strcpy(tojai,"22:05");//copy to string
            break;

        default://condition
            cout << "Wrong input entered" << endl;
            return select_flighti();
        }
    }
};



class passenger: public d_booking,public i_booking//class passenger publicly inherited from class d_booking and i_booking
{
protected://protected members
    char f_name[20],l_name[20],email[50];
    int age,gender;
    long int c_no;
public://public member functions
    void p_detail(int x)//function declaration and definition
    {   if(x==1)//if else for domestic and international booking selection
        { j_detail();//function call
          select_flight();//function call
        }
          else
          {  j_detaili();//function call1353
             select_flighti();//function call
          }
        cout << "\n\n\nEnter passenger details";
        cout << "\nFirst Name:";
        cin >> f_name;
        cout << "Last Name:";
        cin >> l_name;
    }
    int gender_check()//to check gender input as valid
    {
        cout << "\nGender:\nMale-press:1::\nFemale-press:2::\n";
        cin >> gender;
        if(gender>2)//condition
        {
            cout << "\n\nWrong input entered.\nTry again\n\n" << endl;
            return gender_check();//function call
        }
    }
       void more_details()//to take more details of the passenger
       {
        cout << "Age:";
        cin >> age;
        cout << "Email Id:";
        cin >> email;
        cout << "Contact no.(6 digits):";
        cin >> c_no;
        cout << "\n\nDetails Entered:\n";
        cout << "Name:" << f_name << " " << l_name << endl;
        cout << "Gender:" << gender << endl;      //displaying details
        cout << "Age:" << age << endl;
        cout << "Email id:" << email << endl;
        cout << "Contact No.:" << c_no << endl;
    }


     int getpnr()//function to get pnr for domestic booking
        {
            return pnr;
        }

     int getpnri()//function to get pnr for international booking
     {
         return pnri;
     }

     void disp()//function to display details for domestic booking
     {
         cout<<"PNR:" << pnr << endl;
         cout<<"Flight:" << f_d << endl;
         cout<<"Name:" << f_name << " " << l_name << endl;
         cout<<"DOJ:" << doj << endl;
         cout<<"Departure Time:" << tojd << endl;
         cout<<"Arrival Time:" << toja;
     }

      void dispi()//function to display details for international booking
     {
         cout<<"PNR:" << pnri << endl;
         cout<<"Flight:" << f_i << endl;
         cout<<"Name:" << f_name << " " << l_name << endl;
         cout<<"DOJ:" << doji << endl;
         cout<<"Departure Time:" << tojdi << endl;
         cout<<"Arrival Time:" << tojai;
     }
};



class payment//class for payment
{
protected://protected members
    long
    int choice1,bank,card,date,cvv,user_id;
    char password[10];
public://public members functions
    void pay_detail()//function declaration and definition for payment method
    {     cout << "\n\n\nHow would you like to pay?:\n";
        cout << "\n\1.Debit Card(1) \n\2.Credit Card(2) \n\3.Net Banking(3)";
        cout << "\n\nEnter your choice";
        cin >> choice1;
        switch(choice1)//switch case
        {
        case 1://condition
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter CVV no.:";
            cin >> cvv;
            cout << "\nTransaction Successful\n";
            break;
        case 2://condition
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
            break;
        case 3://condition
            cout << "Banks Available: \n1.Bankl of India(1) \n2.SBI(2) \n3.Standard Chartered Bank(3) \n4.HDFC Bank(4) \n5.Others(5)\n";
            cout << "\nSelect your bank:";
            cin >> bank;
            cout << "\nYou have selected:" << bank;
            cout << "\nEnter user id:";
            cin >> user_id;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
            break;
        default://condition
            cout << "\nWrong input entered.\nTry again\n\n";
            return pay_detail();
        }
    }

};

void createfile(passenger p)//file creation for domestic booking
{  ofstream fin("domestic.txt",ios::binary|ios::app);
   fin.write((char*)&p,sizeof(p));//writing to file
   fin.close();//closing file
}

void cancelticket(int x)//function to cancel ticket
{
   passenger p;
   int f=0;
   ifstream fout("domestic.txt",ios::binary|ios::app);//for reading file
   ofstream fin("domestic1.txt",ios::binary|ios::app);//for writing to a new file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getpnr()!=x)//checking pnr
      fin.write((char *)&p,sizeof(p));//writing to file
      else
     {
         p.disp();//display details
         cout<<"\nYour Above ticket is being canceled:\n" << "Amount refunded: Rs 1000\n";
         f++;//incrementing f if pnr found
     }
     fout.read((char *)&p,sizeof(p));//reading another record from file
   }
   if(f==0)//if f==0,pnr not found
    cout<<"Ticket not found\n";
   fout.close();//closing file
   fin.close();//closing file
   remove("domestic.txt");//deleting old file
   rename("domestic1.txt","domestic.txt");//renaming new file

}

void checkticket(int x)//function to check pnr or ticket
{  passenger p;
   int f=0;
   ifstream fout("domestic.txt",ios::binary);//opening file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getpnr()==x)//checking pnr
     {p.disp();//display details
      cout<<"\nYour ticket"<<endl;
      f++;//incrementing f if onr found
      break;
     }
     fout.read((char *)&p,sizeof(p));//reading another record from the same file

   }
   fout.close();//closing file
   if(f==0)//if f==0, pnr not found
   cout<<"Ticket not found"<<endl;

}
void createfilei(passenger p)//opening a file for international booking
{  ofstream fin("international.txt",ios::binary|ios::app);
   fin.write((char*)&p,sizeof(p));//writing to file
   fin.close();//closing file
}
void cancelticketi(int x)//function to cancel ticket
{  passenger p;
   int f=0;
   ifstream fout("international.txt",ios::binary|ios::app);//opening file
   ofstream fin("international1.txt",ios::binary|ios::app);//writing to a new file
   fout.read((char *)&p,sizeof(p));//reading old file
   while(fout)
   {
     if(p.getpnri()!=x)//checking pnr
      fin.write((char *)&p,sizeof(p));//writing to new file;
      else
     {
         p.dispi();//display details
         cout<<"Your Above ticket is being deleted:\n"<<"Amount refunded: Rs 1000\n";
         f++;//incrementing f if pnr found
     }
     fout.read((char *)&p,sizeof(p));//reading another record from old file
   }
   if(f==0)//if f==0,pnr not found
    cout<<"\nTicket not found\n";
   fout.close();//closing file
   fin.close();//closing file
   remove("international.txt");//deleting old file
   rename("international1.txt","international.txt");//renaming new file

}
void checkticketi(int x)//function to check pnr or ticket
{  passenger p;
   int f=0;
   ifstream fout("international.txt",ios::binary);//opening file
   fout.read((char *)&p,sizeof(p));//reading file
   while(fout)
   {
     if(p.getpnri()==x)//checking pnr
     {p.dispi();//display details
      cout<<"\nYour ticket"<<endl;
      f++;//incrementing f if pnr found
      break;
     }
     fout.read((char *)&p,sizeof(p));//reading another record from the file

   }
   fout.close();//closing file
   if(f==0)//if f==0, pnr not found
   cout<<"Ticket not found"<<endl;

}
struct AddData {
    char si[10];
    char train_number[10];
    char train_name[20];
    char start[10];
    char destination[10];
    char price[10];
    int seat;
    char time[10];
};

struct BookTicket {
    char train_number[20];
    char name[20];
    char phone[20];
    char date[20];
    int seat;
};

int k = 0, u = 0;

void viewInfo();
void bookTicket();
void cancelTicket();
void admin();
void password();
void viewPassenger();
void addTrain();
void deleteTrain();
void aWrite();
void aRead();
void bookTicketWrite();
void viewPassengersRead();

AddData add[1000];
BookTicket book[1000];
void bookTicket() {
    int count, j, n, found = -1;
    char trainNumber[10];
    system("cls");
    aRead();
    cout << "\n\n\t\t\How many tickets do you want to buy? ";
    cin >> n;

    for (j = u; j < u + n; j++) {
        cout << "\n\n\t\t\tEnter train number: ";
        cin >> book[j].train_number;

        for (int i = 0; i < k; i++) {
            if (strcmp(book[j].train_number, add[i].train_number) == 0) {
                if (add[i].seat == 0) {
                    cout << "\n\n\t\t\tSeat not available";
                    cin.get();
                    system("cls");

                } else {
                    found = 1;
                    cout << "\n\t\t\tenter book " << j + 1 << " no ticket: ";
                    cout << "\n\t\t\tenter date: ";
                    cin >> book[j].date;
                    cout << "\n\t\t\tenter your name: ";
                    cin >> book[j].name;
                    cout << "\n\t\t\tenter your phone number: ";
                    cin >> book[j].phone;
                    cout << "\n\t\t\tseat number : " << add[i].seat;
                    book[j].seat = add[i].seat;
                    bookTicketWrite();
                    add[i].seat--;
                    aWrite();
                }
            }
        }

        if (found == -1) {
            cout << "\n\n\t\t\tTrain not found!!!";
            cin.get();
            system("cls");
            main();
        }
    }

    u = j;
    bookTicketWrite();
    cout << "\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
    cin >> count;

    if (count == 1) {
        system("cls");
        main();
    }

    if (count != 1) {
        exit(0);
    }
}

void cancelTicket() {
    viewPassengersRead();
    char phoneNumber[100];
    int location = -1, e;
    system("cls");

    cout << "\n\n\t\t\tEnter phone number: ";
    cin >> phoneNumber;

    for (e = 0; e < u; e++) {
        if (strcmp(phoneNumber, book[e].phone) == 0) {
            location = e;
            break;
        }
    }

    if (location == -1) {
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        cin.get();
        system("cls");
        main();
    } else {
        for (e = location; e < u; e++) {
            strcpy(book[e].date, book[e + 1].date);
            strcpy(book[e].train_number, book[e + 1].train_number);
            strcpy(book[e].name, book[e + 1].name);
            strcpy(book[e].phone, book[e + 1].phone);
            bookTicketWrite();
        }

        u--;
        bookTicketWrite();
        cout << "\n\n\t\t\t<<<<<<<<<<<<<<<tTicket cancelled successfully>>>>>>>>>>>>";
        cin.get();
        system("cls");
        main();
    }
}

void admin() {
    int choice;
    system("cls");
    std::cout << " ___________________________________" << std::endl;
    std::cout << "//                                  \\ "<< std::endl;
    std::cout << "|          WELCOME ADMIN            |" << std::endl;
    std::cout << "|-----------------------------------|" << std::endl;
    std::cout << "|        [1] VIEW PASSENGERS        |" << std::endl;
    std::cout << "|        [2] ADD TRAIN              |" << std::endl;
    std::cout << "|        [3] DELETE TRAIN           |" << std::endl;
    std::cout << "|        [4] BACK                   |" << std::endl;
    std::cout << "|                                   |" << std::endl;
    std::cout << "\\__________________________________//" << std::endl;
    std::cout << "         ENTER YOUR CHOICE:         " << std::endl;
    cin >> choice;

    switch (choice) {
        case 1:
            viewPassenger();
            break;
        case 2:
            addTrain();
            break;
        case 3:
            deleteTrain();
            break;
        case 4:
            system("cls");
            cin.get();
            main();
            break;
        default:
            cin.get();
            cout << "\n\t\t\tyou entered wrong KEY!!!!";
            cin.get();
            system("cls");
            main();
    }

   cin.get();
}
void password() {
    int number = 1234567;
    int pass;

    cout << "\n\t\t\tenter password: ";
    cin >> pass;

    if (pass == number) {
        cout << "\n\n\t\t\t<<<<<login successfully>>>>>";
        cin.get();
        system("cls");
        admin();
    } else {
        cout << "\n\n\t\t\t\t   ERROR!!!!!";
        cout << "\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
        cin.get();
        system("cls");
        main();
    }
}

void deleteTrain() {
    system("cls");
    aRead();
    char train[100];
    int location = -1, f;

    cout << "\n\n\tEnter train number: ";
    cin >> train;

    for (f = 0; f < k; f++) {
        if (strcmp(train, add[f].train_number) == 0) {
            location = f;
            break;
        }
    }

    if (location == -1) {
        cout << "\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        cin.get();
        system("cls");
        admin();
    } else {
        for (f = location; f < k; f++) {
            strcpy(add[f].si, add[f + 1].si);
            strcpy(add[f].train_number, add[f + 1].train_number);
            strcpy(add[f].train_name, add[f + 1].train_name);
            strcpy(add[f].start, add[f + 1].start);
            strcpy(add[f].destination, add[f + 1].destination);
            strcpy(add[f].price, add[f + 1].price);
            strcpy(add[f].time, add[f + 1].time);
            aWrite();
        }

        k--;
        aWrite();
        cout << "\n\n\t<<<<<<<<<<<<<Train deleted successfully>>>>>>>>>>>>>";
        cin.get();
        system("cls");
        admin();
    }
}

void viewPassenger() {
    int a, j;
    system("cls");
    viewPassengersRead();


    cout << "\n\n\t\t\tTrain number\t\tName\t\tPhone Number\t\tDate\t\tSeat\n";
    cout << "\n\t\t\t**\n";

    for (j = 0; j < u; j++) {
        cout << "\n\t\t\t" << book[j].train_number << "\t\t\t" << book[j].name << "\t\t" << book[j].phone << "\t\t" << book[j].date << "\t" << book[j].seat;
        book[j].seat++;
    }

    cout << "\n\t\t\t**\n";
    cout << "\n\n\t\t\tenter '1' for main menu & enter '0' for back: ";
    cin >> a;

    if (a == 1) {
        system("cls");
        main();
    }

    if (a == 0) {
        system("cls");
        admin();
    }
}

void addTrain() {
    system("cls");
    int ch;
    aRead();
    int i, a;

    cout << "\n\t\t     *******************ADD TRAINS*******************";
    cout << "\n\n\t\t\tHow many trains do you want to add: ";
    cin >> a;

    for (i = k; i < k + a; i++) {
        cout << "\n\t\t\tenter " << i + 1 << " train details: ";
        cout << "\n\t\t\tenter serial number: ";
        cin >> add[i].si;
        cout << "\n\t\t\tenter train number: ";
        cin >> add[i].train_number;
        cout << "\n\t\t\tenter train name: ";
        cin >> add[i].train_name;
        cout << "\n\t\t\tenter start place: ";
        cin >> add[i].start;
        cout << "\n\t\t\tenter destination place: ";
        cin >> add[i].destination;
        cout << "\n\t\t\tenter price: ";
        cin >> add[i].price;
        cout << "\n\t\t\tenter seat: ";
        cin >> add[i].seat;
        cout << "\n\t\t\tenter time: ";
        cin >> add[i].time;
    }

    cout << "\n\n\t\t\tconfirm train: (y=1/n=0):- ";
    cin >> ch;

    if (ch == 1) {
        aWrite();
        k = i;
        aWrite();
        system("cls");
        cout << "\n\n";
        cout << "\n\t\t\t\t   **********************************";
        cout << "\n\t\t\t\t   <<<<<Train added successfully>>>>>";
        cout << "\n\t\t\t\t   **********************************";
        cin.get();
        cin.get();
        system("cls");
        main();
    }

    if (ch == 0) {
        system("cls");
        admin();
    }

    if ((ch != 1) && (ch != 0)) {
        system("cls");
        main();
    }
}

void viewInfo() {
    int ch, i;

    system("cls");
    aRead();


    cout << "\n\t\t     ******************* AVAILABLE TRAINS *******************";
    cout << "\n\n\n    SI\tTrain number\tTrain name\tSource\tDestination\tPrice\tSeat\tTime\n\n";

    for (i = 0; i < k; i++) {
        cout << "    " << add[i].si << "\t" << add[i].train_number << "\t\t" << add[i].train_name << "\t\t" << add[i].start << "\t\t" << add[i].destination << "\t\t\t" << add[i].price << "\t" << add[i].seat << "\t" << add[i].time << endl;
    }

    cout << "    ***********************************************************************************************\n";
    cout << "\n\t\t\tpress '1' for main menu & press any key for exit:  ";
    cin >> ch;

    switch (ch) {
        case 1:
            system("cls");
            main();
            break;
        default:
            exit(0);
    }
}

void bookTicketWrite() {
    ofstream bookList("booklist.txt", ios::out | ios::binary);
    bookList.write((char*)&book, sizeof(book));
    bookList.close();

    ofstream bookListReport("booklistreport.txt", ios::out | ios::binary);
    bookListReport.write((char*)&u, sizeof(u));
    bookListReport.close();
}

void viewPassengersRead() {
    ifstream bookList("booklist.txt", ios::in | ios::binary);
    bookList.read((char*)&book, sizeof(book));
    bookList.close();

    ifstream bookListReport("booklistreport.txt", ios::in | ios::binary);
    bookListReport.read((char*)&u, sizeof(u));
    bookListReport.close();
}

void aWrite() {
    ofstream trainDetails("train_details.txt", ios::out | ios::binary);
    trainDetails.write((char*)&add, sizeof(add));
    trainDetails.close();

    ofstream trainReport("train_report.txt", ios::out | ios::binary);
    trainReport.write((char*)&k, sizeof(k));
    trainReport.close();
}

void aRead() {
    ifstream trainDetails("train_details.txt", ios::in | ios::binary);
    trainDetails.read((char*)&add, sizeof(add));
    trainDetails.close();

    ifstream trainReport("train_report.txt", ios::in | ios::binary);
    trainReport.read((char*)&k, sizeof(k));
    trainReport.close();
}
int main(){
cout<<ANSI_COLOUR_CYAN;
    std::cout << "                    __      __ ____ __     __        _____  ______  __      __ _____   _____  _______        \n";
    std::cout << "                    \\ \\    / // __ \\\\ \\   / / /\\    / ____||  ____| \\ \\    / /|_   _| / ____||__   __| /\\    \n";
    std::cout << "                     \\ \\  / /| |  | |\\ \\_/ / /  \\  | |  __ | |__     \\ \\  / /   | |  | (___     | |   /  \\   \n";
    std::cout << "                      \\ \\/ / | |  | | \\   / / /\\ \\ | | |_ ||  __|     \\ \\/ /    | |   \\___ \\    | |  / /\\ \\  \n";
    std::cout << "                       \\  /  | |__| |  | | / ____ \\| |__| || |____     \\  /    _| |_  ____) |   | | / ____ \\ \n";
    std::cout << "                        \\/    \\____/   |_|/_/    \\_\\_____||______|      \\/    |_____||_____/    |_|/_/    \\_\\\n";
    std::cout << "                                                                                                \n";
    std::cout << "                                                                                                \n";


    cout<<ANSI_COLOUR_RESET;
    cout<<ANSI_COLOUR_GREEN;
    std::cout << "                          #####\n";
    std::cout << "                       #######\n";
    std::cout << "            ######    ########       #####\n";
    std::cout << "        ###########/#####\\#####  #############\n";
    std::cout << "    ############/##########--#####################\n";
    std::cout << "  ####         ######################          #####\n";
    std::cout << " ##          ####      ##########/@@              ###\n";
    std::cout << "#          ####        ,-.##/`.#\\#####               ##\n";
    std::cout << "          ###         /  |$/  |,-. ####                 #\n";
    std::cout << "         ##           \\_,'$\\_,'|  \\  ###\n";
    std::cout << "         #              \\_$$$$$`._/   ##\n";
    std::cout << "                          $$$$$_/     ##\n";
    std::cout << "                          $$$$$        #\n";
    std::cout << "                          $$$$$\n";
    std::cout << "                          $$$$$\n";
    std::cout << "                         $$$$$\n";
    std::cout << "                         $$$$$\n";
    std::cout << "                         $$$$$                                                                ___\n";
    std::cout << "                         $$$$$                                                            _.-'   `-._\n";
    std::cout << "                        $$$$$                                                           ,'           `.\n";
    std::cout << "                        $$$$$                                                          /               \\\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~$$$$$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'~~~~~~~~~~~~~~~~`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "   ~      ~  ~    ~  ~ $$$$$  ~   ~       ~          ~     ~      ~  ~    ~  ~    ~      ~  ~    ~  ~  ~      ~  ~    ~  ~   ~      ~  ~    ~  ~      ~  ~  \n";
    std::cout << "       ~ ~      .o,    $$$$$     ~    ~  ~        ~         ~    ~  ~        ~       ~    ~  ~        ~             ~    ~  ~        ~       ~    ~  ~      \n";
    std::cout << "  ~            ~ ^   ~ $$$$$~        ______    ~        ~       ~    ~  ~        ~            ~    ~  ~        ~      ~    ~  ~        ~          ~        ~\n";
    std::cout << "_______________________$$$$$________|\\\\\\\\\\_____________________________________________________________________________________________________________\n";
    std::cout << "                       $$$$$        |>\\\\\\\\\\ \n";
    std::cout << "    ______             $$$$$        |>>\\\\\\\\\\ \n";
    std::cout << "   \\Q%=/\\,            $$$$$       /\\>>|#####|\n";
    std::cout << "    `------`           $$$$$      /=|\\>|#####|\n";
    std::cout << "                       $$$$$        ||\\|#####|\n";
    std::cout << "                      $$$$$$$          ||\"\"\"||\n";
    std::cout << "                      $$$$$$$          ||   ||\n";
    std::cout << "                     $$$$$$$$$\n";
    std::cout << "\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"$$$$$$$$$\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"""\"\"\"\"\"\"\"\"\"""\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"""\"\"\"\"\"\"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""";
    std::cout << "                        $$$\n";


cout<<ANSI_COLOUR_RESET;
    getch();
    system("cls");
    int ch;
    cout<<"***************** WOULD YOU LIKE TO BOOK A HOTEL? ***************** \n-->Press 1 for YES\n-->Press 2 for NO\n";
    cin>>ch;
   try{
       if(ch==1)
  {

hotel h;
system("cls");

cout<<ANSI_COLOUR_RESET;
cout<<ANSI_COLOUR_YELLOW;
    std::cout << "                                              ^^                        @@@@@@@@@\n";
    std::cout << "                                              ^^       ^^            @@@@@@@@@@@@@@@\n";
    std::cout << "                                                                   @@@@@@@@@@@@@@@@@@              ^^\n";
    std::cout << "                                                                  @@@@@@@@@@@@@@@@@@@@\n";
    std::cout << "                                        ~~~~ ~~ ~~~~~ ~~~~~~~~ ~~ &&&&&&&&&&&&&&&&&&&& ~~~~~~~ ~~~~~~~~~~~ ~~~\n";
    std::cout << "                                        ~         ~~   ~  ~       ~~~~~~~~~~~~~~~~~~~~ ~       ~~     ~~ ~\n";
    std::cout << "                                           ~      ~~      ~~ ~~ ~~  ~~~~~~~~~~~~~ ~~~~  ~     ~~~    ~ ~~~  ~ ~~\n";
    std::cout << "                                          ~  ~~     ~         ~      ~~~~~~  ~~ ~~~       ~~ ~ ~~  ~~ ~\n";
    std::cout << "                                       ~  ~       ~ ~      ~           ~~ ~~~~~~  ~      ~~  ~             ~~\n";
    std::cout << "                                      ~             ~        ~      ~      ~~   ~             ~\n";
    cout<<"\n\n\n"<<endl;

cout<<ANSI_COLOUR_RESET;
    cout<<ANSI_COLOUR_ORANGE;
    std::cout << "                                                   __  _  _ __  _   __  ___ _____   _   __  __   __ ___  \n";
    std::cout << "                                                 /' _/| || |  \\| |/' _/| __|_   _| | | /__\\| _\\ / _] __| \n";
    std::cout << "                                                 `._`.| \\/ | | ' |`._`.| _|  | |   | || \\/ | v | [/\ _|  \n";
    std::cout << "                                                 |___/ \\__/|_|\\__||___/|___| |_|   |___\\__/|__/ \\__/___| \n";

cout<<ANSI_COLOUR_RESET;
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

getch();
h.main_menu();
}
else
    throw 1;
}
catch(int x)
{
system("cls");
int z;
cout<<"Enter your choice:\n";
cout<<"1.For Airline Ticket Booking\n2.For Train Ticket Boooking\n";
cin>>z;
switch(z)
{
    case 1:
        {
    class d_booking d1;//object for class d_booking
    class i_booking i1;//object for class i_booking
    class passenger p1;//object for class passenger
    class payment p2;//object for class payment
    int ch,ch1,n;//integer variables
    char input;//character variables
    do//do while loop
    {
    	system("CLS");


    cout<<ANSI_COLOUR_BROWN;
    std::cout << "                                                                                                    ,--.\n";
    std::cout << "                                                                                                    \\  _\\_\n";
    std::cout << "                                                                                                    _\\/_|_\\____.'\\\n";
    std::cout << "                                                                                                  -(___.--._____(\n";
    std::cout << "                                                                                                       \\   \\\n";
    std::cout << "                                                                                                        \\   \\\n";
    std::cout << "                                                                                                          `--'\n";
    cout<<"_ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"_ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . _ . "<<endl;

cout<<"\n\n\n";
cout<<ANSI_COLOUR_RESET;
    cout<<ANSI_COLOUR_RED;
    std::cout << "     ___       __  .______           ______    _______  ____    ____  _______.     _______. _______ ____    ____ \n";
    std::cout << "    /   \\     |  | |   _  \\         /  __  \\  |       \\ \\   \\  /   / /       |    /       ||   ____|\\   \\  /   / \n";
    std::cout << "   /  ^  \\    |  | |  |_)  |       |  |  |  | |  .--.  | \\   \\/   / |   (----`   |   (----`|  |__    \\   \\/   /  \n";
    std::cout << "  /  /_\\  \\   |  | |      /        |  |  |  | |  |  |  |  \\_    _/   \\   \\        \\   \\    |   __|    \\_    _/   \n";
    std::cout << " /  _____  \\  |  | |  |\\  \\----.   |  `--'  | |  '--'  |    |  | .----)   |   .----)   |   |  |____     |  |     \n";
    std::cout << "/__/     \\__\\ |__| | _| `._____|    \\______/  |_______/     |__| |_______/    |_______/    |_______|    |__|     \n";
    std::cout << "                                                                                                                  \n";

    cout<<ANSI_COLOUR_RESET;

    std::cout << " ___________________________________" << std::endl;
    std::cout << "//                                  \\ "<< std::endl;
    std::cout << "|        [1] BOOK FLIGHT            |" << std::endl;
    std::cout << "|        [2] CANCEL FLIGHT          |" << std::endl;
    std::cout << "|        [3] CHECK TICKET           |" << std::endl;
    std::cout << "|        [4] EXIT                   |" << std::endl;
    std::cout << "\\__________________________________//" << std::endl;
    cout<<"\n"<<endl;
    std::cout << "         ENTER YOUR CHOICE:         " << std::endl;

    cin >> ch;
      switch(ch)//witch case
      {
          case 1://condition
          system("CLS");
              cout << "\n\n\1-> Domestic Fights(1) \n\-> International Flights(2)" << endl;
              cout << "\nPlease enter your option" << endl;
              cin >> ch1;
              switch(ch1)//inner switch case
              {
                   case 1://for booking domestic ticket
                        p1.d_pnr();
                        p1.p_detail(1);//function calls
                        p1.gender_check();
                        p1.more_details();
                        p2.pay_detail();
                        p1.disp();
                        createfile(p1);//call to create file
                        break;
                   case 2: //for booking international ticket
                           p1.p_detail(2);//function calls
                           p1.i_pnr();
                           p1.gender_check();
                           p1.more_details();
                           p2.pay_detail();
                           p1.dispi();
                           createfilei(p1);//call to create file
                           break;
                   default://wrong input
                    cout << "Wrong input entered\nTry again\n\n\n" << endl;
                    return main();
              }
          break;
          case 2:
              //for canceling ticket
              system("CLS");
              cout << "\-> Domestic Fights(1) \n\-> International Flights(2)" << endl;
                 cout << "\nPlease enter your option" << endl;
                 cin >> ch1;
                  if(ch1==1)
                {
                   cout << "Please enter your PNR no.:" << endl;
                   cin>>n;
                   cancelticket(n);//function call for domestic booking cancellation
                }
                 else if(ch1==2)
               {  cout << "Please enter your PNR no.:" << endl;
                  cin>>n;
                  cancelticketi(n);//function call for international cancellation
               }
               else
               {
                   cout << "Wrong input entered\nTry again\n\n\n";
                   return main();
               }
               break;
          case 3://for displaying booked ticket details
          system("CLS");
                  cout << "\-> Domestic Fights(1) \n\-> International Flights(2)" << endl;
                  cout << "\nPlease enter your option" << endl;
                  cin >> ch1;
                  if(ch1==1)
                  {cout << "Please enter your PNR no.:" << endl;
                  cin>>n;
                  checkticket(n);}//function call to display domestic ticket details
                  else if(ch1==2)

                  {  cout << "Please enter your PNR no.:" << endl;
                     cin>>n;
                     checkticketi(n);//function call to display domestic ticket details
                  }
                   else
               {
                   cout << "Wrong input entered.\nTry again\n\n\n";
                   return main();
               }
               break;
            case 4:
			system("CLS");
			cout<<"Have a fun and enjoyable trip!";
			return 0;
          default:    //for wrong input
            cout << "Wrong input entered\nTry again.\n\n\n\n" << endl;
            return main();
      }
    cout<<"\n\n\nDo you wish to continue:(y/n)" << endl;
    cin >> input;
  }while(input=='y' || input=='n');//condition for do while loop
    }
    case 2:{ system("cls");
    aRead();
    viewPassengersRead();

    system("COLOR 0f");

    int choice;
    time_t currentTime;
    time(&currentTime);

    cout << "\n\t\t\t     " << ctime(&currentTime);
    cout<<"\n\n\n";
    cout<<ANSI_COLOUR_BROWN;

    std::cout << "                                 (\n";
    std::cout << "                                (  )  )\n";
    std::cout << "                             ( ) )\n";
    std::cout << "                            ()        ____.______._____\n";
    std::cout << "                          .--.  ----- |  _  - a:f -   |\n";
    std::cout << "                         __||___|[_]| |.|#|.[].[].[]..|\n";
    std::cout << "                        o)__ |_ | ..|=|_|-|___________|\n";
    std::cout << "                    __ <(__(*)_(*)_~_____~(*)____(*)_____\n";
    std::cout << " ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";

cout<<ANSI_COLOUR_RESET;
cout<<"\n\n\n";
cout<<ANSI_COLOUR_MAGENTA;

    std::cout << ".______           ___       __   __         ____    ____  ______   ____    ____  ___       _______  _______ \n"
                 "|   _  \\         /   \\     |  | |  |        \\   \\  /   / /  __  \\  \\   \\  /   / /   \\     /  _____||   ____|\n"
                 "|  |_)  |       /  ^  \\    |  | |  |         \\   \\/   / |  |  |  |  \\   \\/   / /  ^  \\   |  |  __  |  |__   \n"
                 "|      /       /  /_\\  \\   |  | |  |          \\      /  |  |  |  |   \\_    _/ /  /_\\  \\  |  | |_ | |   __|  \n"
                 "|  |\\  \\----. /  _____  \\  |  | |  `----.      \\    /   |  `--'  |     |  |  /  _____  \\ |  |__| | |  |____ \n"
                 "| _| `._____|/__/     \\__\\ |__| |_______|       \\__/     \\______/      |__| /__/     \\__\\ \\______| |_______|\n";

    cout<<ANSI_COLOUR_RESET;
    cout<<"\n\n\n"<<endl;

    std::cout << " ___________________________________" << std::endl;
    std::cout << "//                                  \\ "<< std::endl;
    std::cout << "|        [1] VIEW INFORMATION       |" << std::endl;
    std::cout << "|        [2] BOOK TICKET            |" << std::endl;
    std::cout << "|        [3] CANCEL TICKET          |" << std::endl;
    std::cout << "|        [4] ADMIN                  |" << std::endl;
    std::cout << "|        [5] EXIT                   |" << std::endl;
    std::cout << "\\__________________________________//" << std::endl;
    cout<<"\n"<<endl;
    std::cout << "         ENTER YOUR CHOICE:         " << std::endl;


    cin >> choice;

    switch (choice) {
        case 1:
            viewInfo();
            break;
        case 2:
            bookTicket();
            break;
        case 3:
            cancelTicket();
            break;
        case 4:
            password();
            break;
        case 5:
            system("cls");

            cin.get();
            exit(0);
            break;
        default:
            system("cls");

            cout << "\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>" << endl;
            cout << "\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>" << endl;
            cin.get();
            system("cls");
            main();}
    }
        }}   }
