#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void topara();  //FONKSIYONLAR
void redko();
void bluko();
void greko();
void izmik();
void rez();
void ana();

typedef struct              //SALON VE MATINE YAPISI
{
    char Red[5][50];
    char Green[5][50];
    char Blue[5][50];
}Sinsalon;

int i,j,k; int unvan; int fiat; int hasilat; int sayaciart=0;      //GLOBAL DEGISKENLER

int main()
{
    char sif[50];char oke[50];
    FILE *login,*kayit,*r,*g,*b;
    login = fopen("login.txt", "r");
    r = fopen("kirmiziseat.txt", "r");
    g = fopen("yesilseat.txt", "r");
    b = fopen("maviseat.txt", "r");            //NULL CHECK + ALDIGIM DEGISIK BIR ERROR ICIN ISLEM + LOGIN EKRANI
if (r==NULL)
{
    fclose(r);
    r = fopen("kirmiziseat.txt", "w");
    for(i=0; i<250; i++)
        {
            fputc('0',r);
        }}
if (g==NULL)
{
    fclose(g);
    g = fopen("yesilseat.txt", "w");
    for(i=0; i<250; i++)
        {
            fputc('0',g);
        }}
if (b==NULL)
{
    fclose(b);
    b = fopen("maviseat.txt", "w");
for(i=0; i<250; i++)
        {
            fputc('0',b);
        }}
fclose(r);fclose(g);fclose(b);

if (login==NULL)
    {
        kayit = fopen("login.txt", "w");
        printf("Lutfen sifreyi girin> ");
        scanf("%s",sif);
        fprintf(kayit,"%s",sif);
        ana();
    }
    else
    {
        system("cls");
        printf("Lutfen sifreyi girin> ");
        scanf("%s",oke);
        fscanf(login,"%s",sif);
        if(strcmp(oke,sif)==0)
            ana();
        else
            printf("\nSifre yanlis!!\n");
    }
fclose(login);fclose(kayit);
return 0;
}

void ana()
{
    system("cls");
    char chomenu;
    printf("HFTTF SINEMASINA HOSGELDINIZ!!\n");
    printf("----------------------------------------\n");
    printf("<1> Film rezervasyonu\n");
    printf("<2> Toplam hasilat\n");
    printf("<3> Anlik izleyici sayisi\n");
    printf("<4> Programdan cikis\n");
    printf("\nBir numara girisi yapin> ");
    scanf(" %c",&chomenu);

    switch(chomenu)
    {
    case '1':
        rez();
        break;
    case '2':
        topara();
        break;
    case '3':
        izmik();
        break;
    case '4':
        system("cls");
        printf("<<<<<<<TEKRAR BEKLERIZ>>>>>>>\n");
        break;
    default:
        printf("\nHatali Giris.\n");
        break;
    }
}

void rez()
{
    system("cls");
    char sechall;
    printf("Mevcut sinema salonlari // <1> (RED)  / <2> (GREEN)  / <3> (BLUE)\n");
    printf("\nRezervasyon yaptirmak istediginiz salonun rakamini giriniz> ");
            scanf(" %c",&sechall);
            switch(sechall)
            {
                case '1':
                    redko();
                    break;
                case '2':
                    greko();
                    break;
                case '3':
                    bluko();
                    break;
                default:
                    printf("\nHatali Giris.\n");
                    break;
}}

void topara()
{
    system("cls");
    FILE *para;
    para=fopen("log.txt","r");
    fscanf(para,"%d",&hasilat);
    fclose(para);
    printf("Elde edilen toplam hasilat> %d TRY.\n",hasilat);
    printf("\nAna menuye donmek icin bir tusa basiniz..");
    getch();
    ana();
}

void izmik()
{
    system("cls");
    Sinsalon mum; Sinsalon *pomum; pomum = &mum;
    FILE *kirmizi;
    kirmizi=fopen("kirmiziseat.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            pomum->Red[j][k] = getc(kirmizi);
        }}
    fclose(kirmizi);

    printf("Red salonu anlik izleyici sayisi..\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(pomum->Red[i][j] == '1')
                        sayaciart++;
                }
                printf("\n%d. matine -> %d kisi.",i+1,sayaciart);
                sayaciart=0;
            }
            FILE *yesil;
            yesil=fopen("yesilseat.txt","r");
             for(j=0;j<5;j++)
               {
                  for(k=0;k<50;k++)
                    {
                      pomum->Green[j][k] = getc(yesil);
                    }}
            fclose(yesil);
            printf("\n------------------------------------------");
            printf("\nGreen salonu anlik izleyici sayisi..\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(pomum->Green[i][j] == '1')
                        sayaciart++;
                }
                printf("\n%d. matine -> %d kisi.",i+1,sayaciart);
                sayaciart=0;
            }
            FILE *mavi;
            mavi=fopen("maviseat.txt","r");
            for(j=0;j<5;j++)
             {
               for(k=0;k<50;k++)
                {
                  pomum->Blue[j][k] = getc(mavi);
                }}
            fclose(mavi);

            printf("\n------------------------------------------");
            printf("\nBlue salonu anlik izleyici sayisi..\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(pomum->Blue[i][j] == '1')
                        sayaciart++;
                }
                printf("\n%d. matine -> %d kisi.",i+1,sayaciart);
                sayaciart=0;
            }
            printf("\n\nAna menuye donmek icin bir tusa basiniz..");
            getch();
            ana();
}

