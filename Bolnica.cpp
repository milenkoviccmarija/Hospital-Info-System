#include "Bolnica.hpp"
#include <iostream>
#include <string>
#include <string.h>

#define MAX 20
using namespace std;
#include <iomanip>
ostream& operator<<(ostream& o, const Datum& d){
    o<< d.mesec << '/' << d.dan << '/' << d.godina;
    return o;
}
Datum::Datum(int x,int y,int z){
        mesec=x;
        dan=y;
        godina=z;
}
ostream &operator<<(ostream &output, const BrojTelefona &broj){
    output << "(" << broj.prviDeo << ")" << broj.drugiDeo << "-" << broj.treciDeo;
    return output;
}
istream &operator>>(istream &input, BrojTelefona &broj){
    input.ignore();
    input >> setw(5) >> broj.prviDeo;
    input.ignore(2);
    input >> setw(4) >> broj.drugiDeo;
    input.ignore();
    input >> setw(5) >> broj.treciDeo;
    return input;

}

Bolnica::Bolnica(){

ime="Bolnica";
lokacija="Zlatne Grede 4";
kontakt="bolnica@gmail.com";
brojKreveta=300;
brojZautetihKreveta=250;
gradnja=blok;
tip=opsta;

}
Bolnica::Bolnica(string imeb, string l, string konb, int bk,int bzk,NacinGradnje n,TipBolnice t){

    ime=imeb;
    lokacija=l;
    kontakt=konb;
    brojKreveta=bk;
    brojZautetihKreveta=bzk;
    gradnja=n;
    tip=t;

}
Bolnica::Bolnica(const Bolnica& b){

    ime=b.ime;
    lokacija=b.lokacija;
    kontakt=b.kontakt;
    brojKreveta=b.brojKreveta;
    brojZautetihKreveta=b.brojZautetihKreveta;
    gradnja=b.gradnja;
    tip=b.tip;
}
string Bolnica::getImeBolnice()const{
        return ime;
    }
string Bolnica::getKontaktBolnice()const{
        return kontakt;
    }
string Bolnica::getLokacija()const{
        return lokacija;
    }
int Bolnica::getBrojKreveta()const{
        return brojKreveta;
    }
int Bolnica::getBrojZauzetihKreveta()const{
        return brojZautetihKreveta;
    }
string Bolnica::getNacinGradnje()const{
         string temp;
    switch(gradnja){
        case paviljonski:
            temp = "paviljonski";
            break;
        case koridorni:
            temp = "koridorni";
            break;
        case blok:
            temp = "blok";
            break;
        case sistemBaraka:
            temp = "sistem baraka";
            break;
        case tranbantni:
            temp = "tranbantni";
            break;
        default:
            temp = "nedefinisan";
            break;
    }

    return temp;
    }
string Bolnica::getTipBolnice()const{
        string temp;
    switch(tip){
        case opsta:
            temp = "opsta";
            break;
        case koridorni:
            temp = "specificna";
            break;
        default:
            temp = "nedefinisan";
            break;
    }

    return temp;
    }
void Bolnica::setImeBolnice(const string s){
        ime=s;
    }
void Bolnica::setLokacijaBolnice(const string s){
        lokacija=s;
    }
void Bolnica::setKontaktBolnice(const string s){
        kontakt=s;
    }
void Bolnica::setBrojKreveta(const int i){
        brojKreveta=i;
    }
void Bolnica::setBrojZauzetihKreveta(const int i){
        brojZautetihKreveta=i;
    }
void Bolnica::setNacinGradnje(const NacinGradnje i){
        gradnja=i;
    }
void Bolnica::setTipBolnice(const TipBolnice i){
        tip=i;
    }
