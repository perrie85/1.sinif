#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct kullanici
{
	char k_adi[20];
	char sifre[20];
	int puan;
};

typedef struct kullanici kontrol_degisim;

int main()
{
	FILE *proje;
	FILE *puanlar;
	int puanlar_degisim[10];
	int i,j,P_secim,pepe;
	int gecici,sira,temp;
	int EvP=1,OkulP=2,CafeP=3,SinemaP=4;
    int secim;
	char k_adi_k[20];
	char sifre_k[20];
	printf("\nSwarm'a hosgeldiniz\n");
	while(1)
	{
        printf("Bir secim yapiniz\n");
        printf("1. Kayit ol\n");
        printf("2. Giris ve check-in\n");
        printf("3. Giris ve Siralama ogrenme\n");
        printf("4. Cikis\n");
        scanf("%d",&secim);
        system("CLS");
    	if(secim == 1)
			{
				kontrol_degisim a;
				proje=fopen("kadisifre.txt","a+");
				a.puan=0;
				i=-1;
				printf("istediginiz kullanici adini giriniz: ");
				scanf("%s",k_adi_k);
				printf("istediginiz sifreyi giriniz: ");
				scanf("%s",sifre_k);
				system("cls");
				while(!feof(proje))
				{
					fscanf(proje,"%s %s %d",a.k_adi,a.sifre,&a.puan);
					if(strcmp(a.k_adi,k_adi_k)==0)
					{
						printf("\nKullanici adi kullanilmaktadir. \nYeni bir kullanici adi giriniz: ");
						scanf("%s",k_adi_k);
					}
					if(feof(proje))
					i=a.puan;
				}
				fprintf(proje,"%s %s %d\n",k_adi_k,sifre_k,i+1);
				fclose(proje);
				system("CLS");
				printf("\nKaydiniz yapilmistir. Ana menuye donmek icin bir tusa basiniz.\n");
				getch();
				system("CLS");
			}
		else if(secim==2)
			{
			if((puanlar=fopen("puanlar.txt","r"))==NULL)
			{
				printf("\nServer hatasi\n");
				break;
			}
			else
			{
			for(i=0;i<10;i++)
			{
				fscanf(puanlar,"%d",&gecici);
				puanlar_degisim[i]=gecici;
			}
			fclose(puanlar);
			if((proje=fopen("kadisifre.txt","a+"))==NULL)
			{
				printf("\nServer hatasi\n");
				break;
			}
			else
			{
			printf("\nGiris yapiniz. Eger hatali kullanici adi veya sifre girerseniz program ana menuye donecektir.\n");
			printf("Kullanici adinizi giriniz: ");
			scanf("%s",k_adi_k);
			printf("Sifrenizi giriniz: ");
			scanf("%s",sifre_k);
			while(!feof(proje))
			{
				kontrol_degisim b;
				fscanf(proje,"%s %s %d",b.k_adi,b.sifre,&b.puan);
				if(strcmp(b.k_adi,k_adi_k)==0)
				{
					if(strcmp(b.sifre,sifre_k)==0)
					{
					printf("\nGiris yapilmistir. Devam etmek icin bir tusa basiniz.\n");
					getch();
					system("cls");
					printf("Check-in yapmak istediginiz mekani seciniz\n");
					printf("Ev icin 1\n");
					printf("Okul icin 2\n");
					printf("Cafe icin 3\n");
					printf("Sinema icin 4 giriniz\n");
					scanf("%d",&P_secim);
						if((puanlar=fopen("puanlar.txt","w"))==NULL)
						{
						printf("\nServer hatasi\n");
						break;
						}
						else	
							{
						switch (P_secim)
						{
						case 1:
							system("cls");
							puanlar_degisim[b.puan-1]+=EvP;
							printf("Evi sectiniz. Yeni puaniniz:%d\n",puanlar_degisim[b.puan-1]);
							for(i=0;i<10;i++)
							{
								fprintf(puanlar,"%d\n",puanlar_degisim[i]);
							}
							printf("Ana menuye donmek icin bir tusa basiniz.\n");
							getch();
							system("cls");
							fclose(puanlar);
							fclose(proje);
							break;
						case 2:
							system("cls");
							puanlar_degisim[b.puan-1]+=OkulP;
							printf("Okulu sectiniz. Yeni puaniniz:%d\n",puanlar_degisim[b.puan-1]);
							for(i=0;i<10;i++)
							{
								fprintf(puanlar,"%d\n",puanlar_degisim[i]);
							}
							printf("Ana menuye donmek icin bir tusa basiniz.\n");
							getch();
							system("cls");
							fclose(puanlar);
							fclose(proje);
							break;
						case 3:
							system("cls");
							puanlar_degisim[b.puan-1]+=CafeP;
							printf("Cafeyi sectiniz. Yeni puaniniz:%d\n",puanlar_degisim[b.puan-1]);
							for(i=0;i<10;i++)
							{
								fprintf(puanlar,"%d\n",puanlar_degisim[i]);
							}
							printf("Ana menuye donmek icin bir tusa basiniz.\n");
							getch();
							system("cls");
							fclose(puanlar);
							fclose(proje);
							break;
						case 4:
							system("cls");
							puanlar_degisim[b.puan-1]+=SinemaP;
							printf("Sinemayi sectiniz. Yeni puaniniz:%d\n",puanlar_degisim[b.puan-1]);
							for(i=0;i<10;i++)
							{
								fprintf(puanlar,"%d \n",puanlar_degisim[i]);
							}
							printf("Ana menuye donmek icin bir tusa basiniz.\n");
							getch();
							system("cls");
							fclose(puanlar);
							fclose(proje);
							break;
						default:
							printf("Gecersiz secim yaptiniz. Ana menuye donmek icin bir tusa basiniz.\n");
							getch();
							system("cls");
							break;
						}
						}
						break;
					}
					else
					{
						system("cls");
					}
				}	
				else
				{
					system("cls");
				}
			}
		}
		}
		}
		else if(secim==3)
		{
			if((proje=fopen("kadisifre.txt","r"))==NULL)
			{
				printf("\nServer hatasi\n");
				break;
			}
			else
			{
			printf("\nGiris yapiniz. Eger hatali kullanici adi veya sifre girerseniz program ana menuye donecektir.\n");
			printf("kullanici adinizi giriniz: ");
			scanf("%s",k_adi_k);
			printf("sifrenizi giriniz: ");
			scanf("%s",sifre_k);
			if((puanlar=fopen("puanlar.txt","r"))==NULL)
			{
				printf("\nServer hatasi\n");
				break;
			}
			else
			{
			for(i=0;i<10;i++)
			{
				fscanf(puanlar,"%d",&gecici);
				puanlar_degisim[i]=gecici;
			}
			fclose(puanlar);
			}
			while(!feof(proje))
			{
				kontrol_degisim b;
				fscanf(proje,"%s %s %d",b.k_adi,b.sifre,&b.puan);
				if(strcmp(b.k_adi,k_adi_k)==0)
				{
					if(strcmp(b.sifre,sifre_k)==0)
					{
						system("cls");
						printf("\nGiris yapilmistir. Devam etmek icin bir tusa basiniz.\n");
						getch();
						system("cls");
						pepe=puanlar_degisim[b.puan-1];
 						for (i=1; i<10; i++)
   						{
        					for (j=0; j<10-i; j++)
        					{
            					if(puanlar_degisim[j] > puanlar_degisim[j+1])
            					{
                	      		 	temp = puanlar_degisim [j];
                    	  			puanlar_degisim [j] = puanlar_degisim [j+1];
						   			puanlar_degisim [j+1] = temp;
            					}
        					}
    					}
    					for(i=9;i>-1;i--)
    					{
    						if(puanlar_degisim[i]==pepe && i==9)
    						{
    							printf("%d puanla 1.siniz tebrikler!!\n",pepe);
								break;
							}
    						else if(puanlar_degisim[i]==pepe && i==8)
							{
								printf("%d puanla 2.siniz. Birinciyle aranizda %d puan bulunmaktadir.\n",pepe,puanlar_degisim[9]-pepe);
								break;
							}
							else if(puanlar_degisim[i]==pepe && i==7)
							{
								printf("%d puanla 3.sunuz. birinciyle aranizda %d puan bulunmaktadir.\n",pepe,puanlar_degisim[9]-pepe);
								break;
							}
							else if(puanlar_degisim[i]==pepe)
							{
								printf("Puaniniz %d dir, ilk 3 e giremediniz. Birincinin puani %d dir.\n",pepe,puanlar_degisim[9]);
								break;
							}
						}
						break;
					}
					else
					{
						system("cls");
					}
				}
				else
				{
					system("cls");
				}	
			}
			}
		}
		else if(secim==4)
		{
			break;
		}
		else
		{
			printf("Yanlis bir secim yaptiniz. Ana menuye donmek icin bir tusa basiniz.");
			getch();
			system("cls");
		}
	}
	printf("Programimizi kullandiginiz icin tesekkur ederiz.");
	return 0;
}
