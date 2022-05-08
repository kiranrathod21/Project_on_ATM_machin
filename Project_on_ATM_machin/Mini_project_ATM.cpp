
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

// Mini Project using OOPS of CPP


// Write a program showing ATM functionalities using OOps
// 1) Check Balance
// 2) Cash WithDraw
// 3) User Datails 
// 4) Update Mobile No


class atm{    // class atm
   private:
   long int account_No;       // private member varibles
   string name;
   int PIN;
   double balance;
   string mobile_No;
  

  public:      

                                              // Public Member functions
      // setData function is setting Data into the private member variable                            
   void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a){
      account_No=account_No_a;
      name=name_a;
      PIN=PIN_a;
      balance=balance_a;
      mobile_No=mobile_No_a;


   }
   //getAccountNo function is returning the user's account no 

   long int getAccountNo(){
  
       return account_No;

   }

   // getName function is returning the user's name
   string getName(){
       return name;
   }
 // getPIN function is returning the user's PIN
   int getPIN(){
       return PIN;
   }

   //getBalance is returning the user's Bank Balance
   double getBalance(){
       return balance;
   }

   // getMobileNo is returning the user's Mobile no
   string getMobileNo(){
       return mobile_No;
   }

   // setMobile function is updating the user mobile no
   void setMobile(string mob_prev, string mob_new){
    if(mob_prev==mob_new){                  //it will check old mobile no
        mobile_No =mob_new;              // and Update with new,if old matches
        cout<<endl<<"Sucessfully Updated Mobile No.";    // getch is to hold the screen (untill user press any key)
        _getch();
    }
    else{              //getch is to hold the screen (untill user press any key) 
        cout<<endl<<"Incorrect !!! Old Mobile No ";
        _getch();
    }
   }

   void cashWithDraw(int amount_a){
       if(amount_a > 0 && amount_a < balance){
           balance -=amount_a;
           cout<<endl<<"Please Collect Your Balance";
           cout<<endl<<"Available Balance: "<<balance;
           _getch();
       }
       else{
           cout<<endl<<"Invalid Input or Insufficient Balance";
           _getch();
       }
   }

};

int main(){
     
  int choice=0,enterPIN;
  long int enterAccountNo;
//   system("cls");

//create user (object)

  atm user1;
user1.setData(123456,"Tim",1111,45000.90,"7822065660");

do{
    system("cls");

    cout<<endl<<"***Welcome to ATM*****"<<endl;
    cout<<endl<<"Enter Your Account NO: ";
    cin>>enterAccountNo;

    cout<<endl<<"Enter PIN: ";
    cin>>enterPIN;


    // check weather enter value matches with user details 

    if((enterAccountNo==user1.getAccountNo()) && (enterPIN==user1.getPIN())){
        do{
            int amount =0;
            string oldMobileNo,newMobileNo;

            system("cls");

            //user interface
            cout<<endl<<"***Welcome to ATM *****"<<endl;
            cout<<endl<<"Select Options";
            cout<<endl<<"1.Check Balance";
            cout<<endl<<"2.Cash Withdraw";
            cout<<endl<<"3.Show User Details";
            cout<<endl<<"4.Update Mobile No";
            cout<<endl<<"5.Exist"; 
            cin>>choice;


            switch(choice){
                case 1: 
                     cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                     getch();
                     break;

                case 2: 
                     cout<<endl<<"Enter the Amount: ";
                     cin>>amount;
                     user1.cashWithDraw(amount);

                     break; 

                 case 3:
                   cout<<endl<<"*** User Details are:-" ;
                   cout<< endl<<"-> Account No   : "<<user1.getAccountNo();
                   cout<<endl<<"-> Name          :  "<<user1.getName();
                   cout<<endl<<"-> Balance       : "<<user1.getBalance();
                   cout<<endl<<"-> Mobile NO     : "<<user1.getMobileNo();

                   _getch();
                   break;


                 case 4: 
                      cout<<endl<<"Enter Old Mobile No. ";
                      cin>>oldMobileNo;

                      cout<<endl<<"Enter New Mobile No. ";
                      cin>>newMobileNo;

                      user1.setMobile(oldMobileNo,newMobileNo);
                      break;   

                case 5: 
                     exit(0);

                default: 
                     cout<<endl<<"Enter Valid Data !!!";    
                                  
            }
        }while(1);
    }
}while(1);




    return 0;
}