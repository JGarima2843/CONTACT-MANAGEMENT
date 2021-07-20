#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void main()
{
   char pass[10],origin[10],ch,*passd ;
   passd=origin ;
   int i ;
   FILE*fp ;
   system("COLOR 4F");
   for(i=0;i<5;i++)
   {

      printf("........welcome.........\n");
      Sleep(500);
      system("cls");
      Sleep(500);
   }  
   system("cls");
   system("COLOR 70");
   
   
      printf("\n\n-----------------------------------------------ENTER PASSWORD------------------------------------------------");
      


   
   i=0;
   while(1)
   {
      
      ch=getch();
      if(ch=='\r')
      {
         pass[i]='\0';
          break ;
      }
      pass[i++]= ch ;
      printf("*");
   }
  printf("\n\n ****************************************YOU ENTERED %s*************************************\n",pass);
  fp=fopen("password.dat","r");
  fgets(origin,10,fp);
  //printf(" origin is :%s",origin);
  fclose(fp);
  if(strcmp(origin,pass)!=0)
  {
     for(i=0;i<5;i++)
     {
        system("COLOR 50");
        printf("\n---------------------------------YOUR ENTERED PASSWORD IS INCORRECT--------------------------------------");
        Sleep(500);
        system("cls");
        Sleep(500);
     }

  }
  else
  {
     system("COLOR B0");
     printf("\n\n\n    ********************************************************* CORRECT *************************************************");
     
  }
}