void Bolnica::ispis(){
        cout<<"***************************\n";
        cout<<"Ime bolnice:"<<ime<<endl;
        cout<<"Lokacija:"<<lokacija<<endl;
        cout<<"Kontakt:"<<kontakt<<endl;
        cout<<"Broj kreveta:"<<brojKreveta<<endl;
        cout<<"Broj zauzetih kreveta:"<<brojZautetihKreveta<<endl;
        string temp;
    switch(gradnja){
        case paviljonski:
            temp = "paviljonski";
            break;
        case koridorni:
            temp = "koridorni";
            break;
        case blok:
            temp = "blok";
            break;
        case sistemBaraka:
            temp = "sistem baraka";
            break;
        case tranbantni:
            temp = "tranbantni";
            break;
        default:
            temp = "nedefinisan";
            break;
    }
        cout<<"Nacin gradnje:"<<temp<<endl;
         string tempp;
    switch(tip){
        case opsta:
            tempp = "opsta";
            break;
        case koridorni:
            tempp = "specificna";
            break;
        default:
            tempp = "nedefinisan";
            break;
    }
        cout<<"Tip bolnice:"<<tempp<<endl;
        cout<<"***************************\n";


    }


Osoba::Osoba(){

    ime="Marija";
    prezime="Milenkovic";
    kontakt="0651234567";
    datumRodjenja="2.1.2005.";
    pol=zenski;

 }
Osoba::Osoba(string ime1, string prezime1, string kon, string DatRodj, Pol p ){

    ime=ime1;
    prezime=prezime1;
    kontakt=kon;
    datumRodjenja=DatRodj;
    pol=p;

 }
Osoba::Osoba(const Osoba& o){

    ime=o.ime;
    prezime=o.prezime;
    kontakt=o.kontakt;
    datumRodjenja=o.datumRodjenja;
    pol=o.pol;

 }
string Osoba::getIme()const{

return ime;

}
string Osoba::getPrezime()const{

return prezime;

}
string Osoba::getKontakt()const{

return kontakt;

}
string Osoba::getDatumRodjenja()const{

return datumRodjenja;

}
string Osoba::getPol()const{

string temp;

switch(pol){
case zenski:
    temp="zenski";
case muski:
    temp="muski";
default:
    temp="nedefinisano";
}

return temp;

}
void Osoba::setIme(const string s){
ime=s;
}
void Osoba::setPrezime(const string s){
prezime=s;
}
void Osoba::setKontakt(const string s){
kontakt=s;
}
void Osoba::setDatumRodjenja(const string s){
datumRodjenja=s;
}
void Osoba::setPol(const Pol s){
pol=s;
}
void Osoba::ispisOsobe(){

        cout<<"***************************\n";
        cout<<"Ime :"<<ime<<endl;
        cout<<"Prezime:"<<prezime<<endl;
        cout<<"Kontakt:"<<kontakt<<endl;
        cout<<"Datum rodjenja:"<<datumRodjenja<<endl;
        string temp;
    switch(pol){
        case zenski:
            temp = "zenski";
            break;
        case muski:
            temp = "muski";
            break;
            temp = "nedefinisan";
            break;
            }
             cout<<"Pol:"<<temp<<endl;
             cout<<"***************************\n";

    }


Pacijent::Pacijent(){
    Osoba:Osoba();
    uput=true;
    datumPrijema="9.3.2021.";
    id=1;

    }
Pacijent::Pacijent(string ime1, string prezime1, string kon, string DatRodj, Pol p ,KrvnaGrupa krv, bool u,string DatPrijema, int i) {

    Osoba:Osoba(ime1,prezime1,kon,DatRodj,p);
    grupa=krv;
    uput=u;
    datumPrijema=DatPrijema;
    id=i;

	}
Pacijent::Pacijent(const Pacijent& p){

    Osoba:Osoba((Osoba)p);
    grupa=p.grupa;
    uput=p.uput;
    datumPrijema=p.datumPrijema;
    id=p.id;

	}
