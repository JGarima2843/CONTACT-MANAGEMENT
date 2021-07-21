#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include<dos.h>
HANDLE screen ;
void main()
{
   int c;
   c=220;
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
     system("cls");
     system("COLOR E3") ;
      screen= GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(screen,12);
      printf("******************************************* CONTACT MANAGEMENT ***********************************************");
      printf("\n\n\n");
      printf("                   ||||||||||***************     FRONTEND :   VISUAL STUDIO CODE     *************|||||||||||");
      printf("\n\n\n");
      printf("                   ||||||||||***************     BACKEND : FILE HANDLING             ************||||||||||||");
      printf("\n\n\n");
      printf("                   ||||||||||***************     DEVELOPED BY : GARIMA JAIN          ************||||||||||||");
      printf("\n\n\n");
      printf("    PLEASE WAIT  ");
      for(i=0;i<40;i++)
      {
         printf(" %c",c);
         Sleep(30);
      }
      system("cls");
      system("COLOR 87");
      printf("\n\n\n                        MAIN MENU                              ");
      printf("\n          ____________________________________________________________");
      // SetConsoleTextAttribute(screen,15);
       printf("\n\n\n");
       printf("           1.  ADD A NEW CONTACT       \n\n");
       printf("           2.  EDITING            \n\n");
       printf("           3.  DELETE A CONTACT    \n\n");
       printf("           4.  LIST OF ALL CONTACT  \n\n");
       printf("           5.  CHANGE A PASSWORD  \n\n");
       printf("           6.  EXIT                \n\n");
       printf("\n\n       _______________________________________________________________");
       printf(" \n\n\n");
       for(i=0;i<10;i++)
       {
             printf("      ENTER  YOUR  CHOICE..................  ");
                Sleep(500);
                system("cls");
                Sleep(500);
       }



  }


}




