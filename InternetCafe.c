#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start();
void open(int *h,int *m, int cho,int *bill);
int foodandrink(int *h,int *m,int *bill);
void foodmoney(int *bill, int chos);
void calculateBill (void);
int main (void)

{
   int i,q,count=1,mh,mm,a,cho=0,bill,co;


	while(count==1)
	{
		printf("0. Sent message to start account\n1. Open account for 30 minutes\n2. Open account for 1 hour\n3. Open account for 2 hour\n4. Show foods and drinks menu\n5. Show bill\n6. Close account\nChoose: ");
	scanf("%d",&q);

	if(q==0)
	   {
	  
	   start();
	   
	   }
	   if(q==1)
	   {
		   cho=1;
	  open(&mh,&mm,cho,&bill);
	 printf("saat:%d:%d\n",mh,mm);
	   
	   }
	   
	   else if(q==2)
	   {
		   cho=2;
		   open(&mh,&mm,cho,&bill);
	   }

	   else if(q==3)
	   {
		   cho=3;
		    open(&mh,&mm,cho,&bill);
	   }

	   else if(q==4)
	   {
	     co=foodandrink(&mh,&mm,&bill);
		 foodmoney(&bill,co);
	   }

	   else if(q==5)
	   {
		   getchar();
		  calculateBill();
	   
	   }
	

	   else if(q==6)
	   {
	   printf("BYE!!\n");
	   count=0;
	   }
	
	
	
	}
	
	return(0);	
}

void start()
{
	int sayi,len,i;
	FILE* fp;
	char time[50];
	char *token;

	printf("Your account has opened!\n");
	fp=fopen("account.txt","w");

   printf("Input your start time(hh:mm):\n ");
   scanf("%s",time);

   fprintf(fp,"%s\n",time);

   fclose(fp);

}

void open(int *h,int *m, int cho,int *bill)
{
	FILE* fp;
	char tim[50],ask[4];
	char* token;
	int main=0,ex,cou=0,fmain=0;

	fp=fopen("account.txt","r");

	fscanf(fp,"%s",tim);
	

	fclose(fp);

	 token = strtok(tim, ":");
   *h=atoi(token);
 
   while( token != NULL ) {
      
    *m=atoi(token);
      token = strtok(NULL, ":");
	  
   }
   main=(*h)*60+(*m);
   fmain=main;
   
   if(cho==1)
   {
     main=main+30;
   }
   if(cho==2)
   {
     main=main+60;
   }
   if(cho==3)
   {
     main=main+120;
   }
   *h=main/60;
   *m=main%60;
   
   

   while(cou==0){
	   printf("Do you want to continue: ");
   scanf("%s",&ask);
   if(ask[0]=='Y' || ask[0]=='y' && ask[1]=='e' || ask[1]=='E'  && ask[2]=='s'|| ask[2]=='S' ){
     printf("How long do you want to use: ");
	 scanf("%d",&ex);

	 main=main+ex;
	 *h=main/60;
   *m=main%60;
   }
   else if(ask[0]=='N' || ask[0]=='n' && ask[1]=='O' || ask[1]=='o')
   {
   FILE* pp;
   pp=fopen("account.txt","a");

   fprintf(pp,"%d:%d\n",*h,*m);

   fclose(pp);
   cou=1;
   }
   }
   main=main-fmain;
   printf("SURE:%d\n",main);
   if(main<=30)
	   *bill=(main/60)*2;
   else if(main>30 && main<=60)
	   *bill=(main/60)*3;
    else if(main>60 && main<=120)
	   *bill=(main/60)*5;
    else if(main>120){
	   *bill=(main/60)*3;
	}
	
}

int foodandrink(int *h,int *m,int *bill)
{
	int chos,count=0;

	
	printf("0. Kofte ekmek (15)\n1. Tavuk ekmek (10)\n2. ONCU (8)\n3. Patso (6)\n4. Gazli Icecek (4)\n5. Ayran (2)\n6. Su (1)\n7.Return to main menu\nEnter your choice (0,1,2,3,4,5,6,7): ");
	scanf("%d",&chos);
	return(chos);
	
}

void foodmoney(int *bill, int chos)
{
	int count=0;
	FILE* tp;

	tp=fopen("account.txt","a");


	
	if(chos==0){
		fprintf(tp,"\nKofte ekmek\n");
	}
	if(chos==1){
		fprintf(tp,"\nTavuk ekmek\n");
	}
	if(chos==2){
		fprintf(tp,"\nONCU\n");
	}
	if(chos==3){
		fprintf(tp,"\nPatso\n");
	}
	if(chos==4){
		fprintf(tp,"\nGazli Icecek\n");
	}
	if(chos==5){
		fprintf(tp,"\nAyran\n");
	}
	if(chos==6){
		fprintf(tp,"\nSu\n");
	}

	
fclose(tp);
}

void calculateBill (void)
{
	FILE* last;
	FILE* billo;
	int count=0,h,m,main,lmain,lh,lm,lasttimehour,lasttimemin,bill=0;
	char ftime[50],ltime[50],ofood[50];
	char* token;

	last=fopen("account.txt","r");

	while(!feof(last))
	{
	   if(count==0)
	   {
	     fscanf(last,"%s",&ftime);
	    token = strtok(ftime, ":");
   h=atoi(token);
   while( token != NULL ) {
    m=atoi(token);
      token = strtok(NULL, ":");
   }
   main=(h)*60+(m);
   printf("%d\n",main);
	   }
	   
	   
	     fgets(ofood,50,last);
		 printf("Food Bill: %s\n",ofood);

		 if(ofood[2]==':'){
			   printf("COUNT:%d\n",count);
			  token = strtok(ofood, ":");
   lh=atoi(token);
   while( token != NULL ) {   
    lm=atoi(token);
      token = strtok(NULL, ":"); 
   }
   lmain=(lh)*60+(lm);
   printf("%d\n",lmain);
			   }

		 if(ofood[0]=='K' && ofood[1]=='o')
			 bill=bill+15;
		 else if(ofood[0]=='T' && ofood[1]=='a')
			 bill=bill+10;
		 else  if(ofood[0]=='O' && ofood[1]=='N')
				 bill=bill+8;
		 else 	 if(ofood[0]=='G' && ofood[1]=='a')
					 bill=bill+4;
		 else 	 if(ofood[0]=='A' && ofood[1]=='y')
						 bill=bill+2;
		 else 		 if(ofood[0]=='S' && ofood[1]=='u')
			                  bill=bill+1;
		 else 		 if(ofood[0]=='P' && ofood[1]=='a')
			                    bill=bill+6;
		 
		   
		 

 printf("Your Bill: %d\n",bill);
	   
	
	count++;
	}
	lmain=lmain-main;
	 lasttimehour=lmain/60;
	 lasttimemin=lmain%60;
	 printf("%d hour %d minute\n",lasttimehour,lasttimemin);
	 
	 
	 if(lmain<=30)
	   bill=bill+2;
   else if(lmain>30 && lmain<=60)
	   bill=bill+3;
    else if(lmain>60 && lmain<=120)
	   bill=bill+5;
    else if(lmain>120)
	   bill=(lmain/60)*3;
	
	printf("Bill:%d\n",bill);

	fclose(last);

	billo=fopen("account.txt","a");
	fprintf(billo,"Your bill : %d",bill);

	fclose(billo);
}