string Pacijent::getKrvnaGrupaPacijenta()const{
string temp;
    switch(grupa){
        case Ap:
            temp = "A pozitina";
            break;
        case An:
            temp = "A negativna";
            break;
            case Bp:
            temp = "B pozitina";
            break;
        case Bn:
            temp = "B negativna";
            break;
            case ABp:
            temp = "AB pozitina";
            break;
        case ABn:
            temp = "AB negativna";
            break;
            case op:
            temp = "0 pozitina";
            break;
        case on:
            temp = "0 negativna";
            break;
            default:
            temp = "nedefinisan";
            break;
            }
            return temp;
}
string Pacijent::getUputPacijenta()const{
string temp;
switch(uput){
case false:
    temp="nema uputa";
    break;
case true:
    temp="ima uput";
    break;
default:
    temp="nedefinisano";
}
return temp;
}
string Pacijent::getDatumPrijemaPacijenta()const{
return datumPrijema;
}
int Pacijent::getIDPacijenta()const{
    return id;
}
void Pacijent::setGrupa(const KrvnaGrupa k){

grupa=k;

}
void Pacijent::setUput(const bool u){

uput=u;

}
void Pacijent::setDatumPrijemaPacijenta(const string s){
datumPrijema=s;
}
void Pacijent::setIDPacijenta(const int i){
id=i;
}
void Pacijent::ispisPacijenta(){

        Osoba::ispisOsobe();
        string temp;
    switch(grupa){
        case Ap:
            temp = "A pozitina";
            break;
        case An:
            temp = "A negativna";
            break;
            case Bp:
            temp = "B pozitina";
            break;
        case Bn:
            temp = "B negativna";
            break;
            case ABp:
            temp = "AB pozitina";
            break;
        case ABn:
            temp = "AB negativna";
            break;
            case op:
            temp = "0 pozitina";
            break;
        case on:
            temp = "0 negativna";
            break;
            default:
            temp = "nedefinisan";
            break;
            }
            string temp2;
switch(uput){
case false:
    temp2="nema uputa";
    break;
case true:
    temp2="ima uput";
    break;
default:
    temp2="nedefinisano";
}

        cout<<"Krvna grupa :"<<temp<<endl;
        cout<<"Uput:"<<temp2<<endl;
        cout<<"Datum prijema u bolnicu:"<<datumPrijema<<endl;
        cout<<"ID pacijenta:"<<id<<endl;

}


Doktor::Doktor(){

    Osoba:Osoba();
    plata=80000;
    specijalizacija="hirurg";
    studije="Medicinski fakultet Novi Sad";

 }
Doktor::Doktor(string ime1, string prezime1, string kon, string DatRodj, Pol p,int pt, string spc,string stdj){

    Osoba:Osoba(ime1,prezime1,kon,DatRodj,p);
    plata=pt;
    specijalizacija=spc;
    studije=stdj;

}
Doktor::Doktor(const Doktor& d){

    Osoba:Osoba((Osoba)d);
    plata=d.plata;
    specijalizacija=d.specijalizacija;
    studije=d.studije;

}
int Doktor::getPlata()const{
return plata;
}
string Doktor::getSpecijalizacija()const{
return specijalizacija;
}
string Doktor::getStudije()const{
return studije;
}
void Doktor::setPlata(const int p){
plata=p;
}
void Doktor::setSpecijalizacija(const string sp){
specijalizacija=sp;
}
void Doktor::setStudije(const string stdj){
studije=stdj;
}
void Doktor::ispisDoktora(){

Osoba::ispisOsobe();
cout<<"Plata:"<<plata<<endl;
cout<<"Specijalizacija:"<<specijalizacija<<endl;
cout<<"Zavrsene studije:"<<studije<<endl;

}


