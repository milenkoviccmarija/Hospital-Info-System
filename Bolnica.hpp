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

class Soba{

protected:
    int sirina;
    int visina;
public:
    Soba();
    Soba(int a,int b);
    Soba(Soba& s);

    int getSirinu();
    int getVisinu();

    void setSirinu(int i);
    void setVisinu(int i);

    virtual int getPovrsinuSobe() = 0;
    virtual float getMogucihKreveta()=0;

};
class Toalet{

protected:
    int sirina;
    int visina;
    int brojKabina;
public:
    Toalet();
    Toalet(int i,int a,int b);
    Toalet(Toalet & t);

    void setBrojKabina(int i);
    void setSirina(int i);
    void setVisina(int i);
    int getBrojKabina();
    int getSirinu();
    int getVisina();

    virtual int getPovrsinuToaleta() = 0;
    virtual double rastojanjeIzmedjuKabina()=0;


};
class BolnickiToalet:public Toalet{

protected:
    int brojInvalidskihPrinceza;
public:
    BolnickiToalet();
    BolnickiToalet(int i);
    BolnickiToalet(BolnickiToalet & bt);

    void setBrojInvalidskihPrinceza(int i);
    int getBrojInvalidskihPrinceza();

     int getPovrsinuToaleta() {
         return (sirina * visina);
      }
      double rastojanjeIzmedjuKabina(){
          int p=getPovrsinuToaleta();
          return p/brojKabina;
      }


};
class Datum{
protected:
    int mesec,dan,godina;
public:
    Datum(int x,int y,int z);
    friend ostream& operator<<(ostream& o, const Datum& d);
    friend istream &operator>>(istream&, Datum &d);
Datum operator++ (int) {
        Datum d(1,2,3);
        ++dan;
        if(dan >31 ) {
            ++mesec;
            dan-=30;
         }
         ++mesec;
         if(mesec >12 ) {
            ++godina;
            mesec -= 11;
         }
         return d;
      }
Datum operator--(int ){
        Datum d(1,2,3);
        --dan;
        if(dan<1 ) {
            --mesec;
            dan*=30;
         }
         --mesec;
         if(mesec <1 ) {
            --godina;
            mesec += 11;
         }
         return d;
      }

};
class Bolnica{

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
    friend ostream &operator<<(ostream&, const Bolnica &b);
    friend istream &operator>>(istream&, Bolnica &b);
    bool operator==(Bolnica& b)
{
return (getTipBolnice() ==b.getTipBolnice()&& getNacinGradnje() == b.getNacinGradnje() && getBrojKreveta() == b.getBrojKreveta() && getBrojZauzetihKreveta() == b.getBrojZauzetihKreveta());

}

};
class Osoba{

public:

     string ime;
     string prezime;
     string kontakt;
     Datum datumRodjenja;
     Pol pol;

public:

    Osoba();
	Osoba(string ime1, string prezime1, string kon, Datum DatRodj, Pol p );
	Osoba(const Osoba& o);

    string getIme()const;
    string getPrezime()const;
    string getKontakt()const;
    Datum getDatumRodjenja()const;
    string getPol()const;

    void setIme(const string s);
    void setPrezime(const string s);
    void setKontakt(const string s);
    void setDatumRodjenja(const int x1,const int y1,const int z1);
    void setPol(const Pol s);


    void ispisOsobe();
    friend ostream &operator<<(ostream&, const Osoba &o);
    friend istream &operator>>(istream&, Osoba &o);

};
class Pacijent:public Osoba{

public:

    KrvnaGrupa grupa;
    bool uput;
    Datum datumPrijema;
    int id;

public:

    Pacijent();
	Pacijent(string ime1, string prezime1, string kon, Datum DatRodj, Pol p ,KrvnaGrupa krv, bool u,Datum DatPrijema, int i);
	Pacijent(const Pacijent& p);

    string getKrvnaGrupaPacijenta()const;
    string getUputPacijenta()const;
    Datum getDatumPrijemaPacijenta()const;
    int getIDPacijenta()const;

    void setGrupa(const KrvnaGrupa k);
    void setUput(const bool u);
    void setDatumPrijemaPacijenta(const int x1,const int y1,const int z1);
    void setIDPacijenta(const int i);

    void ispisPacijenta();
    friend ostream &operator<<(ostream&, const Pacijent &o);
    friend istream &operator>>(istream&, Pacijent &p);

};
class Doktor:public Osoba{

public:
    int plata;
    string specijalizacija;
    string studije;
public:
    Doktor();
    Doktor(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,int pt, string spc,string stdj);
    Doktor(const Doktor& d);

