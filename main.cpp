/*Zeynep Ülkü Kılıç
* 18120205011
* 
* 1.5.19*/

#include "surucu.h"

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 
#include <locale>

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

/*xml dosyasından araçları okuyan ve listeyi dolduran bir global fonksiyondur,
başarılı şekilde okuduğu araç sayısını dönderir */
//HOCAM SİZİN İSTEĞİNİZ AKSİNE ARACLARIN REFERANSINI PARAMETRE OLARAK VERDİM MAINDE YAZDIRABİLMEK İÇİN
unsigned int dosyadanOku(const string& filename, list<Arac*> & araclar){
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile(filename);
	if (theFile.fail()){
		cout << "File open failed." << endl;
		exit(-1);
	}

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");

	for (auto * vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{
		Surucu::EhliyetSinifi ehliyet_sinifi;
		if(!strcmp(vehicle_node->first_node("Turu")->value(), "Otobüs")){
			string plaka = vehicle_node->first_node("Plaka")->value();
			auto * drivers_root_node = vehicle_node->first_node("Suruculer");
			list<Surucu> suruculer;
			Surucu s;
			for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
			{
				string ad = driver_node->first_node("Adi")->value();
				string yas = driver_node->first_node("Yasi")->value();
				string ehliyet = driver_node->first_node("EhliyetSinifi")->value();
				if(ehliyet == "B"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::B;
				}
				else if(ehliyet == "C"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::C;
				}
				else if(ehliyet == "D"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::D;
				}
				else if(ehliyet == "E"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::E;
				}
				s.setAd(ad.c_str());
				s.setYas(stoi(yas));
				s.setEhliyet(ehliyet_sinifi);
				suruculer.push_back(s);
			}
			drivers_root_node = vehicle_node->first_node("Yolcular");
			vector<Yolcu> yolcular;
			Yolcu y;
			for (auto * driver_node = drivers_root_node->first_node("Yolcu"); driver_node; driver_node = driver_node->next_sibling())
			{
				string ad = driver_node->first_node("Adi")->value();
				string binis = driver_node->first_node("BinisNoktasi")->value();
				string inis = driver_node->first_node("InisNoktasi")->value();
				y.setAd(ad.c_str());
				y.setBinis(binis.c_str());
				y.setInis(inis);
				yolcular.push_back(y);
			}
			Arac * otobus = new Otobus (plaka.c_str(), suruculer, yolcular);
			if(otobus == nullptr)
				exit(-1);
			araclar.push_back(otobus);
		}
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon")){
			string plaka = vehicle_node->first_node("Plaka")->value();
			string soz = vehicle_node->first_node("OzluSoz")->value();
			auto * drivers_root_node = vehicle_node->first_node("Suruculer");
			list<Surucu> suruculer;
			Surucu s;
			for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
			{
				string ad = driver_node->first_node("Adi")->value();
				string yas = driver_node->first_node("Yasi")->value();
				string ehliyet = driver_node->first_node("EhliyetSinifi")->value();
				if(ehliyet == "B"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::B;
				}
				else if(ehliyet == "C"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::C;
				}
				else if(ehliyet == "D"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::D;
				}
				else if(ehliyet == "E"){
					ehliyet_sinifi = Surucu::EhliyetSinifi::E;
				}
				s.setAd(ad.c_str());
				s.setYas(stoi(yas));
				s.setEhliyet(ehliyet_sinifi);
				suruculer.push_back(s);
			}
			drivers_root_node = vehicle_node->first_node("Yukler");
			vector<Yuk> yukler;
			Yuk y;
			for (auto * driver_node = drivers_root_node->first_node("Yuk"); driver_node; driver_node = driver_node->next_sibling())
			{
				string icerik = driver_node->first_node("Icerik")->value();
				string agirlik = driver_node->first_node("Agirlik")->value();
				string hacim = driver_node->first_node("Hacim")->value();
				string alici = driver_node->first_node("Alici")->value();
				string binis = driver_node->first_node("BinisNoktasi")->value();
				string inis = driver_node->first_node("InisNoktasi")->value();
				y.setIcerik(icerik.c_str());
				y.setAgirlik(atof(agirlik.c_str()));
				y.setHacim(atof(hacim.c_str()));
				y.setAlici(alici);
				y.setBinis(binis);
				y.setInis(inis);
				yukler.push_back(y);
			}
			Arac * kamyon = new Kamyon (plaka.c_str(), suruculer, soz.c_str(), yukler);
			if(kamyon == nullptr)
				exit(-1);
			araclar.push_back(kamyon);
		}
	}
	theFile.close();
	return araclar.size();
}

int main(){
	list<Arac*> araclar;
	dosyadanOku("bil122_hw08.xml", araclar);
	list<Arac*>::iterator iter;
	for(iter = araclar.begin(); iter != araclar.end(); ++iter)
		cout << *iter;
	cout << endl;
/*	for(Arac* a:araclar)
		cout << *a;
	cout << endl;*/
	return 0;
}