Sestra::Sestra(){
    Osoba:Osoba();
    tipS=medicinska;
    GlavnaSestra=true;
    plata=50000;


}
Sestra::Sestra(string ime1, string prezime1, string kon, string DatRodj, Pol p,tipSestre t, bool gs,int pl){
    Osoba:Osoba(ime1,prezime1,kontakt,datumRodjenja,pol);
    tipS=t;
    GlavnaSestra=gs;
    plata=pl;

}
Sestra::Sestra(const Sestra& s){
    Osoba:Osoba((Osoba)s);
    tipS=s.tipS;
    GlavnaSestra=s.GlavnaSestra;
    plata=s.plata;

}
string Sestra::getTipSestre()const{

string temp;
switch(tipS){
case pedijatrijska:
    temp="pedijatrijska sestra";
    break;
case medicinska:
    temp="medicinska sestra";
    break;
    case instrumentarka:
    temp="instrumentarka";
    break;
case ginekolosko_akusarska:
    temp="ginekolosko akusarska sestra";
    break;
case anesteticarka:
    temp="anesteticarka";
    break;
default:
    temp="nedefinisano";
}
return temp;

}
string Sestra::getGlavnaSestra()const{

string temp;
switch(GlavnaSestra){
case false:
    temp="nije glavna sestra";
    break;
case true:
    temp="glavna sestra";
    break;
default:
    temp="nedefinisano";
}
return temp;

}
int Sestra::getPlataSestre()const{
    return plata;
}
void Sestra::setTipSestre(const tipSestre ts){
    tipS=ts;
}
void Sestra::setGlavnaSestra(const bool gs){
    GlavnaSestra=gs;
}
void Sestra::setPlataSestre(const int pl){
    plata=pl;
}
void Sestra::ispisSestre(){
Osoba::ispisOsobe();
string temp2;
switch(GlavnaSestra){
case false:
    temp2="nije glavna sestra";
    break;
case true:
    temp2="glavna sestra";
    break;
default:
    temp2="nedefinisano";
}

string temp;
switch(tipS){
case pedijatrijska:
    temp="pedijatrijska sestra";
    break;
case medicinska:
    temp="medicinska sestra";
    break;
    case instrumentarka:
    temp="instrumentarka";
    break;
case ginekolosko_akusarska:
    temp="ginekolosko akusarska sestra";
    break;
case anesteticarka:
    temp="anesteticarka";
    break;
default:
    temp="nedefinisano";
}


cout<<"Plata:"<<plata<<endl;
cout<<"Tip Sestre:"<<temp<<endl;
cout<<"Da li je glavna sestra:"<<temp2<<endl;
}


Mrtvacnica::Mrtvacnica():p(){
    brojMesta=50;
    brojZauzetihMesta=40;


}
Mrtvacnica::Mrtvacnica(Pacijent p1,int bm,int bsm):p(p1){
    brojMesta=bm;
    brojZauzetihMesta=bsm;

}
Mrtvacnica::Mrtvacnica(Mrtvacnica & m):p(m.p){
    brojMesta=m.brojMesta;
    brojZauzetihMesta=m.brojZauzetihMesta;

}
void Mrtvacnica::setBrojMesta(const int bm){
brojMesta=bm;
}
void Mrtvacnica::setBrojSlobodnihMesta(const int bsm){
brojZauzetihMesta=bsm;
}
int Mrtvacnica::getBrojMesta()const{
return brojMesta;
}
int Mrtvacnica::getBrojSlobodnihMesta()const{
return brojZauzetihMesta;
}

TehnickoOsoblje::TehnickoOsoblje(){

    Osoba:Osoba();
    t=kuvar;
    plata=30000;

}
TehnickoOsoblje::TehnickoOsoblje(string ime1, string prezime1, string kon, string DatRodj, Pol p,TipTehnickogOsoblja t1,int pl){
    Osoba:Osoba(ime1,prezime1,kon,DatRodj,p);
    t=t1;
    plata=pl;

}
TehnickoOsoblje::TehnickoOsoblje(TehnickoOsoblje &to){
    Osoba:Osoba((Osoba)to);
    t=to.t;
    plata=to.plata;

}
string TehnickoOsoblje::getTipOsoblja()const{

string temp;
    switch(t){
case kuvar:
    temp="kuvar";
    break;
    case cistacica:
    temp="cistacica";
    break;
    case domar:
        temp="domar";
    break;
    case tehnicar:
        temp="tehnicar";
    break;
    default:
        temp="nedefinisano";

}
return temp;

}
int TehnickoOsoblje::getPlataOsoblja()const{
    return plata;
}
void TehnickoOsoblje::setTipOsoblja(const TipTehnickogOsoblja to){
t=to;
}
void TehnickoOsoblje::setPlataOdoblja(const int po){
plata=po;
}


