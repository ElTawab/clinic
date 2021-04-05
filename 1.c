#include <stdio.h>
#include"STD_TYPES.h"
#include<stdlib.h>
typedef struct
{
u8 age;
u8 gender;
u32 id;
struct patient *nx;
u8 name[25];
}patient;
u32 res[5]={0};
patient *head=NULL;
u32 patient_cou=0;
void add_patient (void);
void display (void);
void Edit (void);
void reserve(void);
void cancel_reserve (void);
void view_res(void);

void main (void)
{u32 exit=0;
	u32 x;
	while(exit==0)
	{
		printf("1-Admin mode\n2-User mode\n");
		scanf("%d",&x);
		switch(x)
		{case 1:{u32 y,pass;
		u32 cou_pass=0;
		for(u32 i=0;i<3;i++)
		{printf("Please enter password\n");
		scanf("%d",&pass);
		if(pass==1234)
			break;
		else
		cou_pass++;}
	if(cou_pass==3)
	{exit++;
     continue;}
		printf("1-Add new patient\n2-Edit patient record\n3-Reserve with doctor\n4-Cancel reservation\n5-back\n6-Exit\n");
			scanf("%d",&y);
			switch(y)
			{
				case 1:add_patient(); break;
				case 2:Edit();break;
				case 3:reserve();break;
				case 4:cancel_reserve();break;
				case 5:continue;
				case 6:exit++;continue;
				default:printf("Invalid selection\n");break;
			}
			break;
		}
		case 2:{u32 z;
		printf("1-View patient record\n2-View today's reservations\n3-back\n4-Exit\n");
		scanf("%d",&z);
		switch(z)
		{
		        case 1:display(); break;
				case 2:view_res();break;
				case 3:continue;
		case 4:exit++;break;
		default:printf("Invalid selection\n");break;
		}
	}
	break;
default:printf("Invalid selection\n");break;
}}}


void add_patient (void)
{u32 y; //a variable to check on the existance of a similar id
	patient* current=head;
	patient* temp=(patient *)malloc(sizeof (patient));
	if(patient_cou==0)
	{printf("Please enter the patient's name: ");
fflush(stdin);
	fgets(temp -> name,25,stdin);
	printf("please enter the patient's age: ");
	scanf("%d",&(temp -> age));
	printf("please enter the patient's gender m or f: ");
	fflush(stdin);
	scanf("%c",&(temp -> gender));
	u8 gch=0;
	while(gch==0)
    {
        if((temp -> gender) != 'm'&&(temp -> gender)!='f')
        {free(temp -> gender);
            printf("Invalid entry it must be m or f\n");
            fflush(stdin);
            printf("please enter the patient's gender m or f: ");
	scanf("%c",&(temp -> gender));
        }
        else
            gch++;}
	printf("please enter unique patient ID: ");
	scanf("%d",&y);
	u32 c=0;
	while(c==0)
	{if(y==0)
    {printf("invalid ID shouldn't be zero.\n");
    printf("please enter unique patient ID: ");
	scanf("%d",&y);}
	else
	c++;}
     temp -> id=y;
	temp -> nx =NULL;
	head=temp;
	temp=current;
	head -> nx=NULL;
	patient_cou++;
	}
	else
	{
	    current =head;
	while(current -> nx!=NULL)
		current=current -> nx;
	current -> nx=temp;
	temp -> nx=NULL;
	printf("Please enter the patient's name: ");
	fflush(stdin);
	fgets(temp -> name,25,stdin);
	printf("please enter the patient's age: ");
	scanf("%d",&(temp -> age));
	printf("please enter the patient's gender m or f: ");
	fflush(stdin);
	scanf("%c",&(temp -> gender));
	u8 gch=0;
	while(gch==0)
    {
        if((temp -> gender) != 'm'&&(temp -> gender)!='f')
        {free(temp -> gender);
            printf("Invalid entry it must be m or f\n");
            fflush(stdin);
            printf("please enter the patient's gender m or f: ");
	scanf("%c",&(temp -> gender));
        }
        else
            gch++;}
current=head;
	u32 i=0;
	u32 c=0;
	 printf("please enter unique patient ID: ");
	scanf("%d",&y);
	while(c==0)
	{if(y==0)
    {printf("invalid ID shouldn't be zero.\n");
    printf("please enter unique patient ID: ");
	scanf("%d",&y);}
	else
	c++;}
		while(current!=NULL)
	{
if(y==current ->id)
{
    printf("The ID you entered is already assigned to another patient.\n");
    i++;
}
	current=current -> nx;
if(i!=0)
{printf("1-Try again and  enter unique ID patient ID\n2-Cancel entry\n");
u32 ch;
scanf("%d",&ch);
switch (ch)
{case 1:{ printf("please enter unique patient ID: ");
	scanf("%d",&y);
    c=0;
	while(c==0)
	{if(y==0)
    {printf("invalid ID shouldn't be zero.\n");
    printf("please enter unique patient ID: ");
	scanf("%d",&y);}
	else
	c++;}
current=head;
i=0;
break;}
case 2:{free (temp);
printf("Entry has been cancelled\n");
return;}
default:printf("Invalid selection\n");return;}
}}
if(i==0)
    {temp -> id=y;
    printf("The patient information has been successfully saved\n");
}}}

void display (void)
{u32 num;
printf("please enter your ID number\n");
scanf("%d",&num);
	patient *temp=head;
	while (temp!=NULL)
	{if(num==temp -> id)
		{
			printf("Name: ");
			printf("%s",temp -> name);
			printf("age: %d\n",temp -> age);
			printf("gender: %c\n",temp -> gender);
			printf("ID: %d\n",temp -> id);
			return;
		}
	temp=temp -> nx;}
	printf("The id is invalid please check it and try again\n");
}

