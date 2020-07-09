/*Zeynep Ülkü Kýlýç
* 18120205011
* 
* 1.5.19*/

//!!!Bu ödevde Exception Handling mekanizmalarý kullanýlmalýdýr!!!


#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <iterator>

using namespace std;
//using std::list;

//bir aracý kullanan kiþiyi ifade eder
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
	EhliyetSinifi getEhliyet() const; 		//RETURN TÜRÜ DOÐRU MU
	
	void setAd(const char* ad);
	void setYas(unsigned int yas);
	void setEhliyet(EhliyetSinifi ehliyet);
private:
	//Sürücünün adýný ve soyadýný C tarzý string olarak tutar. Dinamik bellek yönetimi gerekir.
	char *Ad;
	//Sürücünün yaþý en az 30 en çok 62 olabilir. Bunu tutabilecek en küçük veri tipini oluþturun.
	// Bkz: https://en.cppreference.com/w/cpp/language/bit_field
	unsigned int Yas : 6;	//???????????????????????????????????????????????????????????????????????????
	//Sürücünün ehliyet türünü verir. 
	//Ehliyet sýnýflarý B, C, D veya E olabilir. Sadece bu deðerler için çalýþan enumarated bir tip oluþturun
	EhliyetSinifi Ehliyet;
};

//otobüs ile seyahat eden bir kiþiyi ifade eder
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
	//Yolcunun adýný ve soyadýný C tarzý string olarak tutar. Dinamik bellek yönetimi gerekir.
	char *Ad;
	//Yolcunun bineceði yeri C tarzý string olarak tutar. Dinamik bellek yönetimi gerekir.
	char *BinisNoktasi;
	//Yolcunun ineceði yeri C++ tarzý string  nesnesi olarak tutar.
	string InisNoktasi;
};

//kamyon ile taþýnabilen bir yükü ifade eder
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
	//Yükün cinsini C tarzý string olarak tutar. Dinamik bellek yönetimi gerekir. 
	char *Icerik;
	//Yükün aðýrlýðýný tutar. 
	double Agirlik;
	//Yükün hacmini tutar. 
	double Hacim;
	// Yükü alacak kiþinin adýný ve soyadýný C++ tarzý string nesnesi olarak tutar.
	string Alici;
	//Yolcunun bineceði yeri C++ tarzý string nesnesi olarak tutar.  
	string BinisNoktasi;
	//Yolcunun ineceði yeri C++ tarzý string nesnesi olarak tutar.  
	string InisNoktasi;
};

//soyut sýnýf
// Araç sýnýfý kamyon ve otobüs sýnýflarýnýn türetildiði soyut bir sýnýftýr.
class Arac {
	/*Operator <<: Aracýn plakasýný ve þoförlerini ekrana yazdýrýr. 
	 * Kendinden türetilmiþ sýnýflarda otobüsse yolcularý, kamyonsa yükleri 
	 * ekrana basacak þekilde aþýrý yüklenmelidir düzenlenmelidir. 
	 * Bu operatör saf sanal olacak þekilde aþýrý yüklenmelidir. */
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
	//Aracýn plakasýný C tarzý string olarak tutar. Dinamik bellek yönetimi gerekir. 
	char *Plaka;
	//Her aracýn en az bir sürücüsü vardýr. Birden çok sürücü de olabilir. 
	//Sürücü nesnelerini stl listesi içinde tutunuz. 
	//Bkz: https://en.cppreference.com/w/cpp/container/list 
	list<Surucu> Suruculer;
};

// Otobüs sýnýfý Arac sýnýfýndan türetilmiþ, nesnesi oluþturulabilir bir sýnýftýr.
class Otobus : public Arac {
	friend ostream& operator<<(ostream& out, const Otobus& otobus);
public:
	Otobus();
	Otobus(const char* plaka, list<Surucu> s, vector<Yolcu> y);
	
	void print(ostream& out) const;
	
	vector<Yolcu> getYolcu() const;
	void setYolcu(const vector<Yolcu> y);
private:
	//Otobüste yolculuk eden yolcular bir stl vektör içinde tutulmaktadýr. 
	vector<Yolcu> Yolcular;
};

//Bu sýnýf Arac sýnýfýndan türetilmiþ, nesnesi oluþturulabilir bir sýnýftýr.
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
	//Kamyonun üzerine yazýlý aydýnlatýcý, özlü sözdür. C tarzý string olarak tutulur ve dinamik bellek yönetimi gerekir.
	char *OzluSoz;
	//Kamyonda taþýnan yükler bir stl vektör içinde tutulmaktadýr.
	vector<Yuk> Yukler;
};

