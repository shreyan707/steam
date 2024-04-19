#include<iostream>
#include<string.h>
#include<fstream>
using namespace std ;

void login();
void signin();
void forgot();

int main()
{
    int choise;
    cout<<"\t\t\t______________________________________________________________\n\n\n";
    cout<<"\t\t\t                        Welcome to the login page             \n\n\n";
    cout<<"\t\t\t_____________________        MENU       ______________________\n\n\n";
    cout<<"\n\n\n";
    cout<<"| Press 1 to LOGIN           |"<<endl;
    cout<<"| Press 2 to SIGNIN          |"<<endl;
    cout<<"| Press 3 to FORGOT PASSWORD |"<<endl;
    cout<<"| Press 4 to EXIT            |"<<endl;
    cout<<"\n\t\t\t ENTER YOUR CHOICE : ";
    cin>>choise;
    cout<<endl;

    switch(choise)
    {
        case 1:
            login();
            break;

        case 2:
            signin();
            break;

        case 3:
            forgot();
            break;

        case 4 :
            cout<<"\t\t\t THANK YOU! \n\n";
            break;

        default:
            system("cls");
            cout<<"\t\t\t Please select from the option given above \n"<<endl;
            main();

    }

}

 void login()
 {
  string userID, password, id, pass;
  system("cls");
  cout<<"\t\t\t Please enter the username and password :" <<endl;
  cout<<"\t\t\t USERNAME ";
  cin>>userID;
  cout<<"\t\t\t PASSWORD ";
  cin>>password;

  ifstream input("record.txt");

 }



