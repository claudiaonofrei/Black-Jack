#include <iostream>
#include<stdlib.h>
#include<string.h>
#include <ctime>

using namespace std;
int vec[15],manaJucatorului[10],manaDealerului[10],modul=0,punctajManaJucator=0,punctajManaDealer=0,numarCartiJucator=0,numarCartiDealer=0,alege=0;
bool pachetCarti[52];
char alegere,nume[15],nume1[15];
int modulJocului()
{
    int modul=0;
    if(modul!=1||modul!=2)
    {
        cout<<"Alegeti modul in care doriti sa jucati! \n";
        cout<<"1.Jucator vs. Calculator \n";
        cout<<"2.Jucator 1 vs. Jucator 2 \n";
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
    }
        else
            cout<<"Ati tastat o valoare gresita! Va rog sa alegeti din nou! \n";

    return modul;
}
void cineCastiga(int punctajManaJucator, int punctajManaDealer)
{
    system("cls");
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
    srand(time(0));
    int i=0;
    carte=rand()%13+1;
   for(i=0;i<=14;i++)
   if(vec[carte]<4)
   {
       vec[carte]++;
       cout<<carte;
   }
   else
    carte=rand()%13+1;

}
scorMana(int mana[],int nrcarti)
{

}

void afiseazaCartea(int carti)
{
    int cregale;
    cregale=carti%13+1;
    switch(cregale)
    {
    case 1:
        {cout<<'A';}break;
    case 11:
        {cout<<'J';}break;
    case 12:
        {cout<<'Q';}break;
    case 13:
        {cout<<'K';}break;
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
int carteaUrmatoare(bool pachetCarti[])
{
    int cartenoua=0,ok=1;
    while(ok==1)
    {
        cartenoua=rand()%52+1;
        if(pachetCarti[cartenoua]==false)
            ok=0;
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
    cout<< "Apasati tasta enter pentru a incepe jocul"<<endl;
    cin.get();
}

int main()
{
    srand(time(0));
    system("cls");
    afisareMeniu();
    alege=modulJocului();
    if(alege==1)
    {

        for(int i=0;i<2;i++)
            {
                manaJucatorului[i]=carteaUrmatoare(pachetCarti);
                punctajManaJucator=punctajManaJucator+manaJucatorului[i];
                manaDealerului[i]=carteaUrmatoare(pachetCarti);
                punctajManaDealer=punctajManaDealer+manaDealerului[i];
            }
        numarCartiJucator=2;
        numarCartiDealer=2;
        cout<<"Cartile Dealerului sunt:"<<"[]"<<" ";
        cout<<manaDealerului[1]<<endl;
        cout<<endl;
        cout<<"Cartile jucatorului sunt:";
        arataMana(manaJucatorului,numarCartiJucator);
        cout<<"Punctajul tau este:"<<" ";
        cout<<punctajManaJucator<<endl;
        cout<<endl;
        cout<<"Daca mai doriti inca o carte, apasati tasta 'H'. In caz contrar, apasati tasta 'S'";
        cin>>alegere;
        if(alegere=='H'||alegere=='h')
        {
            manaJucatorului[numarCartiJucator]=carteaUrmatoare(pachetCarti);
            numarCartiJucator++;
        }
        else
            if(alegere=='S'||alegere=='s')
            cineCastiga(punctajManaJucator,punctajManaDealer);
        else cout<<"Ati ales o valoare eronata!!Mai incercati o data!"<<endl;
    }
}
