#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
typedef struct name
{
    char name[20];
    int score;
}nm;
void welcome();
void delay(int);
void game(char *, nm *);
void play(char *, char, int, nm *);
int check(char *, nm *);
void homescreen(char *, nm *);
void howtoplay();
void board(char *, nm *);
void pname(nm *);
void feedback(nm *);
void displayScore(nm *);
void history();

int main()
{
    welcome();
    system("cls");
    char a[9]="123456789";
    nm player[3];
    printf("\tTIC TAC TOE\n");
    printf("\nHello Players! Please enter your names!\n\n");
    pname(player);
    printf("\nYayy! Readyy? Let's go...");
    delay(2000);
    homescreen(a,player);

}
void welcome()
{
    for(int i=0;i<25;i++)
    {
        delay(60);
        printf("*");
    }
    printf("\n        ");

    char game[12]="TIC TAC TOE";
    for(int i=0;i<12;i++)
    {
        delay(90);
        printf("%c",game[i]);
    }
    printf("\n");

    for(int i=0;i<25;i++)
    {
        delay(60);
        printf("*");
    }
    printf("\n\n\n        ");

    char wel[]="WELCOME!!!";
    for(int i=0;i<11;i++)
    {
        delay(90);
        printf("%c",wel[i]);
    }
    delay(100);
    printf("\n            :)\n\n\n");

    for(int i=0;i<25;i++)
    {
        delay(60);
        printf("*");
    }
    printf("\n");
    delay(1000);
    char back[]="LOADING GAME...";
    for(int i=0;back[i]!='\0'; i++)
    {
        delay(200);
        printf("%c",back[i]);
    }
}
void pname(nm *player)
{
    for(int i=0;i<2;i++)
    {
        printf("Name of Player %d: ",i+1);
        scanf("%s",(player+i)->name);
        player[i].score=0;
    }
    strcpy(player[2].name,"Draw");
    player[2].score=0;
}
void board(char *a, nm *player)
{
    system("cls");
    printf("\tTIC TAC TOE\n");
    printf("%s ('X') - %s ('O')\n",player[0].name,player[1].name);
    printf("\n");
    printf(" %c | %c | %c\n",a[0],a[1],a[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",a[3],a[4],a[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",a[6],a[7],a[8]);
}
void homescreen(char *a, nm *player)
{
    int choice;
    for(;;)
    {
        system("cls");
        printf("\t\tTIC-TAC-TOE\n\n");
        printf("1.Play\n2.How to play?\n3.Score History\n4.Exit\n\nYour Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: strcpy(a,"123456789");
                    game(a, player);
                    break;
            case 2: howtoplay();
                    break;
            case 3: history(); break;
            case 4: feedback(player);
                    exit(0);
            default: printf("Enter valid choice.\n");
                     delay(2000);
                     break;
        }
    }
}
void delay(int ms) //ms=millisecond
{
    clock_t timeDelay = ms+ clock();
    while(timeDelay>clock());
}
void howtoplay()
{
    char ch;
    system("cls");
    printf("\t\tHOW TO PLAY?\n\n");
    printf("1. The board is of size 3 cross 3\n");
    printf("2. The boxes are numbered from 1 to 9.\n");
    printf("3. Player 1: X\t Player 2: O\n");
    printf("4. Player will get a chance alternatively.\n");
    printf("5. Enter a valid choice from 1-9.\n");
    printf("6. Do not enter a number if that is replaced by 'X' or 'O'.\n");
    printf("7. The first player to get 3 of his/her marks in a row (up, down, across, or diagonally) is the winner.\n\n");
    printf("Enter any key to go back to homepage: ");
    getch();
    char back[]="GOING BACK TO HOME PAGE...";
    printf("\n\n");
    for(int i=0;back[i]!='\0'; i++)
    {
        delay(100);
        printf("%c",back[i]);
    }
}
void play(char *a, char xo, int playerturn, nm *player)
{
    int choice;
    printf("\n\n%s\nEnter a number from 1-9: ",(player[playerturn-1]).name);
    scanf("%d",&choice);
    if(*(a+(choice-1))!='X' && *(a+(choice-1))!='O' && choice>=1 && choice<=9)
        *(a+(choice-1))=xo;
    else
    {
        printf("\nInvalid Position");
        play(a,xo,playerturn,player);
    }
}
void game(char *a, nm *player)
{
    char xo; int playerturn; int checker;
    for(int i=1;i<=9;i++)
    {
        board(a, player);
        if(i%2!=0)
        {
            xo='X';
            playerturn=1;
            play(a,xo,playerturn,player);
        }
        else
        {
            xo='O';
            playerturn=2;
            play(a,xo,playerturn, player);
        }
        checker=check(a,player);
        if(checker==1)
        {
            printf("\n");
            char back[]="GOING BACK TO HOME PAGE...";
            for(int i=0;back[i]!='\0'; i++)
            {
                delay(150);
                printf("%c",back[i]);
            }
            homescreen(a,player);
        }
        else continue;
    }
}
int check(char *a, nm *player)
{
    if((a[0]=='X' && a[1]=='X' && a[2]=='X') || (a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[6]=='X' && a[7]=='X' && a[8]=='X') ||
       (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[2]=='X' && a[5]=='X' && a[8]=='X') ||
       (a[0]=='X' && a[4]=='X' && a[8]=='X') || (a[2]=='X' && a[4]=='X' && a[6]=='X'))
        {
            board(a,player);
            player[0].score++;
            printf("\n\nHurraaaayy!!! %s wins!!!\n\n",player[0].name);
            displayScore(player);
            return 1;
        }
    else if((a[0]=='O' && a[1]=='O' && a[2]=='O') || (a[3]=='O' && a[4]=='O' && a[5]=='O') || (a[6]=='O' && a[7]=='O' && a[8]=='O') ||
            (a[0]=='O' && a[3]=='O' && a[6]=='O') || (a[1]=='O' && a[4]=='O' && a[7]=='O') || (a[2]=='O' && a[5]=='O' && a[8]=='O') ||
            (a[0]=='O' && a[4]=='O' && a[8]=='O') || (a[2]=='O' && a[4]=='O' && a[6]=='O'))
            {
                board(a,player);
                player[1].score++;
                printf("\n\nHurraaaayy!!! %s wins!!!\n\n",player[1].name);
                displayScore(player);
                return 1;
            }
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7] !='8' && a[8]!='9')
    {
        board(a,player);
        player[2].score++;
        printf("\nOops! DRAW MATCH !\n");
        displayScore(player);
        return 1;
    }
    else
        return 0;
}
void feedback(nm *player)
{
    int fb, choice;
    time_t t;
    displayScore(player);
    FILE *fp=fopen("scores.txt","a+");
    time(&t);
    fprintf(fp,"%s V/S %s\n",player[0].name,player[1].name);
    fprintf(fp,"%s\n",ctime(&t));
    fprintf(fp,"       SCORE        \n\n");
    fprintf(fp,"%s  %d\n%s  %d\n%s  %d\n",player[0].name,player[0].score,player[1].name,player[1].score,player[2].name,player[2].score);
    fprintf(fp,"\n********************************\n");
    fclose(fp);
    delay(3000);
    system("cls");
    printf("  __________________________\n");
    printf(" |        www.ads.com       |\n");
    printf(" |                          |\n");
    printf(" |     Would you like to    |\n");
    printf(" |       give FEEDBACK?     |\n");
    printf(" |                          |\n");
    printf(" |      1.Yes      2.No     |\n");
    printf(" |__________________________|\n");
    do
    {
        printf("\nEnter valid choice: ");
        scanf("%d",&fb);
    }while(fb!=1 && fb!=2);

    delay(300);
    if(fb==1)
    {
        do
        {
            system("cls");
            printf("\nRate us STARS so that we can improve!\n");
            printf("1 star - Very Poor\n");
            printf("2 star - Poor\n");
            printf("3 star - Good\n");
            printf("4 star - Very Good\n");
            printf("5 star - Excellent\n");
            printf("\nEnter a number from 1-5: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("\nOh! We're extremely sorry for giving you a very poor experience. We'll definitely work and improvise our game.");break;
                case 2: printf("\nOops! Sorry that we could not match your expectations. Will surely improve."); break;
                case 3: printf("\nGood to hear that you liked our game! Keep Playing!"); break;
                case 4: printf("\nThat's nice to hear! Thank you! Keep Playing!"); break;
                case 5: printf("\nHurayyy! We're glad that you loved our game! Keep Playing!"); break;
                default: printf("Enter a valid number!"); delay(800);
            }
        }while(choice<1 || choice>5);
    }
    else
    {
        printf("\nKeep Playing!");
    }
    printf("\nHave a nice day %s and %s :)\n",player[0].name,player[1].name);
}
void history()
{
    system("cls");
    printf("***********************************\n");
    printf("*******    GAME HISTORY    ********\n");
    printf("***********************************\n\n");
    FILE *fp=fopen("scores.txt","r");
    char s[50];

    while (!feof(fp))
    {
        fgets(s,50,fp);
        printf("%s", s);
    }
    fclose(fp);
    printf("Enter any key to go back to homepage: ");
    getch();
    char back[]="GOING BACK TO HOME PAGE...";
    printf("\n\n");
    for(int i=0;back[i]!='\0'; i++)
    {
        delay(100);
        printf("%c",back[i]);
    }
}
void displayScore(nm *player)
{
    printf("*********************\n");
    printf("\tSCORE        \n\n");
    printf("%s  %d\n%s  %d\n%s  %d\n",player[0].name,player[0].score,player[1].name,player[1].score,player[2].name,player[2].score);
    printf("*********************\n");
}
