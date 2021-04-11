#ifndef BOLNICA_HPP_INCLUDED
#define BOLNICA_HPP_INCLUDED
#include <string>
#define MAX 20

using namespace std;

enum Pol{muski,zenski};
enum KrvnaGrupa{Ap,An,Bp,Bn,op,on,ABp,ABn};
enum NacinGradnje{paviljonski, koridorni, blok, sistemBaraka, tranbantni};
enum TipBolnice{opsta, specificna};
enum tipSestre{pedijatrijska, medicinska, instrumentarka, ginekolosko_akusarska, anesteticarka};
enum TipTehnickogOsoblja{kuvar,cistacica,domar,tehnicar};
enum stanjeNalaza{primljen,obradjuje_se,gotov};
enum TipTesta{BrisIzNosa,BrisIzGrla,TestNaAntitela};

class BrojTelefona{

    protected:
    char prviDeo[5];
    char drugiDeo[4];
    char treciDeo[5];

    public:
    friend ostream &operator<<(ostream&, const BrojTelefona &);
    friend istream &operator>>(istream&, BrojTelefona &);
};
class Datum{
protected:
    int mesec, dan, godina;
public:
    Datum(int x,int y,int z);
    friend ostream& operator<<(ostream& o, const Datum& d);
};
class Bolnica {

public:

    string ime;
    string lokacija;
    string kontakt;
    int brojKreveta;
    int brojZautetihKreveta;
    NacinGradnje gradnja;
    TipBolnice tip;

public:

    Bolnica();
	Bolnica(string imeb, string l, string konb, int bk,int bzk,NacinGradnje n,TipBolnice t);
	Bolnica(const Bolnica& b);

    string getImeBolnice()const;
    string getKontaktBolnice()const;
    string getLokacija()const;
    int getBrojKreveta()const;
    int getBrojZauzetihKreveta()const;
    string getNacinGradnje()const;
    string getTipBolnice()const;

    void setImeBolnice(const string s);
    void setLokacijaBolnice(const string s);
    void setKontaktBolnice(const string s);
    void setBrojKreveta( const int i);
    void setBrojZauzetihKreveta(const int i);
    void setNacinGradnje(const NacinGradnje i);
    void setTipBolnice(const TipBolnice i);

    void ispis();

};
class Osoba{

public:

     string ime;
     string prezime;
     string kontakt;
     string datumRodjenja;
     Pol pol;

public:

    Osoba();
	Osoba(string ime1, string prezime1, string kon, string DatRodj, Pol p );
	Osoba(const Osoba& o);

    string getIme()const;
    string getPrezime()const;
    string getKontakt()const;
    string getDatumRodjenja()const;
    string getPol()const;

    void setIme(const string s);
    void setPrezime(const string s);
    void setKontakt(const string s);
    void setDatumRodjenja(const string s);
    void setPol(const Pol s);


    void ispisOsobe();

};
class Pacijent:public Osoba{

public:

    KrvnaGrupa grupa;
    bool uput;
    string datumPrijema;
    int id;

public:

    Pacijent();
	Pacijent(string ime1, string prezime1, string kon, string DatRodj, Pol p ,KrvnaGrupa krv, bool u,string DatPrijema, int i);
	Pacijent(const Pacijent& p);

    string getKrvnaGrupaPacijenta()const;
    string getUputPacijenta()const;
    string getDatumPrijemaPacijenta()const;
    int getIDPacijenta()const;

    void setGrupa(const KrvnaGrupa k);
    void setUput(const bool u);
    void setDatumPrijemaPacijenta(const string s);
    void setIDPacijenta(const int i);


    void ispisPacijenta();
};
class Doktor:public Osoba{

public:
    int plata;
    string specijalizacija;
    string studije;
public:
    Doktor();
    Doktor(string ime1, string prezime1, string kon, string DatRodj, Pol p,int pt, string spc,string stdj);
    Doktor(const Doktor& d);

    int getPlata()const;
    string getSpecijalizacija()const;
    string getStudije()const;

    void setPlata(const int p);
    void setSpecijalizacija(const string sp);
    void setStudije(const string stdj);

    void ispisDoktora();

};
class Sestra:public Osoba{

protected:
    tipSestre tipS;
    bool GlavnaSestra;
    int plata;
public:
    Sestra();
    Sestra(string ime1, string prezime1, string kon, string DatRodj, Pol p,tipSestre t, bool gs,int pl);
    Sestra(const Sestra& s);

    string getTipSestre()const;
    string getGlavnaSestra()const;
    int getPlataSestre()const;

    void setTipSestre(const tipSestre ts);
    void setGlavnaSestra(const bool gs);
    void setPlataSestre(const int pl);

    void ispisSestre();

};
class PrijemnaAmbulanta{

protected:
    Doktor d;
    Sestra s;
    Pacijent p;
    bool vitalniZnaci;
    int mestaUcekaonici;

private:
    PrijemnaAmbulanta();
    PrijemnaAmbulanta(Doktor d1,Sestra s1,Pacijent p1,bool vz,int c);
    PrijemnaAmbulanta(const PrijemnaAmbulanta& pa);

    void setVitalniZnaci(const bool vz);
    void setBrojMestaUCekaonici(const int c);

    string getVitalniZnaci()const;
    int getBrojMestaUcekaonici()const;

};
class Mrtvacnica{

protected:
    Pacijent p;
    int brojMesta;
    int brojZauzetihMesta;
public:
    Mrtvacnica();
    Mrtvacnica(Pacijent p1,int bm,int bsm);
    Mrtvacnica(Mrtvacnica & m);

    void setBrojMesta(const int bm);
    void setBrojSlobodnihMesta(const int bsm);

