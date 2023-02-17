#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void instructions(char);
typedef pair<string,int> inspair;
inspair makeinspair(string s,int k)
{
    inspair p;
    p.first=s;
    p.second=k;
    return p;
}
static char d=0;
queue<inspair> instruct;
stack<char> temp;
void tracepath(char t)
{
    temp.push(t);
}
void getins()
{
    while(!temp.empty())
    {
        char ch=temp.top();
        temp.pop();
        //printf("%c",ch);
        instructions(ch);
    }
}
void instructions(char t)
{
	static int ins[8];
	switch(t)
    {
        case 'u':ins[0]+=1;break;
        case 'd':ins[1]+=1;break;
        case 'l':ins[2]+=1;break;
        case 'r':ins[3]+=1;break;
        case 'q':ins[4]+=1;break;
        case 'e':ins[5]+=1;break;
        case 'z':ins[6]+=1;break;
        case 'c':ins[7]+=1;break;
    }
    if(d!=0 && t!=d)
    {        
        switch(d)
        {
            case 'u':instruct.push(makeinspair("Go towards North for ",ins[0]));ins[0]=0;break;
            case 'd':instruct.push(makeinspair("Go towards South for ",ins[1]));ins[1]=0;break;
            case 'l':instruct.push(makeinspair("Go towards West for ",ins[2]));ins[2]=0;break;
            case 'r':instruct.push(makeinspair("Go towards East for ",ins[3]));ins[3]=0;break;
            case 'q':instruct.push(makeinspair("Go towards North-West for ",ins[4]));ins[4]=0;break;
            case 'e':instruct.push(makeinspair("Go towards North-East for ",ins[5]));ins[5]=0;break;
            case 'z':instruct.push(makeinspair("Go towards South-West for ",ins[6]));ins[6]=0;break;
            case 'c':instruct.push(makeinspair("Go towards South-East for ",ins[7]));ins[7]=0;break;
        }
    }
    d=t;
}
void display(queue<inspair> q)
{
    while(!q.empty())
    {
        inspair Q=q.front();
        q.pop();
        cout<<Q.first<<Q.second<<" km(s) "<<endl;
    }
}