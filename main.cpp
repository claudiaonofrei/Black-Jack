#include <iostream>

using namespace std;
int vector[15]
bool pachetCarti[52];
int modulJocului()
{
    char nume, nume1;
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
            cout<<"Nume Jucator:"<<nume;
            cin.getline(nume);
        }
        if(modul==2)
        {
            cout<<"Ati ales varianta Jucator 1 vs. Jucator 2"<<endl;
            cout<<"Nume Jucator 1:";
            cin.getline(nume);
            cout<<"Nume Jucator 2:";
            cin.getline(nume1);
        }
        else
            cout<<"Ati tastat o valoare gresita! Va rog sa alegeti din nou! \n";
    }
    return modul;
}
void aiCastigat()
{
    system("cls");
    cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl;
    cout<<"Felicitari!! Ai castigat!"<<endl;
}
void aiPierdut()
{
    system("cls");
    cout<<"|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|"<<endl;
    cout<<"Ai pierdut. Mai incearca o data"<<endl;

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
    int cartenoua=0;
    while(ok==1)
    {
        cartenoua=rand()%53+1;
        if(pachetCarti[cartenoua]==false)
            ok=0;
    }
    return cartenoua;
}


int main()
{
    cout<< "___________________________" <<endl;
    cout<< "|*|*|*|*|*|*|*|*|*|*|*|*|*|" <<endl;
    cout<< "*********BlackJack*********" <<endl;
    cout<< "|*|*|*|*|*|*|*|*|*|*|*|*|*|" <<endl;
    cout<<endl;
    cout<< "Bine ati venit la BlackJack" <<endl;
    cout<< "Apasati tasta enter pentru a incepe jocul"<<endl;
    cin.get();
    modulJocului();
    if(modul==1)
    {
        for(i=0;i<2;i++)
            {
                manaJucatorului[i]=carteaUrmatoare(pachetCarti);
                manaDealerului[i]=carteaUrmatoare(pachetCarti);
            }
        numarCartiJucator=2;
        numarCartiDealer=2;
        cout<<"Cartile Dealerului sunt:"<<"[]"<<" ";
        cout<<manaDealerului[2]<<endl;
        cout<<endl;
        cout<<"Cartile jucatorului sunt:";
        cout<<manaJucatorului[0]<<" ";
        cout<<manaJucatorului[1]<<endl;
    }
}
