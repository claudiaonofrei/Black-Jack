
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include <ctime>

using namespace std;
int vec[15],manaJucatorului[10],manaDealerului[10],modul=0,punctajManaJucator=0,punctajManaDealer=0,numarCartiJucator=0,numarCartiDealer=0,alege=0,punctajJucator1=0,punctajJucator2=0;
int pachetCarti[14],manaJucator1[10],manaJucator2[10],nrCartiJucator1=0,nrCartiJucator2=0,tasta=0;
char alegere,nume[15],nume1[15];

int modulJocului()
{
    int modul=0,punctajManaDealer=punctajManaJucator=0;
    if(modul!=1||modul!=2)
    {
        cout<<"Alegeti modul in care doriti sa jucati! \n";
        cout<<"1.Jucator vs. Calculator \n";
        cout<<"2.Jucator 1 vs. Jucator 2 \n";
        cout<<"3.EXIT \n";
        cin>>modul;
        if(modul==1)
        {
            cout<<"Ati ales varianta Jucator vs. Calculator"<<endl;
            cout<<"Nume Jucator:";
            cin>>nume;
        }
        if(modul==2)
        {
            cout<<"Ati ales varianta Jucator 1 vs. Jucator 2"<<endl;
            cout<<"Nume Jucator 1:";
            cin>>nume;
            cout<<"Nume Jucator 2:";
            cin>>nume1;
        }
        if(modul==3)
            exit (0);
    }
        else
            cout<<"Ati tastat o valoare gresita! Va rog sa alegeti din nou! \n";

    return modul;
}

void cineCastiga(int punctajManaJucator, int punctajManaDealer)
{
    if(punctajManaJucator>21)
    {
        cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl;
        cout<<"Ai pierdut. Mai incearca o data"<<endl;
    }
    else
        if(punctajManaJucator==punctajManaDealer)
    {
        cout<<"Este egalitate!!";
    }
    else
        if(punctajManaJucator>punctajManaDealer&&punctajManaJucator<21)
    {
        cout<<"Felicitari!! Erai atat de aproape de 21, dar totusi ai reusit!";
    }
    else
        if(punctajManaJucator==21)
        {
            cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl;
            cout<<"Felicitari!! Ai castigat!"<<endl;
        }
    else cout<<"Computerul a castigat!! Imi pare rau. Mai incearca o data!";
}

int valoareaCartilor(int carte)
{
   int valoare=0;
   switch(carte)
   {
   case 1:
    {valoare=11;}break;
   case 11:
   case 12:
   case 13:
    {valoare=10;}break;
   default:
    {valoare=carte;};
   }
    return valoare;
}

void afiseazaCartea(int carti)
{
    switch(carti)
    {
    case 1:
        {cout<<'A';}break;
    case 11:
        {cout<<'J';}break;
    case 12:
        {cout<<'Q';}break;
    case 13:
        {cout<<'K';}break;
    default:
        {cout<<carti;}
    }
}

void arataMana(int mana[],int nrcarti)
{
    int i=0,cealaltaCarte=0;
    for(i=0;i<nrcarti;i++)
    {
        cealaltaCarte=mana[i];
        afiseazaCartea(cealaltaCarte);
        cout<<" ";
    }
    cout<<endl;
}

int carteaUrmatoare(int pachetCarti[])
{
    int cartenoua=0,ok=1;
    while(ok==1)
    {
        cartenoua=rand()%13+1;
        if(pachetCarti[cartenoua]<4)
        {
            pachetCarti[cartenoua]++;
            ok=0;
        }
    }
    return cartenoua;
}

void afisareMeniu()
{
    system("cls");
    cout<< "___________________________" <<endl;
    cout<< "|*|*|*|*|*|*|*|*|*|*|*|*|*|" <<endl;
    cout<< "*********BlackJack*********" <<endl;
    cout<< "|*|*|*|*|*|*|*|*|*|*|*|*|*|" <<endl;
    cout<<endl;
    cout<< "Bine ati venit la BlackJack" <<endl;
}

