#include <iostream>

using namespace std;

#include "Bolnica.hpp"

int meni(){

cout<<"\n\t\t\t\t*****************************MENI**********************************\n";
cout<<" \t\t     \t\t* 1.Bolnica                                                       *"<<endl;
cout<<"  \t\t    \t\t* 2.Pacijent                                                      *"<<endl;
cout<<" \t\t     \t\t* 3.Doktor                                                        *"<<endl;
cout<<"  \t\t    \t\t* 4.Kraj                                                          *"<<endl;
cout<<"\n\t\t\t\t*****************************MENI**********************************\n";
int i;
do{
cout<<"Unesite koju opciju zelite:"<<endl;
cin>>i;
}while(i<1 || i>4);
return i;
}

int meni1(){
    int m;
    cout<<"0.Unos informacija o bolnici"<<endl;
    cout<<"1.Ispis informacija o bolnici"<<endl;
    cout<<"2.Promena imena bolnice"<<endl;
    cout<<"3.Promena lokacije"<<endl;
    cout<<"4.Promena kontakta"<<endl;
    cout<<"5.Promena broja kreveta"<<endl;
    cout<<"6.Promena broja zauzetih kreveta"<<endl;
    cout<<"7.Promena nacina gradnje"<<endl;
    cout<<"8.Promena tipa bolnice"<<endl;
    cout<<"9.Kraj"<<endl;
    do{
    cout<<"Unesite opciju koju zelite:"<<endl;
    cin>>m;
    }while(m<0 || m>9 );
    return m;
}
int meni2(){
    int m;
    cout<<"0.Upis informacija o pacijentu"<<endl;
    cout<<"1.Ispis informacija o pacijentu"<<endl;
    cout<<"2.Promena imena"<<endl;
    cout<<"3.Promena prezimena"<<endl;
    cout<<"4.Promena kontakta"<<endl;
    cout<<"5.Promena datuma rodjenja"<<endl;
    cout<<"6.Promena pola"<<endl;
    cout<<"7.Promena krvne grupe"<<endl;
    cout<<"8.Promena uputa"<<endl;
    cout<<"9.Promena datuma prijema"<<endl;
    cout<<"10.Promena ID"<<endl;
    cout<<"11.Kraj"<<endl;
    do{
    cout<<"Unesite opciju koju zelite:"<<endl;
    cin>>m;
    }while(m<0 || m>11 );
    return m;
}
int meni3(){
    int m;
    cout<<"0.Unos informacija o doktoru"<<endl;
    cout<<"1.Ispis informacija o doktoru"<<endl;
    cout<<"2.Promena imena"<<endl;
    cout<<"3.Promena prezimena"<<endl;
    cout<<"4.Promena kontakta"<<endl;
    cout<<"5.Promena datuma rodjenja"<<endl;
    cout<<"6.Promena pola"<<endl;
    cout<<"7.Promena plate"<<endl;
    cout<<"8.Promena specijalizacije"<<endl;
    cout<<"9.Promena studija"<<endl;
    cout<<"10.Kraj"<<endl;
    do{
    cout<<"Unesite opciju koju zelite:"<<endl;
    cin>>m;
    }while(m<0 || m>10 );
    return m;
}
int main()
{
cout<<"\n\t\t*******************************************************************************************\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t**                                            		                                 **\n";
cout<<"\t\t**                                                                     		         **\n";
cout<<"\t\t**                             Dobrodosli u simulaciju bolnice                           **\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t**                                                                                       **\n";
cout<<"\t\t*******************************************************************************************\n\n\n\n";

Bolnica b;
Doktor d;
Pacijent p;
int n;
do{
n=meni();
switch(n){
case 1:
{
int m1=meni1();
switch(m1){
case 0:
    {
        string s1,s2,s3;
        int i1,i2;
        int a1,a2;
        cout<<"Unesite ime:"<<endl;
        cin>>b.ime;
        cout<<"Unesite lokaciju:"<<endl;
        cin>>b.lokacija;
        cout<<"Unesite kontakt:"<<endl;
        cin>>b.kontakt;
        cout<<"Unesite broj kreveta:"<<endl;
        cin>>b.brojKreveta;
        cout<<"Unesite broj zauzetih kreveta:"<<endl;
        cin>>b.brojZautetihKreveta;
        cout<<"Unesite nacin gradnje(0-paviljonski,1-koridorni,2-blok,3-sistemBaraka,4-tranbantni):"<<endl;
        cin>>a1;
        NacinGradnje temp;
    switch(a1){
        case 0:
            b.gradnja= paviljonski;
            break;
        case 1:
            b.gradnja= koridorni;
            break;
        case 2:
            b.gradnja = blok;
            break;
        case 3:
            b.gradnja=sistemBaraka;
            break;
        case 4:
            b.gradnja= tranbantni;
            break;

    }
    TipBolnice t;
        cout<<"Unesite tip bolnice(0-opsta,1-specificna):"<<endl;
        cin>>a2;
        switch(a2){
    case 0:
        b.tip=opsta;
        break;
    case 1:
        b.tip=specificna;
        break;
        }
break;
    }
case 1:
    b.ispis();
    break;
case 2:
    {
    cout<<"Unesite novo ime bolnice:"<<endl;
    string s;
    cin>>s;
    b.setImeBolnice(s);
    break;
    }
case 3:
    {
    cout<<"Unesite novu lokacije bolnice:"<<endl;
    string s;
    cin>>s;
    b.setLokacijaBolnice(s);
    break;
    }
case 4:
    {
    cout<<"Unesite novi kontakt bolnice:"<<endl;
    string s;
    cin>>s;
    b.setKontaktBolnice(s);
    break;
    }
case 5:
    {
    cout<<"Unesite novi broj kreveta u bolnici:"<<endl;
    int s;
    cin>>s;
    b.setBrojKreveta(s);
    break;
    }
case 6:
    {
    cout<<"Unesite novi broj zauzetih kreveta u bolnici:"<<endl;
    int s;
    cin>>s;
    b.setBrojZauzetihKreveta(s);
    break;
    }

case 7:
    {
    cout<<"Unesite ispravljeni nacin gradnje bolnice:(1-paviljonski,2-koridorni, 3-blok, 4-sistemBaraka, 5-tranbantni)"<<endl;
    int s;
    cin>>s;
    switch(s){
case 1:
    b.setNacinGradnje(paviljonski);
    break;
case 2:
    b.setNacinGradnje(koridorni);
    break;
case 3:
    b.setNacinGradnje(blok);
    break;
case 4:
    b.setNacinGradnje(sistemBaraka);
    break;
case 5:
    b.setNacinGradnje(tranbantni);
    break;

    }
    break;
    }
case 8:
    {
    cout<<"Unesite novi tip bolnice:(1-opsta,2-specificna)"<<endl;
    int s;
    cin>>s;
    if(s==1)
        b.setTipBolnice(opsta);
    else if(s==2)
        b.setTipBolnice(specificna);
    break;
    }
}
    break;
}
case 2:
{
int m2=meni2();
switch(m2){
   case 0:
    {
       cout<<"Unesite ime:"<<endl;
       cin>>p.ime;
       cout<<"Unesite prezime:"<<endl;
       cin>>p.prezime;
       cout<<"Unesite kontakt:"<<endl;
       cin>>p.kontakt;
       cout<<"Unesite datum rodjenja:"<<endl;
       cin>>p.datumRodjenja;
       cout<<"Unesite datum prijema:"<<endl;
       cin>>p.datumPrijema;
       cout<<"Unesite id:"<<endl;
       cin>>p.id;
       cout<<"Unesite pol(0-muski,1-zenski):"<<endl;
       int i,x;
       cin>>i;
        switch(i){
        case 1:
            p.pol=zenski;
            break;
        case 0:
            p.pol=muski;
            break;
      }
       cout<<"Unesite krvnu grupu(0-Ap,1-An,2-Bp,3-Bn,4-op,5-on,6-ABp,7-ABn):"<<endl;
       cin>>x;
        switch(x){
        case 0:
            p.grupa= Ap;
            break;
        case 1:
            p.grupa= An;
            break;
        case 2:
            p.grupa= Bp;
            break;
        case 3:
            p.grupa= Bn;
            break;
        case 4:
            p.grupa = ABp;
            break;
        case 5:
            p.grupa= ABn;
            break;
        case 6:
            p.grupa=op;
            break;
        case 7:
            p.grupa= on;
            break;
            }
            cout<<"Da li ima uput(0-false,1-true):"<<endl;
            int y;
            cin>>y;
        switch(y){
case 0:
    p.uput=false;
    break;
case 1:
    p.uput=true;
    break;
    }
       break;
    }
case 1:
    {
       p.ispisPacijenta();
       break;
    }
case 2:
{
        cout<<"Unesite novo ime:"<<endl;
       string s;
       cin>>s;
       p.setIme(s);
       break;
}
case 3:
{
       cout<<"Unesite novo prezime:"<<endl;
       string s;
       cin>>s;
       p.setPrezime(s);
       break;
}
case 4:
{
       cout<<"Unesite novi kontakt:"<<endl;
       string s;
       cin>>s;
       p.setKontakt(s);
       break;
}
case 5:
{
       cout<<"Unesite novi datum rodjenja:"<<endl;
       string s;
       cin>>s;
       p.setDatumRodjenja(s);
       break;

}
case 6:
{
       cout<<"Unesite pol:(1-muski,2-zenski)"<<endl;
       int s;
   cin>>s;
       if(s==1)
        p.setPol(muski);
       else if(s==2)
        p.setPol(zenski);
       break;

}
case 7:
{
 cout<<"Unesite krvnu grupu:(1-Ap,2-An,3-Bp,4-Bn,5-op,6-on,7-ABp,8-ABn)"<<endl;
       int s;
       cin>>s;
       switch(s){
   case 1:
    p.setGrupa(Ap);
    break;
  case 2:
    p.setGrupa(An);
    break;
     case 3:
    p.setGrupa(Bp);
    break;
     case 4:
    p.setGrupa(Bn);
    break;
     case 5:
    p.setGrupa(op);
    break;
     case 6:
    p.setGrupa(on);
    break;
     case 7:
    p.setGrupa(ABp);
    break;
     case 8:
    p.setGrupa(ABn);
    break;

       }
       break;

}
case 8:
    {
 cout<<"Da li ima uput:(1-da ,0-na)"<<endl;
       int s;
       cin>>s;
       if(s==1)
        p.setUput(true);
       else if(s==0)
       p.setUput(false);

       break;

}
case 9:
{
 cout<<"Unesite datum prijema:"<<endl;
       string s;
       cin>>s;
       p.setDatumPrijemaPacijenta(s);
       break;

}
case 10:
    {

    cout<<"Unesite ID:"<<endl;
       int s;
       cin>>s;
       p.setIDPacijenta(s);
       break;

}

}

    break;
}
case 3:
{
    int m3=meni3();
    switch(m3){
    case 0:
         {
       cout<<"Unesite ime:"<<endl;
       cin>>d.ime;
       cout<<"Unesite prezime:"<<endl;
       cin>>d.prezime;
       cout<<"Unesite kontakt:"<<endl;
       cin>>d.kontakt;
       cout<<"Unesite datum rodjenja:"<<endl;
       cin>>d.datumRodjenja;
       cout<<"Unesite pol(0-muski,1-zenski):"<<endl;
       int i,x;
       cin>>i;
        switch(i){
        case 1:
            d.pol=zenski;
            break;
        case 0:
            d.pol=muski;
            break;
             }
             cout<<"Unesite platu:"<<endl;
             cin>>d.plata;
             cout<<"Unesite zavrsene studije:"<<endl;
             cin>>d.studije;
             cout<<"Unesite specijalizaciju:"<<endl;
             cin>>d.specijalizacija;
            break;

      }
    case 1:
    {
     d.ispisDoktora();
     break;
    }
    case 2:
    {
    cout<<"Unesite novo ime:"<<endl;
    string s;
    cin>>s;
    d.setIme(s);
    break;
    }
    case 3:
    {
    cout<<"Unesite novo prezime:"<<endl;
    string s;
    cin>>s;
    d.setPrezime(s);
    break;
    }
    case 4:
    {
    cout<<"Unesite novi kontakt:"<<endl;
    string s;
    cin>>s;
    d.setKontakt(s);
    break;
    }
    case 5:
    {
    cout<<"Unesite novi datum rodjenja:"<<endl;
    string s;
    cin>>s;
    d.setDatumRodjenja(s);
    break;
    }
    case 6:
    {
    cout<<"Unesite pol:(1-muski,2-zenski)"<<endl;
    int s;
    cin>>s;
    if(s==1)
    d.setPol(muski);
    else if(s==2)
    d.setPol(zenski);
    break;
    }
    case 7:
    {
    cout<<"Unesite novu platu:"<<endl;
    int s;
    cin>>s;
    d.setPlata(s);
    break;
    }
    case 8:
    {
    cout<<"Unesite specijalzaciju:"<<endl;
    string s;
    cin>>s;
    d.setSpecijalizacija(s);
    break;
    }
    case 9:
    {
    cout<<"Unesite studije:"<<endl;
    string s;
    cin>>s;
    d.setStudije(s);
    break;
    }
    }
    break;

}
}
}while(n!=4);

    return 0;

}