    int getPlata()const;
    string getSpecijalizacija()const;
    string getStudije()const;

    void setPlata(const int p);
    void setSpecijalizacija(const string sp);
    void setStudije(const string stdj);

    void ispisDoktora();
    friend ostream &operator<<(ostream&, const Doktor &d);
    friend istream &operator>>(istream&, Doktor &d);

};
class Sestra:public Osoba{

protected:
    tipSestre tipS;
    bool GlavnaSestra;
    int plata;
public:
    Sestra();
    Sestra(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,tipSestre t, bool gs,int pl);
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

public:
    PrijemnaAmbulanta();
    PrijemnaAmbulanta(Doktor d1,Sestra s1,Pacijent p1,bool vz,int c);
    PrijemnaAmbulanta(const PrijemnaAmbulanta& pa);

    void setVitalniZnaci(const bool vz);
    void setBrojMestaUCekaonici(const int c);
    void setDoktora(const Doktor d1);
    void setSestru(const Sestra s1);
    void setPacijenta(const Pacijent p1);

    string getVitalniZnaci()const;
    int getBrojMestaUcekaonici()const;
    Doktor getDoktora();
    Sestra getSestru();
    Pacijent getPacijenta();

};
template <class T>
class List{
	protected:
		struct listEl{
			T content;
			struct listEl* next;
		};
		listEl *head;
		listEl *tail;
		int noEl;

	public:
		List(){
			head=tail=NULL;
			noEl=0;
		}

		List(const List<T>&);

		List<T>& operator=(const List<T>&);

		virtual ~List();

		int size() const { return noEl; }

		bool empty() const { return head == NULL ? 1 : 0; }

		bool add(int, const T&);

		bool remove(int);

		bool read(int, T&)const;

		void clear();
};
class Mrtvacnica:public Soba{

protected:
    List<Pacijent*> p;
    int brojMesta;
    int brojZauzetihMesta;
public:
    Mrtvacnica();
    Mrtvacnica(List<Pacijent*> p1,int bm,int bsm);
    Mrtvacnica(Mrtvacnica & m);

    void setBrojMesta(const int bm);
    void setBrojSlobodnihMesta(const int bsm);
    void setP(const List<Pacijent*> p1);

    int getBrojMesta()const;
    int getBrojSlobodnihMesta()const;
    List<Pacijent*> getP();
    int getPovrsinuSobe() {
         return (sirina * visina);
      }


};
class TehnickoOsoblje:public Osoba{
protected:
    TipTehnickogOsoblja t;
    int plata;
public:
    TehnickoOsoblje();
    TehnickoOsoblje(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,TipTehnickogOsoblja t1,int pl);
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
    int ukupno;
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
    void setOsoba(const Osoba o1);

    int getKrv()const;
    int getKrv1()const;
    int getKrv2()const;
    int getKrv3()const;
    int getKrv4()const;
    int getKrv5()const;
    int getKrv6()const;
    int getKrv7()const;
    Osoba getOsoba();
OdeljenjeZaSnabdevanjeKrvlju operator+(const OdeljenjeZaSnabdevanjeKrvlju& b) {
      OdeljenjeZaSnabdevanjeKrvlju o;
      o.brojAp = this->brojAp + b.brojAp;
      o.brojAn = this->brojAn + b.brojAn;
      o.brojBp = this->brojBp + b.brojBp;
      o.brojBn = this->brojBn + b.brojBn;
      o.brojABp = this->brojABp + b.brojABp;
      o.brojABn = this->brojABn + b.brojABn;
      o.brojop = this->brojop + b.brojop;
      o.brojon = this->brojon + b.brojon;
      return o;
   }
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
    void setDoktora(const Doktor d1);
    void setSestru(const Sestra s1);

    int getBrojVozila()const;
    int getBrojKreveta()const;
    Doktor getDoktora();
    Sestra getSestru();

};
class Laborant:public Osoba{

protected:
    int plata;
public:
    Laborant();
    Laborant(string ime1, string prezime1, string kon, Datum DatRodj, Pol p,int p1);
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
    void setLaboranta(const Laborant l1);

    string getStanje()const;
    int getIdNalaza()const;
    int getBrojNezavrsenihNalaza()const;
    Laborant getLaboranta();



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
    void setSestru(const Sestra s1);
    void setPacijenta(const Pacijent p1);

