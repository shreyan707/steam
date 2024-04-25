#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
string filen="test.txt";
fstream file(filen);
string line;
string a,b,c,cedit;
string input="d";
fstream tempfile("temp.txt");
string a2,b2,c2;

while(getline(file,line))
{
    istringstream linevar(line);
    linevar >> a >> b >>c;
    if(a!=input)
    {
        tempfile<<line<<endl;   
    }
    else
    {
        a2=a;
        b2=b;
        c2=c;
    }
}
int num;
num=stoi(c2);
num=num+100;
string c3=to_string(num);
tempfile<<a2<<" "<<b2<<" "<<c3<<endl;
tempfile.close();
file.close();
ofstream ofs;
ofs.open("test.txt",ofstream::out | ofstream::trunc);
ofs.close();
fstream file2("temp.txt");
string line2;
fstream file3("test.txt");
while(getline(file2,line2))
{
    file3<<line2<<endl;
}
return 0;
}