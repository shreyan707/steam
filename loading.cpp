#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>


using namespace std;

void normal()
{
    system("CLS");
    cout<<"PROCESS :"<<endl;
    for(int i=0;i<60;i++)
    {
        cout<<char(176);
    }
    cout<<'\r';
    cout<<"  ";
    for(int i=0;i<58;i++)
    {   
        cout<<char(178);
        Sleep(50);
    }
    cout<<endl;
    cout<<"PROCESS COMPLETE"<<endl;
}



void vec()
{
    string w="[                                                              ]";
    vector <string> word;
    stringstream ss(w);
    for( char c :w)
    {
        word.push_back(string(1,c));
    }
    int per;
    for(int i=0;i<word.size();i++)
    {
        per=(i/word.size())*100;
        string pers=to_string(per);
        word[i]='|';
        word[i+1]=pers;
        word[i+2]="%";
        for(int i=0;i<word.size();i++)
        {
            cout<<word[i];
        }
        cout<<"\r";
        Sleep(1000);
    }
    cout<<endl;

    
}

int main()
{
    normal();
}
