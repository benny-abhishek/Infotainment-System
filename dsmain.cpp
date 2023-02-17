#include<iomanip>
#include<iostream>
#include "astarmod1.cpp"
#include "audio.cpp"
#include "pone1.cpp"
using namespace std;
int main()
{
    int ch;
    do
    {
        cout<<endl<<"\t\t---------------------------";
        cout<<endl<<"\t\t    INFOTAINMENT SYSTEM";
        cout<<endl<<"\t\t---------------------------";
        cout<<endl<<"\n\t\t1. Navigation";
        cout<<endl<<"\t\t2. Audio system";
        cout<<endl<<"\t\t3. Phonebook";
        cout<<endl<<"\t\t4. Exit";
        cout<<endl<<"\t Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:navigation();break;
            case 2:audioplayer();break;
            case 3:phonebook();break;
            case 4:return 0;
        }
    }while(ch!=6);
}
