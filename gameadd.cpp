#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
string filen="library.txt";
fstream file(filen);
string line;
string a,b,c,cedit;
string input="d";
fstream tempfile("gametemp.txt");
string a2,b2,c2;

while(getline(file,line))
{
    istringstream linevar(line);
    linevar >> a >> b >>c;
    if(a!=input)
    {
        tempfile<<line<<"\n";   
    }
    else
    {
        c2=c;
        stringstream ss(line);
        stringstream updated;
        string w;
        vector <string> words;
        int num;
        num=stoi(c2);
        num=num-100;
        string c3=to_string(num);       
        while (ss >> w) 
        {
            words.push_back(w);
        }
        words[2]=c3;
        for(int i=0; i<words.size();i++)
        {
            updated << words[i]<<" ";
            if (i != words.size() - 1) 
            {
                ss << " "; 
            }
        }
        string updatedsentence=updated.str();
        tempfile << updatedsentence << "hello2";
    }
        
        a2=a;
        b2=b;
        /*tempfile<<line<<"hello";*/

    }

tempfile.close();
file.close();
ofstream ofs;
ofs.open("library.txt",ofstream::out | ofstream::trunc);
ofs.close();
fstream file2("gametemp.txt");
string line2;
fstream file3("library.txt");
while(getline(file2,line2))
{
    file3<<line2<<endl;
}
return 0;
}