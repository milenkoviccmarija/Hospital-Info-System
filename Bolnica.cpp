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
istream &operator>>(istream&input, Datum &d){
input>>d.mesec;
input>>d.dan;
input>>d.godina;
return input;

}

ostream &operator<<(ostream& output , const Osoba &o){

        output<<"Ime :"<<o.ime<<endl;
        output<<"Prezime:"<<o.prezime<<endl;
        output<<"Kontakt:"<<o.kontakt<<endl;
        output<<"Datum rodjenja:"<<o.datumRodjenja<<endl;
        string temp;
    switch(o.pol){
        case zenski:
            temp = "zenski";
            break;
        case muski:
            temp = "muski";
            break;
            temp = "nedefinisan";
            break;
            }
             output<<"Pol:"<<temp<<endl;
             return output;
   }
istream &operator>>(istream& input, Osoba &o){

       cout<<"Unesite ime:"<<endl;
       input>>o.ime;
       cout<<"Unesite prezime:"<<endl;
       input>>o.prezime;
       cout<<"Unesite kontakt:"<<endl;
       input>>o.kontakt;
       int x2,y2,z2;
       cout<<"Unesite mesec rodjenja:";
       input>>x2;
       cout<<"dan:";
       input>>y2;
       cout<<"godinu:";
       input>>z2;
       o.setDatumRodjenja(x2,y2,z2);
    cout<<"Unesite pol(0-muski,1-zenski):"<<endl;
       int i,x;
       input>>i;
        switch(i){
        case 1:
            o.pol=zenski;
            break;
        case 0:
            o.pol=muski;
            break;
      }

    return input;

}

