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
double r,Ax,Ay,theta,phi;
int Color;
Planet(double r1,int c,double x,double y)
{
	r=r1;
	Ax=x;
	Ay=y;
	Color=c;
}
void draw(double i,double j)
{
	setcolor(Color);
	theta=i;
	phi=j;

	int x=Ax * r * cos(theta) * sin(phi);
	int y=Ay * r * sin(theta) * sin(phi);
	int z=r * cos(phi);

	setcolor(Color);
	circle(320+x,240+y,z);
	//floodfill(320+x,240+y,Color);
}

};
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI\\");
int i=0,j=0;
Planet Earth(10,1,7,7);//(radius, color, AmplitueX, AmplitudeY)
Planet Mercury(10,8,4,4);
Planet Venus(9,12,6,6);
Planet Mars(7,4,14,8);
Planet Jupitor(14,6,13,9);
Planet Saturn(12,12,15,10);
Planet Uranus(11,9,17,11);
Planet Neptune(11,18,12,12);
Planet Pluto(5,7,39,13);

Star Sun(320,240,20,14);
while(!kbhit())
{
double x=i*22.00/180/7;
double y=j*22.00/180/7;
	Earth.draw(1,y);
	Mercury.draw(1,3.1*y);
	Venus.draw(1,2.9*y);
	Mars.draw(1,2*y);
	Jupitor.draw(1,1*y);
	Saturn.draw(0.1,1.7*y);
	Uranus.draw(0.1,0.9*y);
	Neptune.draw(0.1,0.8*y);
	Pluto.draw(0.2,0.6*y);
	Sun.draw();

	delay(10);
	cleardevice();
	i++;j++;
	if(i>=180)i=0;
	if(j>=360)j=0;

}
getch();
}