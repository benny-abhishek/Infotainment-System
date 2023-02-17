#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

fstream file;
char now[30];

class node{
public:
    char data[30];
    node* bwd;
    node* fwd;
};

class dll{
    node* ptr,*start,*playing;
public:
    dll(){
        start=NULL;
        playing=NULL;
    }


    void createNode(char elt[30]){
        node* n=new node;
        strcpy(n->data,elt);
        n->bwd=NULL;
        n->fwd=NULL;
        start=n;
    }
    void insertNode_end(char elt[30]){
        if (start==NULL){
            createNode(elt);
        }
        else{
            ptr=start;
            while(ptr->fwd!=NULL){
                ptr=ptr->fwd;
            }
            node* n=new node;
            strcpy(n->data,elt);
            n->fwd=NULL;
            n->bwd=ptr;
            ptr->fwd=n;
        }
    }
    void insertNode_beg(char elt[30]){
        if (start==NULL){
            createNode(elt);
        }
        else{
            node* n=new node;
            strcpy(n->data,elt);
            n->fwd=start;
            n->bwd=NULL;
            start=n;
        }
    }
    void insertNode_mid(char elt[30],char afterWhich[30]){
        if (start==NULL){
            createNode(elt);
        }
        else{
            ptr=start;
            while(ptr!=NULL){
                if(ptr->data==afterWhich){
                    node* n=new node;
                    strcpy(n->data,elt);
                    n->fwd=ptr->fwd;
                    n->bwd=ptr;
                    ptr->fwd->bwd=n;
                    ptr->fwd=n;
                    break;
                }
                ptr=ptr->fwd;
            }
        }
    }
    void delete_end(){
        ptr=start;
        node* temp=new node;
        while(ptr->fwd->fwd!=NULL){
            ptr=ptr->fwd;
        }
        temp=ptr->fwd;
        ptr->fwd=NULL;
        delete temp;
    }
    void delete_beg(){
        node* temp=new node;
        temp=start;
        start=start->fwd;
        delete temp;
    }

    void delete_mid(char d[30]){
        ptr=start;
        while(ptr->fwd!=NULL){
            if (ptr->fwd->data==d){
                node* temp=ptr->fwd;
                ptr->fwd=temp->fwd;
                temp->fwd->bwd=ptr;
                break;
            }
            ptr=ptr->fwd;
        }
    }
    void display(){
        ptr=start;
        int c=1;
        cout<<endl<<"Playlist : \n" <<endl;
        while(ptr!=NULL){
            cout<<c<<". "<<ptr->data<<endl;
            ptr=ptr->fwd;
            c++;
        }
    }

    int length(){
        ptr=start;
        int count=0;
        while (ptr!=NULL)
        {
            count++;
            ptr=ptr->fwd;
        }
        return count;
    }

    void startplaylist()
    {
        playing=start;
        strcpy(now,playing->data);
    }

    void nextsong()
    {
        if (playing->fwd==NULL || playing==NULL)
        {
            cout<<"No more songs to play."<<endl;
        }
        else
        {
            playing=playing->fwd;
            strcpy(now,playing->data);
        }
    }

    void prevsong()
    {
        if (playing->bwd==NULL)
        {
            cout<<"No previous songs."<<endl;
        }
        else
        {
            playing=playing->bwd;
            strcpy(now,playing->data);
        }
    }

};

void display1(char a[30])
{
    cout<<endl<<"------------------------------------------------------------";
    cout<<endl<<endl<<endl<<"         Now playing : "<<a;
    cout<<endl<<endl<<endl<<"------------------------------------------------------------\n"<<endl;
}

class music
{
    char name[30];
    char album[30];
public:
    void getdata()
    {
        cout<<"Enter song name : ";
        cin.ignore(1);
        cin.getline(name,30);
        cout<<"Enter album : ";
        cin.ignore(1);
        cin.getline(album,30);
    }
    char* getname()
    {
        return name;
    }

};

int flag=0;
music m1;
void audioplayer()
{
    dll audio;
    int ch;
    do
    {
        system("cls");
        cout<<"\n\t--------------------------";
        cout<<"\n\t      MUSIC SYSTEM";
        cout<<"\n\t--------------------------";
        cout<<"\n\t1. Start from beginning";
        cout<<"\n\t2. Next song ";
        cout<<"\n\t3. Previous song ";
        cout<<"\n\t4. Add new song ";
        cout<<"\n\t5. View playlist";
        cout<<"\n\t6. Delete song from playlist";
        cout<<"\n\t7. Back to main menu";
        cout<<"\n\nEnter your choice : ";
        cin>>ch;
        file.open("Music.bin",ios::binary|ios::in);
        if (!file)
        {
            cerr<<"Error opening file\n";
            exit(0);
        }

        if (flag==0)
        {
            while (file.read((char *)&m1,sizeof(m1)))
            {
                audio.insertNode_end(m1.getname());
            }
            flag=1;
        }

        file.close();
        if (ch==1)
        {

            audio.startplaylist();
            display1(now);

            sleep(3);
        }

        else if (ch==2)
        {
            audio.nextsong();
            display1(now);
            sleep(3);
        }

        else if (ch==3)
        {
            audio.prevsong();
            display1(now);
            sleep(3);
        }

        else if (ch==4)
        {
            m1.getdata();
            file.open("Music.bin",ios::binary|ios::out|ios::app);
            file.write((char *)&m1,sizeof(m1));
            audio.insertNode_end(m1.getname());
            cout<<"New song added!"<<endl;
            file.close();
        }

        else if (ch==5)
        {
            audio.display();
            sleep(3);
        }

        else if (ch==6)
        {
            char delno[30];
            int f=0,count=0,fc=0;
            audio.display();
            cout<<endl<<"\n\tEnter song name to delete : ";
            cin.ignore(1);
            cin.getline(delno,30);
            fstream file1;
            file.open("Music.bin",ios::binary|ios::in);
            file1.open("temp.bin",ios::binary|ios::out);

            while (file.read((char *)&m1,sizeof(m1)))
            {
                count+=1;
                if (strcmp(m1.getname(),delno)==0)
                {
                    f=1;
                    fc=count;
                }
                else
                {
                    file1.write((char *)&m1,sizeof(m1));
                }
            }

            file.close();
            file1.close();
            remove("Music.bin");
            rename("temp.bin","Music.bin");

            if (f==0)
            {
                cout<<"Song not found."<<endl;
            }
            else
            {
                cout<<"Song deleted. View to check."<<endl;
                if (fc==1)
                {
                    audio.delete_beg();
                }

                else if (fc==audio.length())
                {
                    audio.delete_end();
                }

                else
                {
                    audio.delete_mid(delno);
                }
            }

        }

        else if (ch!=7)
        {
            cout<<"Invalid choice."<<endl;
        }
    }while(ch!=7);

}

/*int main()
{

    /*file.open("Music.bin",ios::binary|ios::out);
    for (int i=0;i<5;i++)
    {
        m1.getdata();
        file.write((char *)&m1,sizeof(music));
    }*/
    //audioplayer();

