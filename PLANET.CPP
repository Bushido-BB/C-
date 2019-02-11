#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
class Star
{
public:
int x,y,z;
int Color;
Star(int x1,int y1,int z1,int c)
{
	x=x1;y=y1;z=z1;
	Color=c;
}
void draw()
{
	setcolor(Color);
	circle(x,y,z);
	//floodfill(x,y,Color);
}
};
class Planet
{
public:
int Ox,Oy,Oz;
int Fx,Fy,Fz;
int Ax,Ay,Az;
int Color;
Planet(int x,int y,int z,int x1,int y1,int z1,int x2,int y2,int z2,int c)
{
	Ox=x;Oy=y;Oz=z;
	Fx=x1;Fy=y1;Fz=z1;
	Ax=x2;Ay=y2;Az=z2;
	Color=c;
}
void draw(int i)
{
	setcolor(Color);

	int x=Ax*sin(44.0*i/7+Fx)+Ox;
	int y=Ay*cos(44.0*i/7+Fy)+Oy;
	int z=Az*cos(44.0*i/7+Fz)+Oz;

	//line(x,y,x,y);
	circle(320+x,240+y,z);
	//floodfill(320+x,240+y,Color);
}

};
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI\\");
int i=1;
//ox oy oz fx fy fz ax ay az c
Planet Earth(0,0,1,7,7,7,150,50,10,1);
Planet Venus(0,0,0,0,0,0,-120,40,8,12);
Planet Mars(0,0,1,5,5,5,200,50,6,4);
Planet Jupitor(0,10,8,8,8,8,240,90,12,6);
Planet Saturn(0,0,7,3,3,3,250,90,11,11);
Planet Uranus(0,20,6,2,2,2,-280,119,10,9);
Planet Pluto(0,0,1,10,10,10,290,150,3,7);

Star Sun(320,240,20,14);
while(!kbhit())
{
/*
	int x=100*sin(44.0*i/7);
	int y=50*cos(44.0*i/7);
	int z=10*cos(44.0*i/7)+1;

	int x1=240*sin(44.0*(i)/7+7);
	int y1=50*cos(44.0*(i)/7+7)+x/3;
	int z1=10*cos(44.0*(i)/7+7)+5;

	circle(320+x,240+y,z);
	circle(320+x1,240+y1,z1);
	circle(320,240,10);
*/
	Earth.draw(i);
	Venus.draw(i);
	Mars.draw(i);
	Jupitor.draw(i);
	Saturn.draw(i);
	Uranus.draw(i);
	Pluto.draw(i);
	Sun.draw();
	delay(1);
	cleardevice();
	i++;
}
getch();
}