void Edit (void)
{u32 num;
u32 y;
u32 cou=0;
patient *current=head;
patient *temp=head;
    printf ("please enter the id of patient you want to update information\n");
    scanf("%d",&num);
    while(temp != NULL)
      {

        if(temp -> id ==num)
    {u32 ch;
    printf("please choose information you want to change.\n1-Change name\n2-Change age\n3-Change gender\n4-Change ID\n5-back\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:{printf("Please enter the patient's name: ");
	fflush(stdin);
	fgets(temp -> name,25,stdin);
	break;}
	case 2:{
	printf("please enter the patient's age: ");
	scanf("%d",&(temp -> age));
	break;}
	case 3:{
	printf("please enter the patient's gender m or f: ");
	fflush(stdin);
	scanf("%c",&(temp -> gender));
	u8 gch=0;
	while(gch==0)
    {
        if((temp -> gender) != 'm'&&(temp -> gender)!='f')
        {free(temp -> gender);
            printf("Invalid entry it must be m or f\n");
            fflush(stdin);
            printf("please enter the patient's gender m or f: ");
	scanf("%c",&(temp -> gender));
        }
        else
            gch++;}
	break;}
	case 4:{current=head;
	 printf("please enter unique patient ID: ");
	scanf("%d",&y);
	u32 i=0;
	u32 c=0;
	while(c==0)
	{if(y==0)
    {printf("invalid ID shouldn't be zero.\n");
    printf("please enter unique patient ID: ");
	scanf("%d",&y);}
	else
	c++;}
			while(current!=NULL)
	{
if(y==current ->id)
{
    printf("The ID you entered is already assigned to another patient.\n");
    i++;
}
	current=current -> nx;
if(i!=0)

{ c=0;
printf("please enter unique patient ID: ");
	scanf("%d",&y);
	while(c==0)
	{if(y==0)
    {printf("invalid ID shouldn't be zero.\n");
    printf("please enter unique patient ID: ");
	scanf("%d",&y);}
	else
	c++;}
current=head;
i=0;}
}
if(i==0)
    {u32 z=0;
        for(u32 i=0;i<5;i++)
      if(temp -> id==res[i])
         {printf("This ID has reservation today.\n1-Automatically update the reservation ID.\n2-cancel reservation\n");
            u32 ch2;
            scanf("%d",&ch2);
      switch(ch2)
         {case 1:res[i]=y;break;
         case 2:res[i]=0;break;
             default:printf("Invalid entry\n");z++;break;
         }
    }
    if(z!=0)
        continue;
        temp -> id=y;
    num=y;
    }
    break;}
    case 5:return;
    default:{printf("Invalid selection\n");return;}}
	cou++;
	printf("information has been updated\n");
	continue;}
	temp=temp -> nx;
	}
	if(cou==0)
        printf("incorrect ID \n");
}

void reserve(void)
{while(1)
    {printf("Reservation slots: \n");
printf("1-from 2:00pm to 2:30pm is slot1\n2-from 2:30pm to 3:00pm is slot2\n3-from 3:00pm to 3:30pm is slot3\n4-from 4:00pm to 4:30pm is slot4\n5-from 4:30pm to 5:00pm is slot5\n0-back\n");
printf("The available slots are :\n");
for(u32 i=0;i<5;i++)
    if(res[i]==0)
        printf("slot%d\n",i+1);
    printf("Please enter the number of slot you want to reserve\n");
    u32 sl;
    scanf("%d",&sl);
    if(sl==0)
        return;
    else if(res[sl-1]==0&&sl<=5&&sl>0)
    {u32 num;
        printf("Please enter the patient ID you want to reserve slot to\n");
       scanf("%d",&num);
       u32 ch=0;
       for(u32 i=0;i<5;i++)
        if(num==res[i])
       {
           printf("This patient has already reserved today with doctor in different slot\n");
           ch++;
           break;
       }
       if(ch>0)
        continue;
       patient *current=head;
       u32 cou=0;
       while(current!=NULL)
{
           if(current -> id ==num)
           {
            res[sl-1]=num;
           cou++;
           printf("The reservation completed.\n");
           break;}
           current=current -> nx;}
           if(cou==0)
           {printf("Invalid ID\n");
           continue;}
    }
    else
    {printf("Invalid entry\n");
    continue;}
}}

void cancel_reserve (void)
{while(1)
{
    u32 num;
    u32 cou=0;
    printf("Please enter the ID you want to cancel the reservation\n0-back\n");
    scanf("%d",&num);
    if(num==0)
        return;
    for(u32 i=0;i<5;i++)
    {
        if(res[i]==num)
        {
            res[i]=0;
            printf("Reservation is cancelled\n");
            cou++;
            break;}
    }
    if(cou==0)
    printf("There is no reservation for this ID\n");
}}


void view_res(void)
{
    printf("Reservation slots: \n");
printf("1-from 2:00pm to 2:30pm is slot1\n2-from 2:30pm to 3:00pm is slot2\n3-from 3:00pm to 3:30pm is slot3\n4-from 4:00pm to 4:30pm is slot4\n5-from 4:30pm to 5:00pm is slot5\n0-back\n");
for(u32 i=0;i<5;i++)
{
 if(res[i]==0)
        printf("slot%d Empty\n",i+1);
 else
    printf("slot%d: %d\n ",i+1,res[i]);
}
}
