#include<graphics.h>
#include<iostream>
using namespace std;

void House1Mall1(int color)
{
    setcolor(color);
    line(75,50,155,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,25,"1km");
}
void Mall1House2(int color)
{
    setcolor(color);
    line(180,75,180,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(190,100,"1km");
}
void House2House3(int color)
{
    setcolor(color);
    line(75,170,155,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,145,"1km");
}
void House1House3(int color)
{
    setcolor(color);
    line(50,75,50,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,100,"2km");
}
void House3Mall2(int color)
{
    setcolor(color);
    line(50,195,50,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,240,"4km");
}
void Mall2House4(int color)
{
    setcolor(color);
    line(75,320,305,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(170,295,"3km");
}
void House4Mall3(int color)
{
    setcolor(color);
    line(330,195,330,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(340,235,"1km");
}
void Mall3House2(int color)
{
    setcolor(color);
    line(205,170,305,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(235,145,"1km");
}
void Mall1House5(int color)
{
    setcolor(color);
    line(205,50,425,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(305,25,"2km");
}
void House5Mall4(int color)
{
    setcolor(color);
    line(450,75,450,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(460,180,"5km");
}
void House4Mall4(int color)
{
    setcolor(color);
    line(355,320,425,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(370,290,"1km");
}
void generatemap()
{
    initwindow(640,480,"Map");
    //bg
    setbkcolor(15);
    setfillstyle(SOLID_FILL,15);
    floodfill(1,1,15);

     //hotel
    setcolor(BLACK);
    rectangle(155,25,205,75);
    setfillstyle(SOLID_FILL,7);
    floodfill(156,26,BLACK);

    setcolor(0);
    setbkcolor(7);
    settextstyle(12,0,1);
    outtextxy(160,45,"HOTEL");

    //bus stop
    setcolor(BLACK);
    rectangle(25,295,75,345);
    setfillstyle(SOLID_FILL,6);
    floodfill(26,296,BLACK);

    setcolor(15);
    setbkcolor(6);
    settextstyle(12,0,1);
    outtextxy(26,315,"Bus stop");

    //psg
    setcolor(BLACK);
    rectangle(305,145,355,195);
    setfillstyle(SOLID_FILL,5);
    floodfill(306,146,BLACK);

    setcolor(15);
    setbkcolor(5);
    settextstyle(10,0,1);
    outtextxy(315,165,"PSG");

    //railway
    setcolor(BLACK);
    rectangle(425,295,475,345);
    setfillstyle(SOLID_FILL,9);
    floodfill(426,296,BLACK);

    setcolor(BLACK);
    setbkcolor(9);
    settextstyle(12,0,1);
    outtextxy(426,315,"Railway");

    //mall
    setcolor(BLACK);
    rectangle(25,25,75,75);
    setfillstyle(SOLID_FILL,12);
    floodfill(26,26,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(12,0,1);
    outtextxy(30,45,"MALL");

    //home
    setcolor(BLACK);
    rectangle(155,145,205,195);
    setfillstyle(SOLID_FILL,1);
    floodfill(156,156,BLACK);

    setcolor(15);
    setbkcolor(1);
    settextstyle(12,0,1);
    outtextxy(158,165,"HOME");

    //hospital
    setcolor(BLACK);
    rectangle(25,145,75,195);
    setfillstyle(SOLID_FILL,4);
    floodfill(26,146,BLACK);

    setcolor(15);
    setbkcolor(4);
    settextstyle(12,0,1);
    outtextxy(27,165,"Hospital");

    //school
    setcolor(BLACK);
    rectangle(305,295,355,345);
    setfillstyle(SOLID_FILL,14);
    floodfill(306,296,BLACK);

    setcolor(BLACK);
    setbkcolor(14);
    settextstyle(12,0,1);
    outtextxy(308,315,"School");

    //airport
    setcolor(BLACK);
    rectangle(425,25,475,75);
    setfillstyle(SOLID_FILL,3);
    floodfill(426,26,BLACK);

    setcolor(15);
    setbkcolor(3);
    settextstyle(12,0,1);
    outtextxy(429,45,"Airport");

    int color=5;
    House1Mall1(color);
    Mall1House2(color);
    House2House3(color);
    House1House3(color);
    House3Mall2(color);
    Mall2House4(color);
    House4Mall3(color);
    Mall3House2(color);
    Mall1House5(color);
    House5Mall4(color);
    House4Mall4(color);

    getch();
}
