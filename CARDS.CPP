#include<iostream.h>
#include<conio.h>
class Card{
	int num;
	int shape;
	public:
	Card(int num1,int shape1)
	{
		num=num1;
		shape=shape1;
	}
	void draw();
};
void Card::draw()
{
	for(int i=0;i<10;i++)
	{
		if(i==0)cout<<"©";
		else if(i<9)cout<<"Ä";
		else cout<<"ª\n";
	}
	for(i=0;i<10;i++){
	cout<<"³ ";
		for(int j=0;j<15;j++)
		{
		     if(num%)
		}
		cout<<" ³\n";
	}
	for(i=0;i<10;i++)
	{
		if(i==0)cout<<"À";
		else if(i<9)cout<<"Ä";
		else cout<<"Ù\n";
	}
}
void main()
{
	clrscr();
	cout<<"1.Heart\n 2.Diamond\n 3.Club\n 4.Spade\n";
	int shape;cin>>shape;
	clrscr();
	cout<<"Enter Number b/w 1 to 10";
	int num;cin>>num;
	Card c1(num,shape);
	c1.draw();
	getch();
}