int main()
{
    int tm = time (0);
    system("cls");
    cout << tm << '\n';
    srand(tm);
    afisareMeniu();
    alege=modulJocului();
    while(alege==1)
    {
        numarCartiJucator=2;
        numarCartiDealer=2;
        for(int i=0;i<numarCartiJucator;i++)
        {
            manaJucatorului[i]=carteaUrmatoare(pachetCarti);
            manaDealerului[i]=carteaUrmatoare(pachetCarti);
            punctajManaJucator+=valoareaCartilor(manaJucatorului[i]);
            punctajManaDealer+=valoareaCartilor(manaDealerului[i]);
        }

        cout<<"Cartile Dealerului sunt:"<<"*"<<" ";
        cout<<manaDealerului[1]<<endl;
        cout<<endl;
        cout<<nume<<", cartile tale sunt: ";`
       arataMana(manaJucatorului,numarCartiJucator);
        cout<<endl;
        cout<<"Punctajul tau este:"<<" ";
        cout<<punctajManaJucator<<endl;
        cout<<endl;
        if(punctajManaJucator==21)
            cout<<"Felicitari!!"<<nume<<" ai castigat!";
        if(punctajManaDealer==21)
            cout<<"Computerul a castigat!!";


        cout<<"Daca mai doriti inca o carte, apasati tasta 'H'. In caz contrar, apasati tasta 'S'"<<endl;
        cin>>alegere;
        while(alegere=='H'||alegere=='h')
        {
            manaJucatorului[numarCartiJucator]=carteaUrmatoare(pachetCarti);
            punctajManaJucator+=valoareaCartilor(manaJucatorului[numarCartiJucator]);
            numarCartiJucator++;
            arataMana(manaJucatorului,numarCartiJucator);
            cout<<"Punctajul tau este:";
            cout<<punctajManaJucator<<endl;

            if(punctajManaDealer<17);
                {
                    manaDealerului[numarCartiDealer]=carteaUrmatoare(pachetCarti);
                    punctajManaDealer+=valoareaCartilor(manaDealerului[numarCartiDealer]);
                    numarCartiDealer++;
                }

            cin>>alegere;
        }

        if(alegere=='S'||alegere=='s')
               {
                    arataMana(manaDealerului,numarCartiDealer);
                    cout<<endl;
                    cout<<"punctajul Dealerului este:"<<punctajManaDealer<<endl;
                    cout<<"Punctajul jucatorului:"<<punctajManaJucator<<endl;
                    cineCastiga(punctajManaJucator,punctajManaDealer);
                    cout<<endl;
               }
            else cout<<"Ati ales o valoare eronata!!Mai incercati o data!"<<endl;
            alege=modulJocului();
            cin>>alege;


    }
     if(alege==2)
    {
        for(int i=0;i<2;i++)
        {
            manaJucator1[i]=carteaUrmatoare(pachetCarti);
            punctajJucator1=punctajJucator1+valoareaCartilor(manaJucator1[i]);
            manaJucator2[i]=carteaUrmatoare(pachetCarti);
            punctajJucator2=punctajJucator2+valoareaCartilor(manaJucator2[i]);
        }
        nrCartiJucator1=2;
        nrCartiJucator2=2;
            cout<<nume<< ","<<" cartile tale sunt : ";
            arataMana(manaJucator1,2);
            cout<<nume1<< ","<<" cartile tale sunt: ";
            arataMana(manaJucator2,2);
            cout<<"Punctaj " << nume<<":";
            cout<<punctajJucator1<<endl;
            cout<<endl;
            cout<<"Punctaj " << nume1<<":";
            cout<<punctajJucator2<<endl;
            cout<<endl;
            cout<<nume<<","<<" apasa:"<<endl;
            cout<<" 1 pentru a mai trage o carte"<<endl;
            cout<<" 2 pentru a te opri"<<endl;
            cout<<" 3 pentru EXIT"<<endl;
            cin>>tasta;
            if(tasta==1)
            {
                manaJucator1[nrCartiJucator1]=carteaUrmatoare(pachetCarti);
                punctajJucator1+=valoareaCartilor(manaJucator1[nrCartiJucator1]);
                nrCartiJucator1++;
                arataMana(manaJucator1,nrCartiJucator1);
                cout<<"Punctajul tau este:";
                cout<<punctajJucator1;
            }
            else if(tasta==2)
            {
                if(punctajJucator1>21)
                {
                    cout<<nume<<",";
                    cout<<"ai pierdut. Mai incearca o data"<<endl;
                }
                else
                    if(punctajJucator1==punctajJucator2)
                {
                    cout<<"Este egalitate!!";
                }
                else
                    if(punctajJucator1>punctajJucator2&&punctajJucator1<21)
                {
                    cout<<"Felicitari, "<<nume;
                    cout<<" .Erai atat de aproape de 21, dar totusi ai reusit!";
                }
                else
                    if(punctajManaJucator==21)
                {
                    cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl;
                    cout<<"Felicitari!! "<<nume;
                    cout<<" Ai castigat!"<<endl;
                }
                else cout<<nume1<<" a castigat!!!";

            }
            else if(tasta==3)
                {
                    exit (0);
                    cout<<nume<<" a parasit jocul!"<<endl;
                    cout<<nume1<<" a castigat!"<<endl;
                }


            else cout<<"Ai ales o valoare gresita. Apasa din nou!";


    }
    return 0;
}

