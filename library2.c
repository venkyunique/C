#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>

#include"ludobox.h"          // header file
#include"clear_main.h"      // header file


void take_book();
void return_book();
void my_details();
void print_reciept(int days);



void menu();

void register_module();

void library_module();

void login_module();

struct address{
	char state[20];
	char city[20];
	char street[20];
	int pincode;
}address;

struct member{
	int id,age;
	char name[20],password[20];
	char books[20];
	int bcount;
	struct address address;
}member;
struct book{
	char name[20];
}book[12];
int main() {
	sleep(2);
	
	menu();		
}
void menu()
{
    strcpy(book[1].name,"HARRY POTTER");
	strcpy(book[2].name,"CHETAN BHAGAT");
	strcpy(book[3].name,"50 SHADES OF GREY");
	strcpy(book[4].name,"INDIAN WOMAN");
	strcpy(book[5].name,"RICH DAD POOR DAD");
	strcpy(book[6].name,"WIMPY KID");
	
	strcpy(book[7].name,"HUMAN PSYCHOLOGY");
	strcpy(book[8].name,"HITLER");
	strcpy(book[9].name,"THE LETTER C");
	strcpy(book[10].name,"RUSKIN BOND");
	strcpy(book[11].name,"SHERLOCK HOLMES");
	strcpy(book[12].name,"HALF GIRLFRIEND");
	
	
    FILE* fdb;
	fdb=fopen("database.txt","w");
	if(!fdb) {
		gotoxy(82,37);
		printf("Error\n");
		getch();
		return;
	} 
	else {
		fwrite(&book,sizeof(struct book),1,fdb);
		fclose(fdb);
		
	}
	
	
	
	
	
	
	
	clear();
	gotoxy(63,6);
	printf("W E L C O M E     T O     K L   L I B R A R Y"); 
	
	gotoxy(63,7);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	
	int option=1;
	boxDS(16,2,58,32);      // initial box for register option ( while navigating )
	
	gotoxy(77,14);
	printf("GROUP MEMBERS:");
	lineS(77,15,14);
	
	gotoxy(77,17);
	printf("K.VENKATESH");
	gotoxy(77,19);
	printf("V.YASWANTH");
	gotoxy(77,21);
	printf("P.CALVIN RAJESH");
	
	
	gotoxy(60,33);
	printf("1 -> REGISTER");
	gotoxy(102,33);
	printf("2 -> LOGIN");
		
	gotoxy(75,36);
	printf("Press ' Esc ' to Escape");
	
	
	int nav=1;
	while(1)
	{
		nav=getch();
		if(nav==13)
		{
			break;
		}
		if(nav==75)
		{
			boxerase(16,2,58,32);
			boxerase(16,2,99,32);
			boxDS(16,2,58,32);
			option=1;
		}
		else if(nav==77)
		{
			boxerase(16,2,58,32);
			boxerase(16,2,99,32);
			boxDS(16,2,99,32);
			option=2;
		}
	}
	
//	printf("%d",option);
	
	switch(option){
		case 1:{
			register_module();
			break;
		}
		case 2:{
			login_module();
			break;
		}
		default:menu();
	}
	
	
	
}
void register_module()
{
	clear();
	gotoxy(61,6);
	printf("E N T E R     Y O U R     D E T A I L S     B E L O W");      
	
	gotoxy(61,7);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	
	gotoxy(40,13);
	printf("P E R S O N A L    I N F O.");
	lineS(39,14,28);
	
	gotoxy(100,13);
	printf("A D D R E S S     D E T A I L  S :");
	lineS(100,14,32);
	gotoxy(35,19);
	printf("USERNAME: ");
	lineS(45,20,20);
	gotoxy(35,23);	
	printf("PASSWORD: ");
	lineS(45,24,20);
	gotoxy(35,27);
	printf("     AGE: ");
	lineS(45,28,20);
	gotoxy(35,31);
	printf("      ID: ");
	lineS(45,32,20);
	gotoxy(96,19);
	printf("   STATE: ");
	lineS(106,24,20);
	gotoxy(96,23);
	printf("    CITY: ");
	lineS(106,28,20);
	gotoxy(96,27);
	
	printf("  STREET: ");
	lineS(106,32,20);
	gotoxy(96,31);
	
	printf(" PINCODE: ");
	lineS(106,20,20);
	gotoxy(45,19);
	
	scanf("%s",&member.name);
	gotoxy(45,23);
	scanf("%s",&member.password);
	gotoxy(45,27);
	scanf("%d",&member.age);
	gotoxy(45,31);
	scanf("%d",&member.id);
	gotoxy(106,19);
	scanf("%s",&member.address.state);
	gotoxy(106,23);
	scanf("%s",&member.address.city);
	gotoxy(106,27);
	scanf("%s",&member.address.street);
	gotoxy(106,31);
	scanf("%d",&member.address.pincode);
	FILE *fp;
	char filename[20];
	strcpy(filename,member.name);
	fp = fopen(strcat(filename,".txt"),"w");
	if(!fp) {
		gotoxy(65,35);
		printf("Error\n");
		getch();
		return;
	} 
	else {
		fwrite(&member,sizeof(struct member),1,fp);
		fclose(fp);
		boxDD(27,2,74,34);
		gotoxy(76,35);
		printf("%c%c Account Registered %c%c",16,175,174,17);
		gotoxy(0,0);
		getch();
		menu();
	}
	
}
char name[20];
void login_module()
{
	char password[20],filename[20];
	clear();
	FILE *fq;
	gotoxy(75,36);
	printf("Press ' Esc ' to Escape");
	
	gotoxy(57,6);
	printf("E N T E R     Y O U R     D E T A I L S     T O     L O G I N");      
	
	gotoxy(57,7);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");          
	
	
	boxDD(44,22,64,11);    // main box of login
	boxSS(15,3,65,17);    //name
	boxSS(26,3,81,17);     // enter name 
	
	gotoxy(81,14);
	printf("L O G I N");
	
	gotoxy(71,18);
	printf("NAME:");
	
	boxSS(15,3,65,23);     //pass
	boxSS(26,3,81,23);     // enter pass
	gotoxy(69,24);
	printf("PASSWORD: ");
	
	gotoxy(83,19);
	scanf("%s",&name);
	gotoxy(83,25);
	scanf("%s",&password);
	
	strcpy(filename,name);
	fq = fopen(strcat(filename,".txt"),"r+");
	if(!fq) {
		gotoxy(78,30);
		printf("WRONG  USERNAME!!");
        int p;
		p=getch();
		if(p==27)
		exit(1);
		else
		login_module();
	} else {
		rewind(fq);
		fread(&member,sizeof(struct member),1,fq);
		if(strcmp(password,member.password)) {
			gotoxy(78,30);
		printf("WRONG  PASSWORD!!");
		int p;
		p=getch();
		if(p==27)
		exit(1);
		else
			login_module();
		} else {
			gotoxy(80,30);
			printf("WELCOME %s",member.name);
			int p;
		p=getch();
		fclose(fq);
		if(p==27)
		exit(1);
		else			
		library_module();
        
		return;
		}
	}
}
void library_module()
{
	clear();
	gotoxy(72,6);
	printf("CHOOSE  THE  BELOW  OPTIONS: ");      
	
	gotoxy(72,7);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(77,17);
	printf("1. TAKE BOOK");
	gotoxy(77,20);
	printf("2. RETURN BOOK");
	gotoxy(77,23);
	printf("3. MY DETAILS");
	gotoxy(77,26);
	printf("4. exit");
	gotoxy(80,30);
	printf("CHOICE->");
	gotoxy(88,30);
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:{
			take_book();
			break;
		}
		case 2:{
			return_book();
			break;
		}
		case 3:{
			my_details();
			break;
		}
		case 4:{
			exit(1);
			break;
		}
		default:library_module();
	}
}
void take_book()
{
	clear();
	gotoxy(76,6);
	printf("B O O K S    L I S T: ");  
	lineS(30,7,112);
	lineD(76,7,21);
	
	boxSS(120,25,26,9);       // main box
	
	gotoxy(32,11);
	printf("%c",4);
	gotoxy(32,15);
	printf("%c",4);
	gotoxy(32,19);
	printf("%c",4);
	gotoxy(32,23);
	printf("%c",4);
	gotoxy(32,27);
	printf("%c",4);
	gotoxy(32,31);
	printf("%c",4);
	
	gotoxy(92,11);
	printf("%c",4);
	gotoxy(92,15);
	printf("%c",4);
	gotoxy(92,19);
	printf("%c",4);
	gotoxy(92,23);
	printf("%c",4);
	gotoxy(92,27);
	printf("%c",4);
	gotoxy(92,31);
	printf("%c",4);	
	
	// PRINTING  BOOK  NAMES:
	
	gotoxy(35,11);
	printf("1. %s",book[1].name);
	gotoxy(35,15);
	printf("2. %s",book[2].name);
	gotoxy(35,19);
	printf("3. %s",book[3].name);
	gotoxy(35,23);
	printf("4. %s",book[4].name);
	gotoxy(35,27);
	printf("5. %s",book[5].name);
	gotoxy(35,31);
	printf("6. %s",book[6].name);
	
	gotoxy(95,11);
	printf("7. %s",book[7].name);      
	gotoxy(95,15);
	printf("8. %s",book[8].name);
	gotoxy(95,19);
	printf("9. %s",book[9].name);
	gotoxy(95,23);
	printf("10. %s",book[10].name);
	gotoxy(95,27);
	printf("11. %s",book[11].name);
	gotoxy(95,31);
	printf("12. %s",book[12].name);
	int p;
	gotoxy(83,35);
	printf("->");
	gotoxy(85,35);
	scanf("%d",&p);
	
	
	switch(p){
		case 1:{
			strcpy(member.books,book[1].name);
			break;
		}
		case 2:{
			strcpy(member.books,book[2].name);
			break;
		}
		case 3:{
			strcpy(member.books,book[3].name);
			break;
		}
		case 4:{
			strcpy(member.books,book[4].name);
			break;
		}
		case 5:{
			strcpy(member.books,book[5].name);
			break;
		}
		case 6:{
			strcpy(member.books,book[6].name);
			break;
		}
		case 7:{
			strcpy(member.books,book[7].name);
			break;
		}
		case 8:{
			strcpy(member.books,book[8].name);
			break;
		}
		case 9:{
			strcpy(member.books,book[9].name);
			break;
		}
		case 10:{
			strcpy(member.books,book[10].name);
			break;
		}
		case 11:{
			strcpy(member.books,book[11].name);
			break;
		}
		case 12:{
			strcpy(member.books,book[12].name);
			break;
		}
	}
	
	gotoxy(78,35);
	printf("B O O K     T A K E N");
	getch();
	library_module();
	
	
	
}
void return_book()
{
	int days;
	float fine;
	clear();
	gotoxy(76,6);
	printf("R E T U R N    B O O K: ");  
	lineS(30,7,112);
	lineD(76,7,22);
	gotoxy(75,10);
	printf("RETURNING:%s",member.books);
	lineD(75,11,9);
	gotoxy(73,15);
	printf("NUMBER OF DAYS OVERDUED:");
	gotoxy(97,15);
	scanf("%d",&days);
	fine=(float)(days*1.5);
	gotoxy(80,20);
	printf("fine:");
	gotoxy(85,20);
	printf("Rs.:%.2f",fine);
	boxDD(15,2,79,19);
	gotoxy(73,25);
	printf("press any key to get reciept");
	getch();
	print_reciept(days);
}
void my_details()
{                                         // add option to edit details
	clear();
	gotoxy(72,6);
	printf("DETAILS MENTIONED IN THE RECORD:");
	lineD(72,7,31);
	
	gotoxy(40,13);
	printf("P E R S O N A L    I N F O.");
	lineS(39,14,28);
	
	gotoxy(100,13);
	printf("A D D R E S S     D E T A I L  S :");
	lineS(100,14,32);
	gotoxy(35,19);
	printf("USERNAME: ");
	gotoxy(35,23);	
	printf("PASSWORD: ");
	gotoxy(35,27);
	printf("     AGE: ");
	gotoxy(35,31);
	printf("      ID: ");
	gotoxy(96,19);
	printf("   STATE: ");
	gotoxy(96,23);
	printf("    CITY: ");
	gotoxy(96,27);
	
	printf("  STREET: ");
	gotoxy(96,31);
	
	printf(" PINCODE: ");
	gotoxy(45,19);
	printf("%s",member.name);
	gotoxy(45,23);
	printf("%s",member.password);
	gotoxy(45,27);
	printf("%d",member.age);
	gotoxy(45,31);
	printf("%d",member.id);
	gotoxy(106,19);
	printf("%s",member.address.state);
	gotoxy(106,23);
	printf("%s",member.address.city);
	gotoxy(106,27);
	printf("%s",member.address.street);
	gotoxy(106,31);
	printf("%d",member.address.pincode);
	gotoxy(77,35);
	printf("PRESS ANY KEY FOR MENU");
	getch();
	library_module();
}
void print_reciept(int days)
{
	clear();
	gotoxy(41,6);
	printf("%c K O N N E R U     L A K S H M A I A H     U N I V E R S I T Y    L I B R A R Y %c",4,4); 
	lineD(43,7,79);
	gotoxy(36,15);
	printf("N A M E : %s",member.name);
	lineS(36,16,7);
	gotoxy(36,20);
	printf("STUDENT ID: %d",member.id);
	lineS(36,21,10);
	gotoxy(36,25);
	printf("BOOK RETURNING: %s",member.books);
	lineS(36,26,14);
	gotoxy(116,15);
	printf("B I L L");
	lineD(116,16,7);
	gotoxy(106,18);
	printf("No. days overdued: %d",days);
	gotoxy(106,21);
	printf("fine for extra days: 1.5/-");
	gotoxy(106,23);
	printf("------------------------");
	gotoxy(106,25);
	printf("F I N E :\t%.2f/-",days*1.5);
	boxDS(38,13,99,14);
	gotoxy(31,34);
	printf("librarian");
	gotoxy(141,34);
	printf("principal");
	
	gotoxy(66,36);
	printf("press any key to continue...");
	getch();
	library_module();
}















