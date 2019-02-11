#include<fstream.h>
#include<conio.h>
struct Brackets
{
int sema_P;
int sema_S;
int sema_C;
int tos_P;
int tos_S;
int tos_C;
int charNo_P[50];
int charNo_S[50];
int charNo_C[50];
};
int error(Brackets *B,int x)
{
int i=0;
if(x==1){
if(B->sema_C<0)
{
	i=!i;
	cout<<"\nError: Extra Closed Curly Braces line no."<<B->charNo_C[B->tos_C];
}
else if(B->sema_P<0)
{
	i=!i;
	cout<<"\nError: Extra Closed paranthesis line no."<<B->charNo_P[B->tos_P];
}
else if(B->sema_S<0)
{
	i=!i;
	cout<<"\nError: Extra Closed Square Bracket line no."<<B->charNo_S[B->tos_S];
}
}//if(x==1)
else if(x==2)
{
	if(B->sema_C!=0)
	{i=!i;cout<<"\nError: Unclosed Curly Braces";}
	else if(B->sema_S!=0)
	{i=!i;cout<<"\nError: Unclosed Square Braces";}
	else if(B->sema_P!=0)
	{i=!i;cout<<"\nError: Unclosed Paranthesis";}
}
return i;
}
void main()
{
clrscr();
Brackets B={0,0,0,-1,-1,-1};
ifstream file;file.open("TESTPROG.TXT");
if(file!=NULL)
{
	int line=1;
	char ch;
//cout<<"hello";
while(file.eof()==0)
{
	ch=file.get();if(ch=='\n'){line++;}
	if(ch=='{'){
		B.sema_C++;
		B.tos_C++;
		B.charNo[B.tos_C]=line;
		B.sign[B.tos_C]='{';
		if(error(&B,1)==1)break;
		}
	else if(ch=='}'){
		B.sema_C--;
		B.tos_C++;
		B.charNo[B.tos]=line;
		B.sign[B.tos]='}';
		if(error(&B,1)==1)break;
		}
	else if(ch=='['){
		B.sema_S++;
		B.tos++;
		B.charNo[B.tos]=line;
		B.sign[B.tos]='[';
		if(error(&B,1)==1)break;
		}
	else if(ch==']'){
		B.sema_S--;
		B.tos++;
		B.charNo[B.tos]=line;
		B.sign[B.tos]=']';
		if(error(&B,1)==1)break;
		}
	else if(ch=='('){
		B.sema_P++;
		B.tos++;
		B.charNo[B.tos]=line;
		B.sign[B.tos]='(';
		if(error(&B,1)==1)break;
		}
	else if(ch==')'){
		B.sema_P--;
		B.tos++;
		B.charNo[B.tos]=line;
		B.sign[B.tos]=')';
		if(error(&B,1)==1)break;
		}
}
error(&B,2);
}
file.close();
//cout<<"Anybody?";
//cout<<B.semaphore<<B.tos;
getch();
}