void redko()
{
    system("cls");
    Sinsalon mum; Sinsalon *pomum; pomum = &mum;
    FILE *para;
    para=fopen("log.txt","r");
    fscanf(para,"%d",&hasilat);
    fclose(para);
    FILE *kirmizi;
    kirmizi=fopen("kirmiziseat.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            pomum->Red[j][k] = fgetc(kirmizi);
        }}
    fclose(kirmizi);
    printf("Mevcut matine numaralari -> 1 / 2 / 3 / 4 / 5");
    printf("\n\nRezervasyon yapmak istediginiz matine numarasi?\n>");
    scanf("%d",&j);

    for(k=0;k<50;k++)
     {
       if(pomum->Red[j-1][k] == '0')
         {
           pomum->Red[j-1][k] = '1';
           break;
     }}
                    printf("\nOgrenciyseniz '1', degilseniz '2' basiniz.\n>");
                    scanf(" %d",&unvan);
                    if(unvan == 1)
                    {
                        fiat = 20;
                        hasilat+=fiat;
                    }
                    else if(unvan == 2)
                    {
                        fiat = 30;
                        hasilat+=fiat;
                    }
                    para=fopen("log.txt","w+");
                    fprintf(para,"%d",hasilat);
                    fclose(para);

                    printf("\nRed salonunda, %d numarali koltuk icin rezarvasyonunuz yapilmistir..\nUcretiniz %d TRY'dir.\n",k+1,fiat);
                    kirmizi=fopen("kirmiziseat.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(pomum->Red[j][k] == '1')
                            fputc('1',kirmizi);
                            else
                            fputc('0',kirmizi);
                        }}
                    fclose(kirmizi);
                    printf("\nAna menuye donmek icin bir tusa basiniz..");
                    getch();
                    ana();
}

void greko()
{
    system("cls");
    Sinsalon mum; Sinsalon *pomum; pomum = &mum;
    FILE *para;
    para=fopen("log.txt","r");
    fscanf(para,"%d",&hasilat);
    fclose(para);
    FILE *yesil;
    yesil=fopen("yesilseat.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            pomum->Green[j][k] = getc(yesil);
        }}
    fclose(yesil);
    printf("Mevcut matine numaralari -> 1 / 2 / 3 / 4 / 5");
    printf("\n\nRezervasyon yapmak istediginiz matine numarasi?\n>");
    scanf("%d",&j);
                        for(k=0;k<50;k++)
                        {
                            if(pomum->Green[j-1][k] == '0')
                            {
                                pomum->Green[j-1][k] = '1';
                                break;
                            }}
                    printf("\nOgrenciyseniz '1', degilseniz '2' basiniz.\n>");
                    scanf(" %d",&unvan);
                    if(unvan == 1)
                    {
                        fiat = 20;
                        hasilat+=fiat;
                    }
                    else if(unvan == 2)
                    {
                        fiat = 30;
                        hasilat+=fiat;
                    }
                    para=fopen("log.txt","w+");
                    fprintf(para,"%d",hasilat);
                    fclose(para);

                    printf("\nGreen salonunda, %d numarali koltuk icin rezarvasyonunuz yapilmistir..\nUcretiniz %d TRY'dir.\n",k+1,fiat);
                    yesil=fopen("yesilseat.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(pomum->Green[j][k] == '1')
                            fputc('1',yesil);
                        else
                            fputc('0',yesil);
                        }}
                    fclose(yesil);
                    printf("\nAna menuye donmek icin bir tusa basiniz..");
                    getch();
                    ana();
}
void bluko()
{
    system("cls");
    Sinsalon mum; Sinsalon *pomum; pomum = &mum;
    FILE *para;
    para=fopen("log.txt","r");
    fscanf(para,"%d",&hasilat);
    fclose(para);
    FILE *mavi;
    mavi=fopen("maviseat.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            pomum->Blue[j][k] = getc(mavi);
        }}
    fclose(mavi);
    printf("Mevcut matine numaralari -> 1 / 2 / 3 / 4 / 5");
    printf("\n\nRezervasyon yapmak istediginiz matine numarasi?\n>");
    scanf("%d",&j);
                    for(k=0;k<50;k++)
                        {
                            if(pomum->Blue[j-1][k] == '0')
                            {
                                pomum->Blue[j-1][k] = '1';
                                break;
                            }}
                    printf("\nOgrenciyseniz '1', degilseniz '2' basiniz.\n>");
                    scanf(" %d",&unvan);
                    if(unvan == 1)
                    {
                        fiat = 20;
                        hasilat+=fiat;
                    }
                    else if(unvan == 2)
                    {
                        fiat = 30;
                        hasilat+=fiat;
                    }
                    para=fopen("log.txt","w+");
                    fprintf(para,"%d",hasilat);
                    fclose(para);
                    printf("\nBlue salonunda, %d numarali koltuk icin rezarvasyonunuz yapilmistir..\nUcretiniz %d TRY'dir.\n",k+1,fiat);
                    mavi=fopen("maviseat.txt","w+");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(pomum->Blue[j][k] == '1')
                            fputc('1',mavi);
                        else
                            fputc('0',mavi);
                        }}
                    fclose(mavi);
                    printf("\nAna menuye donmek icin bir tusa basiniz..");
                    getch();
                    ana();
}
