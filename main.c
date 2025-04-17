#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define TAILLE 100
#define n1 6
#define n2 9
#define n3 11

void placer_vedette(int a,int n,char b,char tab1[n][n],char tab[n][n]);
void placer_torpille(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
void placer_sous_marin(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
void placer_porte_avion(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
int verify_vedette(int a,int n,char b,char tab[n][n]);
int verify_torpille(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
int verify_sous_marin(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
int verify_porte_avion(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]);
void ecrire_nvlles_valeurs(FILE *f,int n,char tab[n][n]);
void vedette(int n,char tab[n][n],char virt[n][n], int xx, int yy);
void torpille(int n,char tab[n][n],char virt[n][n], int xx, int yy);
void sous_marin(int n,char tab[n][n],char virt[n][n], int xx, int yy);
void porte_avion(int n,char tab[n][n],char virt[n][n], int xx, int yy);
void gotoxy(int xx, int y);
void afficher_grille(int n,char T[n][n]);
void afficher_grille1(int n,char T[n][n]);
void afficher_virtgrille(int n,char T[n][n]);
void afficher_virtgrille1(int n,char T[n][n]);
void attack_niv_facile(char tab1[n1][n1], char tab[n1][n1]);
void attack_IA_niv_facil(char tab1[n1][n1], char tab[n1][n1]);
void menuprincipal();
void menuniv();
void menujeu();


typedef struct{
    char nom[50];
    int nbre_essaies;
}Joueur;

void enregistrement(Joueur J,int a);
void scores(FILE *f, FILE *g, FILE *h);
void aff_menu(int l, int col, char Menu[l][col], int ch);
void suggest();
void aide();

int menu(int a, char menus[a][TAILLE]);

void suggest();
void aide();





 main()
{

    int zer=0, kol;
    int zor=0, kal;
    int zut=0, kil;
    int zik=0, kel;
    char test[25]="";
    char men[TAILLE][TAILLE] ,  mena[TAILLE][TAILLE], meno[TAILLE][TAILLE], mens[TAILLE][TAILLE];
     FILE *f = fopen("Niveau_facile/J1J2/grille1.txt","r+");
    FILE *g = fopen("Niveau_facile/J1J2/grille2.txt","r+");
    FILE *h = fopen("Niveau_facile/J1J2/virtuel1.txt","r+");
    FILE *p = fopen("Niveau_facile/J1J2/virtuel2.txt","r+");
    FILE *f1 = fopen("Niveau_moyen/J1J2/grille1.txt","r+");
    FILE *g1 = fopen("Niveau_moyen/J1J2/grille2.txt","r+");
    FILE *h1 = fopen("Niveau_moyen/J1J2/virtuel1.txt","r+");
    FILE *p1 = fopen("Niveau_moyen/J1J2/virtuel2.txt","r+");
    FILE *f2 = fopen("Niveau_difficile/J1J2/grille1.txt","r+");
    FILE *g2 = fopen("Niveau_difficile/J1J2/grille2.txt","r+");
    FILE *h2 = fopen("Niveau_difficile/J1J2/virtuel1.txt","r+");
    FILE *p2 = fopen("Niveau_difficile/J1J2/virtuel2.txt","r+");
    FILE *fia = fopen("Niveau_facile/J1IA/grille1.txt","r+");
    FILE *gia = fopen("Niveau_facile/J1IA/grille2.txt","r+");
    FILE *hia = fopen("Niveau_facile/J1IA/virtuel1.txt","r+");
    FILE *pia = fopen("Niveau_facile/J1IA/virtuel2.txt","r+");
    FILE *fmia = fopen("Niveau_moyen/J1IA/grille1.txt","r+");
    FILE *gmia = fopen("Niveau_moyen/J1IA/grille2.txt","r+");
    FILE *hmia = fopen("Niveau_moyen/J1IA/virtuel1.txt","r+");
    FILE *pmia = fopen("Niveau_moyen/J1IA/virtuel2.txt","r+");
    FILE *fdia = fopen("Niveau_difficile/J1IA/grille1.txt","r+");
    FILE *gdia = fopen("Niveau_difficile/J1IA/grille2.txt","r+");
    FILE *hdia = fopen("Niveau_difficile/J1IA/virtuel1.txt","r+");
    FILE *pdia = fopen("Niveau_difficile/J1IA/virtuel2.txt","r+");
    FILE *scorf = fopen("scorefacile.txt","r+");
    FILE *scori = fopen("scoremoyen.txt","r+");
    FILE *scord = fopen("scorepro.txt","r+");

    int choix_principal,choix_niveau1,choix_niveau2,choix_jeu;
    int i,j;int n = 6,x = 1;
    char tab[n][n], tab1[n][n], virt[n][n], virt1[n][n];
    char tabmoy[n2][n2], tab1moy[n2][n2], virtmoy[n2][n2], virt1moy[n2][n2];
    char tabdif[n3][n3], tab1dif[n3][n3], virtdif[n3][n3], virt1dif[n3][n3];
    int batiments_places=0;




    strcpy(men[zer++], "    JOUER        ");
    strcpy(men[zer++], "     AIDE        ");
    strcpy(men[zer++], "MEILLEURS SCORES ");
    strcpy(men[zer++], "   SUGGESTIONS   ");
    strcpy(men[zer++], "    QUITTER      ");
    do{
           do{
          system("cls");
          kol= menu(zer,men);
                }while(kol<1 || kol>zer);
                system("pause");
                switch(kol){

            case 1 :
                system("cls");
                zor=0;
                strcpy(mena[zor++], "    1 CONTRE 1    ");
                strcpy(mena[zor++], " JOUER CONTRE L'ORDINATEUR");
                strcpy(mena[zor++], "     QUITTER       ");
                do{
                    do{
             system("cls");
          kal= menu(zor,mena);
                }while(kal<1 || kal>zor);
                system("pause");

                switch(kal){
                    case 1:
                        system("cls");
                        zik=0;
                       // printf("\n \t\t\t  ====< 1 CONTRE 1 >====\n\n");
                        strcpy(mens[zik++], "     DEBUTANT       ");
                        strcpy(mens[zik++], "     AMATEUR        ");
                        strcpy(mens[zik++], "   PROFESSIONNEL   ");
                        strcpy(mens[zik++], "      QUITTER      ");

                         do{
                             do{
                            system("cls");
                        kel= menu(zik,mens);
                   }while(kel<1 || kel>zik);
                    system("pause");
                        switch(kel){

                        case 1:
                            system("cls");
                             if((f==NULL)||(g==NULL)||(h==NULL)||(p==NULL))
                                printf("Erreur d'ouverture");
                              else{
                                  fread(&tab,sizeof(tab),1,f);
                                  fread(&tab1,sizeof(tab1),1,g);
                                  fread(&virt,sizeof(virt),1,h);
                                  fread(&virt1,sizeof(virt1),1,p);
                                  lvl_facile(n1,tab,tab1,virt,virt1);
                                  attack_niv_facile(virt,virt1);
                              }



                        system("pause");
                        break;

                        case 2:
                            system("cls");
                            if((f1==NULL)||(g1==NULL)||(h1==NULL)||(p1==NULL))
                                printf("Erreur d'ouverture");
                              else{
                                  fread(&tabmoy,sizeof(tabmoy),1,f1);
                                  fread(&tab1moy,sizeof(tab1moy),1,g1);
                                  fread(&virtmoy,sizeof(virtmoy),1,h1);
                                  fread(&virt1moy,sizeof(virt1moy),1,p1);
                                  lvl_moyen(n2,tabmoy,tab1moy,virtmoy,virt1moy);
                                  attack_niv_moy(virtmoy,virt1moy);
                              }



                        system("pause");
                        break;

                         case 3:
                            system("cls");
                            if((f2==NULL)||(g2==NULL)||(h2==NULL)||(p2==NULL))
                                printf("Erreur d'ouverture");
                              else{
                                  fread(&tabdif,sizeof(tabdif),1,f2);
                                  fread(&tab1dif,sizeof(tab1dif),1,g2);
                                  fread(&virtdif,sizeof(virtdif),1,h2);
                                  fread(&virt1dif,sizeof(virt1dif),1,p2);
                                  lvl_difficile(n3,tabdif,tab1dif,virtdif,virt1dif);
                                  attack_niv_pro(virtdif,virt1dif);
                              }



                        system("pause");
                        break;


                            }



                         }while(zik!=kel);


                    fclose(f);
                    fclose(g);
                    fclose(h);
                    fclose(p);
                    fclose(scorf);
                    fclose(f1);
                    fclose(g1);
                    fclose(h1);
                    fclose(p1);
                    system("pause");
                    break;

                    case 2:
                        system("cls");
                        zut=0;

                        strcpy(meno[zut++], "     DEBUTANT       ");
                        strcpy(meno[zut++], "     AMATEUR        ");
                        strcpy(meno[zut++], "   PROFESSIONNEL   ");
                        strcpy(meno[zut++], "      QUITTER      ");

                        do{
                             do{
                            system("cls");
                        kil= menu(zut,meno);
                   }while(kil<1 || kil>zut);
                    system("pause");

                        switch(kil){

                        case 1:
                            system("cls");
                  if((fia==NULL)||(gia==NULL)||(hia==NULL)||(pia==NULL))
                                printf("Erreur d'ouverture");
                            else{
                                fread(&tab,sizeof(tab),1,fia);
                                fread(&tab1,sizeof(tab1),1,gia);
                                fread(&virt,sizeof(virt),1,hia);
                                fread(&virt1,sizeof(virt1),1,pia);
                                lvl_facile_ia(n1,tab,tab1,virt,virt1);
                                attack_IA_niv_facile(virt,virt1);
                            }
                         system("pause");
                         break;

                        case 2:
                        system("cls");
                        if((fmia==NULL)||(gmia==NULL)||(hmia==NULL)||(pmia==NULL))
                                printf("Erreur d'ouverture");
                            else{
                                fread(&tabmoy,sizeof(tabmoy),1,fmia);
                                fread(&tab1moy,sizeof(tab1moy),1,gmia);
                                fread(&virtmoy,sizeof(virtmoy),1,hmia);
                                fread(&virt1moy,sizeof(virt1moy),1,pmia);
                                lvl_moyen_ia(n2,tabmoy,tab1moy,virtmoy,virt1moy);
                                attack_IA_niv_moy(virtmoy,virt1moy);
                            }
                        system("pause");
                         break;

                        case 3:
                             system("cls");
                             if((fdia==NULL)||(gdia==NULL)||(hdia==NULL)||(pdia==NULL))
                                printf("Erreur d'ouverture");
                            else{
                                fread(&tabdif,sizeof(tabdif),1,fdia);
                                fread(&tab1dif,sizeof(tab1dif),1,gdia);
                                fread(&virtdif,sizeof(virtdif),1,hdia);
                                fread(&virt1dif,sizeof(virt1dif),1,pdia);
                                lvl_difficile_ia(n3,tabdif,tab1dif,virtdif,virt1dif);
                                attack_IA_niv_pro(virtdif,virt1dif);
                            }
                        system("pause");
                         break;

                        }// Switch mode solitaire



                        }while(zut!=kil);

                        system("pause");
                        break;

                }// Switch JOUER



                }while(kal!=zor);



                system("pause");
                break;

                    case 2:
                       system("cls");
                        printf("\n \t\t\t\t ====<  AIDE  >===\n");
                        aide();


                system("pause");
                break;

                case 3:
                    system("cls");
                        printf("\n \t\t\t\t ====<  MEILLEURS SCORES  >===\n");
                         scores(scorf,scori,scord);


                system("pause");
                 fclose(scorf);
                 fclose(scori);
                 fclose(scord);
                break;


                case 4:
                    system("pause");
                    printf("\n \t\t\t\t ====<  SUGGESTIONS  >===\n");
                    suggest();

                system("pause");
                break;


         } // Grand switch
    }while(zer!=kol);

    system("pause");
    return 0;
}
void aff_menu(int l, int col, char Menu[l][col], int ch){
    int i;
    system("cls");
    //cadre(0,100,1,25);
    printf("\t\t\t\t  ===============================");
    printf("\n\n\t\t\t\t       %c BATAILLE NAVALLE %c              \n\n", 6,6);
    printf("\t\t\t\t  ===============================\n\n\n");
    for(i=0;i<l;i++){
        if(i == ch)
            printf("\n\n\t\t\t\t\t |[ %s ]|\n", Menu[i]);
        else
            printf("\n\n\t\t\t\t\t   %s\n", Menu[i]);
    }
}
int menu(int a, char menus[a][TAILLE]){
    char n;
    int ch = 0;

    do{
        ch%=a;
        aff_menu(a, TAILLE, menus, ch);
        n = getch();
        if(n == 72)
            ch+=(a-1);
        if(n == 80)
            ch++;
    }while(n!=13);
    ch++;
    return ch;
}






void placer_vedette(int a,int n,char b,char tab1[n][n],char tab[n][n]){
    int e; int i;
    e = ((int)b)-64;
    tab1[a][e] = 'a';
    tab[a][e] = 'o';
}

void placer_torpille(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,j;
    e = ((int)b)-64;
    if(r==1)
    {
        tab1[a][e] = 'b';
        printf("%d\n",tab1[a][e]);
        tab1[a][e+1] = 'b';
        printf("%d\n",tab1[a][e+1]);
        tab[a][e] = 'o';
        tab[a][e+1] = 'o';
    }
    if(r==2)
    {
        tab1[a][e] = 'b';
        tab1[a][e-1] = 'b';
        tab[a][e] = 'o';
        tab[a][e-1] = 'o';
    }
    if(r==3)
    {
        tab1[a+1][e] = 'b';
        tab1[a][e] = 'b';
        tab[a+1][e] = 'o';
        tab[a][e] = 'o';
    }
    if(r==4)
    {
        tab1[a][e] = 'b';
        tab1[a-1][e] = 'b';
        tab[a][e] = 'o';
        tab[a-1][e] = 'o';
    }
}

void placer_sous_marin(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,j;
    e = ((int)b)-64;
    if(r==1)
    {
        tab1[a][e] = 'e';
        tab1[a][e+1] = 'e';
        tab1[a][e+2] = 'e';
        tab[a][e] = 'o';
        tab[a][e+1] = 'o';
        tab[a][e+2] = 'o';
    }
    if(r==2)
    {
        tab1[a][e] = 'e';
        tab1[a][e-1] = 'e';
        tab1[a][e-2] = 'e';
        tab[a][e] = 'o';
        tab[a][e-1] = 'o';
        tab[a][e-2] = 'o';
    }
    if(r==3)
    {
        tab1[a+1][e] = 'e';
        tab1[a+2][e] = 'e';
        tab1[a][e] = 'e';
        tab[a+1][e] = 'o';
        tab[a+2][e] = 'o';
        tab[a][e] = 'o';
    }
    if(r==4)
    {
        tab1[a][e] = 'e';
        tab1[a-1][e] = 'e';
        tab1[a-2][e] = 'e';
        tab[a][e] = 'o';
        tab[a-1][e] = 'o';
        tab[a-2][e] = 'o';
    }
}

void placer_porte_avion(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,j;
    e = ((int)b)-64;
    if(r==1)
    {
        tab1[a][e] = 'h';
        tab1[a][e+1] = 'h';
        tab1[a][e+2] = 'h';
        tab1[a][e+3] = 'h';
        tab[a][e] = 'o';
        tab[a][e+1] = 'o';
        tab[a][e+2] = 'o';
        tab[a][e+3] = 'o';
    }
    if(r==2)
    {
        tab1[a][e] = 'h';
        tab1[a][e-1] = 'h';
        tab1[a][e-2] = 'h';
        tab1[a][e-3] = 'h';
        tab[a][e] = 'o';
        tab[a][e-1] = 'o';
        tab[a][e-2] = 'o';
        tab[a][e-3] = 'o';
    }
    if(r==3)
    {
        tab1[a+1][e] = 'h';
        tab1[a+2][e] = 'h';
        tab1[a+3][e] = 'h';
        tab1[a][e] = 'h';
        tab[a+1][e] = 'o';
        tab[a+2][e] = 'o';
        tab[a+3][e] = 'o';
        tab[a][e] = 'o';
    }
    if(r==4)
    {
        tab1[a][e] = 'h';
        tab1[a-1][e] = 'h';
        tab1[a-2][e] = 'h';
        tab1[a-3][e] = 'h';
        tab[a][e] = 'o';
        tab[a-1][e] = 'o';
        tab[a-2][e] = 'o';
        tab[a-3][e] = 'o';
    }
}

int verify_vedette(int a,int n,char b,char tab[n][n]){
    int e,c;
    e = ((int)b)-64;
    if(tab[a][e] == '-')
        c = 1;
    else
        c = 0;

    return c;
}

int verify_torpille(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,c;
    e = ((int)b)-64;
    if(r==1)
    {
        if((tab[a][e]=='-')&&(tab[a][e+1]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==2)
    {
        if((tab[a][e]=='-')&&(tab[a][e-1]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==3)
    {
        if((tab[a][e]=='-')&&(tab[a+1][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==4)
    {
        if((tab[a][e]=='-')&&(tab[a-1][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    return c;
}

int verify_sous_marin(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,c;
    e = ((int)b)-64;
    if(r==1)
    {
        if((tab[a][e]=='-')&&(tab[a][e+1]=='-')&&(tab[a][e+2]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==2)
    {
        if((tab[a][e]=='-')&&(tab[a][e-1]=='-')&&(tab[a][e-2]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==3)
    {
        if((tab[a][e]=='-')&&(tab[a+1][e]=='-')&&(tab[a+2][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==4)
    {
        if((tab[a][e]=='-')&&(tab[a-1][e]=='-')&&(tab[a-2][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    return c;
}

int verify_porte_avion(int a,int n,char b,int r,char tab1[n][n],char tab[n][n]){
    int e,c;
    e = ((int)b)-64;
    if(r==1)
    {
        if((tab[a][e]=='-')&&(tab[a][e+1]=='-')&&(tab[a][e+2]=='-')&&(tab[a][e+3]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==2)
    {
        if((tab[a][e]=='-')&&(tab[a][e-1]=='-')&&(tab[a][e-2]=='-')&&(tab[a][e-3]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==3)
    {
        if((tab[a][e]=='-')&&(tab[a+1][e]=='-')&&(tab[a+2][e]=='-')&&(tab[a+3][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    if(r==4)
    {
        if((tab[a][e]=='-')&&(tab[a-1][e]=='-')&&(tab[a-2][e]=='-')&&(tab[a-3][e]=='-'))
            c = 1;
        else
            c = 0;
    }
    return c;
}

void ecrire_nvlles_valeurs(FILE *f,int n,char tab[n][n]){
    int i,j;
    rewind(f);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fprintf(f,"%c",tab[i][j]);
        }
    }
}

void vedette(int n,char tab[n][n],char virt[n][n], int xx,int yy){
    int a,r,d;
    char b;
do{

        gotoxy(xx,yy+1);
        printf("Entrez l'abscisse de la vedette : ");
        b = getch();
        printf("\t%c",b);
        gotoxy(xx,yy+3);
        printf("Entrez l'ordonee de la vedette  : ");
        scanf("%d",&a);
        //scanf("%c",&b);
        d=verify_vedette(a,n,b,tab);
        printf("%d\n",d);
        if(d==1){
            placer_vedette(a,n,b,virt,tab);
            d=0;
            }
        else{
            printf("Emplacement non disponible.");
            d=1;
        }
 }while(d!=0);
}

void torpille(int n,char tab[n][n],char virt[n][n], int xx, int yy){
    int i,a,r,d=1;
    char b;
do{
        gotoxy(xx,yy);
        printf("Entrez l'abscisse de la torpille : ");
        b=getch();
        printf("\t%c",b);
        gotoxy(xx,yy+1);
        printf("Entrez l'ordonee de la torpille : ");
        scanf("%d",&a);
        gotoxy(xx,yy+2);
        printf("Donner la direction : 1-Droite  2-Gauche  3-Bas  4-Haut");
        scanf("%d",&r);
        d=verify_torpille(a,n,b,r,virt,tab);
        if(d==1){
            placer_torpille(a,n,b,r,virt,tab);
            d=0;
        }
        else{
            printf("Positionnement impossible.");
            d=1;
        }
    }while(d!=0);
}

void sous_marin(int n,char tab[n][n],char virt[n][n], int xx, int yy){
    int i,a,r,d;
    char b;
    do{
        gotoxy(xx,yy);
        printf("Entrez l'abscisse du sous marin : ");
        b=getch();
        printf("\t%c",b);
        gotoxy(xx,yy+1);
        printf("Entrez l'ordonee du sous marin : ");
        scanf("%d",&a);
        gotoxy(xx,yy+2);
        printf("Donner la direction  1-Droite 2-Gauche 3-Bas 4-Haut ");
        scanf("%d",&r);
        d=verify_sous_marin(a,n,b,r,virt,tab);
        if(d==1){
            placer_sous_marin(a,n,b,r,virt,tab);
            d=0;
        }
        else{
            printf("Positionnement impossible.");
            d=1;
        }
    }while(d!=0);
}

void porte_avion(int n,char tab[n][n],char virt[n][n], int xx, int yy){
    int i,a,r,d;
    int line_effac, colonne_effac;
    char b;
    do{
        gotoxy(xx,yy);
        printf("Entrez l'abscisse du porte avion ; ");
        b=getch();
        printf("\t%c",b);
        gotoxy(xx,yy+1);
        printf("Entrez l'ordonee du porte avion : ");
        scanf("%d",&a);
        gotoxy(xx,yy+2);
        printf("Donner la direction : 1-Droite 2-Gauche 3-Bas 4-Haut : ");
        scanf("%d",&r);
        d=verify_porte_avion(a,n,b,r,virt,tab);
        if(d==1){
            placer_porte_avion(a,n,b,r,virt,tab);
            d=0;
        }
        else{
            gotoxy(xx,yy+3);
            printf("Positionnement impossible.");
            d=1;
            /*for(line_effac=xx;line_effac<xx+40;line_effac++){
                for(colonne_effac=yy;colonne_effac<xx+10;colonne_effac++){
                    printf(" ");
                }
            }*/
        }
    }while(d!=0);
}

void gotoxy(int xx, int y){
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X=xx;
    dwCursorPosition.Y=y;
    hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void afficher_grille(int n,char T[n][n]){
    int i,j;

    for(j=0;j<n;j++){
        gotoxy(3*j+2,0);
        printf("%c",T[0][j]);
    }

    for(i=1;i<n;i++){
        gotoxy(0,2*i);
        printf("%2d ",i);
    }

    for(i=1;i<n;i++){
        gotoxy(5,2*i);
        for(j=1;j<n;j++){
            printf("%c  ",T[i][j]);
        }
    }
}

void afficher_grille1(int n,char T[n][n]){
    int i,j;

    for(j=0;j<n;j++){
        gotoxy(3*j+90,0);
        printf("%c",T[0][j]);
    }

    for(i=1;i<n;i++){
        gotoxy(88,2*i);
        printf("%2d ",i);
    }

    for(i=1;i<n;i++){
        gotoxy(93,2*i);
        for(j=1;j<n;j++){
            printf("%c  ",T[i][j]);
        }
    }
}

void afficher_virtgrille(int n,char T[n][n]){
    int i,j;

    for(j=0;j<n;j++){
        gotoxy(3*j+2,23);
        printf("%c",T[0][j]);
    }

    for(i=1;i<n;i++){
        gotoxy(0,2*i+23);
        printf("%2d ",i);
    }

    for(i=1;i<n;i++){
        gotoxy(5,2*i+23);
        for(j=1;j<n;j++){
            printf("%c  ",T[i][j]);
        }
    }
}

void afficher_virtgrille1(int n,char T[n][n]){
    int i,j;

    for(j=0;j<n;j++){
        gotoxy(3*j+90,23);
        printf("%c",T[0][j]);
    }

    for(i=1;i<n;i++){
        gotoxy(88,2*i+23);
        printf("%2d ",i);
    }

    for(i=1;i<n;i++){
        gotoxy(93,2*i+23);
        for(j=1;j<n;j++){
            printf("%c  ",T[i][j]);
        }
    }
}

void lvl_facile(int n,int tab[n][n],int tab1[n][n],int virt[n][n],int virt1){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n1,tab);
            afficher_grille1(n1,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
            if(batiments_places==0){
                gotoxy(1,35);
                vedette(n1,tab,virt,1,13);
                gotoxy(88,35);
                vedette(n1,tab1,virt1,70,13);
            }
            if(batiments_places==1){
                gotoxy(1,35);
                torpille(n1,tab,virt,1,13);
                gotoxy(88,35);
                torpille(n1,tab1,virt1,70,13);
            }
            if(batiments_places==2){
                gotoxy(1,35);
                sous_marin(n1,tab,virt,1,13);
                gotoxy(88,35);
                sous_marin(n1,tab1,virt1,70,13);
            }
            if(batiments_places==3){
                gotoxy(1,35);
                porte_avion(n1,tab,virt,1,13);
                gotoxy(88,35);
                porte_avion(n1,tab1,virt1,70,13);
            }
        }
          system("cls");
            afficher_grille(n1,tab);
            afficher_grille1(n1,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
}

void lvl_facile_ia(int n,int tab[n][n],int tab1[n][n],int virt[n][n],int virt1){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n1,tab);
            afficher_grille1(n1,tab1);
            afficher_virtgrille(n,virt);
            afficher_virtgrille1(n,virt1);
            if(batiments_places==0){
                gotoxy(1,35);
                vedette(n1,tab,virt,1,35);
            }
            if(batiments_places==1){
                gotoxy(1,35);
                torpille(n1,tab,virt,1,35);
            }
            if(batiments_places==2){
                gotoxy(1,35);
                sous_marin(n1,tab,virt,1,35);
            }
            if(batiments_places==3){
                gotoxy(1,35);
                porte_avion(n1,tab,virt,1,35);
            }
        }
        system("cls");
        afficher_grille(n1,tab);
        afficher_grille1(n1,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
}

void lvl_moyen_ia(int n,char tab[n][n],char tab1[n][n],char virt[n][n],char virt1[n][n]){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n2,tab);
            afficher_grille1(n2,tab1);
            //afficher_virtgrille(n2,virt);
            //afficher_virtgrille1(n2,virt1);
            if(batiments_places==0){
                gotoxy(1,13);
                vedette(n2,tab,virt,1,13);
            }
            if(batiments_places==1){
                gotoxy(1,13);
                torpille(n2,tab,virt,1,13);
            }
            if(batiments_places==2){
                gotoxy(1,13);
                sous_marin(n2,tab,virt,1,13);
            }
            if(batiments_places==3){
                gotoxy(1,13);
                porte_avion(n2,tab,virt,1,13);
            }
        }
        system("cls");
        afficher_grille(n2,tab);
        afficher_grille1(n2,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
}

void lvl_difficile_ia(int n,int tab[n][n],int tab1[n][n],int virt[n][n],int virt1){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n,tab);
            afficher_grille1(n,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
            if(batiments_places==0){
                gotoxy(1,13);
                vedette(n,tab,virt,1,13);
            }
            if(batiments_places==1){
                gotoxy(1,13);
                torpille(n,tab,virt,1,13);
            }
            if(batiments_places==2){
                gotoxy(1,13);
                sous_marin(n,tab,virt,1,13);
            }
            if(batiments_places==3){
                gotoxy(1,13);
                porte_avion(n,tab,virt,1,13);
            }
        }
        system("cls");
        afficher_grille(n,tab);
        afficher_grille1(n,tab1);
            //afficher_virtgrille(n,virt);
            //afficher_virtgrille1(n,virt1);
}

void lvl_moyen(int n,int tab[n][n],int tab1[n][n],int virt[n][n],int virt1){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n2,tab);
            afficher_grille1(n2,tab1);
            afficher_virtgrille(n2,virt);
            afficher_virtgrille1(n2,virt1);
            if(batiments_places==0){
                gotoxy(1,13);
                vedette(n2,tab,virt,1,13);
                gotoxy(70,13);
                vedette(n2,tab1,virt1,70,13);
            }
            if(batiments_places==1){
                gotoxy(1,55);
                torpille(n2,tab,virt,1,13);
                gotoxy(88,55);
                torpille(n2,tab1,virt1,70,13);
            }
            if(batiments_places==2){
                gotoxy(1,55);
                sous_marin(n2,tab,virt,1,13);
                gotoxy(88,55);
                sous_marin(n2,tab1,virt1,70,13);
            }
            if(batiments_places==3){
                gotoxy(1,13);
                porte_avion(n2,tab,virt,1,13);
                gotoxy(70,13);
                porte_avion(n2,tab1,virt1,70,13);
            }
        }
        system("cls");
        afficher_grille(n2,tab);
        afficher_grille1(n2,tab1);
        //afficher_virtgrille(n,virt);
        //afficher_virtgrille1(n,virt1);
}

void lvl_difficile(int n,int tab[n][n],int tab1[n][n],int virt[n][n],int virt1){
        int batiments_places;
        for(batiments_places=0;batiments_places<4;batiments_places++){
            system("cls");
            afficher_grille(n3,tab);
            afficher_grille1(n3,tab1);
            //afficher_virtgrille(n3,virt);
            //afficher_virtgrille1(n3,virt1);
            if(batiments_places==0){
                gotoxy(1,55);
                vedette(n3,tab,virt,1,13);
                gotoxy(88,55);
                vedette(n3,tab1,virt1,70,13);
            }
            if(batiments_places==1){
                gotoxy(1,55);
                torpille(n3,tab,virt,1,13);
                gotoxy(88,55);
                torpille(n3,tab1,virt1,70,13);
            }
            if(batiments_places==2){
                gotoxy(1,55);
                sous_marin(n3,tab,virt,1,13);
                gotoxy(88,55);
                sous_marin(n3,tab1,virt1,70,13);
            }
            if(batiments_places==3){
                gotoxy(1,55);
                porte_avion(n3,tab,virt,1,13);
                gotoxy(88,55);
                porte_avion(n3,tab1,virt1,70,13);
            }
        }
        system("cls");
        afficher_grille(n3,tab);
        afficher_grille1(n3,tab1);
        //afficher_virtgrille(n,virt);
        //afficher_virtgrille1(n,virt1);
}





void enregistrements(Joueur J,int a, int niveau){
    FILE *f = fopen("scorefacile.txt","a+");
    FILE *g = fopen("scoremoyen.txt","a+");
    FILE *h = fopen("scorepro.txt","a+");
    if(f==NULL||g==NULL||h==NULL)
        printf("Erreur.");
    else{
        printf("Entrez votre nom : ");
        scanf("%s",&J.nom);
        J.nbre_essaies = a;
        if(niveau==1){
            fwrite(&J,sizeof(J),1,f);
        }
        if(niveau==2){
            fwrite(&J,sizeof(J),1,g);
        }
        if(niveau==3){
            fwrite(&J,sizeof(J),1,h);
        }
    }
}

void scores(FILE *f, FILE *g, FILE *h){
    Joueur J;
    if(f==NULL||g==NULL||h==NULL)
        printf("Erreur . ");
    else
    {
        printf("NIVEAU: FACILE\n\nNOM\t\tNOMBRE D'ESSAIES\n\n");
        while((!feof(f))&&(fread(&J,sizeof(J),1,f)))
        {
            printf("%15s\t\t\t%d\n",J.nom,J.nbre_essaies);

        }
        printf("NIVEAU: INTERMEDIAIRE\n\nNOM\t\tNOMBRE D'ESSAIES\n\n");
        while((!feof(g))&&(fread(&J,sizeof(J),1,g))){
            printf("%15s\t\t\t%d\n",J.nom,J.nbre_essaies);
        }
        printf("NIVEAU: DIFFICILE\n\nNOM\t\tNOMBRE D'ESSAIES\n\n");
        while((!feof(h))&&(fread(&J,sizeof(J),1,h))){
            printf("%15s\t\t\t%d\n",J.nom,J.nbre_essaies);
        }
    }
}

void attack_niv_moy(char tab1[n2][n2], char tab[n2][n2]){
      FILE *h1;
      FILE *p1;
      int niveau_jeu=2;
      int ligne, colonne;
      char attaquej1[n2][n2], attaquej2[n2][n2];
      int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0;
      int comp1=2, comp2=2, coup1=0, coup2=0;
      int suite;
      Joueur J1,J2;
      int touchcol1=0, touchcol2=0;
      int j1=0,j2=0,j3=0,j4=0;
      int t1=0,t2=0,t3=0,t4=0;
      int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
      char cod, y1;
    for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
      }
      for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaquej2[ligne][colonne]='-';
            else
                attaquej2[ligne][colonne]=tab[ligne][colonne];
        }
      }
            do{

                for(k=0;k<2;k++){
                    u=0;

                        do{
                        system("cls");
                        afficher_grille(n2,attaquej1);
                        afficher_grille1(n2,attaquej2);
                        system("pause");
                   if(k==0){
                        printf("\n 1 Entrer les coordonnees d'attaque\n");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a = (int)cod - 64;
                        attaquej2[b][a]='x';

                       // printf(" %d     %d", b,a);

                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n2;i++){

                for(j=1;j<n2;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            j1++;
            touchcol1++;
            u++;
                system("pause");


        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");

                u++;
                //x++;
            }

        }
       /* if(x!=0)
        {
            printf("Touche");
        }
        if(y!=0)
        {
            printf("Touche et coulee");
        }*/
        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }


            }// fin joueur 1


                    if(k==1){

			 printf("\n JOUEUR 2  Entrer les coordonnees d'attaque\n" );

                         scanf("%s %d" , &cod, &b);

                         coup2++;

			 printf("\n JOUEUR 2  Entrer les coordonnes d'attaque\n" );


                        a= (int)cod - 64;

                        attaquej1[b][a]='x';



// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }





        }
        if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
            printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 1 \n");
            enregistrements( J1, coup1, niveau_jeu);
            system("pause");
            comp2=0;
            w=3;
            k=5;
        }
        if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 2 \n");
                        enregistrements( J2, coup2, niveau_jeu);
                        system("pause");
                        w=3;
                        comp1=0;
                         k=5;

                         }



                        }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));

                    if(w==3){
                        k=3;
                    }
                    else{
                        //ecrire_nvlles_valeurs(h1,n2,tab1);
                        //ecrire_nvlles_valeurs(p1,n2,tab);
                    }

                        }

                        }while((comp1!=0)&&(comp2!=0));

                        }

void attack_IA_niv_facile(char tab1[n1][n1], char tab[n1][n1]){
      FILE *h;
      FILE *pf;
      int niveau_jeu=1;
      char attaquej1[n1][n1], attaqueia[n1][n1];
      int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0, coup1=0, coup2=0;
      int ligne,colonne;
      Joueur J1;
      int comp1=2, comp2=2;
      int suite;
      int touchcol1=0, touchcol2=0;
      int j1=0,j2=0,j3=0,j4=0;
      int t1=0,t2=0,t3=0,t4=0;
      int ram=0, rom=0;
      const int max=5, min=1;
      int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
      char cod, y1;

      for(ligne=0;ligne<n1;ligne++){
        for(colonne=0;colonne<n1;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
      }
      for(ligne=0;ligne<n1;ligne++){
        for(colonne=0;colonne<n1;colonne++){
            if(ligne>0&&colonne>0)
                attaqueia[ligne][colonne]='-';
            else
                attaqueia[ligne][colonne]=tab1[ligne][colonne];
        }
      }
    do{

                for(k=0;k<2;k++){
                    u=0;
                        do{
                            system("cls");
                            afficher_grille(n1,attaquej1);
                            afficher_grille1(n1,attaqueia);
                    if(k==0){
                        printf("\n Joueur 1 Entrer les coordonnes d'attaque\n");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a= (int)cod - 64;
                        attaqueia[b][a]='x';
                       // printf(" %d     %d", b,a);

                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n1;i++){

                for(j=1;j<n1;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            system("pause");
            j1++;
            touchcol1++;
            u++;
                system("pause");



        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                   system("pause");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                   system("pause");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                   system("pause");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                   system("pause");

                u++;
                //x++;
            }

        }
       /* if(x!=0)
        {
            printf("Touche");
        }
        if(y!=0)
        {
            printf("Touche et coulee");
        }*/
        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                   system("pause");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                   system("pause");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                   system("pause");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                   system("pause");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                j4++;
                touchcol1++;
                u++;
 }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                   system("pause");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                           system("pause");
                        w++;


                   }


            }// fin joueur 1
                    if(k==1){
                        ram = rand()%(max-min+1)+1;
                        rom = rand()%(max-min+1)+1;
                        printf(" \n %d  %d", ram,rom);
                        if(touchcol2==1){
                            do{
                                ram = rand()%(max-min+1)+1;
                                rom = rand()%(max-min+1)+1;
                            }while(ram==rom);
                        }
                        b=ram; a=rom;
                        attaquej1[b][a]='x';

// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
               system("pause");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                   system("pause");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
                  system("pause");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
                  system("pause");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                   system("pause");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                   system("pause");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                   system("pause");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                   system("pause");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                    system("pause");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                   system("pause");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau\n");
                           system("pause");
                        w++;


                   }

                    // Condition de fin du match ****à arranger



        }
                    if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
                        printf("\n\n FIN DU MATCH: VOUS AVEZ GAGNE \n");
                        enregistrements(J1, coup1, niveau_jeu);
                        system("pause");
                        comp2=0;
                        w=3;
                        k=5;
                        }
                    if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VOUS AVEZ PERDU \n");
                        system("pause");
                        w=3;
                        comp1=0;
                        k=5;
                    }



                        }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));

                    if(w==3){
                        k=3;
                    }
                        }
                        }while((comp1!=0)&&(comp2!=0));

}

void attack_niv_facile(char tab1[n1][n1], char tab[n1][n1]){
      FILE *h;
      FILE *pf;
      int niveau_jeu=1;
      char attaquej1[n1][n1], attaquej2[n1][n1];
      int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0;
      int comp1=2, comp2=2, coup1=0, coup2=0;
      int suite;
      Joueur J1,J2;
      int touchcol1=0, touchcol2=0;
      int ligne,colonne;
      int j1=0,j2=0,j3=0,j4=0;
      int t1=0,t2=0,t3=0,t4=0;
      int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
      char cod, y1;
      for(ligne=0;ligne<n1;ligne++){
        for(colonne=0;colonne<n1;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
      }
      for(ligne=0;ligne<n1;ligne++){
        for(colonne=0;colonne<n1;colonne++){
            if(ligne>0&&colonne>0)
                attaquej2[ligne][colonne]='-';
            else
                attaquej2[ligne][colonne]=tab[ligne][colonne];
        }
      }
      do{
            for(k=0;k<2;k++){
                u=0;
                do{
                    system("cls");
                    afficher_grille(n1,attaquej1);
                    afficher_grille1(n1,attaquej2);
                    system("pause");
                    if(k==0){
                        printf("\n Joueur 1: Entrer les coordonnees d'attaque : ");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a= (int)cod - 64;
                        attaquej2[b][a]='x';
                       // printf(" %d     %d", b,a);
                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n1;i++){

                for(j=1;j<n1;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            j1++;
            touchcol1++;
            u++;
                system("pause");


        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");

                u++;
                //x++;
            }

        }
       /* if(x!=0)
        {
            printf("Touche");
        }
        if(y!=0)
        {
            printf("Touche et coulee");
        }*/
        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }


            }// fin joueur 1
                    if(k==1){

			 printf("\n JOUEUR 2  Entrer les coordonnees d'attaque\n" );

                         scanf("%s %d" , &cod, &b);

                         coup2++;

			 //printf("\n JOUEUR 2  Entrer les coordonnes d'attaque\n" );


                        a= (int)cod - 64;
                        attaquej1[b][a]='x';
// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }





        }
                    if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 1 \n");
                        enregistrements( J1, coup1, niveau_jeu);
                        system("pause");
                        comp2=0;
                        w=3;
                        k=5;
                        }
                    if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 2 \n");
                        enregistrements( J2, coup2, niveau_jeu);
                        system("pause");
                        w=3;
                        comp1=0;
                        k=5;
                    }

                }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));
                if(w==3){
                    k=3;
                }
                else{

                }
            }
      }while((comp1!=0)&&(comp2!=0));
}

void attack_niv_pro(char tab1[n3][n3], char tab[n3][n3]){
      FILE *h2;
      FILE *p2;
      int niveau_jeu=3;
      char attaquej1[n3][n3], attaquej2[n3][n3];
      int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0;
      int comp1=2, comp2=2, coup1=0, coup2=0;
      int suite;
      Joueur J1,J2;
      int ligne, colonne;
      int touchcol1=0, touchcol2=0;
      int j1=0,j2=0,j3=0,j4=0;
      int t1=0,t2=0,t3=0,t4=0;
      int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
      char cod, y1;
      for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
      }
      for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaquej2[ligne][colonne]='-';
            else
                attaquej2[ligne][colonne]=tab[ligne][colonne];
        }
      }

        do{

            for(k=0;k<2;k++){
                u=0;
                do{
                    system("cls");
                    afficher_grille(n2,attaquej1);
                    afficher_grille1(n2,attaquej2);
                    system("pause");
                   if(k==0){
                        printf("\n JOUEUR 1 Entrer les coordonnees d'attaque\n");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a= (int)cod - 64;
                        attaquej2[b][a]='x';
                       // printf(" %d     %d", b,a);

                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n1;i++){

                for(j=1;j<n1;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            j1++;
            touchcol1++;
            u++;
                system("pause");


        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");

                u++;
                //x++;
            }

        }

        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }


            }// fin joueur 1


                    if(k==1){

			 printf("\n JOUEUR 2  Entrer les coordonnees d'attaque\n" );

                         scanf("%s %d" , &cod, &b);

                         coup2++;

			 printf("\n JOUEUR 2  Entrer les coordonnes d'attaque\n" );


                        a= (int)cod - 64;
                        attaquej1[b][a]='x';


// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }





        }
          if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 1 \n");
			enregistrements( J1, coup1, niveau_jeu);
                        system("pause");
                        comp2=0;
                        w=3;
                        k=5;
                        }
                         if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 2 \n");
                        enregistrements( J2, coup2, niveau_jeu);
                        system("pause");
                        w=3;
                        comp1=0;
                         k=5;

                         }



                        }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));

                    if(w==3){
                            k=3;

                    }
                    else{
                    ecrire_nvlles_valeurs(h2,n2,tab1);
                    ecrire_nvlles_valeurs(p2,n2,tab);
                    }
                }
            }while((comp1!=0)&&(comp2!=0));

}

