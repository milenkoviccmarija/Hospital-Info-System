#ifndef BOLNICA_H_INCLUDED
#define BOLNICA_H_INCLUDED

#define MAX 20

using namespace std;

enum Pol{muski,zenski};
enum KrvnaGrupa{A+,A-,B+,B-,0+,0-,AB+,AB-};
enum NacinGradnje{paviljonski, koridorni, blok, sistem baraka, tranbantni};
enum TipBolnice{opsta, specificna};

typedef struct datum(){

int dan;
int mesec;
int godina;

}dat;

class Bolnica {

private:
    string ime;
    string lokacija;
    string kontakt;
    int brojKreveta;
    int brojZautetihKreveta;
    NacinGradnje gradnja;
    TipBolnice tip;



};

class Osoba{

protected:

     string ime;
     string prezime;
     string kontakt;
     dat datumRodjenja;
     Pol pol;

public:

    Osoba();
	Osoba(string ime1, string prezime1, string kon, dat DatRodj,bool u, Pol p, );
	Osoba(const Osoba& o);

    string getIme( return ime; );
    string getPrezime( return prezime; );
    string getKontakt( return kontakt; );
    dat getDatumRodjenjaPacijenta( return datumRodjenja; );
    Pol getPolPacijenta( return pol; );

    void setIme( string ime1; );
    void setPrezime( string prezime1; );
    void setKontakt( string kontakt1; );
    void setDatumRodjenjaPacijenta( dat datumRodjenja1; );
    void setPolPacijenta( Pol pol1; );


};

class Pacijent: public Osoba{

private:

    KrvnaGrupa grupa;
    bool uput;
    dat datumPrijema;
    int id[MAX];

public:

    Pacijent();
	Pacijent(string ime1, string prezime1, string kon, KrvnaGrupa k,dat DatRodj,bool u, dat prijem, Pol p, int i);
	Pacijent(const Pacijent& p);


	string getImePacijenta( return ime; );
    string getPrezimePacijenta( return prezime; );
    string getKontaktPacijenta( return kontakt; );
    KrvnaGrupa getKrvnaGrupaPacijenta( return grupa; );
    dat getDatumRodjenjaPacijenta( return datumRodjenja; );
    bool getUputPacijenta( return uput; );
    dat getDatumPrijemaPacijenta( return datumPrijema; );
    Pol getPolPacijenta( return pol; );
    int getIDPacijenta( return id; );


};

class Doktor{

private:


};

#endif // BOLNICA_H_INCLUDED
