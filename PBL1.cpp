#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int tt[5]={0};
int l[10]={0};
struct diemMH
 {
 	float l1,l2,pt1,pt2,p,ft,tk,t4;
 	char dc;
 };
 struct thong_tin
 {
 	char msv[20];
 	char ho_ten[40];
 	struct diemMH MH[5];
 };
 int tim(const struct thong_tin a[],int slsv,char x[])
 {
 	int i;
 	for (i=1;i<=slsv;i++)
 	if (strcmp(a[i].msv,x)==0) return i;
 	return -1;
 }
  void docFile(struct thong_tin SV[], int *slsv) 
  {
	FILE *fOut = fopen("Thongtin.txt","r");
	int i = 0;
		while (feof(fOut)==0) 
		{
			struct thong_tin sv;
			fscanf(fOut, "%10s %30[^\n]\n",sv.msv,sv.ho_ten );			
			SV[++i] = sv;	
		}
	fclose(fOut);
    *slsv=i;	
	}	
void docFileDiem(struct thong_tin* SV,int stt,char fname[] ,int slsv) 
{
	FILE *fOut = fopen(fname,"r");
	int tk;
	char k[20]; 
	fscanf(fOut,"%d\n",&tt[stt]);
	while (feof(fOut)==0)
	{
		struct thong_tin sv;
		fscanf(fOut,"%10s",k);
		tk=tim(SV,slsv,k);
		printf("%d\n",tk);
		sv=SV[tk];
		fscanf(fOut,"%5f %5f %5f %5f %5f %5f",&sv.MH[stt].l1,&sv.MH[stt].l2,&sv.MH[stt].pt1,&sv.MH[stt].pt2,&sv.MH[stt].p,&sv.MH[stt].ft);			
		if (tt[stt]==1) fscanf(fOut,"%5f %5f %5c\n",&sv.MH[stt].tk,&sv.MH[stt].t4,&sv.MH[stt].dc);
		else fscanf(fOut,"\n");
		SV[tk] =sv;
	}
	fclose(fOut);		
}
 void ghiFileDiem(const struct thong_tin SV[], int stt,char fname[] ,int slsv)
{
	FILE *fOut = fopen(fname,"w");
	int i ;
	fprintf(fOut,"%d\n",tt[stt]);
	for(i = 1; i <= slsv; i++) 
	{
		struct thong_tin sv=SV[i];
		fprintf(fOut,"%-9s %-4.1f %-4.1f %-4.1f %-4.1f %-4.1f %-4.1f ",
		sv.msv,sv.MH[stt].l1,sv.MH[stt].l2,sv.MH[stt].pt1,sv.MH[stt].pt2,sv.MH[stt].p,sv.MH[stt].ft);	
		if (tt[stt]==1) fprintf(fOut,"%-4.1f %-4.1f %-4c\n",sv.MH[stt].tk,sv.MH[stt].t4,sv.MH[stt].dc);
		else fprintf(fOut,"\n");				
	}	
	fclose(fOut);		
}
void outfull(struct thong_tin SV[],int slsv,int stt)
{
	int i;
	     if(stt==1) printf ("\n 	    			BANG DIEM MON GIAI TICH  \n");
	else if(stt==2) printf ("\n 	    			BANG DIEM MON KI THUAT LAP TRINH  \n");
	else if(stt==3) printf ("\n 	    			BANG DIEM MON PHUONG PHAP TINH  \n"); 
	else if(stt==4) printf ("\n 	    			BANG DIEM MON CAU TRUC DU LIEU  \n"); 
	printf("	-----------------------------------------------------------------------------------------------------------------------------------");
		if (tt[stt]==1) printf("----------------------\n"); else printf("\n");
	    printf("	| MSV           ");
	    printf("| Ho Va Ten                ");
		printf("| Lab1   ");
		printf("| Lab2   ");
		printf("| Progress Test 1   ");
		printf("| Progress Test 2   ");
		printf("| Presentation ");
		printf("| Final Test  |");
		if (tt[stt]==1) {
		printf("final   ");   
		printf("| GPA  ");
		printf("| Chu |\n");
		}
		else printf("\n");
		printf("	-----------------------------------------------------------------------------------------------------------------------------------");
		if (tt[stt]==1) printf("----------------------\n"); else printf("\n");
	   for (i=1;i<=slsv;i++){	
	   	struct thong_tin sv=SV[i];	
			printf("	| %s         ",sv.msv);
			printf("| %-25s",sv.ho_ten);		
		 	printf("| %-7.1f",sv.MH[stt].l1); 
			printf("| %-7.1f",sv.MH[stt].l2); 
			printf("| %-18.1f",sv.MH[stt].pt1); 
		    printf("| %-18.1f",sv.MH[stt].pt2);
			printf("| %-14.1f",sv.MH[stt].p);
			printf("| %-11.1f|",sv.MH[stt].ft);
		if (tt[stt]==1) 
		{
			printf("%-8.1f",sv.MH[stt].tk);
			printf("| %-5.1f",sv.MH[stt].t4);
			printf("| %-4.c|\n",sv.MH[stt].dc);
		}	else printf("\n");
		printf("	-----------------------------------------------------------------------------------------------------------------------------------");
		if (tt[stt]==1) printf("----------------------\n"); else printf("\n");
	   } 
 }  
 void out(struct thong_tin sv,int stt)
 {
	printf("	-----------------------------------------------------------------------------------------------------------------------------------");
	if (tt[stt]==1) printf("------------------------------\n"); else printf("\n");
	    printf("	| MSV           ");
	    printf("| Ho Va Ten                ");
		printf("| Lab1   ");
		printf("| Lab2   ");
		printf("| Progress Test 1   ");
		printf("| Progress Test 2   ");
		printf("| Presentation ");
		printf("| Final Test  |");
	if (tt[stt]==1)
	{
		printf("final   ");   
		printf("| GPA  ");
		printf("| Chu |\n"); 
	}
	else printf("\n");
    if (tt[stt]==1) printf("	----------------------"); else printf ("	"); 
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");		
		printf("	| %s         ",sv.msv);
		printf("| %-25s",sv.ho_ten);		
	 	printf("| %-7.1f",sv.MH[stt].l1); 
		printf("| %-7.1f",sv.MH[stt].l2); 
		printf("| %-18.1f",sv.MH[stt].pt1); 
	    printf("| %-18.1f",sv.MH[stt].pt2);
		printf("| %-14.1f",sv.MH[stt].p);
		printf("| %-11.1f|",sv.MH[stt].ft);
	if (tt[stt]==1) {
		printf("%-8.1f",sv.MH[stt].tk);
		printf("| %-5.1f",sv.MH[stt].t4);
		printf("| %-4.c|\n",sv.MH[stt].dc);
		}else printf("\n");
   if (tt[stt]==1) printf("	----------------------"); else printf ("	"); 
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");				
} 
 void outtt(struct thong_tin sv)
 {
 	int i;
 	printf("\n    Ho va ten:  %s      MSV:  %s\n",sv.ho_ten,sv.msv);
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");

        printf ("|      MON HOC       ");	
		printf("| Lab1   ");
		printf("| Lab2   ");
		printf("| Progress Test 1   ");
		printf("| Progress Test 2   ");
		printf("| Presentation ");
		printf("| Final Test  |");
		printf("final   ");   
		printf("| GPA  ");
		printf("| Chu |\n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");	
	for(i=1;i<5;i++)
	{
		 	    if (i==1)     printf ("|     GIAI TICH      ");
				else if(i==2) printf ("| KI THUAT LAP TRINH ");
				else if(i==3) printf ("| PHUONG PHAP TINH   "); 
				else if(i==4) printf ("| CAU TRUC DU LIEU   "); 
				if (l[i]==1){
			 	printf("| %-7.1f",sv.MH[i].l1); 
				printf("| %-7.1f",sv.MH[i].l2); 
				printf("| %-18.1f",sv.MH[i].pt1); 
			    printf("| %-18.1f",sv.MH[i].pt2);
				printf("| %-13.1f",sv.MH[i].p);
				printf("| %-11.1f |",sv.MH[i].ft);
				if(tt[i]==1){
			
				printf(" %-7.1f",sv.MH[i].tk);
				printf("| %-5.1f",sv.MH[i].t4);
				printf("| %-4.c|\n",sv.MH[i].dc);}
				else {
					printf("    _   ");
				printf("|   _  ");
				printf("|  _  |\n");
				}
				}
				else {
				printf("|    _   "); 
				printf("|    _   "); 
				printf("|         _         "); 
			    printf("|         _         ");
				printf("|       _      ");
				printf("|      _      |");
				printf("    _   ");
				printf("|   _  ");
				printf("|  _  |\n");	
				}
			printf("-----------------------------------------------------------------------------------------------------------------------------------\n");				
 	} 
 }