void attack_IA_niv_moy(char tab1[n2][n2], char tab[n2][n2]){
      FILE *h;
      FILE *pf;
      int niveau_jeu=2;
      char attaquej1[n2][n2], attaqueia[n2][n2];
      int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0, coup1=0, coup2=0;
      int ligne,colonne;
      Joueur J1;
      int comp1=2, comp2=2;
      int suite;
      int touchcol1=0, touchcol2=0;
      int j1=0,j2=0,j3=0,j4=0;
      int t1=0,t2=0,t3=0,t4=0;
      int ram=0, rom=0;
      const int max=8, min=1;
      int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
      char cod, y1;
        for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
      }
      for(ligne=0;ligne<n2;ligne++){
        for(colonne=0;colonne<n2;colonne++){
            if(ligne>0&&colonne>0)
                attaqueia[ligne][colonne]='-';
            else
                attaqueia[ligne][colonne]=tab1[ligne][colonne];
        }
      }
        do{

                for(k=0;k<2;k++){
                    u=0;
                    do{
                    if(k==0){
                        printf("\n Joueur 1 Entrer les coordonnes d'attaque\n");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a= (int)cod - 64;
                        attaqueia[b][a]='x';
                       // printf(" %d     %d", b,a);

                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n2;i++){

                for(j=1;j<n2;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            j1++;
            touchcol1++;
            u++;
                system("pause");


        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");

                u++;
                //x++;
            }

        }
       /* if(x!=0)
        {
            printf("Touche");
        }
        if(y!=0)
        {
            printf("Touche et coulee");
        }*/
        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
 }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }


            }// fin joueur 1
                    if(k==1){
                        ram = rand()%(max-min+1)+1;
                        rom = rand()%(max-min+1)+1;
                        printf(" \n %d  %d", ram,rom);
                        if(touchcol2==1){
                            do{
                                ram = rand()%(max-min+1)+1;
                                rom = rand()%(max-min+1)+1;
                            }while(ram==rom);
                        }
                        b=ram; a=rom;
                        attaquej1[b][a]='x';
// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n2;i++){
                for(j=1;j<n2;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau\n");
                        w++;


                   }

                    // Condition de fin du match ****à arranger



        }
                    if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
                        printf("\n\n FIN DU MATCH: VOUS AVEZ GAGNE \n");
                        enregistrements(J1, coup1, niveau_jeu);
                        system("pause");
                        comp2=0;
                        w=3;
                        k=5;
                        }
                         if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VOUS AVEZ PERDU \n");
                        system("pause");
                        w=3;
                         comp1=0;
                         k=5;

                         }



                        }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));

                    if(w==3){
                            k=3;

                    }

                        }




                        }while((comp1!=0)&&(comp2!=0));

                        }

