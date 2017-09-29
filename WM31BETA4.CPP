/*****************************************************************************************\
| Program name     : Workers Manager                                                      |
| Author           : Peng Chhaileng                                                       |
| Email            : chhailengpeng@gmail.com                                              |
| Facebook         : https://facebook.com/ChhailengPeng | https://fb.com/PengChhaileng    |
| LinkedIn         : https://www.linkedin.com/in/ChhailengPeng                            |
| YouTube          : https://youtube.com/c/ChhailengPeng                                  |
| WeChat ID        : ChhailengPeng                                                        |
| Line ID          : chhailengpeng                                                        |
| Website          : http://neakit.com                                                    |
| Personal Blog    : http://chhaileng.info                                                |
| Current Version  : 3.1 (BETA 4)                                                         |
| Place            : Royal University of Phnom Penh                                       |
| Description      : This Program is written in C Programming Language using compiler     |
|                    Turbo C++ version 3.5 or 4.0 (DOS). In this 3.0 version, all used    |
|                    variable are globally declared because it's easy to call it to use   |
|                    in main program. While running this program, data is stored in       |
|                    array so it is not good for using memory space. I'm developing it    |
|                    to store the data in Linked List or Trees. It is better and save     |
|                    the memory space. When the program is terminated, the data is stored |
|                    in a binary file.                                                    |
|                    This program was created my me for my final assignment and it is     |
|                    included all lesson of C Programming Language. For any help, feel    |
|                    free to ask me by my above contact info. Thank !!!                   |
\*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//#include<flag.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
//#include<minion.h>

typedef struct worker
{
	int id;
	char name[20];
	char sex[5];
	int d,m,y;
	char position[20];
	float salary;
};

//Global Variables easy

worker data[101];
int N=0;
char getpw[20],mypw[20];
char pw0[20],pw1[20],pw2[20];
FILE *fp,*pass;

//prototypes
void write();

//functions create table
void table(int height,int width,int border,int color)
{
	textcolor(color);
	int i,a,b=height,c,d=width;
	a=c=border;
	gotoxy(c,a);
	cprintf("%c",201);
	gotoxy(d,a);
	cprintf("%c",187);
	gotoxy(c,b);
	cprintf("%c",200);
	gotoxy(d,b);
	cprintf("%c",188);
	for(i=a+1;i<d;i++)
	{
		gotoxy(i,a);
		cprintf("%c",205);
		gotoxy(i,b);
		cprintf("%c",205);
	}
	for(i=c+1;i<b;i++)
	{
		gotoxy(c,i);
		cprintf("%c",186);
		gotoxy(d,i);
		cprintf("%c",186);
	}
}
void blank(int n)
{
	for(int i=0;i<n;i++)
		cprintf(" ");
}
void restore_color()
{
	for(int i=0;i<80;i++);
		for(int j=0;j<25;j++)
		{
			textbackground(BLACK);
			cprintf(" ");
		}
}
void selected_box(int x,int y) //used in main menu
{
	int i=0;
	textcolor(WHITE);
	gotoxy(x,y);	cprintf("%c",201);
	gotoxy(x+19,y);	cprintf("%c",187);
	gotoxy(x,y+2);	cprintf("%c",200);
	gotoxy(x+19,y+2);	cprintf("%c",188);
	gotoxy(x,y+1);	cprintf("%c",186);
	gotoxy(x+19,y+1);	cprintf("%c",186);
	x=x+1;
	for(;i<18;x++)
	{
		gotoxy(x,y);	cprintf("%c",205);
		gotoxy(x,y+2);	cprintf("%c",205);
		i++;
	}
}
void help_box()
{
	int i=0;
	textcolor(YELLOW);
	textbackground(BLACK);
	gotoxy(7,18);	cprintf("%c",218);
	gotoxy(72,18);	cprintf("%c",191);
	gotoxy(7,21);	cprintf("%c",192);
	gotoxy(72,21);	cprintf("%c",217);

	gotoxy(7,19);	cprintf("%c",179);
	gotoxy(7,20);	cprintf("%c",179);

	gotoxy(72,19);	cprintf("%c",179);
	gotoxy(72,20);	cprintf("%c",179);
	for(i=1;i<65;i++)
	{
		gotoxy(7+i,18);	cprintf("%c",196);
		gotoxy(7+i,21);	cprintf("%c",196);
	}
}
void interface() // main interface
{
	table(24,77,2,7);
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(6,3);
	cprintf("--------------------------------------------------------------------");
	gotoxy(6,4);
	blank(68);
	gotoxy(6,5);
	cprintf("--------------------------------------------------------------------");
	for(int i=6;i<22;i++)
	{
		gotoxy(6,i);
		cprintf(" ");
	}
	for(i=6;i<22;i++)
	{
		gotoxy(73,i);
		cprintf(" ");
	}
	gotoxy(6,22);
	blank(68);
	gotoxy(6,23);
	blank(68);
	textbackground(BLACK);
}
void menu()
{
	table(24,77,2,7);
	interface();
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(28,4);
	cprintf("[ Workers Manager v.3.1 ]");
	textcolor(0);

	textbackground(6);
	gotoxy(47+3,11+4);	blank(20);
	gotoxy(47+3,12+4);	cprintf("       Update       ");
	gotoxy(47+3,13+4);	blank(20);

	textbackground(5);
	gotoxy(37+3,10+3);	blank(20);
	gotoxy(37+3,11+3);	cprintf("       Search       ");
	gotoxy(37+3,12+3); 	blank(20);

	textbackground(4);
	gotoxy(27+3,9+2);	blank(20);
	gotoxy(27+3,10+2);	cprintf("     Sort  Data     ");
	gotoxy(27+3,11+2);	blank(20);

	textbackground(3);
	gotoxy(17+3,8+1);	blank(20);
	gotoxy(17+3,9+1);	cprintf("  Show Information  ");
	gotoxy(17+3,10+1);	blank(20);

	textbackground(2); //case 1
	gotoxy(7+3,7);	blank(20);
	gotoxy(7+3,8);	cprintf("  Add More Workers  ");
	gotoxy(7+3,9);	blank(20);
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(6,22);
	cprintf("  Help: Press [   ] or [   ] to move    |     Enter key to select   ");
	gotoxy(6,23);
	//cprintf("         Esc : Exit Program       |       F1 : About Program        ");
	cprintf("     Esc : Exit Program  |  F1 : About Program  |  F2 : Options     ");
	textcolor(RED);
	gotoxy(22,22);	cprintf("%c",24);  //arrow up
	gotoxy(31,22);	cprintf("%c",25);  //arrow down
	gotoxy(52,22);	cprintf("Enter");
	gotoxy(11,23);	cprintf("Esc");
	gotoxy(34,23);	cprintf("F1");
	gotoxy(57,23);	cprintf("F2");
	textcolor(2);
	gotoxy(46,22);	cprintf("|");
	gotoxy(31,23);	cprintf("|");
	gotoxy(54,23);	cprintf("|");

	help_box();
}
void help(int a)
{
	textcolor(LIGHTGREEN);
	switch(a)
	{
	case 1:
		gotoxy(10,19); cprintf("- Add more information of workers to list.");
		gotoxy(10,20); cprintf("- Save Data.");
		break;
	case 2:
		gotoxy(10,19); cprintf("- Show all workers' information.");
		break;
	case 3:
		gotoxy(10,19); cprintf("- Sort workers' information by ID, name or salary.");
		break;
	case 4:
		gotoxy(10,19); cprintf("- Search workers' information by name or ID.");
		break;
	case 5:
		gotoxy(10,19); cprintf("- Delete or edit workers' information.");
		break;
	}
}
void show_menu(int a)
{
	switch(a)
	{
		case 1:
			textbackground(2);
			gotoxy(10,7);		blank(20);
			gotoxy(10,8);		blank(20);
			gotoxy(10,9);		blank(20);
			selected_box(10,7);
			gotoxy(12,8);		cprintf("Add More Workers");
			textbackground(BLACK);
			textcolor(YELLOW);
			gotoxy(12,18);	cprintf("[ Add More Workers ]");
			help(a);
			break;
		case 2:
			textbackground(3);
			gotoxy(20,9);		blank(20);
			gotoxy(20,10);		blank(20);
			gotoxy(20,11);		blank(20);
			selected_box(20,9);
			gotoxy(22,10);		cprintf("Show Information");
			textbackground(BLACK);
			textcolor(YELLOW);
			gotoxy(12,18);	cprintf("[ Show Information ]");
			help(a);
			break;
		case 3:
			textbackground(4);
			gotoxy(30,11);	blank(20);
			gotoxy(30,12);	blank(20);
			gotoxy(30,13);	blank(20);
			selected_box(30,11);
			gotoxy(35,12);	cprintf("Sort  Data");
			textbackground(BLACK);
			textcolor(YELLOW);
			gotoxy(12,18);	cprintf("[ Sort Data ]");
			help(a);
			break;
		case 4:
			textbackground(5);
			gotoxy(40,13);	blank(20);
			gotoxy(40,14);	blank(20);
			gotoxy(40,15);	blank(20);
			selected_box(40,13);
			gotoxy(47,14);	cprintf("Search");
			textbackground(BLACK);
			textcolor(YELLOW);
			gotoxy(12,18);	cprintf("[ Search ]");
			help(a);
			break;
		case 5:
			textbackground(6);
			gotoxy(50,15);	blank(20);
			gotoxy(50,16);	blank(20);
			gotoxy(50,17);	blank(20);
			selected_box(50,15);
			gotoxy(57,16);	cprintf("Update");
			textbackground(BLACK);
			textcolor(YELLOW);
			gotoxy(12,18);	cprintf("[ Update ]");
			help(a);
			break;
	}
}
void menu1()
{
	textcolor(10);
	gotoxy(12,8);	textbackground(2);	cprintf("A");
	gotoxy(27,10);	textbackground(3); 	cprintf("I");
	gotoxy(41,12);	textbackground(4);	cprintf("D");
	gotoxy(47,14);	textbackground(5);	cprintf("S");
	gotoxy(57,16);	textbackground(6);	cprintf("U");
}
void about_us()
{
	_setcursortype(0);
	clrscr();
	interface();
	gotoxy(36,4);
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	cprintf("[ About ]");
	textbackground(0);
	table(19,71,8,3);
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(6,22);
	textcolor(LIGHTGREEN);
	gotoxy(6,22);
	cprintf("--------------------------------------------------------------------");
	gotoxy(6,23);
	cprintf("--------------------------------------------------------------------");
	textcolor(WHITE);
	textbackground(3);
	gotoxy(8,7);	blank(64);
	gotoxy(10,7);  	cprintf("Royal University of Phnom Penh");
	textcolor(WHITE);
	gotoxy(52,7);	cprintf("Faculty of Science");
	textbackground(6);
	gotoxy(20,9);	blank(40);
	gotoxy(29,9);	cprintf("C Programming Language");
	textbackground(BLUE);
	gotoxy(20,10);	blank(40);
	gotoxy(20,11);	blank(40);
	gotoxy(20,12);	blank(40);
	gotoxy(20,13);	blank(40);
	gotoxy(20,14);	blank(40);
	gotoxy(20,15);	blank(40);
	gotoxy(20,16);	blank(40);
	gotoxy(20,16);	blank(40);
	gotoxy(20,17);	blank(40);
	textbackground(6);
	gotoxy(20,18);	blank(40);

	gotoxy(30,10);
	textbackground(BLUE);
	textcolor(YELLOW);
	cprintf("Workers Manager v.3.1");
	gotoxy(28,11);
	cprintf(". Lecturer: Mr. Heng Sokha");
	gotoxy(28,12);
	cprintf(". Group members:");
	gotoxy(30,13);
	cprintf("- Mr. Peng Chhaileng");
	gotoxy(30,14);
	cprintf("- N/A");
	gotoxy(30,15);
	cprintf("- N/A");
	gotoxy(30,16);
	cprintf("- N/A");
	gotoxy(30,17);
	cprintf("- N/A");
	textcolor(WHITE);
	textbackground(6);
	gotoxy(28,18);
	cprintf("All rights reserved 2015");
	textbackground(RED);
	gotoxy(23,20);
	cprintf("Press any key to exit to Main Menu");
	textbackground(BLACK);
	getch();
}
void input_interface(int a)
{
	_setcursortype(0);
	clrscr();
	interface();
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(23,4); cprintf("[ Add More Workers : Worker %d ]",a+1);
	textbackground(0);
	textcolor(WHITE);
	textbackground(5);
	for(int b=0;b<13;b++)
	{
		gotoxy(15,7+b);	blank(50);
	}
	for(b=0;b<13;b+=2)
	{
		gotoxy(17,7+b);	cprintf("----------------------------------------------");
	}
	textcolor(WHITE);
	gotoxy(18,8);	cprintf("ID            :");
	gotoxy(18,10);  cprintf("Name          :");
	gotoxy(18,12);  cprintf("Sex           :");
	gotoxy(18,14);  cprintf("Date of birth :");
	gotoxy(18,16);  cprintf("Position      :");
	gotoxy(18,18);	cprintf("Salary ($)    :");
	gotoxy(15,20);
	textbackground(BLACK);
}

void output_style(int i) //body of table style
{
	textcolor(GREEN);
	textbackground(BLACK);
	gotoxy(3,4+i);	cprintf("%c",179);
	gotoxy(4+6,4+i);	cprintf("%c",179);
	gotoxy(4+25,4+i);	cprintf("%c",179);
	gotoxy(4+31,4+i);	cprintf("%c",179);
	gotoxy(4+47,4+i);	cprintf("%c",179);
	gotoxy(5+60,4+i);	cprintf("%c",179);
	gotoxy(5+71,4+i);	cprintf("%c",179);

}
void output_start() //header of table
{
	textcolor(GREEN);
	textbackground(BLACK);
	for(int a=3;a<77;a++)
	{
		gotoxy(a,3);
		cprintf("%c",196);
	}
	gotoxy(3,3);	cprintf("%c",218);
	gotoxy(4+6,3);	cprintf("%c",194);
	gotoxy(4+25,3);	cprintf("%c",194);
	gotoxy(4+31,3);	cprintf("%c",194);
	gotoxy(4+47,3);	cprintf("%c",194);
	gotoxy(5+60,3);	cprintf("%c",194);
	gotoxy(5+71,3);	cprintf("%c",191);
}
void output_end(int i) //footer of table
{
	textcolor(GREEN);
	textbackground(BLACK);
	for(int a=3;a<77;a++)
	{
		gotoxy(a,i);
		cprintf("%c",196);
	}
	gotoxy(3,i);	cprintf("%c",192);
	gotoxy(4+6,i);	cprintf("%c",193);
	gotoxy(4+25,i);	cprintf("%c",193);
	gotoxy(4+31,i);	cprintf("%c",193);
	gotoxy(4+47,i);	cprintf("%c",193);
	gotoxy(5+60,i);	cprintf("%c",193);
	gotoxy(5+71,i);	cprintf("%c",217);
}
void show_month(int month)
{
	switch(month)
	{
		case 1:
			cprintf("-Jan-");
			break;
		case 2:
			cprintf("-Feb-");
			break;
		case 3:
			cprintf("-Mar-");
			break;
		case 4:
			cprintf("-Apr-");
			break;
		case 5:
			cprintf("-May-");
			break;
		case 6:
			cprintf("-Jun-");
			break;
		case 7:
			cprintf("-Jul-");
			break;
		case 8:
			cprintf("-Aug-");
			break;
		case 9:
			cprintf("-Sep-");
			break;
		case 10:
			cprintf("-Oct-");
			break;
		case 11:
			cprintf("-Nov-");
			break;
		case 12:
			cprintf("-Dec-");
			break;
	}
}
int input_ask()
{
	int status=0;
	char press;
	while(1)
	{
		_setcursortype(0);
		clrscr();
		input_interface(N);
		gotoxy(15,21);
		textbackground(RED);
		cprintf(" Press Enter to start    Esc to exit to Main Menu ");
		textbackground(0);
		press=getch();
		if(press==27)
		{
			status=1;
			break;
		}
		else if(press==13)
		{
			status=0;
			break;
		}
	}
	return status;
}
void input()
{
	char tmp_id[5],tmp_name[20],tmp_position[20],tmp_salary[8],tmp_d[3],tmp_m[3],tmp_y[5];
	char b,c;
	float tmp;
	int a=1,j,count,status;
	do{ //main loop

		clrscr();
		input_interface(N);
		textcolor(WHITE);
		textbackground(5);
		_setcursortype(2);
		//id;
		do{
			status=0;
			do{
				_setcursortype(2);
				count=0;
				textbackground(5);
				fflush(stdin);
				gotoxy(34,8);	gets(tmp_id);
				textbackground(0);
				for(j=0;j<strlen(tmp_id);j++)
					if(*(tmp_id+j)>=48&&*(tmp_id+j)<=57)
						count++;
				if(count!=strlen(tmp_id))
				{
					input_interface(N);
					gotoxy(15,21);
					textbackground(RED);
					cprintf("           Message : ID must in number !          ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_id));
			if(atoi(tmp_id)<=0||atoi(tmp_id)>100)
			{
				status=1;
				input_interface(N);
				gotoxy(15,21);
				textbackground(RED);
				cprintf("    Message : Invalid ID, ID must between 1-100   ");
				textbackground(0);
			}
			for(j=0;j<N;j++)
				if(atoi(tmp_id)==data[j].id)
				{
					status=1;
					input_interface(N);
					gotoxy(15,21);
					textbackground(RED);
					cprintf("           Message : ID already exist !           ");
					textbackground(0);
				}
		}while(status==1);
		data[N].id=atoi(tmp_id);
		gotoxy(15,21);	blank(50);

		//name
		do{
			status=0;
			count=0;
			_setcursortype(2);
			gotoxy(34,10);
			textbackground(5);
			blank(31);
			fflush(stdin);
			gotoxy(34,10);	gets(tmp_name);
			for(j=0;j<strlen(tmp_name);j++)
				if(*(tmp_name+j)>=65&&*(tmp_name+j)<=90||*(tmp_name+j)>=97&&*(tmp_name+j)<=122||*(tmp_name+j)==32)
					count++;
			if(count!=strlen(tmp_name))
			{
				gotoxy(15,21);
				textbackground(RED);
				cprintf("            Message : Incorrect name              ");
				textbackground(0);
			}
			if(strlen(tmp_name)==0||*tmp_name==' ')
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("            Message : Incorrect name              ");
				textbackground(0);
			}
		}while(count!=strlen(tmp_name)||status==1);
		//make the first letter of name to capital latter
		if(*(tmp_name)>=97&&*(tmp_name)<=122)
			*tmp_name=*tmp_name-32;
		for(j=0;j<strlen(tmp_name);j++)
		{
			if((*(tmp_name+j)>=97&&*(tmp_name+j)<=122)&&*(tmp_name+j-1)==' ')
				*(tmp_name+j)=*(tmp_name+j)-32;
		}
		gotoxy(34,10);
		cprintf("%s",tmp_name);
		strcpy(data[N].name,tmp_name);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		textbackground(5);

		//sex
		a=1;
		_setcursortype(0);
		textbackground(GREEN);
		textcolor(WHITE);
		gotoxy(34,12);
		cprintf("     Male     ");
		gotoxy(34+13,12);
		textbackground(7);
		textcolor(0);
		cprintf("    Female    ");
		gotoxy(15,21);
		textbackground(RED);
		textcolor(WHITE);
		cprintf("       Help : Press [ %c ] or [ %c ] to select      ",27,26);
		textbackground(0);
		do{

			b=getch();
			if(b==77)  //  ->
				a++;
			else if(b==75)  //  <-
				a--;
			if(a>=3)
				a=1;
			else if(a<=0)
				a=2;
			switch(a)
			{
				case 1:
					textbackground(GREEN);
					textcolor(WHITE);
					gotoxy(34,12);
					cprintf("     Male     ");
					gotoxy(34+13,12);
					textbackground(7);
					textcolor(0);
					cprintf("    Female    ");

					break;
				case 2:
					textbackground(7);
					textcolor(0);
					gotoxy(34,12);
					cprintf("     Male     ");
					gotoxy(34+13,12);
					textbackground(GREEN);
					textcolor(WHITE);
					cprintf("    Female    ");

					break;
			}
		}while(b!=13);
		textbackground(5);
		textcolor(WHITE);
		gotoxy(34,12);
		blank(27);
		if(a==1)
		{
			strcpy(data[N].sex,"M");
			gotoxy(34,12);
			cprintf("Male");
		}
		else if(a==2)
		{
			strcpy(data[N].sex,"F");
			gotoxy(34,12);
			cprintf("Female");
		}
		_setcursortype(2);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		textbackground(5);




		//day
		gotoxy(15,20);
		textbackground(RED);
		cprintf("              Help : Input Day (01-31)            ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34,14);
				textbackground(5);
				blank(31);
				gotoxy(34,14);	gets(tmp_d);
				for(j=0;j<strlen(tmp_d);j++)
					if(*(tmp_d+j)>=48&&*(tmp_d+j)<=57)
						count++;
				if(count!=strlen(tmp_d))
				{
					gotoxy(15,21);
					textbackground(RED);
					cprintf("       Message : Invalid day, enter 01 to 31      ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_d));
			if(atoi(tmp_d)<=0||atoi(tmp_d)>31)
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("       Message : Invalid day, enter 01 to 31      ");
				textbackground(0);
			}
		}while(status==1);
		data[N].d=atoi(tmp_d);
		gotoxy(34,14);	cprintf("%2d-",data[N].d);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		textbackground(5);
		//month
		gotoxy(15,20);
		textbackground(RED);
		cprintf("            Help : Input Month (01-12)            ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34+3,14);
				textbackground(5);
				blank(26);
				gotoxy(34+3,14);	gets(tmp_m);
				for(j=0;j<strlen(tmp_m);j++)
					if(*(tmp_m+j)>=48&&*(tmp_m+j)<=57)
						count++;
				if(count!=strlen(tmp_m))
				{
					gotoxy(15,21);
					textbackground(RED);
					cprintf("      Message : Invalid month, enter 01 to 12     ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_m));
			if(atoi(tmp_m)<=0||atoi(tmp_m)>12)
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("      Message : Invalid month, enter 01 to 12     ");
				textbackground(0);
			}
		}while(status==1);
		data[N].m=atoi(tmp_m);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		textbackground(5);
		gotoxy(36,14);
		show_month(data[N].m);

		//year
		gotoxy(15,20);
		textbackground(RED);
		cprintf("           Help : Input Year (1955-2000)          ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34+3+4,14);
				textbackground(5);
				blank(22);
				gotoxy(34+3+4,14);	gets(tmp_y);
				for(j=0;j<strlen(tmp_y);j++)
					if(*(tmp_y+j)>=48&&*(tmp_y+j)<=57)
						count++;
				if(count!=strlen(tmp_y))
				{
					gotoxy(15,21);
					textbackground(RED);
					cprintf("    Message : Invalid year, enter 1955 to 2000    ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_y));
			if(atoi(tmp_y)<=1954||atoi(tmp_y)>2000)
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("    Message : Invalid year, enter 1955 to 2000    ");
				textbackground(0);
			}
		}while(status==1);
		data[N].y=atoi(tmp_y);
		textbackground(0);
		gotoxy(15,20);	blank(50);
		gotoxy(15,21);	blank(50);
		textbackground(5);

		//position
		do{
			status=0;
			count=0;
			_setcursortype(2);
			gotoxy(34,16);
			textbackground(5);
			blank(31);
			fflush(stdin);
			gotoxy(34,16);	gets(tmp_position);
			for(j=0;j<strlen(tmp_position);j++)
				if(*(tmp_position+j)>=65&&*(tmp_position+j)<=90||*(tmp_position+j)>=97&&*(tmp_position+j)<=122||*(tmp_position+j)==32)
					count++;
			if(count!=strlen(tmp_position))
			{
				gotoxy(15,21);
				textbackground(RED);
				cprintf("          Message : Incorrect position            ");
				textbackground(0);
			}
			if(strlen(tmp_position)==0||*tmp_position==' ') //first character can't be a space
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("          Message : Incorrect position            ");
				textbackground(0);
			}
		}while(count!=strlen(tmp_position)||status==1);
		if(*(tmp_position)>=97&&*(tmp_position)<=122)
			*tmp_position=*tmp_position-32;
		for(j=0;j<strlen(tmp_position);j++)
			if((*(tmp_position+j)>=97&&*(tmp_position+j)<=122)&&*(tmp_position+j-1)==' ')
				*(tmp_position+j)=*(tmp_position+j)-32;
		gotoxy(34,16);
		cprintf("%s",tmp_position);
		strcpy(data[N].position,tmp_position);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		textbackground(5);

		//salary
		do{
			_setcursortype(2);
			count=0;
			status=0;
			textbackground(5);
			gotoxy(34,18);	blank(20);
			gotoxy(34,18);	gets(tmp_salary);
			textbackground(0);
			for(j=0;j<strlen(tmp_salary);j++)
				if(*(tmp_salary+j)>=48&&*(tmp_salary+j)<=57||*(tmp_salary+j)==46)
					count++;
			if(count!=strlen(tmp_salary))
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("         Message : salary must in number !        ");
				textbackground(0);
			}
			if(count==strlen(tmp_salary)&&atoi(tmp_salary)<=0)
			{
				status=1;
				gotoxy(15,21);
				textbackground(RED);
				cprintf("             Message : Invalid Salary !           ");
				textbackground(0);
			}
		}while(status==1);
		data[N].salary=atof(tmp_salary);
		gotoxy(15,21);	blank(50);
		N++;
		gotoxy(15,21);
		textbackground(RED);
		cprintf("Press any key to add more Esc to exit to Main Menu");
		_setcursortype(0);
		textbackground(0);
		c=getch();

	}while(c!=27);
	clrscr();
	menu();
	menu1();
	show_menu(1);
	write();
}
void output1(int a,int r)//r=row
{
		output_style(r+1);
		gotoxy(6,5+r);	cprintf("%2d",data[a].id);
		gotoxy(11,5+r);	cprintf("%s",data[a].name);
		gotoxy(32,5+r);	cprintf("%s",strupr(data[a].sex));
		gotoxy(38,5+r);	cprintf("%2d-   -%d",data[a].d,data[a].y);
		gotoxy(53,5+r);	cprintf("%s",data[a].position);
		gotoxy(67,5+r);	cprintf("$%.2f",data[a].salary);
		switch(data[a].m)
		{
			case 1:
				gotoxy(41,5+r);
				cprintf("Jan");
				break;
			case 2:
				gotoxy(41,5+r);
				cprintf("Feb");
				break;
			case 3:
				gotoxy(41,5+r);
				cprintf("Mar");
				break;
			case 4:
				gotoxy(41,5+r);
				cprintf("Apr");
				break;
			case 5:
				gotoxy(41,5+r);
				cprintf("May");
				break;
			case 6:
				gotoxy(41,5+r);
				cprintf("Jun");
				break;
			case 7:
				gotoxy(41,5+r);
				cprintf("Jul");
				break;
			case 8:
				gotoxy(41,5+r);
				cprintf("Aug");
				break;
			case 9:
				gotoxy(41,5+r);
				cprintf("Sep");
				break;
			case 10:
				gotoxy(41,5+r);
				cprintf("Oct");
				break;
			case 11:
				gotoxy(41,5+r);
				cprintf("Nov");
				break;
			case 12:
				gotoxy(41,5+r);
				cprintf("Dec");
				break;
		}
}
void output()
{
	int a,row=0,index,status=0,i,j;
	char arrow;
	a=N;
	if(a%17==0)
	{
		a--;
		status=1;
	}
	i=1;
	while(i<=a/17+1)//i is number of page
	{
		clrscr();
		table(24,77,2,GREEN);
		if(N<=17)
		{
			gotoxy(32,2);
			cprintf("[ Workers List ]");
		}
		else
		{
			gotoxy(25,2);
			cprintf("[ Workers List : Page %d of %d ]",i,a/17+1);
		}
		output_start();
		textcolor(7);
		textbackground(BLUE);
		gotoxy(4,4);
		blank(72);           //("123456789-123456789-123456789-123456789-123456789-123456789-123456789-12");
		gotoxy(3,4);	cprintf("|  ID  |       Name       | Sex | Date of Birth |   Position  |  Salary  |");
		output_style(0);
		index=17*(i-1);
		j=index;
		row=0;
		while(j<17*i&&j<a)
		{
			output1(j,row);
			row++;
			j++;
		}
		output_end(5+row);
		if(status==1&&i==a/17+1)
		{
			gotoxy(4,21);
			blank(72);
			output1(j,row);
			output_end(6+row);
		}
		gotoxy(4,23);
		textbackground(RED);
		textcolor(WHITE);
		cprintf(" Press [ %c ] or [ %c ] to scroll      Press [ Esc ] to exit to Main Menu ",24,25);
		gotoxy(4,23);
		textcolor(0);
		cprintf(" Press [ %c ] or [ %c ] to scroll",24,25);
		if(N>17)
		{
			gotoxy(4,23);
			textcolor(WHITE);
			textbackground(RED);
			cprintf(" Press [ %c ] or [ %c ] to scroll      Press [ Esc ] to exit to Main Menu ",24,25);
		}
		textbackground(0);
		arrow=getch();
		if(arrow==72)
			i--;
		else if(arrow==80)
			i++;
		else if(arrow==27)
			break;
		if(i>a/17+1)
			i=1;
		if(i==0)
			i=a/17+1;

	}
	clrscr();
	menu();
	menu1();
	show_menu(2);
}
//sort function start here
void sort_id(int A)
{
	worker temp;
	int i,j;
	switch(A)
	{
		case 1:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(data[i].id>data[j].id)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
		case 2:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(data[i].id<data[j].id)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
	}
}
void sort_name(int A) //if a = 1 then sort by increase, a = 2 decrease
{
	worker temp;
	int i,j;
	switch(A)
	{
		case 1:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(stricmp(data[i].name,data[j].name)>0)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
		case 2:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(stricmp(data[i].name,data[j].name)<0)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
	}
}

void sort_salary(int A)
{
	worker temp;
	int i,j;
	switch(A)
	{
		case 1:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(data[i].salary>data[j].salary)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
		case 2:
			for(i=0;i<N-1;i++)
				for(j=i+1;j<N;j++)
					if(data[i].salary<data[j].salary)
					{
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
			break;
	}
}
void sort_menu()
{
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(20,9); 	cprintf("Sort by ID        ");
	gotoxy(20,11);	cprintf("Sort by Name      ");
	gotoxy(20,13);	cprintf("Sort by Salary    ");
	gotoxy(20,15);	cprintf("Cancel            ");
	help_box();
}
void show_sort_menu(int a)
{
	textcolor(WHITE);
	switch(a)
	{
		case 1:
			gotoxy(20,9);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Sort by ID     ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Sort by ID ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Sort workers' information by ID, increase or decrease.   ");
			break;
		case 2:
			gotoxy(20,11);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Sort by Name   ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Sort by Name ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Sort workers' information by name, increase or decrease.  ");
			break;
		case 3:
			gotoxy(20,13);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Sort by Salary ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Sort by Salary ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Sort workers' information by salary, increase or decrease.");
			break;
		case 4:
			gotoxy(20,15);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Cancel         ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Cancel ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Exit to Main Menu.                                         ");
			break;
	}
	textbackground(0);
}
int show_sort_menu1()
{
	int a=1,status=0;
	char b;
	textcolor(LIGHTGREEN);
	gotoxy(27,19);	cprintf("%c",27);
	gotoxy(36,19);	cprintf("%c",26);
	textbackground(GREEN);
	textcolor(WHITE);
	gotoxy(42,12);	cprintf("    1 %c 9    ",26);
	textbackground(7);
	textcolor(0);
	gotoxy(54,12);	cprintf("    9 %c 1    ",26);
	while(status!=1){

		b=getch();
		if(b==77)  //  ->
			a++;
		else if(b==75)  //  <-
			a--;
		if(a>=3)
			a=1;
		else if(a<=0)
			a=2;
		switch(a)
		{
			case 1:
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(42,12);	cprintf("    1 %c 9    ",26);
				textbackground(7);
				textcolor(0);
				gotoxy(54,12);	cprintf("    9 %c 1    ",26);
				break;
			case 2:
				textbackground(7);
				textcolor(0);
				gotoxy(42,12);	cprintf("    1 %c 9    ",26);
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(54,12);	cprintf("    9 %c 1    ",26);
				break;
		}
		if(b==13&&a==1)
			status=1;
		if(b==13&&a==2)
			status=1;
	}
	return a;
}
int show_sort_menu2()
{
	int a=1,status=0;
	char b;
	textcolor(LIGHTGREEN);
	gotoxy(27,19);	cprintf("%c",27);
	gotoxy(36,19);	cprintf("%c",26);
	textbackground(GREEN);
	textcolor(WHITE);
	gotoxy(42,12);	cprintf("    A %c Z    ",26);
	textbackground(7);
	textcolor(0);
	gotoxy(54,12);	cprintf("    Z %c A    ",26);
	while(status!=1){

		b=getch();
		if(b==77)  //  ->
			a++;
		else if(b==75)  //  <-
			a--;
		if(a>=3)
			a=1;
		else if(a<=0)
			a=2;
		switch(a)
		{
			case 1:
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(42,12);	cprintf("    A %c Z    ",26);
				textbackground(7);
				textcolor(0);
				gotoxy(54,12);	cprintf("    Z %c A    ",26);
				break;
			case 2:
				textbackground(7);
				textcolor(0);
				gotoxy(42,12);	cprintf("    A %c Z    ",26);
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(54,12);	cprintf("    Z %c A    ",26);
				break;
		}
		if(b==13&&a==1)
			status=1;
		if(b==13&&a==2)
			status=1;
	}
	return a;
}
void msg_box();
void sort()
{
	int a=1,option,status=0;
	char b;
	_setcursortype(0);
	clrscr();
	interface();
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(25,4);	cprintf("[ Sort Workers' Information ]");
	sort_menu();
	show_sort_menu(a);
	do{
		b=getch();
		sort_menu();
		if(b==72) // 72 up
			a--;
		else if(b==80) // 80 down
			a++;
		if(a<=0)
			a=4;
		if(a>=5)
			a=1;
		switch(a)
		{
			case 1:
				show_sort_menu(a);
				break;
			case 2:
				show_sort_menu(a);
				break;
			case 3:
				show_sort_menu(a);
				break;
			case 4:
				show_sort_menu(a);
				break;
		}
		if(b==13&&a==1)
		{
			fflush(stdin);
			option=show_sort_menu1();
			sort_id(option);
			msg_box();
			textbackground(RED);
			gotoxy(25,12);
			cprintf("Records has been sorted by ID.");
			getch();
			status=1;
			textbackground(0);
		}
		if(b==13&&a==2)
		{
			fflush(stdin);
			option=show_sort_menu2();
			sort_name(option);
			msg_box();
			textbackground(RED);
			gotoxy(24,12);
			cprintf("Records has been sorted by Name.");
			getch();
			status=1;
			textbackground(0);
		}
		if(b==13&&a==3)
		{
			fflush(stdin);
			option=show_sort_menu1();
			sort_salary(option);
			msg_box();
			textbackground(RED);
			gotoxy(23,12);
			cprintf("Records has been sorted by Salary.");
			getch();
			status=1;
			textbackground(0);
		}
		else if(b==13&&a==4)
			status=1;
	}while(status!=1);
	clrscr();
	menu();
	menu1();
	show_menu(3);
}//end sort function

//search
void search_output()
{
	restore_color();
	//clrscr();
	_setcursortype(0);
	textbackground(0);
	table(24,77,2,GREEN);
	gotoxy(32,2);	cprintf("[ Search result ]");
	output_start();
	textcolor(7);
	textbackground(BLUE);
	gotoxy(4,4);
	blank(72);
	gotoxy(3,4);	cprintf("|  ID  |       Name       | Sex | Date of Birth |   Position  |  Salary  |");
	gotoxy(15,23);
	textbackground(RED);
	textcolor(WHITE);
	cprintf("        Press any key to exit to Main Menu        ");
	textbackground(0);
}
void search1()
{
	char s[20];
	int i,row=0,status,status_id=0,status_name=0;
	do{
		textbackground(RED);
		textcolor(0);
		gotoxy(35,15);	cprintf("    OK    ");
		_setcursortype(2);
		status=0;
		textcolor(WHITE);
		textbackground(LIGHTGREEN);
		gotoxy(31,12);
		blank(15);
		gotoxy(31,12);
		gets(s);
		if(*s==' '||strlen(s)==0)
			status=1;
		_setcursortype(0);
		textbackground(RED);
		textcolor(WHITE);
		gotoxy(35,15);	cprintf("    OK    ");
		delay(200);
	}while(status==1);
	restore_color();
	clrscr();
	for(i=0;i<N;i++)
		if(atoi(s)==data[i].id)
		{
			status_id=1;
			search_output();
			textbackground(0);
			output_style(0);
			output1(i,0); //row=0
			output_end(6);
			getch();
		}
	if(status_id==0)
	{
		search_output();
		for(i=0;i<N;i++)
			if(stricmp(data[i].name,s)==0)
			//if(strstr(data[i].name,s)!=NULL)
			{
				status_name=1;
				textbackground(0);
				output_style(0);
				output1(i,row);
				row++;
			}
		output_end(row+5);
		if(status_name==0)
		{
			restore_color();
			clrscr();
			textbackground(RED);
			gotoxy(19,11);	blank(42);
			gotoxy(19,12);	blank(42);
			gotoxy(19,13);	blank(42);
			textcolor(WHITE);
			gotoxy(35,12);	cprintf("NOT FOUND!");
			textbackground(BLUE);
			gotoxy(35,15);	cprintf("    OK    ");
			textbackground(0);

		}
		getch();
	}
	clrscr();
	menu();
	menu1();
	show_menu(4);
}
void search()
{
	clrscr();
	interface();
	textbackground(BLUE);
	textcolor(LIGHTGREEN);
	gotoxy(31,4);	cprintf("[ Search Worker ]");
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(22,10);	cprintf("Enter ID or Name of worker to search");
	textbackground(6);
	gotoxy(19,11);	blank(42);
	gotoxy(19,12);	blank(42);
	gotoxy(19,13);	blank(42);
	textcolor(WHITE);
	gotoxy(21,12);	cprintf("Search :");
	textbackground(LIGHTGREEN);
	gotoxy(30,12);	blank(29);
	textbackground(RED);
	textcolor(0);
	gotoxy(35,15);	cprintf("    OK    ");
	_setcursortype(2);
	search1();
	_setcursortype(0);
	getch();
	textbackground(0);
	clrscr();
	menu();
	menu1();
	show_menu(4);
}

//update function start here
void update_menu()
{
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(20,9); 	cprintf("Edit worker's record   ");
	gotoxy(20,11);	cprintf("Delete one record      ");
	gotoxy(20,13);	cprintf("Delete all records     ");
	gotoxy(20,15);	cprintf("Cancel                 ");
	help_box();
}
void show_update_menu(int a)
{
	textcolor(WHITE);
	switch(a)
	{
		case 1:
			gotoxy(20,9);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Edit worker's record ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Edit worker's record ]");
			textcolor(LIGHTGREEN);
			textbackground(0);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Edit a worker's record by enter ID.                         ");

			break;
		case 2:
			gotoxy(20,11);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Delete one record    ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Delete one record ]");
			textcolor(LIGHTGREEN);
			textbackground(0);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Delete a worker's record.                                   ");

			break;
		case 3:
			gotoxy(20,13);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Delete all records   ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Delete all records ]");
			textcolor(LIGHTGREEN);
			textbackground(0);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Delete all workers' records and data saved on disk.         ");

			break;
		case 4:
			gotoxy(20,15);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Cancel               ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Cancel ]");
			textcolor(LIGHTGREEN);
			textbackground(0);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Exit to Main Menu.                                          ");
			break;
	}
	textbackground(0);
}
void update_search()
{
	clrscr();
	_setcursortype(0);
	interface();
	textbackground(6);
	gotoxy(19,11);	blank(42);
	gotoxy(19,12);	blank(42);
	gotoxy(19,13);	blank(42);
	textcolor(WHITE);
	gotoxy(21,12);	cprintf("Search :");
	textbackground(LIGHTGREEN);
	gotoxy(30,12);	blank(29);
	textbackground(RED);
	textcolor(0);
	gotoxy(35,15);	cprintf("    OK    ");
}
void edit(int i)
{
	char tmp_id[5],tmp_name[20],tmp_position[20],tmp_salary[8],tmp_d[3],tmp_m[3],tmp_y[5];
	int a=1,j,count,status;
	char option,b;
	textcolor(WHITE);
	//id
	gotoxy(34,9);
	textbackground(GREEN);
	cprintf("Edit ID?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,9);
		blank(20);
		gotoxy(34,9);
		cprintf("%d",data[i].id);
		textbackground(0);
	}
	else
	{
		do{
			status=0;
			do{
				_setcursortype(2);
				count=0;
				textbackground(5);
				gotoxy(34,9);
				blank(20);
				fflush(stdin);
				gotoxy(34,9);	gets(tmp_id);
				textbackground(0);
				for(j=0;j<strlen(tmp_id);j++)
					if(*(tmp_id+j)>=48&&*(tmp_id+j)<=57)
						count++;
				if(count!=strlen(tmp_id))
				{
					gotoxy(15,22);
					textbackground(RED);
					cprintf("           Message : ID must in number !          ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_id));
			if(atoi(tmp_id)<=0||atoi(tmp_id)>100)
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("    Message : Invalid ID, ID must between 1-100   ");
				textbackground(0);
			}
			for(j=0;j<N;j++)
				if(atoi(tmp_id)==data[j].id)
				{
					status=1;
					gotoxy(15,22);
					textbackground(RED);
					cprintf("           Message : ID already exist !           ");
					textbackground(0);
				}
		}while(status==1);
		data[i].id=atoi(tmp_id);
		gotoxy(15,22);	blank(50);
	}


	//name
	_setcursortype(0);
	gotoxy(34,11);
	textbackground(GREEN);
	cprintf("Edit Name?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,11);
		blank(30);
		gotoxy(34,11);
		cprintf("%s",data[i].name);
		textbackground(0);
	}
	else
	{
		do{
			status=0;
			count=0;
			_setcursortype(2);
			gotoxy(34,11);
			textbackground(5);
			blank(31);
			fflush(stdin);
			gotoxy(34,11);	gets(tmp_name);
			for(j=0;j<strlen(tmp_name);j++)
				if(*(tmp_name+j)>=65&&*(tmp_name+j)<=90||*(tmp_name+j)>=97&&*(tmp_name+j)<=122||*(tmp_name+j)==32)
					count++;
			if(count!=strlen(tmp_name))
			{
				gotoxy(15,22);
				textbackground(RED);
				cprintf("            Message : Incorrect name              ");
				textbackground(0);
			}
			if(strlen(tmp_name)==0||*tmp_name==' ') //first character cant be a space
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("            Message : Incorrect name              ");
				textbackground(0);
			}
		}while(count!=strlen(tmp_name)||status==1);
		//capital letter name
		if(*(tmp_name)>=97&&*(tmp_name)<=122)
			*tmp_name=*tmp_name-32;
		for(j=0;j<strlen(tmp_name);j++)
		{
			if((*(tmp_name+j)>=97&&*(tmp_name+j)<=122)&&*(tmp_name+j-1)==' ')
				*(tmp_name+j)=*(tmp_name+j)-32;
		}
		gotoxy(34,11);
		cprintf("%s",tmp_name);
		strcpy(data[i].name,tmp_name);
		textbackground(0);
		gotoxy(15,22);	blank(50);
		textbackground(5);
	}

	//sex
	_setcursortype(0);
	gotoxy(34,13);
	textbackground(GREEN);
	cprintf("Edit Sex?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,13);
		blank(30);
		gotoxy(34,13);
		if(stricmp(data[i].sex,"M")==0)
			cprintf("Male");
		else if(stricmp(data[i].sex,"F")==0)
			cprintf("Female");
		textbackground(0);
	}
	else
	{
		a=1;
		_setcursortype(0);
		textbackground(GREEN);
		textcolor(WHITE);
		gotoxy(34,13);
		cprintf("     Male     ");
		gotoxy(34+13,13);
		textbackground(7);
		textcolor(0);
		cprintf("    Female    ");
		gotoxy(15,22);
		textbackground(RED);
		textcolor(WHITE);
		cprintf("       Help : Press [ %c ] or [ %c ] to select      ",27,26);
		textbackground(0);
		do{

			b=getch();
			if(b==77)  //  ->
				a++;
			else if(b==75)  //  <-
				a--;
			if(a>=3)
				a=1;
			else if(a<=0)
				a=2;
			switch(a)
			{
				case 1:
					textbackground(GREEN);
					textcolor(WHITE);
					gotoxy(34,13);
					cprintf("     Male     ");
					gotoxy(34+13,13);
					textbackground(7);
					textcolor(0);
					cprintf("    Female    ");

					break;
				case 2:
					textbackground(7);
					textcolor(0);
					gotoxy(34,13);
					cprintf("     Male     ");
					gotoxy(34+13,13);
					textbackground(GREEN);
					textcolor(WHITE);
					cprintf("    Female    ");

					break;
			}
		}while(b!=13);
		textbackground(5);
		textcolor(WHITE);
		gotoxy(34,13);
		blank(27);
		if(a==1)
		{
			strcpy(data[i].sex,"M");
			gotoxy(34,13);
			cprintf("Male");
		}
		else if(a==2)
		{
			strcpy(data[i].sex,"F");
			gotoxy(34,13);
			cprintf("Female");
		}
		_setcursortype(2);
		textbackground(0);
		gotoxy(15,22);	blank(50);
		textbackground(5);
	}
	//dob
	_setcursortype(0);
	gotoxy(34,15);
	textbackground(GREEN);
	cprintf("Edit Date of birth?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,15);
		blank(30);
		gotoxy(34,15);
		cprintf("%2d-   -%d",data[i].d,data[i].y);
		gotoxy(36,15);
		show_month(data[i].m);
		textbackground(0);
	}
	else
	{
		//day
		_setcursortype(2);
		gotoxy(15,21);
		textbackground(RED);
		cprintf("              Help : Input Day (01-31)            ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34,15);
				textbackground(5);
				blank(31);
				gotoxy(34,15);	gets(tmp_d);
				for(j=0;j<strlen(tmp_d);j++)
					if(*(tmp_d+j)>=48&&*(tmp_d+j)<=57)
						count++;
				if(count!=strlen(tmp_d))
				{
					gotoxy(15,22);
					textbackground(RED);
					cprintf("       Message : Invalid day, enter 01 to 31      ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_d));
			if(atoi(tmp_d)<=0||atoi(tmp_d)>31)
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("       Message : Invalid day, enter 01 to 31      ");
				textbackground(0);
			}
		}while(status==1);
		data[i].d=atoi(tmp_d);
		gotoxy(34,15);	cprintf("%2d-",data[i].d);
		textbackground(0);
		gotoxy(15,22);	blank(50);
		textbackground(5);
		//month
		gotoxy(15,21);
		textbackground(RED);
		cprintf("            Help : Input Month (01-12)            ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34+3,15);
				textbackground(5);
				blank(26);
				gotoxy(34+3,15);	gets(tmp_m);
				for(j=0;j<strlen(tmp_m);j++)
					if(*(tmp_m+j)>=48&&*(tmp_m+j)<=57)
						count++;
				if(count!=strlen(tmp_m))
				{
					gotoxy(15,22);
					textbackground(RED);
					cprintf("      Message : Invalid month, enter 01 to 12     ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_m));
			if(atoi(tmp_m)<=0||atoi(tmp_m)>12)
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("      Message : Invalid month, enter 01 to 12     ");
				textbackground(0);
			}
		}while(status==1);
		data[i].m=atoi(tmp_m);
		textbackground(0);
		gotoxy(15,22);	blank(50);
		textbackground(5);
		gotoxy(36,15);
		show_month(data[i].m);

		//year
		gotoxy(15,21);
		textbackground(RED);
		cprintf("           Help : Input Year (1955-2000)          ");
		do{
			status=0;
			do{
				count=0;
				gotoxy(34+3+4,15);
				textbackground(5);
				blank(22);
				gotoxy(34+3+4,15);	gets(tmp_y);
				for(j=0;j<strlen(tmp_y);j++)
					if(*(tmp_y+j)>=48&&*(tmp_y+j)<=57)
						count++;
				if(count!=strlen(tmp_y))
				{
					gotoxy(15,22);
					textbackground(RED);
					cprintf("    Message : Invalid year, enter 1955 to 2000    ");
					textbackground(0);
				}
			}while(count!=strlen(tmp_y));
			if(atoi(tmp_y)<=1954||atoi(tmp_y)>2000)
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("    Message : Invalid year, enter 1955 to 2000    ");
				textbackground(0);
			}
		}while(status==1);
		data[i].y=atoi(tmp_y);
		textbackground(0);
		gotoxy(15,21);	blank(50);
		gotoxy(15,22);	blank(50);
		textbackground(5);
	}
	//position
	_setcursortype(0);
	gotoxy(34,17);
	textbackground(GREEN);
	cprintf("Edit Position?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,17);
		blank(30);
		gotoxy(34,17);
		cprintf("%s",data[i].position);
		textbackground(0);
	}
	else
	{
		do{
			status=0;
			count=0;
			_setcursortype(2);
			gotoxy(34,17);
			textbackground(5);
			blank(31);
			fflush(stdin);
			gotoxy(34,17);	gets(tmp_position);
			for(j=0;j<strlen(tmp_position);j++)
				if(*(tmp_position+j)>=65&&*(tmp_position+j)<=90||*(tmp_position+j)>=97&&*(tmp_position+j)<=122||*(tmp_position+j)==32)
					count++;
			if(count!=strlen(tmp_position))
			{
				gotoxy(15,22);
				textbackground(RED);
				cprintf("          Message : Incorrect position            ");
				textbackground(0);
			}
			if(strlen(tmp_position)==0||*tmp_position==' ') //first character can't be a space
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("          Message : Incorrect position            ");
				textbackground(0);
			}
		}while(count!=strlen(tmp_position)||status==1);
		if(*(tmp_position)>=97&&*(tmp_position)<=122)
			*tmp_position=*tmp_position-32;
		for(j=0;j<strlen(tmp_position);j++)
			if((*(tmp_position+j)>=97&&*(tmp_position+j)<=122)&&*(tmp_position+j-1)==' ')
				*(tmp_position+j)=*(tmp_position+j)-32;
		gotoxy(34,17);
		cprintf("%s",tmp_position);
		strcpy(data[i].position,tmp_position);
		textbackground(0);
		gotoxy(15,22);	blank(50);
		textbackground(5);
	}
	//salary
	_setcursortype(0);
	gotoxy(34,19);
	textbackground(GREEN);
	cprintf("Edit Salary?");
	gotoxy(15,22);
	textbackground(RED);
	cprintf("    HELP : Press Any key to edit, Esc to skip.    ");
	textbackground(0);
	option=getch();
	gotoxy(15,22);	blank(50);
	if(option==27)
	{
		textbackground(5);
		gotoxy(34,19);
		blank(30);
		gotoxy(34,19);
		cprintf("%0.2f",data[i].salary);
		textbackground(0);
	}
	else
	{
		do{
			_setcursortype(2);
			count=0;
			status=0;
			textbackground(5);
			gotoxy(34,19);	blank(20);
			gotoxy(34,19);	gets(tmp_salary);
			textbackground(0);
			for(j=0;j<strlen(tmp_salary);j++)
				if(*(tmp_salary+j)>=48&&*(tmp_salary+j)<=57||*(tmp_salary+j)==46)
					count++;
			if(count!=strlen(tmp_salary))
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("         Message : salary must in number !        ");
				textbackground(0);
			}
			if(count==strlen(tmp_salary)&&atoi(tmp_salary)<=0)
			{
				status=1;
				gotoxy(15,22);
				textbackground(RED);
				cprintf("             Message : Invalid Salary !           ");
				textbackground(0);
			}
		}while(status==1);//count!=strlen(tmp_salary));
		data[i].salary=atof(tmp_salary);
		gotoxy(15,22);	blank(50);
	}
	//end
	_setcursortype(0);
	//getch();
}

void show_edit()
{
	char s[10],option;
	int status,i,count,a;
	update_search();
	textbackground(BLUE);
	textcolor(LIGHTGREEN);
	gotoxy(33,4);	cprintf("[ Edit Worker ]");
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(22,10);	cprintf("Enter ID of worker you want to edit:");
	_setcursortype(2);
	do{
		textbackground(RED);
		textcolor(0);
		gotoxy(35,15);	cprintf("    OK    ");
		_setcursortype(2);
		status=0;
		count=0;
		textcolor(WHITE);
		textbackground(LIGHTGREEN);
		gotoxy(31,12);
		blank(15);
		gotoxy(31,12);
		gets(s);
		for(i=0;i<strlen(s);i++)
			if(*(s+i)>=48&&*(s+i)<=57)
				count++;
		if(count!=strlen(s))
			status=1;
		if(*s==' '||strlen(s)==0)
			status=1;
		_setcursortype(0);
		textbackground(RED);
		textcolor(WHITE);
		gotoxy(35,15);	cprintf("    OK    ");
		//delay(200);
		if(status==1)
		{
			textbackground(0);
			textcolor(RED);
			gotoxy(22,10);	cprintf("Enter ID of worker you want to edit:");
			delay(100);
			textcolor(LIGHTGREEN);
			gotoxy(22,10);	cprintf("Enter ID of worker you want to edit:");
			delay(100);
			textcolor(YELLOW);
			gotoxy(22,10);	cprintf("Enter ID of worker you want to edit:");
		}
	}while(status==1);
	status=0;
	for(i=0;i<N;i++)
		if(atoi(s)==data[i].id)
		{
			//start
			status=1;
			restore_color();
			clrscr();
			search_output();
			output_style(0);
			output1(i,0);
			output_end(6);
			gotoxy(15,23);
			textbackground(0);
			blank(50);
			gotoxy(18,9);
			textcolor(RED);
			cprintf("Are you sure to update this worker's record?");
			textcolor(WHITE);
			gotoxy(30,11);
			textbackground(GREEN);
			textcolor(WHITE);
			cprintf("   YES   ");
			gotoxy(45,11);
			textbackground(7);
			textcolor(0);
			cprintf("   NO   ");
			a=1;
			do{
				option=getch();
				if(option==77)
					a++;
				else if(option==75)
					a--;
				if(a>=3)
					a=1;
				else if(a<=0)
					a=2;
				switch(a)
				{
					case 1:
						gotoxy(30,11);
						textbackground(GREEN);
						textcolor(WHITE);
						cprintf("   YES   ");
						gotoxy(45,11);
						textbackground(7);
						textcolor(0);
						cprintf("   NO   ");
						break;
					case 2:
						gotoxy(30,11);
						textbackground(7);
						textcolor(0);
						cprintf("   YES   ");
						gotoxy(45,11);
						textbackground(GREEN);
						textcolor(WHITE);
						cprintf("   NO   ");
						break;
				}
			}while(option!=13);
			textbackground(0);
			textcolor(LIGHTGREEN);
			switch(a)
			{
				case 1: //yes
					textcolor(YELLOW);
					gotoxy(21,7);
					cprintf("Enter new information of this worker:");
					textcolor(WHITE);
					textbackground(5);
					for(int b=0;b<13;b++)
					{
						gotoxy(15,8+b);	blank(50);
					}
					for(b=0;b<13;b+=2)
					{
						gotoxy(17,8+b);	cprintf("----------------------------------------------");
					}
					textcolor(WHITE);
					gotoxy(18,9);	cprintf("ID            :");
					gotoxy(18,11);  cprintf("Name          :");
					gotoxy(18,13);  cprintf("Sex           :");
					gotoxy(18,15);  cprintf("Date of birth :");
					gotoxy(18,17);  cprintf("Position      :");
					gotoxy(18,19);	cprintf("Salary ($)    :");
					gotoxy(15,21);
					//function edit
					edit(i);
					//getch();
					textbackground(BLACK);
					break;
				case 2:
					msg_box();
					textbackground(RED);
					gotoxy(36,12);
					cprintf("Canceled");
					break;
			}
			gotoxy(15,23);
			textbackground(RED);
			textcolor(WHITE);
			cprintf("        Press any key to exit to Main Menu        ");
			textbackground(0);
			getch();
		}
	if(status==0)
	{
		restore_color();
		clrscr();
		textbackground(RED);
		gotoxy(19,11);	blank(42);
		gotoxy(19,12);	blank(42);
		gotoxy(19,13);	blank(42);
		textcolor(WHITE);
		gotoxy(35,12);	cprintf("NOT FOUND!");
		textbackground(BLUE);
		gotoxy(35,15);	cprintf("    OK    ");
		textbackground(0);
		getch();
	}

	_setcursortype(0);
	restore_color();
}
void show_delete_one()
{
	char s[10],option;
	int status,i,count,a;
	clrscr();
	update_search();
	textbackground(BLUE);
	textcolor(LIGHTGREEN);
	gotoxy(31,4);	cprintf("[ Delete Worker ]");
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(21,10);	cprintf("Enter ID of worker you want to delete:");
	_setcursortype(2);
	do{
		textbackground(RED);
		textcolor(0);
		gotoxy(35,15);	cprintf("    OK    ");
		_setcursortype(2);
		status=0;
		count=0;
		textcolor(WHITE);
		textbackground(LIGHTGREEN);
		gotoxy(31,12);
		blank(15);
		gotoxy(31,12);
		gets(s);
		for(i=0;i<strlen(s);i++)
			if(*(s+i)>=48&&*(s+i)<=57)
				count++;
		if(count!=strlen(s))
			status=1;
		if(*s==' '||strlen(s)==0)
			status=1;
		_setcursortype(0);
		textbackground(RED);
		textcolor(WHITE);
		gotoxy(35,15);	cprintf("    OK    ");
		if(status==1)
		{
			textbackground(0);
			textcolor(RED);
			gotoxy(21,10);	cprintf("Enter ID of worker you want to delete:");
			delay(100);
			textcolor(LIGHTGREEN);
			gotoxy(21,10);	cprintf("Enter ID of worker you want to delete:");
			delay(100);
			textcolor(YELLOW);
			gotoxy(21,10);	cprintf("Enter ID of worker you want to delete:");
		}
	}while(status==1);
	status=0;
	for(i=0;i<N;i++)
		if(atoi(s)==data[i].id)
		{
			//start
			status=1;
			restore_color();
			clrscr();
			search_output();
			output_style(0);
			output1(i,0);
			output_end(6);
			gotoxy(15,23);
			textbackground(0);
			blank(50);
			gotoxy(18,9);
			textcolor(RED);
			cprintf("Are you sure to delete this worker's record?");
			textcolor(WHITE);
			gotoxy(30,11);
			textbackground(GREEN);
			textcolor(WHITE);
			cprintf("   YES   ");
			gotoxy(45,11);
			textbackground(7);
			textcolor(0);
			cprintf("   NO   ");
			a=1;
			do{
				option=getch();
				if(option==77)
					a++;
				else if(option==75)
					a--;
				if(a>=3)
					a=1;
				else if(a<=0)
					a=2;
				switch(a)
				{
					case 1:
						gotoxy(30,11);
						textbackground(GREEN);
						textcolor(WHITE);
						cprintf("   YES   ");
						gotoxy(45,11);
						textbackground(7);
						textcolor(0);
						cprintf("   NO   ");
						break;
					case 2:
						gotoxy(30,11);
						textbackground(7);
						textcolor(0);
						cprintf("   YES   ");
						gotoxy(45,11);
						textbackground(GREEN);
						textcolor(WHITE);
						cprintf("   NO   ");
						break;
				}
			}while(option!=13);
			textbackground(0);
			textcolor(LIGHTGREEN);
			switch(a)
			{
				case 1: //yes
					for(int j=i;j<N;j++)
						data[j]=data[j+1];
					N--;
					msg_box();
					gotoxy(36,12);
					textbackground(RED);
					cprintf("Deleted!");
					break;
				case 2:
					msg_box();
					gotoxy(36,12);
					textbackground(RED);
					cprintf("Canceled");
					//getch();
					break;
			}
			gotoxy(15,23);
			textbackground(RED);
			textcolor(WHITE);
			cprintf("        Press any key to exit to Main Menu        ");
			textbackground(0);
			getch();
		}
	if(status==0)
	{
		restore_color();
		clrscr();
		textbackground(RED);
		gotoxy(19,11);	blank(42);
		gotoxy(19,12);	blank(42);
		gotoxy(19,13);	blank(42);
		textcolor(WHITE);
		gotoxy(35,12);	cprintf("NOT FOUND!");
		textbackground(BLUE);
		gotoxy(35,15);	cprintf("    OK    ");
		textbackground(0);
		getch();
	}
	_setcursortype(0);
	//getch();
	restore_color();
}
int show_delete_all()
{
	int a=1,status=0;
	char b;
	textcolor(LIGHTGREEN);
	gotoxy(27,19);	cprintf("%c",27);
	gotoxy(36,19);	cprintf("%c",26);

	gotoxy(10,20);
	textbackground(RED);
	textcolor(WHITE);
	cprintf("- Warning : Are you sure to delete all workers' records?    ");
	textbackground(GREEN);
	textcolor(WHITE);
	gotoxy(44,12);	cprintf("     YES     ",26);
	textbackground(7);
	textcolor(0);
	gotoxy(57,12);	cprintf("      NO     ",26);
	while(status!=1){

		b=getch();
		if(b==77)  //  ->
			a++;
		else if(b==75)  //  <-
			a--;
		if(a>=3)
			a=1;
		else if(a<=0)
			a=2;
		switch(a)
		{
			case 1:
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(44,12);	cprintf("     YES     ",26);
				textbackground(7);
				textcolor(0);
				gotoxy(57,12);	cprintf("      NO     ",26);
				break;
			case 2:
				textbackground(7);
				textcolor(0);
				gotoxy(44,12);	cprintf("     YES     ",26);
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(57,12);	cprintf("      NO     ",26);
				break;
		}
		if(b==13&&a==1)
			status=1;
		if(b==13&&a==2)
			status=1;
	}
	return a;
}
void update()
{
	int a=1,status=0,option;
	char b;
	_setcursortype(0);
	clrscr();
	interface();
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(24,4);	cprintf("[ Update Workers' Information ]");
	update_menu();
	show_update_menu(a);
	do{
		b=getch();
		update_menu();
		if(b==72) // 72 up
			a--;
		else if(b==80) // 80 down
			a++;
		if(a<=0)
			a=4;
		if(a>=5)
			a=1;
		switch(a)
		{
			case 1:
				show_update_menu(a);
				break;
			case 2:
				show_update_menu(a);
				break;
			case 3:
				show_update_menu(a);
				break;
			case 4:
				show_update_menu(a);
				break;
		}
		if(b==13&&a==1)
		{
			//edit_fun here
			show_edit();
			break;
		}
		else if(b==13&&a==2)
		{
			show_delete_one();
			break;
		}
		else if(b==13&&a==3)
		{
			option=show_delete_all();
			switch(option)
			{
				case 1:
					msg_box();
					textbackground(RED);
					gotoxy(27,12);
					cprintf("All data has been deleted!");
					for(int i=0;i<N;i++)
						data[i]=data[N];
					N=0;
					textbackground(0);
					break;
				case 2:
					msg_box();
					textbackground(RED);
					gotoxy(36,12);
					cprintf("Canceled");
					textbackground(0);
					break;
			}

			status=1;
			getch();
		}
		else if(b==13&&a==4)
			status=1;
	}while(status!=1);
	clrscr();
	menu();
	menu1();
	show_menu(5);
}
int check_data()
{
	int a=0;
	if(data[0].id==NULL)
	{
		clrscr();
		textbackground(RED);
		gotoxy(19,11);	blank(42);
		gotoxy(19,12);	blank(42);
		gotoxy(19,13);	blank(42);
		textcolor(WHITE);
		gotoxy(22,12);	cprintf("No data of workers found, add first.");
		textbackground(BLUE);
		gotoxy(35,15);	cprintf("    OK    ");
		textbackground(0);
		a=1;
	}
	return a;
}
//end all main funtions

//password and backup functions
void pass_interface(int a)
{
	clrscr();
	switch(a)
	{
		case 0:
			textbackground(RED);
			gotoxy(19,10);	blank(42);
			gotoxy(19,11);	blank(42);
			gotoxy(19,12);	blank(42);
			gotoxy(19,13);	blank(42);
			gotoxy(19,14);	blank(42);
			textcolor(WHITE);
			gotoxy(22,11);	cprintf("Password  : ");
			gotoxy(22,13);	cprintf("Re-type   : ");
			textbackground(GREEN);
			gotoxy(35,11);	blank(24); //input 36,11
			gotoxy(35,13);  blank(24);
			textbackground(BLUE);
			gotoxy(35,16);	cprintf("    OK    ");
			textbackground(0);
			//getch();
			break;
		case 1:
			textbackground(RED);
			gotoxy(19,11);	blank(42);
			gotoxy(19,12);	blank(42);
			gotoxy(19,13);	blank(42);
			textcolor(WHITE);
			gotoxy(22,12);	cprintf("Password  : ");
			textbackground(GREEN);
			gotoxy(35,12);	blank(24);
			textbackground(BLUE);
			gotoxy(35,15);	cprintf("    OK    ");
			textbackground(0);
			//getch();
			break;
		case 2:
			textbackground(RED);
			gotoxy(19,9);	blank(42);
			gotoxy(19,10);	blank(42);
			gotoxy(19,11);	blank(42);
			gotoxy(19,12);	blank(42);
			gotoxy(19,13);	blank(42);
			gotoxy(19,14);	blank(42);
			gotoxy(19,15);	blank(42);
			textcolor(WHITE);
			gotoxy(22,10);	cprintf("Old password: ");
			gotoxy(22,12);	cprintf("New Password: ");
			gotoxy(22,14);	cprintf("Re-type     : ");
			textbackground(GREEN);
			gotoxy(35,10);	blank(22);
			gotoxy(35,12);	blank(22);
			gotoxy(35,14);	blank(22);
			textbackground(BLUE);
			gotoxy(35,17);	cprintf("    OK    ");
			textbackground(0);
			//getch();
			break;
	}
}
void msg_box()
{
	textbackground(RED);
	gotoxy(19,11);	blank(42);
	gotoxy(19,12);	blank(42);
	gotoxy(19,13);	blank(42);
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(35,15);	cprintf("    OK    ");
	textbackground(0);
}
int check_password()
{
	pass=fopen("c:/pass.pas","rb");
	if(pass==NULL)
		return 0;
	else return 1;
}
void encrypt()
{
	for(int i=0;i<strlen(mypw);i++)
		*(mypw+i)+=(2*i+i+7);
}
void decrypt()
{
	for(int i=0;i<strlen(mypw);i++)
		*(mypw+i)-=(2*i+i+7);
}
void read_password()
{
	int i;
	pass=fopen("c:/pass.pas","rb");
	fseek(pass,0L,2);
	i=ftell(pass)/sizeof(char);
	rewind(pass);
	fread(&mypw,sizeof(char),i,pass);
	fclose(pass);
	decrypt();
}
void save_password()
{
	encrypt();
	pass=fopen("c:/pass.pas","wb");
	fwrite(&mypw,sizeof(char),strlen(mypw),pass);
	fclose(pass);
}
void input_password()
{
	int s,i,check;
	char p;
	textcolor(WHITE);
	textbackground(GREEN);
	_setcursortype(2);
	check=check_password();
	switch(check)
	{
		case 0:
			for(i=0;i<20;i++)
			{
				*(pw0+i)=NULL;
				*(pw1+i)=NULL;
			}
			i=0;
			s=0;
			//enter pass
			while(s!=1)
			{
				gotoxy(36+i,11);
				fflush(stdin);
				p=getch();
				if(p==8)
				{
					if(i==0)	continue;
					else	i--;
					gotoxy(36+i,11);
					cprintf(" ");
					*(pw0+i)=NULL;
				}
				else if(p==13)
				{
					s=1;
					if(i==0)
						*(pw0+i)=NULL;
				}
				else
				{
					cprintf("*");
					*(pw0+i)=p;
					i++;
				}
			}
			i=0;
			s=0;
			//re-enter pass
			while(s!=1)
			{
				gotoxy(36+i,13);
				fflush(stdin);
				p=getch();
				if(p==8)
				{
					if(i==0)	continue;
					else	i--;
					gotoxy(36+i,13);
					cprintf(" ");
					*(pw1+i)=NULL;
				}
				else if(p==13)
				{
					s=1;
					if(i==0)
						*(pw1+i)=NULL;
				}
				else
				{
					cprintf("*");
					*(pw1+i)=p;
					i++;
				}
			}
			if(strcmp(pw0,pw1)==0)
			{
				if(*pw0!=NULL)
				{
					strcpy(mypw,pw1);
					save_password();
					_setcursortype(0);
					restore_color();
					clrscr();
					msg_box();
					textbackground(RED);
					gotoxy(31,12);	cprintf("New Password Set !");
					textbackground(0);
					getch();
				}
				else
				{
					_setcursortype(0);
					restore_color();
					clrscr();
					msg_box();
					textbackground(RED);
					gotoxy(31,12);	cprintf("Password Not Set !");
					textbackground(0);
					getch();
				}
			}
			else
			{
				_setcursortype(0);
				restore_color();
				clrscr();
				msg_box();
				textbackground(RED);
				gotoxy(29,12);	cprintf("Password doesn't match !");
				textbackground(0);
				getch();
			}
			break;
		case 1:
			for(i=0;i<20;i++)
			{
				*(pw1+i)=NULL;
			}
			i=0;
			s=0;
			//enter pass
			while(s!=1)
			{
				gotoxy(36+i,12);
				fflush(stdin);
				p=getch();
				if(p==8)
				{
					if(i==0)	continue;
					else	i--;
					gotoxy(36+i,12);
					cprintf(" ");
					*(pw1+i)=NULL;
				}
				else if(p==13)	s=1;
				else
				{
					cprintf("*");
					*(pw1+i)=p;
					i++;
				}
			}
			break;
	}
	_setcursortype(0);
}
void update_password()
{
	int i,s;
	char p;
	_setcursortype(2);
	textcolor(WHITE);
	textbackground(GREEN);
	for(i=0;i<20;i++)
	{
		*(pw0+i)=NULL;
		*(pw1+i)=NULL;
		*(pw2+i)=NULL;
	}
	i=0;
	s=0;
	//enter old pass
	while(s!=1)
	{
		gotoxy(36+i,10);
		fflush(stdin);
		p=getch();
		if(p==8)
		{
			if(i==0)	continue;
			else	i--;
			gotoxy(36+i,10);
			cprintf(" ");
			*(pw0+i)=NULL;
		}
		else if(p==13)
		{
			s=1;
			if(i==0)
				*(pw0+i)=NULL;
		}
		else
		{
			cprintf("*");
			*(pw0+i)=p;
			i++;
		}
	}
	i=0;
	s=0;
	//new pass
	while(s!=1)
	{
		gotoxy(36+i,12);
		fflush(stdin);
		p=getch();
		if(p==8)
		{
			if(i==0)	continue;
			else	i--;
			gotoxy(36+i,12);
			cprintf(" ");
			*(pw1+i)=NULL;
		}
		else if(p==13)
		{
			s=1;
			if(i==0)
				*(pw1+i)=NULL;
		}
		else
		{
			cprintf("*");
			*(pw1+i)=p;
				i++;
		}
	}
	i=0;
	s=0;
	while(s!=1)
	{
		gotoxy(36+i,14);
		fflush(stdin);
		p=getch();
		if(p==8)
		{
			if(i==0)	continue;
			else	i--;
			gotoxy(36+i,14);
			cprintf(" ");
			*(pw2+i)=NULL;
		}
		else if(p==13)
		{
			s=1;
			if(i==0)
				*(pw2+i)=NULL;
		}
		else
		{
			cprintf("*");
			*(pw2+i)=p;
				i++;
		}
	}
	if(strcmp(pw0,mypw)==0)
	{
		if(strcmp(pw1,pw2)==0)
		{
			if(*(pw1)==NULL)
			{
				remove("c:/pass.pas");
				_setcursortype(0);
				restore_color();
				clrscr();
				msg_box();
				textbackground(RED);
				gotoxy(32,12);	cprintf("Password Removed !");
				textbackground(0);
				getch();
			}
			else
			{
				strcpy(mypw,pw1);
				save_password();
				_setcursortype(0);
				restore_color();
				clrscr();
				msg_box();
				textbackground(RED);
				gotoxy(31,12);	cprintf("New Password Set !");
				textbackground(0);
				getch();
			}
		}
		else
		{
			_setcursortype(0);
			restore_color();
			clrscr();
			msg_box();
			textbackground(RED);
			gotoxy(29,12);	cprintf("Password doesn't match !");
			textbackground(0);
			getch();
		}
	}
	else
	{
		_setcursortype(0);
		restore_color();
		clrscr();
		msg_box();
		textbackground(RED);
		gotoxy(30,12);	cprintf("Incorrect Password !");
		textbackground(0);
		getch();
	}
	_setcursortype(0);
}
void backup_menu()
{
	textbackground(0);
	textcolor(YELLOW);
	gotoxy(20,9); 	cprintf("Backup Data       ");
	gotoxy(20,11);	cprintf("Restore Backup    ");
	gotoxy(20,13);	cprintf("Set Password      ");
	gotoxy(20,15);	cprintf("Cancel            ");
	help_box();
}
void show_backup_menu(int a)
{
	textcolor(WHITE);
	switch(a)
	{
		case 1:
			gotoxy(20,9);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Backup Data    ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Backup ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Backup information of worker.                              ");
			break;
		case 2:
			gotoxy(20,11);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Restore Backup ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Restore Backup ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Restore information of workers from backup file.          ");
			break;
		case 3:
			gotoxy(20,13);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Set Password   ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Set Password ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Set Password to protect accessing from other.             ");
			break;
		case 4:
			gotoxy(20,15);
			textbackground(0);
			cprintf("%c",16);
			textbackground(GREEN);
			cprintf(" Cancel         ");
			textbackground(0);
			textcolor(YELLOW);
			gotoxy(12,18);
			cprintf("[ Cancel ]");
			textcolor(LIGHTGREEN);
			gotoxy(10,19);
			cprintf("- Help : Press [ %c ] or [ %c ] to select options from Menu.",24,25);
			gotoxy(10,20);
			cprintf("- Exit to Main Menu.                                         ");
			break;
	}
	textbackground(0);
}
void backup()
{
	int i,a=1,option,status=0,check;
	char b;
	_setcursortype(0);
	clrscr();
	interface();
	textcolor(LIGHTGREEN);
	textbackground(BLUE);
	gotoxy(35,4);	cprintf("[ Options ]");
	backup_menu();
	show_backup_menu(a);
	do{
		b=getch();
		backup_menu();
		if(b==72) // 72 up
			a--;
		else if(b==80) // 80 down
			a++;
		if(a<=0)
			a=4;
		if(a>=5)
			a=1;
		switch(a)
		{
			case 1:
				show_backup_menu(a);
				break;
			case 2:
				show_backup_menu(a);
				break;
			case 3:
				show_backup_menu(a);
				break;
			case 4:
				show_backup_menu(a);
				break;
		}
		if(b==13&&a==1)
		{
			FILE *backup;
			if(data[0].id!=NULL)
			{
				backup=fopen("backup","wb");
				fwrite(data,sizeof(worker),N,backup);
				fclose(backup);
				clrscr();
				textbackground(RED);
				textcolor(7);
				gotoxy(19,10);	blank(42);
				gotoxy(19,14);	blank(42);
				gotoxy(32,10);	cprintf("Backup Completed");
				gotoxy(23,14);	cprintf("Press any key to exit to Main Menu");
				textbackground(YELLOW);
				gotoxy(19,11);	blank(42);
				gotoxy(19,12);	blank(42);
				gotoxy(19,13);	blank(42);
				gotoxy(27,12);	cprintf("File name : \"BACKUP\" saved.");
				getch();
				status=1;
			}
			else
			{
				clrscr();
				textbackground(RED);
				textcolor(7);
				gotoxy(19,10);	blank(42);
				gotoxy(19,14);	blank(42);
				gotoxy(34,10);	cprintf("Backup Failed");
				gotoxy(23,14);	cprintf("Press any key to exit to Main Menu");
				textbackground(YELLOW);
				gotoxy(19,11);	blank(42);
				gotoxy(19,12);	blank(42);
				gotoxy(19,13);	blank(42);
				gotoxy(26,12);	cprintf("Message : No data to backup.");
				getch();
				status=1;
			}
		}
		if(b==13&&a==2)
		{
			char ask;
			FILE *temp;
			temp=fopen("backup","rb");
			if(temp==NULL)
			{
				clrscr();
				textbackground(RED);
				textcolor(7);
				gotoxy(19,9);	blank(42);
				gotoxy(19,15);	blank(42);
				gotoxy(30,9);	cprintf("BACKUP FILE NOT FOUND");
				gotoxy(23,15);	cprintf("Press any key to exit to Main Menu");
				textbackground(YELLOW);
				gotoxy(19,10);	blank(42);
				gotoxy(19,11);	blank(42);
				gotoxy(19,12);	blank(42);
				gotoxy(19,13);	blank(42);
				gotoxy(19,14);	blank(42);
				//textcolor(WHITE);
				gotoxy(21,10);	cprintf(" - Make sure BACKUP file is in the same");
				gotoxy(20,11);	cprintf("directory with this program.");
				gotoxy(21,12);	cprintf(" - Dont rename BACKUP file. If you have");
				gotoxy(20,13);	cprintf("renamed it, please rename it to \"BACKUP\"");
				gotoxy(20,14);	cprintf("without double quote.");
				textbackground(0);
				//getch();
				fclose(temp);
				getch();
				status=1;

			}
			else
			{
				fclose(temp);
				clrscr();

				textbackground(RED);
				textcolor(7);
				gotoxy(19,9);	blank(43);
				gotoxy(19,14);	blank(43);
				gotoxy(35,9);	cprintf("WARNING !");
				gotoxy(23,14);	cprintf("Press [ %c ] or [ %c ] to select.",27,26);
				textbackground(YELLOW);
				gotoxy(19,10);	blank(43);
				gotoxy(19,11);	blank(43);
				gotoxy(19,12);	blank(43);
				gotoxy(19,13);	blank(43);
				//textcolor(WHITE);
				gotoxy(20,11);	cprintf("Are you sure to restore from BACKUP file?");
				gotoxy(20,12);	cprintf(" Old data will be replace with new data. ");
				textbackground(0);

				gotoxy(30,16);
				textbackground(GREEN);
				textcolor(WHITE);
				cprintf("   YES   ");
				gotoxy(45,16);
				textbackground(7);
				textcolor(0);
				cprintf("   NO   ");
				i=1;
				do{
					ask=getch();
					if(ask==77)
						i++;
					else if(ask==75)
						i--;
					if(i>=3)
						i=1;
					else if(a<=0)
						i=2;
					switch(i)
					{
						case 1:
							gotoxy(30,16);
							textbackground(GREEN);
							textcolor(WHITE);
							cprintf("   YES   ");
							gotoxy(45,16);
							textbackground(7);
							textcolor(0);
							cprintf("   NO   ");
							break;
						case 2:
							gotoxy(30,16);
							textbackground(7);
							textcolor(0);
							cprintf("   YES   ");
							gotoxy(45,16);
							textbackground(GREEN);
							textcolor(WHITE);
							cprintf("   NO   ");
							break;
					}
				}while(ask!=13);
				if(i==1)
				{
					remove("record.pcl");
					rename("backup","record.pcl");
					for(int j=0;j<100;j++)
						data[j]=data[100];
					N=0;
					fp=fopen("record.pcl","rb");
					fseek(fp,0L,2);
					N=ftell(fp)/sizeof(worker);
					rewind(fp);
					fread(data,sizeof(worker),N,fp);
					fclose(fp);
					restore_color();
					clrscr();
					textbackground(RED);
					gotoxy(19,11);	blank(42);
					gotoxy(19,12);	blank(42);
					gotoxy(19,13);	blank(42);
					textcolor(WHITE);
					gotoxy(31,12);	cprintf("Succesfully Restored.");
					textbackground(BLUE);
					gotoxy(35,15);	cprintf("    OK    ");
					textbackground(0);
					getch();
					//exit(0);
					status=1;
				}
				else if(i==2)
				{
					//msg cancel
					restore_color();
					clrscr();
					textbackground(RED);
					gotoxy(19,11);	blank(42);
					gotoxy(19,12);	blank(42);
					gotoxy(19,13);	blank(42);
					textcolor(WHITE);
					gotoxy(29,12);	cprintf("File Restoring Canceled.");
					textbackground(BLUE);
					gotoxy(35,15);	cprintf("    OK    ");
					textbackground(0);
					getch();
					status=1;
				}
			}
		}
		if(b==13&&a==3)
		{
			check=check_password();
			if(check==1)
				check=2;
			switch(check)
			{
				case 0: //new new
					pass_interface(check);
					input_password();
					break;
				case 2: //old new new
					pass_interface(check);
					update_password();
					break;
			}
			status=1;
		}
		else if(b==13&&a==4)
			status=1;
	}while(status!=1);
	clrscr();
	menu();
	menu1();
	show_menu(1);
}
void exit_program()
{
	char option;
	int a;
	clrscr();
	msg_box();
	textbackground(RED);
	textcolor(WHITE);
	gotoxy(29,12);
	cprintf("Are you sure to exit?");
	textbackground(0);
	gotoxy(19,15);
	blank(42);
	textbackground(GREEN);
	textcolor(WHITE);
	gotoxy(27,15);
	cprintf("    OK    ");
	gotoxy(43,15);
	textbackground(3);
	textcolor(0);
	cprintf("    No    ");
	a=1;
	while(option!=13)
	{
		option=getch();
		if(option==77)
			a++;
		else if(option==75)
			a--;
		if(a>=3)
			a=1;
		else if(a<=0)
			a=2;
		switch(a)
		{
			case 1:
				textbackground(GREEN);
				textcolor(WHITE);
				gotoxy(27,15);
				cprintf("    OK    ");
				gotoxy(43,15);
				textbackground(3);
				textcolor(0);
				cprintf("    No    ");
				break;
			case 2:
				textbackground(3);
				textcolor(0);
				gotoxy(27,15);
				cprintf("    OK    ");
				gotoxy(43,15);
				textbackground(GREEN);
				textcolor(WHITE);
				cprintf("    No    ");
				break;
		}
	}
	if(a==1)
		exit(0);
	else
		restore_color();
		clrscr();
}
void write() //func write over old file
	{
		fp=fopen("record.pcl","wb"); //*pcl (peng chhaileng)
		fwrite(data,sizeof(worker),N,fp);
		fclose(fp);
	}

//main
void main()
{
	_setcursortype(0);
	restore_color();
	clrscr();
	int i=1,j,check,check_pass;
	char ch;
	//cambodia_flag();
	//delay(3000);
	//minion();
	restore_color();
	clrscr();
	read_password();
	check_pass=check_password();
	switch(check_pass)
	{
		case 0:
			break;
		case 1:
			pass_interface(check_pass);
			input_password();

			//clrscr();
			//printf("%s",getpw);
			if(strcmp(pw1,mypw)!=0)
			{
				_setcursortype(0);
				restore_color();
				clrscr();
				msg_box();
				textbackground(RED);
				gotoxy(30,12);	cprintf("Incorrect Password !");
				textbackground(0);
				getch();
				exit(0);
			}
			//input and check
			break;
	}
	//read file
	restore_color();
	clrscr();
	fp=fopen("record.pcl","rb");
	fseek(fp,0L,2);
	N=ftell(fp)/sizeof(worker);
	rewind(fp);
	fread(data,sizeof(worker),N,fp);
	fclose(fp);
	//end read file
	menu();
	menu1();
	show_menu(i);
	do{
		_setcursortype(0);
		ch=getch();
		if(ch==72) // 72 up
			i--;
		else if(ch==80) // 80 down
			i++;
		else if(ch==27)
			exit_program();
		else if(ch=='a'||ch=='A')
			i=1;
		else if(ch=='i'||ch=='I')
			i=2;
		else if(ch=='d'||ch=='D')
			i=3;
		else if(ch=='s'||ch=='S')
			i=4;
		else if(ch=='u'||ch=='U')
			i=5;
		else if(ch==59)
			about_us();
		else if(ch==60)
			backup();
		//else if(ch==61) //F7

		//arrow key
		if(i<=0)
			i=5;
		else if(i>=6)
			i=1;
		clrscr();
		menu();
		menu1();
		switch(i)
		{
			case 1:
					show_menu(i);
					break;
			case 2:
					show_menu(i);
					break;
			case 3:
					show_menu(i);
					break;
			case 4:
					show_menu(i);
					break;
			case 5:
					show_menu(i);
					break;
		}
		if(ch==13)
		{
			switch(i)
			{
				case 1:
					clrscr();
					check=input_ask();
					if(check==1)
					{
						clrscr();
						menu();
						menu1();
						show_menu(i);
						break;
					}
					input();
					break;
				case 2:
					check=check_data();
					if(check==1)
					{
						getch();
						clrscr();
						menu();
						menu1();
						show_menu(i);
						break;
					}
					clrscr();
					output();
					break;
				case 3:
					check=check_data();
					if(check==1)
					{
						getch();
						clrscr();
						menu();
						menu1();
						show_menu(i);
						break;
					}
					clrscr();
					sort();
					write();
					break;
				case 4:
					check=check_data();
					if(check==1)
					{
						getch();
						clrscr();
						menu();
						menu1();
						show_menu(i);
						break;
					}
					clrscr();
					search();
					break;
				case 5:
					check=check_data();
					if(check==1)
					{
						getch();
						clrscr();
						menu();
						menu1();
						show_menu(i);
						break;
					}
					clrscr();
					update();
					write();
					break;
			}
		}
		//end switch
	}while(1);
}
