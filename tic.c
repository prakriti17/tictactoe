#include<conio.h>
#include<stdio.h>

static char map[5][5];
void px();
void po();
int check();
void display();

int move=1;
int p;

void display()
{
int i,j;
system("cls");
printf("-------------------------\n");
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
printf("| %c |",map[i][j]);
}
printf("\n-------------------------\n");
}

}


void po()
{
 printf("\nPlayer o Enter the Position For Your Move  ");
 scanf("%d",&p);
 p=p-1;
 
 if(map[p/5][p%5]=='o' || map[p/5][p%5]=='x')
  {
   printf("\nPosition is already occupied\nEnter the Position Again\n");
   po();
  }
  
 else
   map[p/5][p%5]='o';
 
 display();
}


void px()
{
 printf("\nPlayer x Enter the Position For Your Move  ");
 scanf("%d",&p);
 p=p-1;
 if(map[p/5][p%5]=='o' || map[p/5][p%5]=='x')
  {
   printf("\nPosition is already occupied\nEnter the Position Again\n");
   px();
  }
  
 else
   map[p/5][p%5]='x';

 display();
}

int check()
{
int i;
for(i=0;i<5;i++)
{
if((map[i][0]=='o' && map[i][1]=='o' && map[i][2]=='o')||(map[i][1]=='o' && map[i][2]=='o' && map[i][3]=='o')||(map[i][2]=='o' && map[i][3]=='o' && map[i][4]=='o'))
{
printf("\nPlayer o Wins");
return 2;
}
if((map[0][i]=='o' && map[1][i]=='o' && map[2][i]=='o')||(map[1][i]=='o' && map[2][i]=='o' && map[3][i]=='o')||(map[2][i]=='o' && map[3][i]=='o' && map[4][i]=='o'))
{
printf("\nPlayer o Wins");
return 2;
}
if((map[0][0]=='o' && map[1][1]=='o' && map[2][2]=='o') ||
   (map[0][4]=='o' && map[1][3]=='o' && map[2][2]=='o') ||
   (map[1][3]=='o' && map[2][2]=='o' && map[3][1]=='o') ||
   (map[2][2]=='o' && map[3][1]=='o' && map[4][0]=='o') ||
   (map[0][2]=='o' && map[1][1]=='o' && map[2][0]=='o') ||
   (map[1][1]=='o' && map[2][2]=='o' && map[3][3]=='o') ||
   (map[2][2]=='o' && map[3][3]=='o' && map[4][4]=='o'))
{
printf("\nPlayer o Wins");
return 2;
}
if((map[i][0]=='x' && map[i][1]=='x' && map[i][2]=='x')||(map[i][1]=='x' && map[i][2]=='x' && map[i][3]=='x')||(map[i][2]=='x' && map[i][3]=='x' && map[i][4]=='x'))
{
printf("\nPlayer x Wins");
return 1;
}
if((map[0][i]=='x' && map[1][i]=='x' && map[2][i]=='x')||(map[1][i]=='x' && map[2][i]=='x' && map[3][i]=='x')||(map[2][i]=='x' && map[3][i]=='x' && map[4][i]=='x'))
{
printf("\nPlayer x Wins");
return 1;
}
if((map[0][0]=='x' && map[1][1]=='x' && map[2][2]=='x') ||
   (map[0][4]=='x' && map[1][3]=='x' && map[2][2]=='x') ||
   (map[1][3]=='x' && map[2][2]=='x' && map[3][1]=='x') ||
   (map[2][2]=='x' && map[3][1]=='x' && map[4][0]=='x') ||
   (map[0][2]=='x' && map[1][1]=='x' && map[2][0]=='x') ||
   (map[1][1]=='x' && map[2][2]=='x' && map[3][3]=='x') ||
   (map[2][2]=='x' && map[3][3]=='x' && map[4][4]=='x'))
{
printf("\nPlayer x Wins");
return 1;
}

}
} 
 
 
int main()
{
 int i;
 for(i=1;i<=4;i++)
 {
   if(i%2==1)
    px();
   if(i%2==0)
   po();
   move++;
 }
 
 while(move<=25)
 {
  if(check()!=1 && check()!=2)
  {
   if(move%2==1)
    px();
   if(move%2==0)
    po();
  }
  else
  {
   printf("\t\t%c\tThank You For Playing\t%c",1,1);
   break;
  }
   
   move++;
  }
  if(move>25)
  printf("\t\t %c\tIt's a Tie\t%c",1,1);
  getch();
  return 0;
}