OdeljenjeZaSnabdevanjeKrvlju::OdeljenjeZaSnabdevanjeKrvlju():o(){
    brojAp=MAX;
    brojAn=MAX;
    brojBp=MAX;
    brojBn=MAX;
    brojABp=MAX;
    brojABn=MAX;
    brojop=MAX;
    brojon=MAX;


}
OdeljenjeZaSnabdevanjeKrvlju::OdeljenjeZaSnabdevanjeKrvlju(Osoba o1,int a,int a1,int b,int b1,int ab,int ab1,int o2,int o3):o(o1){
    brojAp=a;
    brojAn=a1;
    brojBp=b;
    brojBn=b1;
    brojABp=ab;
    brojABn=ab1;
    brojop=o2;
    brojon=o3;

}
OdeljenjeZaSnabdevanjeKrvlju::OdeljenjeZaSnabdevanjeKrvlju(OdeljenjeZaSnabdevanjeKrvlju& od):o(od.o){
    brojAp=od.brojAp;
    brojAn=od.brojAn;
    brojBp=od.brojBp;
    brojBn=od.brojBn;
    brojABp=od.brojABp;
    brojABn=od.brojABn;
    brojop=od.brojop;
    brojon=od.brojon;

}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv(const int a){brojAp=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv1(const int a){brojAn=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv2(const int a){brojBp=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv3(const int a){brojBn=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv4(const int a){brojABp=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv5(const int a){brojABn=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv6(const int a){brojop=a;}
void OdeljenjeZaSnabdevanjeKrvlju::setKrv7(const int a){brojon=a;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv()const{return brojAp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv1()const{return brojAn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv2()const{return brojBp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv3()const{return brojBn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv4()const{return brojABp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv5()const{return brojABn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv6()const{return brojop;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv7()const{return brojon;}

PrijemnaAmbulanta::PrijemnaAmbulanta():d(),s(),p(){
    vitalniZnaci=true;
    mestaUcekaonici=50;
}
PrijemnaAmbulanta::PrijemnaAmbulanta(Doktor d1,Sestra s1,Pacijent p1,bool vz,int c):d(d1),s(s1),p(p1),vitalniZnaci(vz),mestaUcekaonici(c){}
PrijemnaAmbulanta::PrijemnaAmbulanta(const PrijemnaAmbulanta& pa):d(pa.d),s(pa.s),p(pa.p){
    vitalniZnaci=pa.vitalniZnaci;
    mestaUcekaonici=pa.mestaUcekaonici;
}
void PrijemnaAmbulanta::setVitalniZnaci(const bool vz){
vitalniZnaci=vz;
}
void PrijemnaAmbulanta::setBrojMestaUCekaonici(int c){
mestaUcekaonici=c;
}
int PrijemnaAmbulanta::getBrojMestaUcekaonici()const{
return mestaUcekaonici;
}
string PrijemnaAmbulanta::getVitalniZnaci()const{

string temp;
switch(vitalniZnaci){
case false:
    temp="nema vitalnih znaka";
    break;
case true:
    temp="ima vitalnih znaka";
    break;
default:
    temp="nedefinisano";
}
return temp;
}


Apoteka::Apoteka():apotekar(),sestra(){
   char sl[MAX][MAX]={"aspirin","brufen"};
   int x,y;
for (int x=0 ; x < MAX; x++)
{
  for (int y=0 ; y < MAX; y++)
  {
    SpisakLekova[x][y] = sl[x][y];
  }
}
}
Apoteka::Apoteka(Osoba ap,char sl[MAX][MAX],Sestra s):apotekar(ap),sestra(s){
int x,y;
for (int x=0 ; x < MAX; x++)
{
  for (int y=0 ; y < MAX; y++)
  {
    sl[x][y] = SpisakLekova[x][y];
  }
}
}
Apoteka::Apoteka(Apoteka& a):apotekar(a.apotekar),sestra(a.sestra){
int x,y;
for (int x=0 ; x < MAX; x++)
{
  for (int y=0 ; y < MAX; y++)
  {
    a.SpisakLekova[x][y] = SpisakLekova[x][y];
  }
}
}

Hitna::Hitna():d(),s(),brojVozila(20),brojKreveta(30){}
Hitna::Hitna(Doktor d1,Sestra s1,int bv,int bk):d(d1),s(s1),brojVozila(bv),brojKreveta(bk){}
Hitna::Hitna(Hitna &h):d(h.d),s(h.s),brojVozila(h.brojVozila),brojKreveta(h.brojKreveta){}
void Hitna::setBrojVozila(const int i){
brojVozila=i;
}
void Hitna::setBrojKreveta(const int i){
brojKreveta=i;
}
int Hitna::getBrojVozila()const{
return brojVozila;
}
int Hitna::getBrojKreveta()const{
return brojKreveta;
}


Laborant::Laborant(){
  Osoba:Osoba();
  plata=70000;
  }
Laborant::Laborant(string ime1, string prezime1, string kon, string DatRodj, Pol p,int p1){
      Osoba:Osoba(ime1,prezime1, kon, DatRodj, p);
      plata=p1;

  }
Laborant::Laborant(Laborant &l){
  Osoba:Osoba((Osoba)l);
  plata=l.plata;
  }
void Laborant::setPlata(const int p){
plata=p;
}
int Laborant::getPlata()const{
return plata;
}


Laboratorija::Laboratorija():l(){
stanjen=gotov;
idNalaza=1;
brojNezavrsenihNalaza=10;
}
Laboratorija::Laboratorija(Laborant l1,stanjeNalaza st,int id,int bnn):l(l1){
stanjen=st;
idNalaza=id;
brojNezavrsenihNalaza=bnn;
}
Laboratorija::Laboratorija(Laboratorija &l1):l(l1.l){
stanjen=l1.stanjen;
idNalaza=l1.idNalaza;
brojNezavrsenihNalaza=l1.brojNezavrsenihNalaza;
}
void Laboratorija::setStanje(const stanjeNalaza n){
stanjen=n;
}
void Laboratorija::setIdNalaz(const int id){
idNalaza=id;
}
void Laboratorija::setBrojNezavrsenihNalaza(const int bnn){
brojNezavrsenihNalaza=bnn;
}
string Laboratorija::getStanje()const{
string temp;
switch(stanjen){
case primljen:
    temp="primljen";
    break;
case obradjuje_se:
    temp="obradjuje se";
    break;
case gotov:
    temp="gotov";
    break;
default:
    temp="nedefinisan";

}
return temp;
}
int Laboratorija::getIdNalaza()const{
return idNalaza;
}
int Laboratorija::getBrojNezavrsenihNalaza()const{
return brojNezavrsenihNalaza;
}


KovidAmbulanta::KovidAmbulanta():s(),p(){
zastita=true;
tipTesta=TestNaAntitela;
brojNovoZarazenih=200;
}
KovidAmbulanta::KovidAmbulanta(Sestra s1,Pacijent p1,bool z,TipTesta tip,int m):s(s1),p(p1){
zastita=z;
tipTesta=tip;
brojNovoZarazenih=m;
}
KovidAmbulanta::KovidAmbulanta(KovidAmbulanta &ka):s(ka.s),p(ka.p){
zastita=ka.zastita;
tipTesta=ka.tipTesta;
brojNovoZarazenih=ka.brojNovoZarazenih;
}
void KovidAmbulanta::setZastita(const bool z){
zastita=z;
}
void KovidAmbulanta::setTipTesta(const TipTesta tip){
tipTesta=tip;
}
void KovidAmbulanta::setBrojNovozarazenih(const int i){
brojNovoZarazenih=i;
}
string KovidAmbulanta::getZastita()const{
string temp;
switch(zastita){
case false:
    temp="nema zastitu";
    break;
case true:
    temp="ima zastitu";
    break;
default:
    temp="nedefinisano";
}
return temp;
}
string KovidAmbulanta::getTipSestrea()const{
string temp;
switch(tipTesta){
case TestNaAntitela:
    temp="test na antitela";
    break;
case BrisIzGrla:
    temp="bris iz grla";
    break;
case BrisIzNosa:
    temp="bris iz nosa";
    break;
default:
    temp="nedefinisano";
}
return temp;

}
int KovidAmbulanta::getBrojNovozarazenih()const{
return brojNovoZarazenih;
}

Parking::Parking(){

brojMesta=100;
brojSlobodnihMesta=50;
brojSpratova=2;
VIPmesta[0]=1;
VIPmesta[1]=2;
VIPmesta[2]=3;
VIPmesta[3]=4;
VIPmesta[4]=5;
naplata=50;

}
Parking::Parking(int b1,int b2,int b3,int b4[5],int naplata1){

brojMesta=b1;
brojSlobodnihMesta=b2;
brojSpratova=b3;
VIPmesta[0]=b4[0];
VIPmesta[1]=b4[1];
VIPmesta[2]=b4[2];
VIPmesta[3]=b4[3];
VIPmesta[4]=b4[4];
naplata=naplata1;

}
Parking::Parking(Parking &p){

brojMesta=p.brojMesta;
brojSlobodnihMesta=p.brojSlobodnihMesta;
brojSpratova=p.brojSpratova;
VIPmesta[0]=p.VIPmesta[0];
VIPmesta[1]=p.VIPmesta[1];
VIPmesta[2]=p.VIPmesta[2];
VIPmesta[3]=p.VIPmesta[3];
VIPmesta[4]=p.VIPmesta[4];
naplata=p.naplata;

}
void Parking::setBrojMesta(const int b){
brojMesta=b;
}
void Parking::setBrojSlobidnihMesta(const int b){
brojSlobodnihMesta=b;
}
void Parking::setBrojSpratova(const int b){
brojSpratova=b;
}
void Parking::setBrojVIPmesta(const int b[5]){
   int i;
    for(i=0;i<5;i++)
VIPmesta[i]=b[i];
}
void Parking::setNaplata(const int b){
naplata=b;
}
int Parking::getBrojMesta()const{
return brojMesta;
}
int Parking::getBrojSlobodnihMesta()const{
return brojSlobodnihMesta;
}
int Parking::getBrojSpratova()const{
return brojSpratova;
}
int Parking::getnaplata()const{
return naplata;
}

KovidDeo::KovidDeo():a(){
brojOsobaUintenzivnoj=50;
brojOsobaUpoluIntenzivnoj=150;
brojRespiratora=50;
}
KovidDeo::KovidDeo(KovidAmbulanta k,int i, int x,int y):a(k){
brojOsobaUintenzivnoj=i;
brojOsobaUpoluIntenzivnoj=x;
brojRespiratora=y;
}
KovidDeo::KovidDeo(KovidDeo&k):a(k.a){
brojOsobaUintenzivnoj=k.brojOsobaUintenzivnoj;
brojOsobaUpoluIntenzivnoj=k.brojOsobaUpoluIntenzivnoj;
brojRespiratora=k.brojRespiratora;
}
void KovidDeo::setBrojOsoba1(const int i){
brojOsobaUintenzivnoj=i;
}
void KovidDeo::setBrojOsoba2(const int i){
brojOsobaUpoluIntenzivnoj=i;
}
void KovidDeo::setBrojRespiratora(const int i){
brojRespiratora=i;
}
int KovidDeo::getBrojOsoba1()const{
return brojOsobaUintenzivnoj;
}
int KovidDeo::getBrojOsoba2()const{
return brojOsobaUpoluIntenzivnoj;
}
int KovidDeo::getBrojRespiratora()const{
return brojRespiratora;
}

