#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//ANGGOTA KELOMPOK :
//1. Luqman Nurhoiriza_2702374592
//2. Ryan Hanif Dwihandoyo - 2702358134
//3. Muhammad Robby Kusumah - 2702380891



int length;
int bend_no;
int len;
int n;
int i;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate
{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int main()
{
	while (1){
	system("cls");
	int aq=0;

	printf("Berikut game yang kami miliki : \n1.Snake game(main game)\n2.Sorting game(mini game)\n3.Searching your number(mini game)\n4.exit\n\n");
	printf("Note : khusus main game tidak ngulang, namun ke save\n");
	printf("Masukkan game apa yang diinginkan: ");
	scanf("%d",&aq);
	
	
	if (aq == 1){
    	Print();

    	system("cls");
    	system("color 5f");

    	load();

    	length=5;

    	head.x=25;

    	head.y=20;

   	 	head.direction=RIGHT;

    	Boarder();

    	Food(); 

    	life=3; 

    	bend[0]=head;

    	Move();  
    }
    	
    	else if (aq == 2){
		int az[10],aw,ae,ap,temp=0;
		printf("Masukkan ukuran banyaknya angka yang ada: ");
		scanf("%d",&aw);
		printf("Masukkan angka berapa saja dengan maks ukuran dari yang dimasukkan tadi: \n");
	
		for(ae=0;ae<aw;ae++){
			scanf("%d",&az[ae]);
		}
	
	
		for(ae=0;ae<aw;ae++){
			for(ap=ae+1;ap<aw;ap++){
				if(az[ae]>az[ap]){
					temp=az[ae];
					az[ae]=az[ap];
					az[ap]=temp;
				}
			}
		}
		printf("Urutan angka yang benar: ");
	
		for(ae=0;ae<aw;ae++){
			printf("%d ",az[ae]);
		}
		getch();
	}
		
		else if (aq == 3){
		 int data[100], cari, bs, by, ketemu;
     	 printf("Masukkan banyaknya jumlah data: ");
 		 scanf(" %d", &by);
      	printf("Masukkan data array sebanyak %d: \n", by);
  		for (bs = 0; bs < by; bs++) {
    		scanf(" %d", &data[bs]);
		  }
      	printf("Masukkan data yang ingin dicari: ");
 		 scanf(" %d", &cari);
     	ketemu = 0;
     
     	for (bs = 0; bs < by; bs++) {

    		 if (data[bs] == cari) {
     
     			ketemu = 1;
				printf("Data %d ditemukan pada indeks ke-%d\n", cari, bs);
    		 
    		}
 		 }
	
      if (ketemu == 0) {
      printf("Data %d tidak ditemukan\n", cari);
  }
  	getch();
  }
  	else if (aq == 4){
  		exit (0);
	  }
}
  	}


  




void Move(){
    int a,i;

    do{
        Food();
        fflush(stdin);

        len=0;

        for(i=0; i<30; i++){

            body[i].x=0;

            body[i].y=0;

            if(i==length)

                break;
			 }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)
            Right();

        else if(head.direction==LEFT)
            Left();

        else if(head.direction==DOWN)
            Down();

        else if(head.direction==UP)
            Up();

        ExitGame();
    }
    
    while(!kbhit());

    a=getch();

    if(a==27){

        system("cls");

        exit(0);
    }
    
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();
    }

    else if(key==27)
    {

        system("cls");

        exit(0);
    }

    else
    {

        printf("\a");

        Move();
    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("Loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); 
        printf("%c",177);
    }
    getch();
}

void Down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}

void Delay(long double k)
{
    Score();
    long double i;
    for(i=0; i<=(10000000); i++);
}

void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++){
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;   
        }
        if(i==length||check!=0)
            break;
    }
    
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0){
        life--;
        if(life>=0){
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else{
            system("cls");
            printf("Semua Kehidupan Selesai\nSemoga Lebih Beruntung Lain Kali!!!\nTekan Tombol Apa Saja Untuk Keluar Dari Permainan\n");
            record();
            exit(0);
        }
    }
}

void Food(){
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++)
    {
        
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {
                   
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++)
                {
                
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++)
                {
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   
    printf("F");
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("!");
        GotoXY(i,30);
        printf("!");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
}
void Print()
{
    
    printf("\tSelamat Datang Di Game Si Ular Cepat.\n\n (Tekan Tombol Apa Saja Untuk Melanjutkan...)\n");
    getch();
    system("cls");
    printf("\tPetunjuk Permainan:\n");
    printf("\n-> Gunakan Tombol Panah Untuk Menggerakkan Ular.\n\n-> Anda Akan Disediakan Makanan (F) di Koordinat Acak Layar Yang Harus Anda Makan, Untuk Membuat Skor.\n");
	printf("Setiap Kali Anda Memakan Makanan, Panjang Ular Akan Bertambah 1 Elemen yang menunjukkan skor.");
	printf("\n\n-> Di sini Anda Diberikan Tiga Nyawa. Nyawa Anda Akan Berkurang Saat Anda Menabrak Dinding Atau Tubuh Ular.");
	printf("\n\n-> Anda Dapat Menjeda Game Saat Bermain Dengan Menekan Tombol Apa Saja, Untuk Melanjutkan Game yang Dijeda Tekan Tombol Apa Saja Sekali Lagi.");
	printf("\n\n-> Jika Anda Ingin Keluar dari Game ESC.\n");
    printf("\n\n\nTekan Tombol Apa Saja Untuk Memainkan Game...");
    if(getch()==27)
        exit(0);
}
void record()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    system("cls");
    printf("Masukkan Nama Anda: ");
    scanf("%[^\n]",plname);
    
    for(j=0; plname[j]!='\0'; j++)
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
   
    fprintf(info,"\n\nNama Player: %s\n",nplname);
    

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"\nTanggal Dimainkan:%s",ctime(&mytime));
    
    fprintf(info,"Score: %d\n",px=Scoreonly());
   
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Tekan 'y' jika Anda ingin melihat catatan masa lalu (y/n): ");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}
int Score()
{
    int score;
    GotoXY(20,8);
    score=length-5;
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(50,8);
    printf("Life : %d",life);
    return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
void Up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++)
    {
        GotoXY(head.x,head.y+i);
        {
            if(len==0)
                printf("^");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}