void tb(struct thong_tin SV[],int slsv,int stt)
{
 	int i;
 	for (i=1;i<=slsv;i++)
	 {
 		SV[i].MH[stt].tk=(SV[i].MH[stt].l1+SV[i].MH[stt].l2+SV[i].MH[stt].pt1+SV[i].MH[stt].pt2+SV[i].MH[stt].p+SV[i].MH[stt].ft)/6;
	 }
 }
 void quydoi(struct thong_tin SV[],int slsv,int stt)
 {
 		int i;
 	for (i=1;i<=slsv;i++){
 		if (SV[i].MH[stt].tk>=8.5) {
		SV[i].MH[stt].dc='A';
		SV[i].MH[stt].t4=4;
	}
 		else 
		 if (SV[i].MH[stt].tk<8.5 && SV[i].MH[stt].tk>=7) {
		 SV[i].MH[stt].dc='B'; 
		SV[i].MH[stt].t4=3;
	}
 		else 
		 if  (SV[i].MH[stt].tk>=5.5 && SV[i].MH[stt].tk<7) {
		 SV[i].MH[stt].dc='C';
		 SV[i].MH[stt].t4=2;
		 } 
 		else if (SV[i].MH[stt].tk>=4 && SV[i].MH[stt].tk<5.5) {
	    SV[i].MH[stt].dc='D'; 
		SV[i].MH[stt].t4=1;
	}
 		else {
		 SV[i].MH[stt].dc='F'; 
		 SV[i].MH[stt].t4=0;
		 }
	 }
 }
  void sort1(struct thong_tin SV[],int slsv,int stt)
  {
  	int i;
  	struct thong_tin tam;
  	for (i=1;i<slsv;i++)
  	 for (int j=i+1;j<=slsv;j++)
  	  if (SV[i].MH[stt].tk<SV[j].MH[stt].tk) 
  	  {
  	  	tam=SV[i];
  	  	SV[i]=SV[j];
  	  	SV[j]=tam;
		}
  }
   void sort2(struct thong_tin SV[],int slsv,int stt)
  {
  	int i,t;
  	char a[50][20]={{""}};
  	char x[20];
  	 for (i=1;i<=slsv;i++)
  	 {
  	 	struct thong_tin sv=SV[i];
  	 	int j=strlen(sv.ho_ten)-1;
  	 	while(sv.ho_ten[j]!=32) j--;
  	 	j++;
  	 	a[i][0]=sv.ho_ten[j];
  	 	for (t=j+1;t<strlen(sv.ho_ten);t++)
  	 	a[i][strlen(a[i])]=sv.ho_ten[t];
	   }
	  struct thong_tin tam;
  	for (i=1;i<slsv;i++)
  	 for (int j=i+1;j<=slsv;j++)
  	  if  (strcmp(a[i],a[j])==1) 
  	  {
  	  	tam=SV[i];
  	  	SV[i]=SV[j];
  	  	SV[j]=tam;
  	  	strcpy(x,a[i]);
  	  	strcpy(a[i],a[j]);
  	  	strcpy(a[j],x);
		}
  }
    void out3(struct thong_tin SV[],int slsv,int stt)
 {
		int i,j;
		int a[5]={0};
		double b[5];
		for (i=1;i<=slsv;i++)	
		   if(SV[i].MH[stt].t4==0) a[0]++;
		   else 
		   if(SV[i].MH[stt].t4==1) a[1]++;
		    else 
		   if(SV[i].MH[stt].t4==2) a[2]++;
		    else 
		   if(SV[i].MH[stt].t4==3) a[3]++;
		    else 
		    a[4]++;
		for(i=0;i<5;i++) b[i]=(double)a[i]/slsv;  
		  printf("Thong ke theo thang diem 4 la :\n\n");
	    for(i=0;i<5;i++)
		{
	    	printf("	GPA diem %d.0 la: ",i);
	    	for(j=1;j<=a[i];j++) printf("%c%c",219,219);
	    	printf("%7.2lf%c\n",b[i]*100,37);
	    	printf("\n");
		}
}
 void kt(float *x)
 {
 	while (*x<0 || *x>10)
	 {
 		printf("Nhap diem sai vui long nhap lai\n");
 		scanf("%f",x);
	 }
 }
 main(){
 	struct thong_tin SV[50];
 	int i,n,k,zz,t,tk,m,sx=0,v,r;
 	float o;
 	char x[20];
 	char u[200];
 	system ("color fa");
 	char fname[][50]={{"Giai_tich.txt"},{"KTLT.txt"},{"PPT.txt"},{"CTDL.txt"}};
 		docFile(SV,&n);
 	do {
 		do{
		printf("-----Chon file:-----\n");
 		printf(" 1. Giai tich \n");
 		printf(" 2. KTLT      \n");
 		printf(" 3. PPT       \n");
  		printf(" 4. CTDL       \n");		
 		printf(" 5. Thong tin \n");
 		printf(" 6. Thoat     \n\n");
 		fflush(stdin);
 		gets(u);
 		zz=0;
 		if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 && strcmp(u,"3")!=0 && strcmp(u,"4")!=0 &&  strcmp(u,"5")!=0 && strcmp(u,"6")!=0)
			 { 
				system("cls");
		 		printf("           Vui long nhap dung lua chon\n\n"); 
			 }
		else zz=1;
 		}
		 while ( zz==0);
 		
		 t=u[0]-48;
 		if(t==6) break;
		else 
		if(t==5) {	
		system("cls");
		do{
		printf(" \n Nhap MSV ");
		fflush(stdin);
		gets(x);
	    tk=tim(SV,n,x);   
		if(tk==-1) printf("\n            Khong tim thay sinh vien\n");
		else{
			do{
			do{
		printf("\n     1.Xem thong tin sinh vien\n");
		printf("     2.Xem diem cac mon cua sinh vien\n");
		printf("     3.Thoat\n");
		 fflush(stdin);
 		gets(u);
 		zz=0;
 		if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 && strcmp(u,"3")!=0) {
 			system("cls");
 		printf("         Vui long nhap dung lua chon\n"); }else zz=1;
 		}while ( zz==0);
 		r=u[0]-48;
		 system("cls");
		 if(r==1) printf("\n    Ho va ten  %s      MSV  %s\n",SV[tk].ho_ten,SV[tk].msv);
		else
			if(r==2){

			system("cls");
			outtt(SV[tk]);}
		 } while(r!=3);}
		 do{
		printf("\n1. Xem sinh vien khac\n");
		printf("2. Dung xem\n");
	    fflush(stdin);
 		gets(u);
 		zz=0;
 		if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0) {
 			system("cls");
 		printf("         Vui long nhap dung lua chon\n");
		  }else zz=1;
 		}while ( zz==0);
 		v=u[0]-48;
		system("cls");
		} while(v==1);	
		}  
		else{
		if (l[t]==0){	
 		docFileDiem(SV,t,fname[t-1],n);
 		l[t]=1;}
 		system("cls");
 				do{
 				do{
				printf("\n");
 				printf("-----Nhap lua chon:-----\n");
			   	printf("2. Xem Diem\n");
			   	printf("3. Sua Diem\n");
			   	printf("4. Sap Xep\n");
			   	printf("5. In Danh Sach\n");
			   	printf("6. Thoat\n");
			   	fflush(stdin);
 		gets(u);
 		zz=0;
 		if (strcmp(u,"2")!=0 && strcmp(u,"3")!=0 && strcmp(u,"4")!=0 && strcmp(u,"5")!=0 && strcmp(u,"6")){
 			system("cls");
 		printf("         Vui long nhap dung lua chon\n"); }else zz=1;
 		}while ( zz==0);
 		k=u[0]-48;
			   	system("cls");
 				switch(k){
					case 2:{
					 	do{
						printf(" \n Nhap MSV ");
						fflush(stdin);
				        gets(x);
				        tk=tim(SV,n,x);
						if(tk==-1) printf("khong tim thay sinh vien\n");
						else out(SV[tk],t);
						do{
						printf("\n1. Xem sinh vien khac\n");
						printf("2. Dung xem\n");
						fflush(stdin);
 		gets(u);
 		zz=0;
 		if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0)
		{
 			system("cls");
 		printf("         Vui long nhap dung lua chon\n"); 
		}	else zz=1;
 		}	while ( zz==0);
 		v=u[0]-48;
						system("cls");
					} while(v==1);
						break;
					 }                        
					case 3:{
						do{
						printf(" \n Nhap MSV ");
				        fflush(stdin);
				        gets(x);
						tk=tim(SV,n,x); 
						if(tk==-1) printf("Khong tim thay sinh vien\n");
						else
						{
						do{
						printf("\n");	
						out(SV[tk],t);
						printf("\n");
						printf("---NHAP COT DIEM CAN SUA---\n");
						printf(" 1. Lab1\n"); 
						printf(" 2. Lab2\n"); 
						printf(" 3. Progress Test 1\n"); 
				   		printf(" 4. Progress Test 2\n"); 
						printf(" 5. Presentation\n"); 
						printf(" 6. Final Test\n");
						fflush(stdin);
 		                gets(u);
 		                zz=0;
 		    if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 && strcmp(u,"3")!=0 && strcmp(u,"4")!=0 && strcmp(u,"5")!=0 && strcmp(u,"6")){
 			system("cls");
 		printf("         Vui long nhap dung lua chon\n"); }
		    else zz=1;
 		                }while ( zz==0);
 		m=u[0]-48;	
								switch (m){
						  	case 1:{
						  		printf("Lab1= "); 
						  		scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].l1=o;
								break;
							  }
							case 2:{
								printf("Lab2= "); 
						  		scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].l2=o;
								break;
							} 
							case 3:{
								printf("Progress Test 1= "); 
								scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].pt1=o;
								break;
							} 
							case 4:{
								printf("Progress Test 2= "); 
								scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].pt2=o;
								break;
							}
							case 5:{
								printf("Presentation= "); 
								scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].p=o;
								
								break;
							}
							case 6:{
								printf("Final Test=");
								scanf("%f",&o);
						  		kt(&o);
						  		SV[tk].MH[t].ft=o;
								break;
							}
						  }	
						   	system("cls");		
							   printf("\n    Da cap nhat\n"); 
								}
						do
						{		
							printf("\n1. Tiep tuc sua\n");
							printf("2. Ket thuc\n");
							fflush(stdin);
					 		gets(u);
					 		zz=0;
					 		if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 )
							{
					 			system("cls");
					 			printf("         Vui long nhap dung lua chon\n");
							}	else zz=1;
				 		}	while ( zz==0);
				 		v=u[0]-48;
						system("cls");	
							} while (v==1);
							if (tt[t]==1){
							tb(SV,n,t);
						    quydoi(SV,n,t);
							}
						ghiFileDiem(SV,t,fname[t-1],n);
								break;
							} 
					
					case 4:
					{
						tb(SV,n,t);
						quydoi(SV,n,t);
						tt[t]=1;
						do
						{
							printf("1. Sap xep theo diem\n");
							printf("2. sap xep theo ten\n");
							fflush(stdin);
			 		        gets(u);
			 				zz=0;
			 				if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 )
							{
			 					system("cls");
			 					printf("         Vui long nhap dung lua chon\n"); 
							}	else zz=1;
		 				}	while ( zz==0);
		 				v=u[0]-48;
		 				if (v==1) sort1(SV,n,t);
		 				else sort2(SV,n,t);
							ghiFileDiem(SV,t,fname[t-1],n);
							printf("\n Da sap xep\n");
							break;
					}
					case 5:
					{
						printf("\n");
						outfull(SV,n,t);
						printf("\n");
						if (tt[t]==1){
						do{
						printf("Ban co muon thong ke diem\n");
						printf("\n1. Co\n");
						printf("2. Khong\n");
						fflush(stdin);
 	                	gets(u);
 	                 	zz=0;
 	                 	if (strcmp(u,"1")!=0 && strcmp(u,"2")!=0 ){
 		             	system("cls");
 	                	printf("         Vui long nhap dung lua chon\n"); }else zz=1;
 	                	}while ( zz==0);
 	                	v=u[0]-48;
 	                	 if (v==1) out3(SV,n,t);else system("cls");}
						break;
					}
		 					}	}while (k!=6);
		 				}
	    }
		while(t!=6); 
	return 0;    
}
