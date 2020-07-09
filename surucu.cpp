/*Zeynep Ülkü Kılıç
* 18120205011
* 
* 1.5.19*/

#include "surucu.h"

//SURUCU SINIFI
ostream& operator <<(ostream & out, const Surucu& surucu){
	out << "Ad: " << surucu.getAd() << endl;
	out << "Yas: " << surucu.getYas() << endl;
	out << "Ehliyet: ";
	if(surucu.getEhliyet() == 0)
		out << "B" << endl;
	else if(surucu.getEhliyet() == 1)
		out << "C" << endl;
	else if(surucu.getEhliyet() == 2)
		out << "D" << endl;
	else if(surucu.getEhliyet() == 3)
		out << "E" << endl;
	return out;
}
Surucu::Surucu(){
	Ad = nullptr;
}
Surucu::Surucu(const char *ad, unsigned int yas, EhliyetSinifi ehliyet){
	unsigned size = strlen(ad);
	Ad = nullptr;
	Ad = new char[size+1];
	if (Ad == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Ad[i] = ad[i];
	Ad[size] = '\0';
	try{
		if(yas < 30){
			yas = yas << 1;
			throw yas;
		}
		else if(yas > 62){
			yas = yas >> 1;
			throw yas;
		}
		else
			Yas = yas;
	}
	catch(unsigned e){
		Yas = yas;
	}
	Ehliyet = ehliyet;
}
Surucu::~Surucu(){
	if (Ad != nullptr)
		delete[]Ad;
}
Surucu::Surucu(const Surucu& other){
	setAd(other.getAd());
	setYas(other.getYas());
	setEhliyet(other.getEhliyet());
}
const Surucu& Surucu::operator=(const Surucu & other){
	//check self-assignment 
	if (this == &other)
		return *this;
	setAd(other.getAd());
	setYas(other.getYas());
	setEhliyet(other.getEhliyet());
	return *this;	
}
char* Surucu::getAd() const{
	return Ad;
}
unsigned int Surucu::getYas() const{
	return Yas;
}
Surucu::EhliyetSinifi Surucu::getEhliyet() const{
	return Ehliyet;
}
void Surucu::setAd(const char* ad){
	if (Ad != nullptr)
		delete[] Ad;
	unsigned size = strlen(ad);
	Ad = nullptr;
	Ad = new char[size+1];
	if (Ad == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Ad[i] = ad[i];
	Ad[size] = '\0';
}
void Surucu::setYas(unsigned int yas){
	Yas = yas;
}
void Surucu::setEhliyet(EhliyetSinifi ehliyet){
	Ehliyet = ehliyet;
}

//YOLCU SINIFI
ostream& operator<<(ostream & out , const Yolcu& yolcu){
	out << "Ad: " << yolcu.getAd() << endl;
	out << "Binis Noktasi: " << yolcu.getBinis() << endl;
	out << "Inis Noktasi: " << yolcu.getInis() << endl;
	return out;
}
Yolcu::Yolcu(){
	Ad = nullptr;
	BinisNoktasi = nullptr;
	InisNoktasi = "";
}
Yolcu::Yolcu(const char *ad, const char * binis, const string & inis){
	unsigned size1 = strlen(ad);
	Ad = nullptr;
	Ad = new char[size1+1];
	if (Ad == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size1; ++i)
		Ad[i] = ad[i];
	Ad[size1] = '\0';
	unsigned size2 = strlen(binis);
	BinisNoktasi = nullptr;
	BinisNoktasi = new char[size2+1];
	if (BinisNoktasi == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size2; ++i)
		BinisNoktasi[i] = binis[i];
	BinisNoktasi[size2] = '\0';
	InisNoktasi = inis;
}
//destructor
Yolcu::~Yolcu(){
	if (Ad != nullptr)
		delete[]Ad;	
	if (BinisNoktasi != nullptr)
		delete[]BinisNoktasi;	
}
//copy constructor
Yolcu::Yolcu(const Yolcu& other){
	setAd(other.Ad);
	setBinis(other.BinisNoktasi);
	setInis(other.InisNoktasi);
}
//assignment operator
const Yolcu& Yolcu::operator=(const Yolcu& other){
	//check self-assignment
	if (this == &other)
		return *this;
	setAd(other.Ad);
	setBinis(other.BinisNoktasi);
	setInis(other.InisNoktasi);
	return *this;
}
char* Yolcu::getAd() const{
	return Ad;
}
char* Yolcu::getBinis() const{
	return BinisNoktasi;
}
string Yolcu::getInis() const{
	return InisNoktasi;
}
void Yolcu::setAd(const char* ad){
	if (Ad != nullptr)
		delete[] Ad;
	unsigned size = strlen(ad);
	Ad = nullptr;
	Ad = new char[size+1];
	if (Ad == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Ad[i] = ad[i];
	Ad[size] = '\0';
}
void Yolcu::setBinis(const char* binis){
	if (BinisNoktasi != nullptr)
		delete[] Ad;
	unsigned size = strlen(binis);
	BinisNoktasi = nullptr;
	BinisNoktasi = new char[size+1];
	if (BinisNoktasi == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		BinisNoktasi[i] = binis[i];
	BinisNoktasi[size] = '\0';
}
void Yolcu::setInis(const string & inis){
	InisNoktasi = inis;
}


//YUK SINIFI
ostream& operator<<(ostream & out , const Yuk& yuk){
	out << "Icerik: " << yuk.getIcerik() << endl;
	out << "Agirlik: " << yuk.getAgirlik() << endl;
	out << "Hacim: " << yuk.getHacim() << endl;
	out << "Alici: " << yuk.getAlici() << endl;
	out << "Binis Noktasi: " << yuk.getBinis() << endl;
	out << "Inis Noktasi: " << yuk.getInis() << endl;
	return out;
}
Yuk::Yuk(){
	Icerik = nullptr;
	Agirlik = 0;
	Hacim = 0;
	Alici = "";
	BinisNoktasi = "";
	InisNoktasi = "";
}
Yuk::Yuk(const char *icerik, double agirlik, double hacim,
		const string &  alici, const string & binis,const string & inis){
	unsigned size = strlen(icerik);
	Icerik = nullptr;
	Icerik = new char[size+1];
	if (Icerik == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Icerik[i] = icerik[i];
	Icerik[size] = '\0';
	Agirlik = agirlik;
	Hacim = hacim;
	Alici = alici;
	BinisNoktasi = binis;
	InisNoktasi = inis;
}
Yuk::~Yuk(){
	if (Icerik != nullptr)
		delete[]Icerik;
}
Yuk::Yuk(const Yuk& other){
	setIcerik(other.Icerik);
	setAgirlik(other.Agirlik);
	setHacim(other.Hacim);
	setAlici(other.Alici);
	setBinis(other.BinisNoktasi);
	setInis(other.InisNoktasi);
}
const Yuk& Yuk::operator=(const Yuk& other){
	//check self-assignment
	if (this == &other)
		return *this;
	setIcerik(other.Icerik);
	setAgirlik(other.Agirlik);
	setHacim(other.Hacim);
	setAlici(other.Alici);
	setBinis(other.BinisNoktasi);
	setInis(other.InisNoktasi);
	return *this;
}
char* Yuk::getIcerik() const{
	return Icerik;
}
double Yuk::getAgirlik() const{
	return Agirlik;
}
double Yuk::getHacim() const{
	return Hacim;
}
string Yuk::getAlici() const{
	return Alici;
}
string Yuk::getBinis() const{
	return BinisNoktasi;
}
string Yuk::getInis() const{
	return InisNoktasi;
}
void Yuk::setIcerik(const char *icerik){
	if (Icerik != nullptr)
		delete[] Icerik;
	unsigned size = strlen(icerik);
	Icerik = nullptr;
	Icerik = new char[size+1];
	if (Icerik == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Icerik[i] = icerik[i];
	Icerik[size] = '\0';
}
void Yuk::setAgirlik(double agirlik){
	Agirlik = agirlik;
}
void Yuk::setHacim(double hacim){
	Hacim = hacim;
}
void Yuk::setAlici(const string& alici){
	Alici = alici;
}
void Yuk::setBinis(const string& binis){
	BinisNoktasi = binis;
}
void Yuk::setInis(const string& inis){
	InisNoktasi = inis;
}

//ARAC SINIFI
ostream& operator<<(ostream& out, const Arac& arac){
	arac.print(out);
	return out;
}
Arac::Arac(){
	Plaka = nullptr;
}
Arac::Arac(const char* plaka, list<Surucu> s){
	unsigned size = strlen(plaka);
	Plaka = nullptr;
	Plaka = new char[size+1];
	if (Plaka == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Plaka[i] = plaka[i];
	Plaka[size] = '\0';
	Suruculer = s;
}
Arac::~Arac(){
	if (Plaka != nullptr)
		delete[]Plaka;
}
Arac::Arac(const Arac& other){
	setPlaka(other.Plaka);
	setSurucu(other.Suruculer);
}
const Arac& Arac::operator=(const Arac& other){
	if (this == &other)
		return *this;
	setPlaka(other.Plaka);
	setSurucu(other.Suruculer);
	return *this;
}
char* Arac::getPlaka() const{
	return Plaka;
}
list<Surucu> Arac::getSurucu() const{
	return Suruculer;
}
void Arac::setPlaka(const char* plaka){
	if (Plaka != nullptr)
		delete[] Plaka;
	unsigned size = strlen(plaka);
	Plaka = nullptr;
	Plaka = new char[size+1];
	if (Plaka == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		Plaka[i] = plaka[i];
	Plaka[size] = '\0';
}
void Arac::setSurucu(const list<Surucu> s){
	Suruculer = s;
}

//OTOBUS SINIFI
ostream& operator<<(ostream& out, const Otobus& otobus){
	otobus.print(out);
	return out;
}
Otobus::Otobus() : Arac(){

}
Otobus::Otobus(const char* plaka, list<Surucu> s, vector<Yolcu> y): Arac(plaka, s) {
	Yolcular.resize(y.size());
	for(unsigned i = 0; i < y.size(); ++i)
		Yolcular[i] = y[i];
}
void Otobus::print(ostream& out) const{
	out << "Plaka: " << getPlaka() << endl;
	out << "Suruculer: 	" << endl;
	for(Surucu s: getSurucu())
		out << s;
	out << endl;
	out << "Yolcular: " << endl;
	for(Yolcu y:Yolcular)
		out << y;
	out << endl;
}
vector<Yolcu> Otobus::getYolcu() const{
	return Yolcular;
}
void Otobus::setYolcu(const vector<Yolcu> y){
	Yolcular.resize(y.size());
	for(unsigned i = 0; i < y.size(); ++i)
		Yolcular[i] = y[i];
}

//KAMYON SINIFI
ostream& operator<<(ostream& out, const Kamyon& kamyon){
	kamyon.print(out);
	return out;
}
Kamyon::Kamyon() : Arac(){
	OzluSoz = nullptr;
}
Kamyon::Kamyon(const char* plaka, list<Surucu> s, const char* soz, vector<Yuk> y) 
	   : Arac(plaka, s){
	unsigned size = strlen(soz);
	OzluSoz = nullptr;
	OzluSoz = new char[size+1];
	if (OzluSoz == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		OzluSoz[i] = soz[i];
	OzluSoz[size] = '\0';
	Yukler.resize(y.size());
	for(unsigned i = 0; i < y.size(); ++i)
		Yukler[i] = y[i];
}
Kamyon::~Kamyon(){
	if (OzluSoz != nullptr)
		delete[]OzluSoz;
}
Kamyon::Kamyon(const Kamyon& other){
	setPlaka(other.getPlaka());
	setSurucu(other.getSurucu());
	setSoz(other.OzluSoz);
	setYuk(other.Yukler);
}
const Kamyon& Kamyon::operator=(const Kamyon& other){
	if (this == &other)
		return *this;
	setPlaka(other.getPlaka());
	setSurucu(other.getSurucu());
	setSoz(other.OzluSoz);
	setYuk(other.Yukler);
	return *this;
}
void Kamyon::print(ostream& out) const{
	out << "Plaka: " << getPlaka() << endl;
	for(Surucu s: getSurucu())
		out << s;
	out << endl;
	out << "Ozlu soz: " << getSoz() << endl;
	out << "Yukler: " << endl;
	for(Yuk y:Yukler)
		out << y;
	out << endl;
}
char* Kamyon::getSoz() const{
	return OzluSoz;
}
vector<Yuk> Kamyon::getYuk() const{
	return Yukler;
}
void Kamyon::setSoz(const char* soz){
	if (OzluSoz != nullptr)
		delete[] OzluSoz;
	unsigned size = strlen(soz);
	OzluSoz = nullptr;
	OzluSoz = new char[size+1];
	if (OzluSoz == nullptr)
		exit(-1);
	for(unsigned i = 0; i < size; ++i)
		OzluSoz[i] = soz[i];
	OzluSoz[size] = '\0';
}
void Kamyon::setYuk(vector<Yuk> y){
	Yukler.resize(y.size());
	for(unsigned i = 0; i < y.size(); ++i)
		Yukler[i] = y[i];
}
