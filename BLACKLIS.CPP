#include<fstream.h>
#include<conio.h>
class BlackList
{
char sort[50][10];
public:
BlackList();
void makeList();
void getList();
void viewList();
void swapList();
};
BlackList::BlackList()
{
	fstream list;
	list.open("BLACKLIST.dat",ios::out|ios::trunc);
	if(list==NULL)
	{cout<<"ERROR: List Initiation failed...";return;}
	cout<<"Welcome to the BLACKLIST\nEnter list of all "
	<<"sorts and fight your way up...\n";
	char ch[10];
	while(1)
	{
		cin>>ch;
		cout<<"\n"<<ch<<"\n";
		if(ch[0]!='x')
		{list<<ch<<"\n";}
		else
		{break;}
	}
	list.close();
	cout<<"\nBlackList initiated";
	viewList();
}
void BlackList::viewList()
{
	fstream list;
	list.open("BLACKLIST.dat",ios::in);
	clrscr();
	do
	{       char c;
		list.get(c);
		cout<<c;
	}
	while(list.eof()!=1);
	list.close();
}
void BlackList::getList(){
fstream list;
	list.open("BLACKLIST.dat",ios::in);
	clrscr();
	do
	{       char c;
		list.get(dc);
		cout<<c;
	}
	while(list.eof()!=1);
	list.close();

}
void BlackList::swapList(){}
void main()
{
clrscr();
BlackList l;
getch();
}