/*Zeynep �lk� K�l��
* 18120205011
* 
* 1.5.19*/

//!!!Bu �devde Exception Handling mekanizmalar� kullan�lmal�d�r!!!


#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <iterator>

using namespace std;
//using std::list;

//bir arac� kullanan ki�iyi ifade eder
class Surucu {
	friend ostream& operator <<(ostream & out, const Surucu& surucu);
public:
	enum EhliyetSinifi {B, C, D, E};

	Surucu();	//default constructor
	Surucu(const char *ad, unsigned int yas, EhliyetSinifi ehliyet);	//constructor
	
	~Surucu();	//destructor
	Surucu(const Surucu& other);	//copy constructor
	const Surucu& operator=(const Surucu & other);	//assignment operator
	
	char* getAd() const;
	unsigned int getYas() const;
	EhliyetSinifi getEhliyet() const; 		//RETURN T�R� DO�RU MU
	
	void setAd(const char* ad);
	void setYas(unsigned int yas);
	void setEhliyet(EhliyetSinifi ehliyet);
private:
	//S�r�c�n�n ad�n� ve soyad�n� C tarz� string olarak tutar. Dinamik bellek y�netimi gerekir.
	char *Ad;
	//S�r�c�n�n ya�� en az 30 en �ok 62 olabilir. Bunu tutabilecek en k���k veri tipini olu�turun.
	// Bkz: https://en.cppreference.com/w/cpp/language/bit_field
	unsigned int Yas : 6;	//???????????????????????????????????????????????????????????????????????????
	//S�r�c�n�n ehliyet t�r�n� verir. 
	//Ehliyet s�n�flar� B, C, D veya E olabilir. Sadece bu de�erler i�in �al��an enumarated bir tip olu�turun
	EhliyetSinifi Ehliyet;
};

//otob�s ile seyahat eden bir ki�iyi ifade eder
class Yolcu {
	friend ostream& operator<<(ostream & out , const Yolcu& yolcu);
public:
	Yolcu();	//default constructor
	Yolcu(const char *ad, const char * binis, const string & inis);	//constructor
	
	~Yolcu();	//destructor
	Yolcu(const Yolcu& other);	//copy constructor
	const Yolcu& operator=(const Yolcu& other);	//assignment operator
	
	char* getAd() const;
	char* getBinis() const;
	string getInis() const;
	
	void setAd(const char *ad);
	void setBinis(const char *binis);
	void setInis(const string & inis);
private:
	//Yolcunun ad�n� ve soyad�n� C tarz� string olarak tutar. Dinamik bellek y�netimi gerekir.
	char *Ad;
	//Yolcunun binece�i yeri C tarz� string olarak tutar. Dinamik bellek y�netimi gerekir.
	char *BinisNoktasi;
	//Yolcunun inece�i yeri C++ tarz� string  nesnesi olarak tutar.
	string InisNoktasi;
};

//kamyon ile ta��nabilen bir y�k� ifade eder
class Yuk {
	friend ostream& operator<<(ostream & out , const Yuk& yuk);
public:
	Yuk();	//default constructor
	//constructor
	Yuk(const char *icerik, double agirlik, double hacim,
		const string & alici, const string & binis, const string & inis);

	~Yuk();	//destructor
	Yuk(const Yuk& other);	//copy constructor
	const Yuk& operator=(const Yuk& other);	//assignment operator
	
	char* getIcerik() const;
	double getAgirlik() const;
	double getHacim() const;
	string getAlici() const;
	string getBinis() const;
	string getInis() const;
	
	void setIcerik(const char *icerik);
	void setAgirlik(double agirlik);
	void setHacim(double hacim);
	void setAlici(const string& alici);
	void setBinis(const string& binis);
	void setInis(const string& inis);
	
private:
	//Y�k�n cinsini C tarz� string olarak tutar. Dinamik bellek y�netimi gerekir. 
	char *Icerik;
	//Y�k�n a��rl���n� tutar. 
	double Agirlik;
	//Y�k�n hacmini tutar. 
	double Hacim;
	// Y�k� alacak ki�inin ad�n� ve soyad�n� C++ tarz� string nesnesi olarak tutar.
	string Alici;
	//Yolcunun binece�i yeri C++ tarz� string nesnesi olarak tutar.  
	string BinisNoktasi;
	//Yolcunun inece�i yeri C++ tarz� string nesnesi olarak tutar.  
	string InisNoktasi;
};

//soyut s�n�f
// Ara� s�n�f� kamyon ve otob�s s�n�flar�n�n t�retildi�i soyut bir s�n�ft�r.
class Arac {
	/*Operator <<: Arac�n plakas�n� ve �of�rlerini ekrana yazd�r�r. 
	 * Kendinden t�retilmi� s�n�flarda otob�sse yolcular�, kamyonsa y�kleri 
	 * ekrana basacak �ekilde a��r� y�klenmelidir d�zenlenmelidir. 
	 * Bu operat�r saf sanal olacak �ekilde a��r� y�klenmelidir. */
	friend ostream& operator<<(ostream& out, const Arac& arac);
public:
	Arac();
	Arac(const char* plaka, list<Surucu> s);
	
	virtual ~Arac();
	Arac(const Arac& other);
	const Arac& operator=(const Arac& other);
	
	virtual void print(ostream& out) const = 0;
	
	char* getPlaka() const;
	list<Surucu> getSurucu() const;
	void setPlaka(const char* plaka);
	void setSurucu(const list<Surucu> s);
private:
	//Arac�n plakas�n� C tarz� string olarak tutar. Dinamik bellek y�netimi gerekir. 
	char *Plaka;
	//Her arac�n en az bir s�r�c�s� vard�r. Birden �ok s�r�c� de olabilir. 
	//S�r�c� nesnelerini stl listesi i�inde tutunuz. 
	//Bkz: https://en.cppreference.com/w/cpp/container/list 
	list<Surucu> Suruculer;
};

// Otob�s s�n�f� Arac s�n�f�ndan t�retilmi�, nesnesi olu�turulabilir bir s�n�ft�r.
class Otobus : public Arac {
	friend ostream& operator<<(ostream& out, const Otobus& otobus);
public:
	Otobus();
	Otobus(const char* plaka, list<Surucu> s, vector<Yolcu> y);
	
	void print(ostream& out) const;
	
	vector<Yolcu> getYolcu() const;
	void setYolcu(const vector<Yolcu> y);
private:
	//Otob�ste yolculuk eden yolcular bir stl vekt�r i�inde tutulmaktad�r. 
	vector<Yolcu> Yolcular;
};

//Bu s�n�f Arac s�n�f�ndan t�retilmi�, nesnesi olu�turulabilir bir s�n�ft�r.
class Kamyon : public Arac {
	friend ostream& operator<<(ostream& out, const Kamyon& kamyon);
public:
	Kamyon();
	Kamyon(const char* plaka, list<Surucu> s, const char* soz, vector<Yuk> y);
	
	virtual ~Kamyon();	//destructor
	Kamyon(const Kamyon& other);
	const Kamyon& operator=(const Kamyon& other);
	
	void print(ostream& out) const;
	
	char* getSoz() const;
	vector<Yuk> getYuk() const;
	void setSoz(const char* soz);
	void setYuk(vector<Yuk> y);
private:
	//Kamyonun �zerine yaz�l� ayd�nlat�c�, �zl� s�zd�r. C tarz� string olarak tutulur ve dinamik bellek y�netimi gerekir.
	char *OzluSoz;
	//Kamyonda ta��nan y�kler bir stl vekt�r i�inde tutulmaktad�r.
	vector<Yuk> Yukler;
};

