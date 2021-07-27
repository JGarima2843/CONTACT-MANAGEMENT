#include<strings.h>
void search_serial()
{
    int found=0 ;
    int n ; 
    printf("\n ENTER SERIAL NUMBER :\n");
    scanf("%d",&n);
    FILE *fp ;
    fp= fopen("info.dat","rb");

    while(fread(&person,sizeof(person),1,fp)!=NULL)
    {
        if(person.sno==n)
        {
            found=1 ;
            printf("\n----------------------------------------------------------------------------------------------\n");
            printf("\n CATEGORY         :  %s\n",person.category);
            printf("\n NAME             :  %s\n",person.name);
            printf("\n GENDER           :  %s\n",person.gender);
            printf("\n PHONE NUMBER     :  %s\n",person.ph_no);
            printf("\n ADDRESS          :  %s\n",person.address);
        }
            

    }
    if(found==0)
    {
        printf("\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>> CONTACT NOT FOUND <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
           printf("\n\n PRESS ANY KEY ");
           getch();
           fclose(fp);
    }
       fclose(fp);
}


void search_name()
{
    char id[20];
    int found ;
     printf("\n\n ENTER NAME YOU WANT TO SEARCH ::");
     gets(id);
     FILE *fp ;
     fp=fopen("info.dat","rb");
     while(fread(&person,sizeof(person),1,fp)!=NULL)
     {
         if(strcmpi(id,person.name)==0)
         {
             found=1 ;
             printf("\n\n---------------------------------------------------------------------------------------------------\n");
             printf("\n SERIAL NUMBER      : %d\n ",person.sno);
             printf("\n CATEGORY           : %d\n",person.category);
             printf("\n GENDER             : %c\n",person.gender);
             printf("\n ADDRESS            : %s\n ",person.address);
         }
     }

     if(found=0)
     {
         printf("\n\n------------------------------------------------------------------------------------------------");
           printf("\n CONTACT NOT FOUND \n");
            printf("\n\n\n");
            fclose(fp);
            printf(">>>>>>>>>>>>>>>>>>>>> PRESS ANY KEY >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
            getch();        
     }
            fclose(fp);

}

void search_address()
{
    char add[30];
    int found =0 ;
    FILE *fp ;
    printf("\n\n -------------------------------------------------------------------------------------------------------");
    printf(" ENTER ADDRESS :::\n");
    gets(add);
    fp=fopen("info.dat","rb");

    while(fread(&person,sizeof(person),1,fp)!=NULL)
    {
        if(strcmpi(add,person.address)==0) 
        {
            found=1 ;
            printf("\n SERIAL NUMBER : %d\n",person.sno);
            printf("\n CATEGORY      : %s\n",person.category);
            printf("\n GENDER        : %s\n",person.gender);
            printf("\n PHONE NUMBER  : %s\n",person.ph_no);
            
        }
        
    }

    if(found=0)
    {
        printf("\n\n------------------------------------------------------------------------------------------------------");
        printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   CONTACT NOT FOUND  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
        printf("\n\n PRESS ANY KEY ::  \n");
        getch();
        fclose(fp);
    }

    fclose(fp);
}

void search_phone()
{
    char ph[11];
    int found ;
    FILE *fp ;
    printf("\n\n------------------------------------------------------------------------------------------------------------");
    printf("\n\n SEARCHED   PHONE NUMBER ::  \n");
    gets(ph);
    fp=fopen("info.dat","rb");

    while(fread(&person,sizeof(person),1,fp)!=NULL)
    {
        if(strcmpi(ph,person.ph_no)==0)
        {
            found=1 ;
            printf("\n\n---------------------------------------------------------------------------------------------------\n");
            printf(" SERIAL NUMBER  :  %d\n",person.sno);
            printf(" CATEGORY       :  %s\n",person.category);
            printf(" NAME           :  %s\n",person.name);
            printf(" GENDER         :  %c\n",person.gender);
            printf(" ADDRESS        :  %s\n",person.address);

        }
    }
    if(found==0)
    {
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        fclose(fp);
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> CONTACT NOT FOUND <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n ");
        printf("\n\n   PRESS  ANY   KEY  ::\n");
        getch();        
    }
    fclose(fp);
}