ostream &operator<<(ostream& output, const Bolnica &b){

        output<<"Ime bolnice:"<<b.ime;
        output<<"Lokacija:"<<b.lokacija;
        output<<"Kontakt:"<<b.kontakt;
        output<<"Broj kreveta:"<<b.brojKreveta;
        output<<"Broj zauzetih kreveta:"<<b.brojZautetihKreveta;
        string temp;
    switch(b.gradnja){
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
        output<<"Nacin gradnje:"<<temp;
         string tempp;
    switch(b.tip){
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
        output<<"Tip bolnice:"<<tempp;
         if(b.spisakPacijenata.size() == 0) {
            output << endl << "Nema pacijenata." << endl;
        } else {
            Pacijent* o;
            output << endl << "Pacijent:" << endl;
            for (int i = 1; i <= b.spisakPacijenata.size(); i++){
                b.spisakPacijenata.read(i, o);
                output<<o;
            }
            }
             if(b.spisakDoktora.size() == 0) {
            output<< endl << "Nema doktora." << endl;
        } else {
            Doktor* o;
            output<< endl << "Doktori:" << endl;
            for (int i = 1; i <= b.spisakDoktora.size(); i++){
                b.spisakDoktora.read(i, o);
                output<<o;
            }
}
 if(b.spisakSestri.size() == 0) {
            output<< endl << "Nema sestara." << endl;
        } else {
            Sestra* o;
             output<< endl << "Sestre:" << endl;
            for (int i = 1; i <= b.spisakSestri.size(); i++){
                b.spisakSestri.read(i, o);
                output<<o;
            }
}
output<<b.prijemana_ambulanta<<endl;
output<<b.mrtvacnica<<endl;
 if(b.osoblje.size() == 0) {
            output << endl << "Nema tehnickog osoblja." << endl;
        } else {
            TehnickoOsoblje* o;
            output<< endl << "Tehnicko osoblje:" << endl;
            for (int i = 1; i <= b.osoblje.size(); i++){
                b.osoblje.read(i, o);
                output<<o;
            }
}
output<<b.hitna<<endl;
 if(b.Laboranti.size() == 0) {
            output << endl << "Nema laboranata." << endl;
        } else {
            Laborant* o;
            output << endl << "Laborant:" << endl;
            for (int i = 1; i <= b.Laboranti.size(); i++){
                b.Laboranti.read(i, o);
                output<<o;
            }
}
output<<b.lab<<endl;
output<<b.ka<<endl;
output<<b.apoteka<<endl;
if(b.sobe.size() == 0) {
            output << endl << "Nema soba." << endl;
        } else {
            BolnickaSoba* o;
            output << endl << "Sobe:" << endl;
            for (int i = 1; i <= b.sobe.size(); i++){
                b.sobe.read(i, o);
                output<<o;
            }
}
if(b.toaleti.size() == 0) {
            output<< endl << "Nema toaleta." << endl;
        } else {
            BolnickiToalet* o;
            output << endl << "Toaleti:" << endl;
            for (int i = 1; i <= b.toaleti.size(); i++){
                b.toaleti.read(i, o);
                output<<o;
            }
}
return output;

}
istream &operator>>(istream& input, Bolnica &b){
    string s1,s2,s3;
        int i1,i2;
        int a1,a2;
        cout<<"Unesite ime:"<<endl;
        input>>b.ime;
        cout<<"Unesite lokaciju:"<<endl;
        input>>b.lokacija;
        cout<<"Unesite kontakt:"<<endl;
        input>>b.kontakt;
        cout<<"Unesite broj kreveta:"<<endl;
        input>>b.brojKreveta;
        cout<<"Unesite broj zauzetih kreveta:"<<endl;
        input>>b.brojZautetihKreveta;
        cout<<"Unesite nacin gradnje(0-paviljonski,1-koridorni,2-blok,3-sistemBaraka,4-tranbantni):"<<endl;
        input>>a1;
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
        input>>a2;
        switch(a2){
    case 0:
        b.tip=opsta;
        break;
    case 1:
        b.tip=specificna;
        break;
        }
        return input;

}

ostream &operator<<(ostream& output, const Pacijent &o){


        output<<"Ime :"<<o.ime;
        output<<"Prezime:"<<o.prezime;
        output<<"Kontakt:"<<o.kontakt;
        output<<"Datum rodjenja:"<<o.datumRodjenja;
        string temp;
    switch(o.pol){
        case zenski:
            temp = "zenski";
            break;
        case muski:
            temp = "muski";
            break;
            temp = "nedefinisan";
            break;
            }
             output<<"Pol:"<<temp;
        string temp3;
    switch(o.grupa){
        case Ap:
            temp3 = "A pozitina";
            break;
        case An:
            temp3 = "A negativna";
            break;
            case Bp:
            temp3 = "B pozitina";
            break;
        case Bn:
            temp3 = "B negativna";
            break;
            case ABp:
            temp3 = "AB pozitina";
            break;
        case ABn:
            temp3 = "AB negativna";
            break;
            case op:
            temp3 = "0 pozitina";
            break;
        case on:
            temp3 = "0 negativna";
            break;
            default:
            temp3 = "nedefinisan";
            break;
            }
            string temp2;
switch(o.uput){
case false:
    temp2="nema uputa";
    break;
case true:
    temp2="ima uput";
    break;
default:
    temp2="nedefinisano";
}

        output<<"Krvna grupa :"<<temp3;
        output<<"Uput:"<<temp2;
        output<<"Datum prijema u bolnicu:"<<o.datumPrijema;
        output<<"ID pacijenta:"<<o.id;
        return output;
}
istream &operator>>(istream&input, Pacijent &p){

        int x1,y1,z1;
       cout<<"Unesite ime:"<<endl;
       input>>p.ime;
       cout<<"Unesite prezime:"<<endl;
       input>>p.prezime;
       cout<<"Unesite kontakt:"<<endl;
       input>>p.kontakt;
       int x2,y2,z2;
       cout<<"Unesite mesec rodjenja:";
       input>>x2;
       cout<<"dan:";
       input>>y2;
       cout<<"godinu:";
       input>>z2;
       p.setDatumRodjenja(x2,y2,z2);
       cout<<"Unesite mesec prijema:";
       input>>x1;
       cout<<"dan:";
       input>>y1;
       cout<<"godinu:";
       input>>z1;
        p.setDatumPrijemaPacijenta(x1,y1,z1);
       cout<<"Unesite id:"<<endl;
       input>>p.id;
       cout<<"Unesite pol(0-muski,1-zenski):"<<endl;
       int i,x;
       input>>i;
        switch(i){
        case 1:
            p.pol=zenski;
            break;
        case 0:
            p.pol=muski;
            break;
      }
       cout<<"Unesite krvnu grupu(0-Ap,1-An,2-Bp,3-Bn,4-op,5-on,6-ABp,7-ABn):"<<endl;
       input>>x;
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
            input>>y;
        switch(y){
case 0:
    p.uput=false;
    break;
case 1:
    p.uput=true;
    break;
    }

    return input;
}

ostream &operator<<(ostream&output, const Doktor &d){

        output<<"Ime :"<<d.ime;
        output<<"Prezime:"<<d.prezime;
        output<<"Kontakt:"<<d.kontakt;
        output<<"Datum rodjenja:"<<d.datumRodjenja;
        string temp;
    switch(d.pol){
        case zenski:
            temp = "zenski";
            break;
        case muski:
            temp = "muski";
            break;
            temp = "nedefinisan";
            break;
            }
             output<<"Pol:"<<temp;
output<<"Plata:"<<d.plata;
output<<"Specijalizacija:"<<d.specijalizacija;
output<<"Zavrsene studije:"<<d.studije;
}
istream &operator>>(istream& input, Doktor &d){

    cout<<"Unesite ime:";
       input>>d.ime;
       cout<<"Unesite prezime:";
       input>>d.prezime;
       cout<<"Unesite kontakt:";
       input>>d.kontakt;
       int x2,y2,z2;
       cout<<"Unesite mesec rodjenja:";
       input>>x2;
       cout<<"dan:";
       input>>y2;
       cout<<"godinu:";
       input>>z2;
       d.setDatumRodjenja(x2,y2,z2);
       cout<<"Unesite pol(0-muski,1-zenski):";
       int i,x;
       input>>i;
        switch(i){
        case 1:
            d.pol=zenski;
            break;
        case 0:
            d.pol=muski;
            break;
             }
             cout<<"Unesite platu:";
             input>>d.plata;
             cout<<"Unesite zavrsene studije:";
             input>>d.studije;
             cout<<"Unesite specijalizaciju:";
             input>>d.specijalizacija;
return input;
}

Soba::Soba(){
sirina=1;
visina=1;
}
Soba::Soba(int a,int b){
sirina=a;
visina=b;
}
Soba::Soba(Soba& s){
sirina=s.sirina;
visina=s.visina;
}
int Soba::getSirinu(){
return sirina;
}
int Soba::getVisinu(){
return visina;
}
void Soba::setSirinu(int i){
if(i>0)
sirina=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void Soba::setVisinu(int i){
if(i>0)
visina=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;

}

BolnickaSoba::BolnickaSoba():spisakPacijenata(){
brojLezaja=5;
}
BolnickaSoba::BolnickaSoba(int i,int a,List<Pacijent*> p):RastojanjeIzmedjuKreveta(a),spisakPacijenata(p){
brojLezaja=i;
}
BolnickaSoba::BolnickaSoba(BolnickaSoba &b):spisakPacijenata(b.spisakPacijenata){
brojLezaja=b.brojLezaja;
}
void BolnickaSoba::setBrojLezaja(int i){
if(i>0)
brojLezaja=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void BolnickaSoba::setRastojanje(int i){
if(i>0)
    RastojanjeIzmedjuKreveta=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;

}
void BolnickaSoba::setSpisakPacijenata(List<Pacijent*> s){
spisakPacijenata=s;
}
int BolnickaSoba::getBrojLezaja(){
return brojLezaja;
}
int BolnickaSoba::getRastojanje(){
return RastojanjeIzmedjuKreveta;
}
List<Pacijent*> BolnickaSoba::getSpisakPacijenata(){
return spisakPacijenata;
}

Toalet::Toalet(){
visina=1;
sirina=1;
brojKabina=1;
}
Toalet::Toalet(int i,int a,int b){
sirina=i;
visina=a;
brojKabina=b;
}
Toalet::Toalet(Toalet & t){
sirina=t.sirina;
visina=t.visina;
brojKabina=t.brojKabina;
}
void Toalet::setBrojKabina(int i){
if(i>0)
    brojKabina=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void Toalet::setSirina(int i){
if(i>0)
sirina=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void Toalet::setVisina(int i){
if(i>0)
visina=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;

}
int Toalet::getBrojKabina(){
return brojKabina;
}
int Toalet::getSirinu(){
return sirina;
}
int Toalet::getVisina(){
return visina;
}
BolnickiToalet::BolnickiToalet(){
brojInvalidskihPrinceza=1;
}
BolnickiToalet::BolnickiToalet(int i){
    brojInvalidskihPrinceza=i;
}
BolnickiToalet::BolnickiToalet(BolnickiToalet & bt){
brojInvalidskihPrinceza=bt.brojInvalidskihPrinceza;
}
void BolnickiToalet::setBrojInvalidskihPrinceza(int i){
if(i>0)
brojInvalidskihPrinceza=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
int BolnickiToalet::getBrojInvalidskihPrinceza(){
return brojInvalidskihPrinceza;
}

Bolnica::Bolnica():spisakPacijenata(),spisakDoktora(),spisakSestri(),prijemana_ambulanta(),mrtvacnica(),osoblje(),snabdevanjeKrvlju(),hitna(),Laboranti(),lab(),ka(),kdeo(),apoteka(),sobe(){

ime="Bolnica";
lokacija="Zlatne Grede 4";
kontakt="bolnica@gmail.com";
brojKreveta=300;
brojZautetihKreveta=250;
gradnja=blok;
tip=opsta;


}
Bolnica::Bolnica(string imeb, string l, string konb, int bk,int bzk,NacinGradnje n,TipBolnice t,List<Pacijent*> spisakPacijenataa,
    List<Doktor*> spisakDoktoraa,
    List<Sestra*> spisakSestrii,
    PrijemnaAmbulanta prijemana_ambulantaa,
    Mrtvacnica* mrtvacnicaa,
    List<TehnickoOsoblje*> osobljee,
    OdeljenjeZaSnabdevanjeKrvlju snabdevanjeKrvljuu,
    Hitna hitnaa,
    List<Laborant*> Laborantii,
    Laboratorija labb,
    KovidAmbulanta kaa,
    KovidDeo kdeoo,
    Apoteka apotekaa,
    List<BolnickaSoba*> sobee,
    List<BolnickiToalet*> toaletii){

    ime=imeb;
    lokacija=l;
    kontakt=konb;
    brojKreveta=bk;
    brojZautetihKreveta=bzk;
    gradnja=n;
    tip=t;
    spisakPacijenata=spisakPacijenataa;
    spisakDoktora=spisakDoktoraa;
    spisakSestri=spisakSestrii;
    prijemana_ambulanta=prijemana_ambulantaa;
    mrtvacnica=mrtvacnicaa;
    osoblje=osobljee;
    snabdevanjeKrvlju=snabdevanjeKrvljuu;
    hitna=hitnaa;
    Laboranti=Laborantii;
    lab=labb;
    ka=kaa;
    kdeo=kdeoo;
    apoteka=apotekaa;
    sobe=sobee;
    toaleti=toaletii;

}
Bolnica::Bolnica(const Bolnica& b){

    ime=b.ime;
    lokacija=b.lokacija;
    kontakt=b.kontakt;
    brojKreveta=b.brojKreveta;
    brojZautetihKreveta=b.brojZautetihKreveta;
    gradnja=b.gradnja;
    tip=b.tip;
    spisakPacijenata=b.spisakPacijenata;
    spisakDoktora=b.spisakDoktora;
    spisakSestri=b.spisakSestri;
    prijemana_ambulanta=b.prijemana_ambulanta;
    mrtvacnica=b.mrtvacnica;
    osoblje=b.osoblje;
    snabdevanjeKrvlju=b.snabdevanjeKrvlju;
    hitna=b.hitna;
    Laboranti=b.Laboranti;
    lab=b.lab;
    ka=b.ka;
    kdeo=b.kdeo;
    apoteka=b.apoteka;
    sobe=b.sobe;
    toaleti=b.toaleti;
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
List<Pacijent*> Bolnica::getspisakPacijenata(){
return spisakPacijenata;
}
List<Doktor*> Bolnica::getspisakDoktoraa(){
return spisakDoktora;
}
List<Sestra*> Bolnica::getspisakSestri(){
return spisakSestri;
}
PrijemnaAmbulanta Bolnica::getprijemana_ambulanta(){
return prijemana_ambulanta;
}
Mrtvacnica* Bolnica::getmrtvacnica(){
return mrtvacnica;
}
List<TehnickoOsoblje*> Bolnica::getosoblje(){
return osoblje;
}
OdeljenjeZaSnabdevanjeKrvlju Bolnica::getsnabdevanjeKrvlju(){
return snabdevanjeKrvlju;
}
Hitna Bolnica::gethitna(){
return hitna;
}
List<Laborant*> Bolnica::getLaboranti(){
return Laboranti;
}
Laboratorija Bolnica::getlab(){
return lab;
}
KovidAmbulanta Bolnica::getka(){
return ka;
}
KovidDeo Bolnica::getkdeo(){
return kdeo;
}
Apoteka Bolnica::getapoteka(){
return apoteka;
}
List<BolnickaSoba*> Bolnica::getsobe(){
return sobe;
}
List<BolnickiToalet*> Bolnica::gettoaleti(){
return toaleti;
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
        if(i>0)
        brojKreveta=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
    }
void Bolnica::setBrojZauzetihKreveta(const int i){
     if(i>0)
        brojZautetihKreveta=i;
    else
    cout<<"Nije uneta validna vrednost!"<<endl;
    }
void Bolnica::setNacinGradnje(const NacinGradnje i){
        gradnja=i;
    }
void Bolnica::setTipBolnice(const TipBolnice i){
        tip=i;
    }
void Bolnica::setspisakPacijenata(List<Pacijent*>i){
spisakPacijenata=i;
}
void Bolnica::setspisakDoktora(List<Doktor*>i){
spisakDoktora=i;
}
void Bolnica::setspisakSestri(List<Sestra*>i){
spisakSestri=i;
}
void Bolnica::setprijemana_ambulanta(PrijemnaAmbulanta i){
prijemana_ambulanta=i;
}
void Bolnica::setmrtvacnica(Mrtvacnica* i){
mrtvacnica=i;
}
void Bolnica::setosoblje(List<TehnickoOsoblje*> i){
osoblje=i;
}
void Bolnica::setsnabdevanjeKrvlju(OdeljenjeZaSnabdevanjeKrvlju i){
snabdevanjeKrvlju=i;
}
void Bolnica::sethitna(Hitna i){
hitna=i;
}
void Bolnica::setLaboranti(List<Laborant*> i){
Laboranti=i;
}
void Bolnica::setlab(Laboratorija i){
lab=i;
}
void Bolnica::setka(KovidAmbulanta i){
ka=i;
}
void Bolnica::setkdeo(KovidDeo i ){
kdeo=i;
}
void Bolnica::setapoteka(Apoteka i){
apoteka=i;
}
void Bolnica::setsobe(List<BolnickaSoba*> i){
sobe=i;
}
void Bolnica::settoaleti(List<BolnickiToalet*> i){
toaleti=i;
}

Osoba::Osoba():datumRodjenja(4,11,2021){

    ime="Marija";
    prezime="Milenkovic";
    kontakt="0651234567";
    pol=zenski;

 }
Osoba::Osoba(string ime1, string prezime1, string kon, Datum DatRodj, Pol p ):datumRodjenja(DatRodj){

    ime=ime1;
    prezime=prezime1;
    kontakt=kon;
    pol=p;

 }
Osoba::Osoba(const Osoba& o):datumRodjenja(o.datumRodjenja){

    ime=o.ime;
    prezime=o.prezime;
    kontakt=o.kontakt;
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
Datum Osoba::getDatumRodjenja()const{
cout<<datumRodjenja;
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
void Osoba::setDatumRodjenja(const int x1,const int y1,const int z1){
if(x1>0 && y1>0 && z1>0){
Datum d(x1,y1,z1);
datumRodjenja=d;
}else
cout<<"Nije uneta validna vrednost!"<<endl;
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

Pacijent::Pacijent():datumPrijema(1,2,3){
    Osoba:Osoba();
    uput=true;
    id=1;
    }
Pacijent::Pacijent(string ime1, string prezime1, string kon, Datum DatRodj, Pol p ,KrvnaGrupa krv, bool u,Datum DatPrijema, int i):datumPrijema(DatPrijema) {

    Osoba:Osoba(ime1,prezime1,kon,DatRodj,p);
    grupa=krv;
    uput=u;
    id=i;

	}
Pacijent::Pacijent(const Pacijent& p):datumPrijema(p.datumPrijema){

    Osoba:Osoba((Osoba)p);
    grupa=p.grupa;
    uput=p.uput;
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
Datum Pacijent::getDatumPrijemaPacijenta()const{
cout<<datumPrijema;
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
void Pacijent::setDatumPrijemaPacijenta(const int x1,const int y1,const int z1){
if(x1>0 && y1>0 && z1>0){
Datum d1(x1,y1,z1);
datumPrijema=d1;
}else
cout<<"Nije uneta validna vrednost!"<<endl;
}
void Pacijent::setIDPacijenta(const int i){
if(i>0)
id=i;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
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
Doktor::Doktor(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,int pt, string spc,string stdj){

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
    if(p>0)
plata=p;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
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
Sestra::Sestra(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,tipSestre t, bool gs,int pl){
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
   if(pl>0)
    plata=pl;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
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
Mrtvacnica::Mrtvacnica(List<Pacijent*> p1,int bm,int bsm):p(p1){
    brojMesta=bm;
    brojZauzetihMesta=bsm;

}
Mrtvacnica::Mrtvacnica(Mrtvacnica & m):p(m.p){
    brojMesta=m.brojMesta;
    brojZauzetihMesta=m.brojZauzetihMesta;

}
void Mrtvacnica::setBrojMesta(const int bm){
if(bm>0)
brojMesta=bm;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void Mrtvacnica::setBrojSlobodnihMesta(const int bsm){
if(bsm>0)
brojZauzetihMesta=bsm;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
}
void Mrtvacnica::setP(const List<Pacijent*> p1){
p=p1;
}
int Mrtvacnica::getBrojMesta()const{
return brojMesta;
}
int Mrtvacnica::getBrojSlobodnihMesta()const{
return brojZauzetihMesta;
}
List<Pacijent*> Mrtvacnica::getP(){
return p;
}
ostream &operator<<(ostream& out, const Mrtvacnica &b){
out<<"Pacijenti:"<<endl;
if(b.p.size() == 0) {
            out<< endl << "Nema pacijenata." << endl;
        } else {
            Pacijent* o;
            out << endl << "Pacijent:" << endl;
            for (int i = 1; i <= b.p.size(); i++){
                b.p.read(i, o);
                out<<o;
            }
            }
out<<"Broj mesta:"<<b.brojMesta<<endl;
out<<"Broj zauzetih mesta:"<<b.brojZauzetihMesta<<endl;
return out;
}

TehnickoOsoblje::TehnickoOsoblje(){

    Osoba:Osoba();
    t=kuvar;
    plata=30000;

}
TehnickoOsoblje::TehnickoOsoblje(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,TipTehnickogOsoblja t1,int pl){
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
if(po>0)
plata=po;
else
    cout<<"Nije uneta validna vrednost!"<<endl;
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
void OdeljenjeZaSnabdevanjeKrvlju::setOsoba(const Osoba o1){
o=o1;
}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv()const{return brojAp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv1()const{return brojAn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv2()const{return brojBp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv3()const{return brojBn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv4()const{return brojABp;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv5()const{return brojABn;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv6()const{return brojop;}
int OdeljenjeZaSnabdevanjeKrvlju::getKrv7()const{return brojon;}
Osoba OdeljenjeZaSnabdevanjeKrvlju::getOsoba(){
return o;
}
ostream& operator<<(ostream&out,OdeljenjeZaSnabdevanjeKrvlju& o){
out<<o.brojABn<<o.brojABp<<o.brojAn<<o.brojAp<<o.brojBn<<o.brojBp<<o.brojon<<o.brojop<<endl;
out<<o.o;
return out;
}

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
if(c>0)
mestaUcekaonici=c;
else
    cout<<"Uneta vrednost nije validna!"<<endl;
}
void PrijemnaAmbulanta::setDoktora(const Doktor d1){
d=d1;
}
void PrijemnaAmbulanta::setSestru(const Sestra s1){
s=s1;
}
void PrijemnaAmbulanta::setPacijenta(const Pacijent p1){
p=p1;
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
Doktor PrijemnaAmbulanta::getDoktora(){
return d;
}
Sestra PrijemnaAmbulanta::getSestru(){
return s;
}
Pacijent PrijemnaAmbulanta::getPacijenta(){
return p;
}
ostream &operator<<(ostream& out, const PrijemnaAmbulanta &b){
out<<b.d;
out<<b.s;
out<<b.p;
switch(b.vitalniZnaci){
case true:
    out<<"Ima vitalnih znaka"<<endl;
    break;
case false:
    out<<"Nema vitalnih znakova"<<endl;
    break;
default:
    out<<"Nedefinisano"<<endl;
}
out<<"Broj mesta u cekaonici:"<<b.mestaUcekaonici<<endl;
return out;
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
void Hitna::setDoktora(const Doktor d1){
d=d1;
}
void Hitna::setSestru(const Sestra s1){
s=s1;
}
int Hitna::getBrojVozila()const{
return brojVozila;
}
int Hitna::getBrojKreveta()const{
return brojKreveta;
}
Doktor Hitna::getDoktora(){
return d;
}
Sestra Hitna::getSestru(){
return s;
}
ostream &operator<<(ostream&out, const Hitna &b){
out<<"Doktor:"<<b.d;
out<<"Sestra:"<<b.s;
out<<"Broj kreveta:"<<b.brojKreveta;
out<<"Broj vozila:"<<b.brojVozila;
return out;
}

Laborant::Laborant(){
  Osoba:Osoba();
  plata=70000;
  }
Laborant::Laborant(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,int p1){
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
void Laboratorija::setLaboranta(const Laborant l1){
l=l1;
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
Laborant Laboratorija::getLaboranta(){
return l;
}
ostream &operator<<(ostream&out, const Laboratorija &b){
out<<b.l;
out<<"stanje nalaza:"<<b.stanjen<<endl;
out<<"id nalaza:"<<b.idNalaza<<endl;
out<<"broj nezavrsenih nalaza:"<<b.brojNezavrsenihNalaza<<endl;
return out;
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
void KovidAmbulanta::setSestru(const Sestra s1){
s=s1;
}
void KovidAmbulanta::setPacijenta(const Pacijent p1){
p=p1;
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
Sestra KovidAmbulanta::getSestru(){
return s;
}
Pacijent KovidAmbulanta::getPacijent(){
return p;
}
ostream &operator<<(ostream&out, const KovidAmbulanta &b){
out<<b.s<<endl;
out<<b.p<<endl;
out<<"zastita:"<<b.zastita<<endl;
out<<"tip testa:"<<b.tipTesta<<endl;
out<<"broj novozarazenih:"<<b.brojNovoZarazenih<<endl;
return out;
}

template <class T>
ostream& operator<<(ostream& out, const List<T>& rl) {
	out << endl;
	out << "--------" << endl;
	for(int i = 1; i <= rl.size(); i++){
		if(i != 1) out << ", ";
		T res;
		rl.read(i, res);
		out << res;
	}
	out << endl << "--------" << endl;
	return out;
}
template <class T>
List<T>::List(const List<T>& rl) {
	head = NULL;
	tail = NULL;
	noEl = 0;

	for(int i = 1; i <= rl.noEl; i++){
		T res;
		if(rl.read(i, res))
			add(i, res);
	}
}
template <class T>
List<T>& List<T>::operator=(const List<T>& rl) {
	if(this != &rl) {
		clear();
		head = NULL;
		tail = NULL;
		noEl = 0;

		for(int i = 1; i <= rl.noEl; i++){
			T res;
			if(rl.read(i, res))
				add(i, res);
		}
	}
	return *this;
}
template <class T>
List<T>::~List() {
	while(!empty())
		remove(1);
}
template <class T>
bool List<T>::add(int n, const T& newContent) {
	if(n < 1 || n > noEl + 1)
		return false;
	else {
		listEl* newEl = new listEl;
		if(newEl == NULL)
			return false;
		else {
			newEl->content = newContent;
			if(n == 1) {
				newEl->next = head;
				head = newEl;
			} else if(n == noEl + 1) {
				newEl->next = NULL;
				tail->next = newEl;
			} else {
				listEl* temp = head;
				for(int i = 2; i < n; i++)
					temp = temp->next;
				newEl->next = temp->next;
				temp->next = newEl;
			}
			noEl++;
			if(newEl->next == NULL)
				tail = newEl;
			return true;
		}
	}
}
template <class T>
bool List<T>::remove(int n){
	if(n < 1 || n > noEl)
		return false;
	else {
		if(n == 1) {
			listEl* del = head;
			head = head->next;
			if(tail == del)
				tail = NULL;
			delete del;
			noEl--;
		} else {
			listEl* temp = head;
			for(int i = 2; i < n; i++)
				temp = temp->next;
			listEl* del = temp->next;
			temp->next = del->next;
			if(tail == del)
				tail = temp;
			delete del;
			noEl--;
		}
		return true;
	}
}
template <class T>
bool List<T>::read(int n,T& retVal) const {
	if(n < 1 || n > noEl)
		return false;
	else {
		if(n == 1)
			retVal = head->content;
		else if(n == noEl)
			retVal = tail->content;
		else {
			listEl* temp = head;
			for(int i = 1; i < n; i++)
				temp = temp->next;
			retVal = temp->content;
		}
		return true;
	}
}
template <class T>
void List<T>::clear() {
	while(!empty())
		remove(1);
}

Parking::Parking():nizSlobodnihMesta(),nizZauzetihMesta(),nizVIPmesta(){
    brojSpratova=1;
    naplata=1;
}
Parking::Parking(List<int> a,List<int> b,List<int> c, int d,int e):nizSlobodnihMesta(a),nizZauzetihMesta(b),nizVIPmesta(c),brojSpratova(d),naplata(e){}
Parking::Parking(Parking& p):nizSlobodnihMesta(p.nizSlobodnihMesta),nizZauzetihMesta(p.nizZauzetihMesta),nizVIPmesta(p.nizVIPmesta),brojSpratova(p.brojSpratova),naplata(p.naplata){}
void Parking::setnizZauzetihMesta(List<int> l){
nizZauzetihMesta=l;
}
void Parking::setnizSlobodnihMesta(List<int> l){
nizSlobodnihMesta=l;
}
void Parking::setBrojSpratova(const int b){
brojSpratova=b;
}
void Parking::setnizVIPMesta(List<int> l){
nizVIPmesta=l;
}
void Parking::setNaplata(const int b){
naplata=b;
}
List<int> Parking::getnizZauzetihMesta()const{
return nizZauzetihMesta;
}
List<int> Parking::getnizSlobodnihMesta()const{
return nizSlobodnihMesta;
}
int Parking::getBrojSpratova()const{
return brojSpratova;
}
List<int> Parking::getnizVIPMesta()const{
return nizVIPmesta;
}
int Parking::getnaplata()const{
return naplata;
}
void Parking::ispisNizSlobodnihMesta(){
        if(nizSlobodnihMesta.size() == 0)
        {
            cout<<"------>Nema slobodnih mesta"<<endl;
        }
        else
        {
            int d;
            cout<<"Niz slobodnih mesta:"<<endl;
            cout<<endl;
            for (int i = 1; i <= nizSlobodnihMesta.size(); i++)
            {
                nizSlobodnihMesta.read(i, d);
                cout<<d;
            }
        }
    }
void Parking::ispisNizZauzetihMesta(){
if(nizZauzetihMesta.size() == 0)
        {
            cout<<"------>Nema zauzetih mesta"<<endl;
        }
        else
        {
            int d;
            cout<<"Niz zauzetih mesta:"<<endl;
            cout<<endl;
            for (int i = 1; i <= nizZauzetihMesta.size(); i++)
            {
                nizZauzetihMesta.read(i, d);
                cout<<d;
            }
        }
}
void Parking::ispisNizVIPMesta(){
if(nizVIPmesta.size() == 0)
        {
            cout<<"------>Nema VIP mesta"<<endl;
        }
        else
        {
            int d;
            cout<<"Niz VIP mesta:"<<endl;
            cout<<endl;
            for (int i = 1; i <= nizVIPmesta.size(); i++)
            {
                nizVIPmesta.read(i, d);
                cout<<d;
            }
        }
}
void Parking::ispisParking(){
ispisNizSlobodnihMesta();
ispisNizZauzetihMesta();
ispisNizVIPMesta();
cout<<"Broj spratova:"<<brojSpratova<<endl;
cout<<"Naplata:"<<naplata<<endl;

}

Lek::Lek(){
    jkl=10000000;
    naziv="aspirin";
    jedinicnaCena=200;
    kolicina=200;
    }
Lek::Lek(int j,string n,double c, int k):naziv(n){
    jkl=j;
    jedinicnaCena=c;
    kolicina=k;
    }
Lek::Lek(Lek& l){
    jkl=l.jkl;
    naziv=l.naziv;
    jedinicnaCena=l.jedinicnaCena;
    kolicina=l.kolicina;
    }
int Lek::getJKL(){
return jkl;
}
string Lek::getNaziv(){
return naziv;
}
double Lek::getJedinicnaCena(){
return jedinicnaCena;
}
int Lek::getKolicina(){
return kolicina;
}
void Lek::setJKl(int jk){
jkl=jk;
}
void Lek::setNaziv(string s){
naziv=s;
}
void Lek::setJedinicnuCenu(double cena){
jedinicnaCena=cena;
}
void Lek::setKolicina(int i){
kolicina=i;
}
double Lek::izvracunajVrednostArtikla(){
    kolicina*jedinicnaCena;
    }
ostream& operator<<(ostream& out, const Lek& l) {
    out<<l.jkl<<endl;
    out << l.naziv;
    out<<"Cena:"<<l.jedinicnaCena<<endl;
    out<<"Kolicina:"<<l.kolicina<<endl;
    return out;
}

Apoteka::Apoteka():apotekar(),sestra(),spisakLekova(){}
Apoteka::Apoteka(List<Lek*> l,Osoba o,Sestra s):apotekar(o),sestra(s),spisakLekova(l){}
Apoteka::Apoteka(Apoteka& a):apotekar(a.apotekar),sestra(a.sestra),spisakLekova(a.spisakLekova){}
void Apoteka::setApotekar(const Osoba o){
apotekar=o;
}
void Apoteka::setSestru(const Sestra s){
sestra=s;
}
void Apoteka::setSpisakLekova(List<Lek*> s){
spisakLekova=s;
}
Osoba Apoteka::getApotekar(){
return apotekar;
}
Sestra Apoteka::getSestra(){
return sestra;
}
List<Lek*> Apoteka::getSpisakLekova(){
return spisakLekova;
}
void Apoteka::ispisSpisakLekova(){
        if(spisakLekova.size() == 0) {
            cout << endl << "Nema lekova." << endl;
        } else {
            Lek* o;
            cout << endl << "Spisak lekova:" << endl;
            for (int i = 1; i <= spisakLekova.size(); i++){
                spisakLekova.read(i, o);
                cout<<o;
            }
}
}
void Apoteka::ispisApoteke(){
ispisSpisakLekova();
cout<<sestra;
cout<<apotekar;
}
ostream &operator<<(ostream&out, const Apoteka &b){
out<<b.apotekar<<endl;;
out<<b.sestra<<endl;
if(b.spisakLekova.size() == 0) {
            out << endl << "Nema lekova." << endl;
        } else {
            Lek* o;
            out << endl << "Spisak lekova:" << endl;
            for (int i = 1; i <= b.spisakLekova.size(); i++){
                b.spisakLekova.read(i, o);
                out<<o;
            }
}


return out;
}

KovidDeo::KovidDeo():a(),spisak(){
brojOsobaUintenzivnoj=50;
brojOsobaUpoluIntenzivnoj=150;
brojRespiratora=50;
}
KovidDeo::KovidDeo(KovidAmbulanta k,List<Pacijent*> l,int i, int x,int y):a(k),spisak(l){
brojOsobaUintenzivnoj=i;
brojOsobaUpoluIntenzivnoj=x;
brojRespiratora=y;
}
KovidDeo::KovidDeo(KovidDeo&k):a(k.a),spisak(k.spisak){
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
void KovidDeo::setSpisak(List<Pacijent*> p){
spisak=p;
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
List<Pacijent*> KovidDeo::getSpisak(){
return spisak;
}
void KovidDeo::setKovidAmbulantu(const KovidAmbulanta k){
a=k;
}
KovidAmbulanta KovidDeo::getKovidAmbulantu(){
return a;
}
ostream &operator<<(ostream&out, const KovidDeo &b){
out<<b.a<<endl;
if(b.spisak.size() == 0) {
            out << endl << "Nema pacijenata." << endl;
        } else {
            Pacijent* o;
            out << endl << "Pacijenti:" << endl;
            for (int i = 1; i <= b.spisak.size(); i++){
                b.spisak.read(i, o);
                out<<o;
            }
            }
out<<"Broj respiratora:"<<b.brojRespiratora<<endl;
out<<"Broj osoba na intenzivnoj:"<<b.brojOsobaUintenzivnoj<<endl;
out<<"Broj osoba na poli intenzivnoj:"<<b.brojOsobaUpoluIntenzivnoj<<endl;
return out;
}
