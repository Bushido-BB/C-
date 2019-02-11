#include<conio.h>
#include<dos.h>
#include<iostream.h>
void main(){
	clrscr();
	char array[100]="Hello How are You! I'm fine and hoping the same for you";
	while(!kbhit()){
		clrscr();
		cout<<array;
		for(int i=0;array[i]!='\0';i++){
			int j=i+1;
			if(array[i+1]=='\0'){
				j=0;
			}
			char t=array[i];
			array[i]=array[j];
			array[j]=t;

		}
		delay(100);
	}
}