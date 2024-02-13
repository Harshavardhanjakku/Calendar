/* C program for Calender Project
        NAME: HARSHAVARDHAN
        CLASS:B.TECH III Semester
        HALLTICKET NO: 2203A51012
        College:SR UNIVERSITY
        DATE:27/09/2023.  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct cal
{
    int d,m,y;
    char event[100];
    struct cal *next;
};
void mon();
int disp();
int monthcode(int m);
int centurycode(int c);
int leapyearcode(int l);
int daycode(int d);
int ndinmon(int m,int y);
void adj();
void jmp();
int addevent();
int searchevent(int ,int ,int);
void dispall();
void sort();
void swapd();
void swape();
void del();
void delall();
struct cal *start=NULL,*temp,*ptr,*ne;
static int date,month,year;
int i,j,k,r,flag=0,opt,c;
char ch[3],y[]="yes",n[]="no",op,t[100];
FILE *fptr;
int main()
{
    static int z=1;
    if(z==1)
    {
        printf("\n---------------------------------------------");
        printf("\nWELCOME TO THE CALENDAR PROGRAM");
        printf("\n---------------------------------------------");
        fptr=fopen("demo.txt","w");
        fputs("       EVENTS \n",fptr);
        fclose(fptr);
    }
    printf("\n\n\nPlease go through the choice given below:\n");
    printf("\n1.Display Month Calendar");
    printf("\n2.Adjacent Calendar");
    printf("\n3.Jump to date ");
    printf("\n4.Display Year Calendar");
    printf("\n5.Add Event");
    printf("\n6.Search Event");
    printf("\n7.Display All Events");
    printf("\n8.Sort By Dates");
    printf("\n9.Exit ");
    printf("\n\nEnter the Option:");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        mon();
        printf("\n\nEnter the month:");
        scanf("%d",&month);
        printf("Enter the year:");
        scanf("%d",&year);
        disp();
        break;
    case 2:
        adj();
        break;
    case 3:
        jmp();
        break;
    case 4:
        printf("\nEnter the year:");
        scanf("%d",&year);
        for(month=1; month<=12; month++)
        {
            disp();
        }
        break;
    case 5:
        addevent();
        break;
    case 6:
        printf("\nEnter the Date:");
        scanf("%d",&date);
        printf("\nEnter the Month:");
        scanf("%d",&month);
        printf("\nEnter the Year:");
        scanf("%d",&year);
        flag=searchevent(date,month,year);
        if(flag==0||temp==NULL)
        {
            printf("\nNo Event is there on %d / %d / %d",date, month,year);
        }
        else
        {
            printf("\n\n%d /  %d  /  %d ",temp->d,temp->m,temp->y);
            printf("\n%s",temp->event);
        }
        break;
    case 7:
        dispall();
        break;
    case 8:
        sort();
        break;
    case 9:
        printf("\nExiting program.....\nThank you");
        exit(0);
        break;
    default:
        printf("Invalid Choice");
    }
    z++;
    main();
    return 0;
}
void mon()
{
    printf("\n_____________________________________________");
    printf("\n\nPlease go through the choice given below:\n");
    printf("\n1.JANUARY");
    printf("\n2.FEBRUARY");
    printf("\n3.MARCH");
    printf("\n4.APRIL");
    printf("\n5.MAY");
    printf("\n6.JUNE");
    printf("\n7.JULY");
    printf("\n8.AUGUST");
    printf("\n9.SEPTEMBER");
    printf("\n10.OCTOBER");
    printf("\n11.NOVEMBER");
    printf("\n12.DECEMBER");
}
int disp()
{
    int sp,p,gap,date=1,mc,cc,lyc,yc,cent,dc,tot;
    char week[7][7]= {"Sat   ","Sun   ","Mon   ","Tue   ","Wed   ","Thr   ","Fri   "};
    printf("\n\n\n________________________________________");
    printf("\n\n~~The calendar of ");

    switch(month)
    {
    case 1:
        printf("JANUARY");
        break;
    case 2:
        printf("FEBRUARY");
        break;
    case 3:
        printf("MARCH");
        break;
    case 4:
        printf("APRIL");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUNE");
        break;
    case 7:
        printf("JULY");
        break;
    case 8:
        printf("AUGUST");
        break;
    case 9:
        printf("SEPTEMBER");
        break;
    case 10:
        printf("OCTOBER");
        break;
    case 11:
        printf("NOVEMBER");
        break;
    case 12:
        printf("DECEMBER");
        break;
    }
    printf(" %d~~",year);
    printf("\n________________________________________\n\n\n");
    k=ndinmon(month,year);
    for(i=0; i<=6; i++)
    {

        for(j=0; j<=6; j++)
        {
            if(i==0)
            {
                printf("%s",week[j]);
            }
            else  if(i==1)
            {
                yc=year%100;
                cent=year/100;
                mc=monthcode(month);
                cc=centurycode(cent);
                lyc=leapyearcode(yc);
                if(date==1)
                {
                    tot=1+mc+cc+yc+lyc;
                    dc=daycode(tot);
                    sp=dc;
                    if((year%4==0&&month==2)||(month==1&&year%4==0))
                        p=sp-1;
                    else
                        p=sp;
                    for(gap=0; gap<p; gap++)
                        printf("      ");
                    for(j=p; j<=6; j++)
                    {
                        if(date<10)
                            printf("%d     ",date++);
                        else
                            printf(" %d    ",date++);
                    }
                }
                else
                {

                    if(date<10)
                        printf("%d     ",date++);
                    else
                        printf("%d    ",date++);
                    if(date==k+1)
                        goto nxt;
                }
            }
            else
            {
                if(date<10)
                    printf("%d     ",date++);
                else
                    printf("%d    ",date++);
                if(date==k+1)
                    goto nxt;
            }
        }
        printf("\n");
    }
nxt:
    printf("\n\n-----------------------------------------");
}
void adj()
{
    printf("\nInput > for forward and < for Backward");
    printf("\nEnter the choice:");
    scanf("%s",&op);
    if(op=='>')
    {
        if(month<=11)
            month+=1;
        else if(month==12)
        {
            month=1;
            year+=1;

        }
        disp();
    }
    else if(op=='<')
    {
        if(month>1)
            month-=1;
        else if(month==1)
        {
            month=12;
            year-=1;
        }
        disp();
    }
    else
    {
        printf("\nInvalid Character");
    }
}
void jmp()
{
    mon();
    printf("\n\nEnter the month:");
    scanf("%d",&month);
    printf("Enter the year:");
    scanf("%d",&year);
    disp();
}
int addevent()
{
    ne=(struct cal*)malloc(sizeof(struct cal));
    printf("\nEnter the Date:");
    scanf("%d",&ne->d);
    printf("\nEnter the Month:");
    scanf("%d",&ne->m);
    printf("\nEnter the Year:");
    scanf("%d",&ne->y);
    printf("\nEnter the Text:");
    scanf(" %[^\n]s", ne->event);
    flag=searchevent(ne->d,ne->m,ne->y);
    if(flag==1)
    {
        printf("\nEvent already exists.Do you want to overwrite");
        printf("\nEnter YES or NO:");
        scanf("%s",ch);
        r=strcasecmp(ch,y);
        if(r==0)
        {
            strcpy(temp->event,ne->event);
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ne;
            ne->next=NULL;
            printf("\nEvent Successfully added");
        }
    }
    else
    {
        if(start==NULL)
        {
            ne->next=NULL;
            start=ne;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ne;
            ne->next=NULL;
        }
        printf("\nEvent Successfully added");
    }
    fptr=fopen("demo.txt","a");
    if(fptr!=NULL)
    {
        fprintf(fptr,"\n\n%d /  %d  /  %d \n%s\n",ne->d,ne->m,ne->y,ne->event);
        
    }
    else
    {
        printf("Can't open the file");
    }
    fclose(fptr);
}
int searchevent(int date,int month,int year)
{
    flag=0;
    if(start==NULL)
    {
        return flag;
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            if(temp->d==date&&temp->m==month&&temp->y==year)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        return flag;
    }
}
void dispall()
{
    if(start==NULL)
        printf("\nNo Events");
    else
    {
        printf("\n\n\nDisplaying Events...");
        temp=start;
        while(temp!=NULL)
        {
            printf("\n\n%d /  %d  /  %d ",temp->d,temp->m,temp->y);
            printf("\n%s",temp->event);
            temp=temp->next;
        }
    }
}
void sort()
{
    if(start==NULL||start->next==NULL)
    {
       printf("\nNo events to sort");
    }
    else
    {
    for(temp=start; temp->next!=NULL; temp=temp->next)
    {
        for(ptr=temp->next; ptr!=NULL; ptr=ptr->next)
        {
            if(temp->y>ptr->y)
            {
                swapd();
                swape();
            }
            else if (temp->y==ptr->y)
            {
                if(temp->m>ptr->m)
                {
                    swapd();
                    swape();
                }
                else if(temp->m==ptr->m)
                {
                    if(temp->d>=ptr->d)
                    {
                        swapd();
                        swape();
                    }
                }
                else
                    continue;
            }
            else
                continue;
        }
    }
    }
}
void swapd()
{
    int  c;
    c=temp->d;
    temp->d=ptr->d;
    ptr->d=c;
    c=temp->m;
    temp->m=ptr->m;
    ptr->m=c;
    c=temp->y;
    temp->y=ptr->y;
    ptr->y=c;
}
void swape()
{
    char t[100];
    strcpy(t,temp->event);
    strcpy(temp->event,ptr->event);
    strcpy(ptr->event,t);
}
int monthcode(int m)
{
    int mc;
    switch(m)//month code
    {
    case 1:
        mc=1;
        break;
    case 2:
        mc=4;
        break;
    case 3:
        mc=4;
        break;
    case 4:
        mc=0;
        break;
    case 5:
        mc=2;
        break;
    case 6:
        mc=5;
        break;
    case 7:
        mc=0;
        break;
    case 8:
        mc=3;
        break;
    case 9:
        mc=6;
        break;
    case 10:
        mc=1;
        break;
    case 11:
        mc=4;
        break;
    case 12:
        mc=6;
        break;
    }
    return mc;
}
int centurycode(int c)
{
    int r,rcc;// required century code
    r=c%4;//remainder
    switch(r)
    {
    case 0:
        rcc=6;
        break;
    case 1:
        rcc=4;
        break;
    case 2:
        rcc=2;
        break;
    case 3:
        rcc=0;
        break;
    }
    return rcc;
}
int leapyearcode(int l)
{
    int nl;//number of leap years
    nl=l/4;
    return nl;
}
int daycode(int d)
{
    d=d%7;// no of days
    return d;
}
int ndinmon(int m,int y)
{
    int nd,f,cy;//century years
    if(m==1)//month
        nd=31;//number of days
    else if(m==2)
    {
        cy=y%400;
        f=y%4;
        if(cy==0)
            nd=29;
        else if(y%100!=0&&f==0)
            nd=29;
        else
            nd=28;
    }
    else if(m==3)
        nd=31;
    else if(m==4)
        nd=30;
    else if(m==5)
        nd=31;
    else if(m==6)
        nd=30;
    else if(m==7)
        nd=31;
    else if(m==8)
        nd=31;
    else if(m==9)
        nd=30;
    else if(m==10)
        nd=31;
    else if(m==11)
        nd=30;
    else
        nd=31;
    return nd;
}