void attack_IA_niv_pro(char tab1[n3][n3], char tab[n3][n3]){
    FILE *h;
    FILE *pf;
    char attaquej1[n3][n3], attaqueia[n3][n3];
    int a,b,k,c,u=0,i,j,p=0, x=0, y=0,d=0,w=0,l=0, coup1=0, coup2=0;
    int comp1=2, comp2=2;
    int suite;
    int niveau_jeu=3;
    int ligne,colonne;
    int touchcol1=0, touchcol2=0;
    int j1=0,j2=0,j3=0,j4=0;
    int t1=0,t2=0,t3=0,t4=0;
    int ram=0, rom=0;
    Joueur J1;
    const int max=10, min=1;
    int z2=1, z3=1, z4=1,z5=0, B[1], C[1], D[1],E[1],F[1],G[1];
    char cod, y1;

    for(ligne=0;ligne<n3;ligne++){
        for(colonne=0;colonne<n3;colonne++){
            if(ligne>0&&colonne>0)
                attaquej1[ligne][colonne]='-';
            else
                attaquej1[ligne][colonne]=tab1[ligne][colonne];
        }
    }
    for(ligne=0;ligne<n3;ligne++){
        for(colonne=0;colonne<n3;colonne++){
            if(ligne>0&&colonne>0)
                attaqueia[ligne][colonne]='-';
            else
                attaqueia[ligne][colonne]=tab1[ligne][colonne];
        }
    }
    do{

                for(k=0;k<2;k++){
                    u=0;
                        do{
                            system("cls");
                            afficher_grille(n3,attaquej1);
                            afficher_grille1(n3,attaqueia);
                   if(k==0){
                        printf("\n Joueur 1 Entrer les coordonnes d'attaque\n");
                        coup1++;
                        scanf("%s %d" , &cod, &b);
                        a= (int)cod - 64;
                        attaqueia[b][a]='x';
                       // printf(" %d     %d", b,a);

                        cod= 'a';

// vedette
      if ((tab[b][a]== cod)||(tab[b][a]=='A'))
    {

            y1=tab[b][a];

            tab[b][a]='A';
            for(i=1;i<n3;i++){

                for(j=1;j<n3;j++){

                    if(tab[i][j]==y1){

                        z5++;

                                    }
                    else
                        z5=0;
                }

            }
            printf("TOUCHE COULE\n");
            j1++;
            touchcol1++;
            u++;
                system("pause");


        }

       /* else*/
            if ((tab[b][a]!= cod)&&(tab[b][a]!='A'))
                u=0;



   // torpille

                if ((tab[b][a]=='b')||(tab[b][a]=='c')||(tab[b][a]=='d')||(tab[b][a]=='B')||(tab[b][a]=='C')||(tab[b][a]=='D'))
    {
        y1=tab[b][a];

        if(tab[b][a]=='b')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='B';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[0]=d;
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;

            }
            else{
                printf("TOUCHE \n");
                u++;
                //x++;

            }

        }
         if(tab[b][a]=='c')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='C';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }


            }
            B[1]=d;
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                touchcol1++;
                u++;
                //y++;
            }
            else{

                printf("TOUCHE");
                u++;
                //x++;
            }

        }
         if(tab[b][a]=='d')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='D';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }
                }
            }
            B[2]=d;
            if(B[2]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='B')
        {
            if(B[0]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE\n");
                u++;
                //x++;

            }

        }
        if(y1=='C')
        {
            if(B[1]==0){
                printf("TOUCHE COULE\n");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");
                u++;
                //x++;
            }

        }
        if(y1=='D')
        {
            if(B[2]==0){
                printf("TOUCHE COULE");
                j2++;
                 touchcol1++;
                u++;
                //y++;
            }
            else{
                printf("TOUCHE");

                u++;
                //x++;
            }

        }
       /* if(x!=0)
        {
            printf("Touche");
        }
        if(y!=0)
        {
            printf("Touche et coulee");
        }*/
        }



              if ((tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D'))
                u=0;


        //sous marin
        if ((tab[b][a]=='e')||(tab[b][a]=='f')||(tab[b][a]=='E')||(tab[b][a]=='F')) //Sous-marins
    {
        y1=tab[b][a];

        if(tab[b][a]=='e')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='E';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }

            }
            C[0]=d;
            if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='f')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='F';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

                }
            }
            C[1]=d;
            if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");

                u++;
            }

        }
        if(y1=='E')
        {
           if(C[0]==0){
                printf("TOUCHE COULE\n");
                j3++;
                touchcol1++;
                u++;
           }
            else{
                printf("Touche");
                u++;
            }
        }
        if(y1=='F')
        {
           if(C[1]==0){
                printf("TOUCHE COULE\n");
                j3++;
                 touchcol1++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }



           if ((tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F'))
                u=0;


        // porte avion
        if ((tab[b][a]=='i')||(tab[b][a]=='h')||(tab[b][a]=='I')||(tab[b][a]=='H')) //Porte avion
    {
        y1=tab[b][a];

        if(tab[b][a]=='h')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='H';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;

                    }

                }
            }
            D[0]=d;
            if(D[0]==0){
                printf("TOUCHE COULE \n");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab[b][a]=='i')
        {
            d=0;
            y1=tab[b][a];
            tab[b][a]='I';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab[i][j]==y1){
                        d++;
                    }

            }
            }
            D[1]=d;
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
 }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='I')
        {
            if(D[1]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE");
                u++;
            }
        }
        if(y1=='H')
        {
            if(D[0]==0){
                printf("TOUCHE COULE\n ");
                j4++;
                touchcol1++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }


            if ((tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H'))
                u=0;





            comp1 = z5;
              for(i=0; i<z2; i++){
                    comp1+= B[i];
                }
                for(i=0; i<z3; i++){
                    comp1+= C[i];
                }
                for(i=0; i<z4; i++){
                    comp1+= D[i];
                }


                w=0;
                 if((tab[b][a]!= cod)&&(tab[b][a]!='A')&&(tab[b][a]!='i')&&(tab[b][a]!='h')&&(tab[b][a]!='I')&&(tab[b][a]!='H')&&(tab[b][a]!='e')&&(tab[b][a]!='f')&&(tab[b][a]!='E')&&(tab[b][a]!='F')&&(tab[b][a]!='b')&&(tab[b][a]!='c')&&(tab[b][a]!='d')&&(tab[b][a]!='B')&&(tab[b][a]!='C')&&(tab[b][a]!='D')){
                        printf("A l eau");
                        w++;


                   }


            }// fin joueur 1


                    if(k==1){
                        ram = rand()%(max-min+1)+1;
                        rom = rand()%(max-min+1)+1;
                        printf(" \n %d  %d", ram,rom);
                        if(touchcol2==1){
                            do{
                                ram = rand()%(max-min+1)+1;
                                rom = rand()%(max-min+1)+1;
                            }while(ram==rom);
                        }
                        b=ram; a=rom;
                        attaquej1[b][a]='x';

// vedette
      if ((tab1[b][a]=='a')||(tab1[b][a]=='A'))
    {
            y1=tab1[b][a];
            tab1[b][a]='A';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab1[i][j]==y1){
                        l++;

                    }
                    else
                        l=0;

                }

            }
            printf("TOUCHE COULE\n ");
            t1++;
                touchcol2++;
            u++;
                //system("pause");


        }

            if ((tab1[b][a]!= cod)&&(tab1[b][a]!='A'))
                u=0;

   // torpille

                if ((tab1[b][a]=='b')||(tab1[b][a]=='c')||(tab1[b][a]=='d')||(tab1[b][a]=='B')||(tab1[b][a]=='C')||(tab1[b][a]=='D'))
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='b')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='B';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

            }
            }
            E[0]=d;
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n ");
                u++;
            }

        }
         if(tab1[b][a]=='c')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='C';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab1[i][j]=='y1'){
                        d++;
                    }

                }

        }
            E[1]=d;
            if(E[1]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='d')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='D';
            for(i=1;i<n3;i++){
                for(j=1;j<n3;j++){
                    if(tab1[i][j]==y1){
                        d++;

                    }

                }

            }
            E[2]=d;
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='B')
        {
            if(E[0]==0){
                printf("TOUCHE COULE\n ");
                t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        if(y1=='C')
        {
            if(E[1]==0){
               printf("TOUCHE COULE\n ");
               t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='D')
        {
            if(E[2]==0){
                 printf("TOUCHE COULE\n ");
                 t2++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
        }
        if ((tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D'))
                u=0;

        //sous marin
        if ((tab1[b][a]=='e')||(tab1[b][a]=='f')||(tab1[b][a]=='E')||(tab1[b][a]=='F')) //Sous-marins
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='e')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='E';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            F[0]=d;
            if(F[0]==0){
               printf("TOUCHE COULE\n ");
               t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE\n");
                u++;
            }

        }
         if(tab1[b][a]=='f')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='F';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            F[1]=d;
            if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
        if(y1=='E')
        {
           if(F[0]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='F')
        {
           if(F[1]==0){
                 printf("TOUCHE COULE\n ");
                 t3++;
                touchcol2++;
                u++;
           }
            else{
                printf("TOUCHE \n");
            }
        }

        }

               if ((tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F'))
                u=0;



        // porte avion
        if ((tab1[b][a]=='i')||(tab1[b][a]=='h')||(tab1[b][a]=='I')||(tab1[b][a]=='H')) //Porte avion
    {
        y1=tab1[b][a];

        if(tab1[b][a]=='h')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='H';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }
            }
            G[0]=d;
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }

        }
         if(tab1[b][a]=='i')
        {
            d=0;
            y1=tab1[b][a];
            tab1[b][a]='I';
            for(i=1;i<n1;i++){
                for(j=1;j<n1;j++){
                    if(tab1[i][j]==y1){
                        d++;
                    }

                }


            }
            G[1]=d;
            if(G[1]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n ");
                u++;
            }

        }
        if(y1=='I')
        {
            if(G[1]==0){
                printf("TOUCHE COULE\n ");
                t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }
        if(y1=='H')
        {
            if(G[0]==0){
                 printf("TOUCHE COULE\n ");
                 t4++;
                touchcol2++;
                u++;
            }
            else{
                printf("TOUCHE \n");
                u++;
            }
        }

        }

            if ((tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H'))
                u=0;







            comp2 = l;
              for(i=0; i<z2; i++){
                    comp2+= E[i];
                }
                for(i=0; i<z3; i++){
                    comp2+= F[i];
                }
                for(i=0; i<z4; i++){
                    comp2+= G[i];
                }


                w=0;
                 if((tab1[b][a]!= cod)&&(tab1[b][a]!='A')&&(tab1[b][a]!='i')&&(tab1[b][a]!='h')&&(tab1[b][a]!='I')&&(tab1[b][a]!='H')&&(tab1[b][a]!='e')&&(tab1[b][a]!='f')&&(tab1[b][a]!='E')&&(tab1[b][a]!='F')&&(tab1[b][a]!='b')&&(tab1[b][a]!='c')&&(tab1[b][a]!='d')&&(tab1[b][a]!='B')&&(tab1[b][a]!='C')&&(tab1[b][a]!='D')){
                        printf("A l eau\n");
                        w++;


                   }

                    // Condition de fin du match ****à arranger



        }
          if((j1>0)&&(j2>0)&&(j3>0)&&(j4>0)){
                        printf("\n\n FIN DU MATCH: VICTOIRE DU JOUEUR 1 \n");
                        enregistrements(J1, coup1, niveau_jeu);
                        system("pause");
                        comp2=0;
                        w=3;
                        k=5;
                        }
                         if((t1>0)&&(t2>0)&&(t3>0)&&(t4>0)){
                        printf("\n\n FIN DU MATCH: VOUS AVEZ PERDU \n");
                        system("pause");
                        w=3;
                         comp1=0;
                         k=5;

                         }



                        }while( (w==0) && (((j1==0)||(j2==0)||(j3==0)||(j4==0))&&((t1==0)||(t2==0)|| (t3==0)|| (t4==0))));

                    if(w==3){
                            k=3;

                    }

                        }




            }while((comp1!=0)&&(comp2!=0));

}
void suggest(){
    FILE* f;
    f=fopen("suggestions.txt", "r");
    if(f==NULL){
        printf("\n PROBLEME D'OUVERTURE\n");
    }
    else{
        system("cls");
        printf("\n Dans le fichier texte suivant, Veuillez enregistrer des idees pour ameliorer le jeu\n");
        system("pause");
        system("start suggestions.txt");

    }
    fclose(f);

}
void aide(){
    system("pause");
    printf("\n \t\t\t\t\t====< AIDE >===\n\n");
    printf("\n La Bataille navale oppose 2 joueurs chacun disposant d'une flotte composee de :\n -Une vedette (1 case); \n -Un torpilleur (2 case); \n -Un sous-marin (3 case); \n -Un porte avion (4 case); \n LES REGLES: \n-Le joueur qui a la manche la garde apres un TOUCHE ou TOUCHE COULE \n-Ce dernier la perd dans le cas d'un echec (A l'eau)\n-La partie prend fin lorsqu'un des joueurs a coule la flotte entiere de son adversaire \n ");


}