    int getBrojMesta()const;
    int getBrojSlobodnihMesta()const;

};
class TehnickoOsoblje:Osoba{
protected:
    TipTehnickogOsoblja t;
    int plata;
public:
    TehnickoOsoblje();
    TehnickoOsoblje(string ime1, string prezime1, string kon, string DatRodj, Pol p,TipTehnickogOsoblja t1,int pl);
    TehnickoOsoblje(TehnickoOsoblje &to);

    string getTipOsoblja()const;
    int getPlataOsoblja()const;

    void setTipOsoblja(const TipTehnickogOsoblja to);
    void setPlataOdoblja(const int po);

};
class OdeljenjeZaSnabdevanjeKrvlju{

protected:
    Osoba o;
    int brojAp;
    int brojAn;
    int brojBp;
    int brojBn;
    int brojABp;
    int brojABn;
    int brojop;
    int brojon;
    bool nabavka;

public:
    OdeljenjeZaSnabdevanjeKrvlju();
    OdeljenjeZaSnabdevanjeKrvlju(Osoba o1,int a,int a1,int b,int b1,int ab,int ab1,int o2,int o3);
    OdeljenjeZaSnabdevanjeKrvlju(OdeljenjeZaSnabdevanjeKrvlju& od);

    void setKrv(const int);
    void setKrv1(const int);
    void setKrv2(const int);
    void setKrv3(const int);
    void setKrv4(const int);
    void setKrv5(const int);
    void setKrv6(const int);
    void setKrv7(const int);

    int getKrv()const;
    int getKrv1()const;
    int getKrv2()const;
    int getKrv3()const;
    int getKrv4()const;
    int getKrv5()const;
    int getKrv6()const;
    int getKrv7()const;



};
class Hitna{

protected:
    Doktor d;
    Sestra s;
    int brojVozila;
    int brojKreveta;
public:
    Hitna();
    Hitna(Doktor d1,Sestra s1,int bv,int bk);
    Hitna(Hitna &h);

    void setBrojVozila(const int i);
    void setBrojKreveta(const int i);

    int getBrojVozila()const;
    int getBrojKreveta()const;

};
class Laborant:public Osoba{

protected:
    int plata;
public:
    Laborant();
    Laborant(string ime1, string prezime1, string kon, string DatRodj, Pol p,int p1);
    Laborant(Laborant &l);

    void setPlata(const int p);
    int getPlata()const;

};
class Laboratorija{

protected:
    Laborant l;
    stanjeNalaza stanjen;
    int idNalaza;
    int brojNezavrsenihNalaza;
public:
    Laboratorija();
    Laboratorija(Laborant l1,stanjeNalaza st,int id,int bnn);
    Laboratorija(Laboratorija &l1);

    void setStanje(const stanjeNalaza n);
    void setIdNalaz(const int id);
    void setBrojNezavrsenihNalaza(const int bnn);

    string getStanje()const;
    int getIdNalaza()const;
    int getBrojNezavrsenihNalaza()const;


};
class KovidAmbulanta{

protected:
    Sestra s;
    Pacijent p;
    bool zastita;
    TipTesta tipTesta;
    int brojNovoZarazenih;
public:
    KovidAmbulanta();
    KovidAmbulanta(Sestra s1,Pacijent p1,bool z,TipTesta tip,int m);
    KovidAmbulanta(KovidAmbulanta &ka);

    void setZastita(const bool z);
    void setTipTesta(const TipTesta tip);
    void setBrojNovozarazenih(const int i);

    string getZastita()const;
    string getTipSestrea()const;
    int getBrojNovozarazenih()const;

};
class KovidDeo{

protected:

    KovidAmbulanta a;
    int brojOsobaUpoluIntenzivnoj;
    int brojOsobaUintenzivnoj;
    int brojRespiratora;

public:

    KovidDeo();
    KovidDeo(KovidAmbulanta k,int i, int x,int y);
    KovidDeo(KovidDeo&k);

    void setBrojOsoba1(const int i);
    void setBrojOsoba2(const int i);
    void setBrojRespiratora(const int i);

    int getBrojOsoba1()const;
    int getBrojOsoba2()const;
    int getBrojRespiratora()const;

};
///Nema geter za broj vip mesta tj.niz, to je ustvari preko statickih promelnjlivih
class Parking{

protected:
    int brojMesta;
    int brojSlobodnihMesta;
    int brojSpratova;
    int VIPmesta[5];
    int naplata;
public:
    Parking();
    Parking(int b1,int b2,int b3,int b4[5],int naplata1);
    Parking(Parking &p);

    void setBrojMesta(const int b);
    void setBrojSlobidnihMesta(const int b);
    void setBrojSpratova(const int b);
    void setBrojVIPmesta(const int b[5]);
    void setNaplata(const int b);

    int getBrojMesta()const;
    int getBrojSlobodnihMesta()const;
    int getBrojSpratova()const;
    int* getBrojVIPMesta()const;
    int getnaplata()const;

};
/// NEMA SETER I GETER ZA SPISAK LEKOVA, APOTEKA JE USTVARI PREKO STATICKIH PROMENLJIVIH
class Apoteka{

protected:
    Osoba apotekar;
    char SpisakLekova[MAX][MAX];
    Sestra sestra;
private:
    Apoteka();
    Apoteka(Osoba ap,char sl[MAX][MAX],Sestra s);
    Apoteka(Apoteka& a);

    void setSpisakLekova(const char[MAX][MAX]);

    char* getSpisakLekova()const;


};

class CentralnaKuhinja{};
class Veseraj{};
class CajnaKuhinja{};
class DinamickiDeo{};
class StacionarniDeo{};
class TehnickiDeo{};
class MedicinskiFakultet{};



#endif // BOLNICA_HPP_INCLUDED