    string getZastita()const;
    string getTipSestrea()const;
    int getBrojNovozarazenih()const;
    Sestra getSestru();
    Pacijent getPacijent();

};
class KovidDeo{

protected:

    KovidAmbulanta a;
    List<Pacijent*> spisak;
    int brojOsobaUpoluIntenzivnoj;
    int brojOsobaUintenzivnoj;
    int brojRespiratora;

public:

    KovidDeo();
    KovidDeo(KovidAmbulanta k,List<Pacijent*> l,int i, int x,int y);
    KovidDeo(KovidDeo&k);

    void setBrojOsoba1(const int i);
    void setBrojOsoba2(const int i);
    void setBrojRespiratora(const int i);
    void setKovidAmbulantu(const KovidAmbulanta k);
    void setSpisak(List<Pacijent*> p);

    int getBrojOsoba1()const;
    int getBrojOsoba2()const;
    int getBrojRespiratora()const;
    KovidAmbulanta getKovidAmbulantu();
    List<Pacijent*> getSpisak();

    bool operator/(KovidDeo& b)
{
        if((b.brojOsobaUintenzivnoj/b.brojRespiratora)!=(this->brojOsobaUintenzivnoj/this->brojRespiratora))
        return false;
        else
            return true;

}

};
class Parking{

protected:
    List<int> nizZauzetihMesta;
    List<int> nizSlobodnihMesta;
    List<int> nizVIPmesta;
    int brojSpratova;
    int naplata;
public:

    Parking();
    Parking(List<int> a,List<int> b,List<int> c, int d,int e);
    Parking(Parking& p);

    void setnizZauzetihMesta(List<int> l);
    void setnizSlobodnihMesta(List<int> l);
    void setBrojSpratova(const int b);
    void setnizVIPMesta(List<int> l);
    void setNaplata(const int b);

    List<int> getnizZauzetihMesta()const;
    List<int> getnizSlobodnihMesta()const;
    int getBrojSpratova()const;
    List<int> getnizVIPMesta()const;
    int getnaplata()const;

    Parking& operator+=(int i)
    {
        nizSlobodnihMesta.add(nizSlobodnihMesta.size()+1, i);
        return *this;
    }
    void ispisNizSlobodnihMesta();
    void ispisNizZauzetihMesta();
    void ispisNizVIPMesta();
    void ispisParking();


};
class Artikal{
public:
    virtual double izvracunajVrednostArtikla()const=0;
};
class Lek:public Artikal {
protected:
    int jkl;
    string naziv;
    double jedinicnaCena;
    int kolicina;
public:
    Lek();
    Lek(int j,string n,double c, int k);
    Lek(Lek& l);

    void setJKl(int jk);
    void setNaziv(string s);
    void setJedinicnuCenu(double cena);
    void setKolicina(int i);

    int getJKL();
    string getNaziv();
    double getJedinicnaCena();
    int getKolicina();

    double izvracunajVrednostArtikla();
    friend ostream& operator<<(ostream& out, const Lek& l);
};
class Apoteka{

protected:
    List<Lek*> spisakLekova;
    Osoba apotekar;
    Sestra sestra;
public:
    Apoteka();
    Apoteka(List<Lek*> l,Osoba o,Sestra s);
    Apoteka(Apoteka& a);

    void setApotekar(const Osoba o);
    void setSestru(const Sestra s);
    void setSpisakLekova(List<Lek*> s);

    Osoba getApotekar();
    Sestra getSestra();
    List<Lek*> getSpisakLekova();

    void ispisSpisakLekova();
    void ispisApoteke();

};
class BolnickaSoba:public Soba{
protected:
    int brojLezaja;
    int RastojanjeIzmedjuKreveta;
    List<Pacijent*> spisakPacijenata;
public:
    BolnickaSoba();
    BolnickaSoba(int i,int a,List<Pacijent*> p);
    BolnickaSoba(BolnickaSoba &b);

    void setBrojLezaja(int i);
    void setRastojanje(int i);
    void setSpisakPacijenata(List<Pacijent*> s);

    int getBrojLezaja();
    int getRastojanje();
    List<Pacijent*> getSpisakPacijenata();

      int getPovrsinuSobe() {
         return (sirina * visina);
      }
      float getMogucihKreveta(){
      int m=getPovrsinuSobe();
      return m/RastojanjeIzmedjuKreveta;
      }

};
#endif // BOLNICA_HPP_INCLUDED
