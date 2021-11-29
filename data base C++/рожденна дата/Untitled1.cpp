#include <iostream>
#include <string>
using namespace std;
class People
{
private:
int age;
string name;
int nowYear;
int birthYear;
public:
void setAgeNameNowYear();
void setBirthYear();
int getAge();
string getName();
int getNowYear();
int getBirthYear();
};
void People::setAgeNameNowYear()
{
cout<<"Enter name:";
cin>>name;
cout<<"Enter age:";
cin>>age;
cout<<"Enter the current year:";
cin>>nowYear;
}
void People::setBirthYear()
{
 birthYear=nowYear-age;
}
int People::getAge()
{
    return age;
}
string People::getName()
{
    return name;
}
int People::getBirthYear()
{
    return birthYear;
}
int People::getNowYear()
{
    return nowYear;
}
int main()
{
    People f1;
    f1.setAgeNameNowYear();
    f1.setBirthYear();
    cout<<"Name:"<<f1.getName()<<endl;
    cout<<"Age:"<<f1.getAge()<<endl;
    cout<<"Current year:"<<f1.getNowYear()<<endl;
    cout<<"Birth year:"<<f1.getBirthYear()<<endl;
    return 0;
}
