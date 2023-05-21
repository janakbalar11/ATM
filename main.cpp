#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <list>
using namespace std;

//account no are 1-10.
//passwords are password + the account number. Ex: Account no = 1. password = password1. 


class Transactions{
public:
    vector<string> type; 
    vector<string> date;

 vector<string>getType(){
    return type;
}
vector<string>getDate(){
    return date;
}

void insertVectorStr(string s_input){
  type.push_back(s_input);
}
void insertVectorDate(string d_input){
  date.push_back(d_input);
}


};






class Account{
    public:
    int account;
    string password;
    float balance;
    vector<float> transactions;
    Transactions t;
public:
   Account(int account, string password, float balance, vector<float> transactions){
     this->password = password;
     this->account = account;
     this->balance = balance;
     this->transactions = transactions;
     
   }
    Account() : account(0), password(""), balance(0) {}

  int getBalance() const{
    return balance;
  }
  void setBalance(int newBalance);

  int getAccount() const{
    return account;
  }

  string getPassword() const{
    return password;
  }

  vector<float> getTransactions() {
      return transactions;
        }


 void showBalance(){
  cout<<"Main Window --> Show Balance"<<endl;
  cout<<"=================================================="<<endl;
  cout<<"Your account is "; cout<<account<<endl;
  cout<<"Your current balance is: $"; cout<<balance<<endl;
  cout<<"--------------------------------------------------"<<endl;
  cout<<"Press enter to go back to the Main Window"<<endl;

  
}

void insertVector(float input){
  transactions.push_back(input);
}


void Deposit(){
  cout<<"Main Window --> Deposit (Enter the following information)"<<endl;
  cout<<"===================================================================="<<endl;
  cout<<"The amount you want to deposit: "; float input;
  cin>>input;
  while(input<0){
      cout<<"Please enter a positive value: ";
      cin>> input;
    }
  if(input>0){
    balance+=input;
  }
  
  
  cout<<"--------------------------------------------------------------------"<<endl;
  cout<<"Well done. This was added to your balance successfully... Press enter to go back to the Main Window"<<endl;
  insertVector(input);


}
void Withdraw(){
  cout<<"Main Window --> Withdraw (Enter the following information)"<<endl;
  cout<<"===================================================================="<<endl;
  cout<<"The amount you want to withdraw: "; float input;
  cin>>input;
  
  while(input>=balance){
    cout<<"Please input an amount less than your current balance: ";
    cin>>input;

  }

  if(input<=balance){
      balance-=input;
  }

  cout<<"--------------------------------------------------------------------"<<endl;
  cout<<"Please take your money then... Press enter to go back to the Main Window"<<endl;
  insertVector(input);
   
}

void ShowTransactions(){
  cout<<"Main window --> Show All transactions"<<endl;
  cout<<"====================================================================="<<endl;
  cout<<"Account no: "; cout<<account<<endl;
  cout<<"-----------------------------------------------------"<<endl;
  cout<<"Date\t\t\t\t\t\t|Type\t\t\t|Amount"<<endl;
  cout<<"-----------------------------------------------------"<<endl;
  
}

};



  int main(){
  int size = 10;
   Account user[size];
    static int num_accounts = 0;
   for(int i = 0; i<size; i++){
     string password = "password" + to_string(i+1);
     const char* password_cstr = password.c_str();
     vector<float> transactions = {};
      num_accounts+=1;
      user[i] = Account(num_accounts, password_cstr, 5000, transactions);
    
   }
      
    cout<<"Login Window"<<endl;
    cout<<"============="<<endl;
    cout<<"Enter Your Account no: "<<endl;
    int account;
    cin >> account; 
    
  int found = 0;
  int ver = 0;
   while(found==0){ 
    for(int i = 0; i< 10; i++){
      if(user[i].getAccount()==account){
        found =1;
        cout<<"Enter your password: "<< endl; 
        string password;
        cin>> password;
        while(ver==0){
          if(strcmp(user[i].getPassword().c_str(),password.c_str())==0){
          ver = 1;
          goto label;
        }
          cout<<"Enter your password: "<<endl;
         cin>>password;
        }
        
      }
    
      }
      cout<<"Enter Your Account no: "<<endl;
     cin>>account;
     }
      
    label: 


    while(1){
    cout<<"Main Window"<<endl;
    cout<<"==========="<<endl;
    cout<<"Choose one of the following options:"<<endl;
    cout<<"(1) Show balance"<<endl;
    cout<<"(2) Deposit"<<endl;
    cout<<"(3) Withdraw"<<endl;
    cout<<"(4) Show All Transactions"<<endl;
    
    cout<<"Enter your choice:"<<endl;
    int choice;
    cin >> choice;
    
    for (int i = 0; i < 10; i++) {
        if(user[i].getAccount() == account){
          if(choice==1){
          user[i].showBalance();
          cin.ignore();  
          cin.get();
            
      }
    else if(choice==2){
      user[i].Deposit();
      user[i].t.insertVectorStr("Deposit");
      time_t now = time(0);
      char* dt = ctime(&now);
      user[i].t.insertVectorDate(string(dt, strlen(dt) - 1));
      cin.ignore();  
      cin.get();
    }
   else if(choice==3){
      user[i].Withdraw();
      user[i].t.insertVectorStr("Withdraw");
      time_t now = time(0);
      char* dt = ctime(&now);
      user[i].t.insertVectorDate(string(dt, strlen(dt) - 1));
      cin.ignore();  
      cin.get();
    }
    else if(choice==4){
      user[i].ShowTransactions();
      int j = i;
       for(int k= 0 ;k< user[j].t.type.size(); k++){
           cout<<user[j].t.date[k]; cout<<"\t|";  cout<<user[j].t.type[k]; cout<<"\t\t|"; cout<<user[j].transactions[k]<<endl;
            
         }
      cout<<"-----------------------------------------------------"<<endl;
      cout<<"Press enter to go back to the Main Window"<<endl;
      cin.ignore();  
      cin.get();
    }
          
        
      
    }
 
    
      }
      }
    return 0;
  }
