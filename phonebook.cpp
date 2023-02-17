#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<unistd.h>
using namespace std;
fstream filee;
struct node1
{
    char phoneNumber[30];
    char name[30];
    int time;
    struct node1* link;
};
class LinkStack
{
    struct node1* top;
public:
    LinkStack()
    {
        top=NULL;
    }
    void createTop(char p[30],char N[30],int t)
    {
        struct node1* n=new node1;
        strcpy(n->phoneNumber,p);
        strcpy(n->name,N);
        n->time=t;
        n->link=NULL;
        top=n;
    }

    void push(char p[30],char N[30],int t)
    {
        if(top==NULL)
        {
            createTop(p,N,t);
        }
        else{
            struct node1* n=new node1;
            strcpy(n->phoneNumber,p);
            strcpy(n->name,N);
            n->time=t;
            n->link=top;
            top=n;
        }
    }
    node1* pop()
    {
        if(top==NULL)
            return NULL;
        else
        {
            node1* temp=top;
            top=top->link;
            temp->link=NULL;
            delete temp;
        }
        return top;
    }
    void displayTop()
    {
        /*cout<<endl<<"Name           :"<<top->name;
        cout<<endl<<"Phone number   :"<<top->phoneNumber;
        cout<<endl<<"Duration       :"<<top->time;
        cout<<endl<<"Date           :"<<top->day<<"/"<<top->month<<"/"<<top->year;*/
        cout<<setw(20)<<left<<top->name;
        cout<<setw(30)<<top->phoneNumber;
        cout<<setw(2)<<int(top->time)<<setw(20)<<" mins";

    }
};
class call
{
    char phoneNumber[30];
    char name[30];
    int time;
public:
    void insert(char p[30],char a[30],int b)
    {
        strcpy(phoneNumber,p);
        strcpy(name,a);
        time=b;
    }
};
call cal;
LinkStack s;
void phonebook()
{
    int ch;
    char name1[30],phone[30];
    int time1;
    do
    {
        system("cls");
        cout<<"\n\t--------------------------";
        cout<<"\n\t      PHONEBOOK";
        cout<<"\n\t--------------------------";
        cout<<"\n\t1. Make a call";
        cout<<"\n\t2. View recent history ";
        cout<<"\n\t3. Back to main menu";
        cout<<"\n\nEnter your choice : ";
        cin>>ch;

        if (ch==1)
        {
            filee.open("Calls.bin",ios::binary|ios::app);
            cout<<endl<<"\t Enter contact name : ";
            cin>>name1;
            cout<<endl<<"\t Enter phone number : ";
            cin>>phone;
            cout<<endl<<"\t Enter duration (mins) : ";
            cin>>time1;
            s.push(name1,phone,time1);
            cal.insert(name1,phone,time1);
            filee.write((char *)&cal,sizeof(cal));
            filee.close();
        }

        else if (ch==2)
        {

            int recents;
            cout<<endl<<"How many recent history contacts you want to view?";
            do
            {
                cout<<endl<<"Enter here : ";
                cin>>recents;
                if(recents <0)
                {
                    cout<<endl<<"Please enter a positive value";
                }
            }while(recents<0);
            node1* temp;
            cout<<endl<<"--------------------------------------------------------------------------------";
            cout<<endl<<setw(20)<<left<<"NAME"<<setw(30)<<"CONTACT NUMBER"<<setw(25)<<"DURATION";
            cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
            for(int i=0;i<recents;i++)
            {
                s.displayTop();
                temp=s.pop();
                if(temp==NULL)
                {
                    cout<<endl<<"All contacts are displayed";
                    break;
                }

            }
            sleep(3);
        }

        else if (ch!=3)
        {
            cout<<"Invalid input"<<endl;
        }
    }while (ch!=3);
}
