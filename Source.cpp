#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include <locale>

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile("bil122_hw08.xml");

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");

	// Iterate over the Vehicles
	cout << "Parsing Vehicles.xml..." << endl;

	int i = 0;
	for (auto * vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{
		cout << "Arac-" << ++i << "\t" << vehicle_node->first_node("Turu")->value()
			<< "\t" << vehicle_node->first_node("Plaka")->value();

		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
			cout << "\t\"" << vehicle_node->first_node("OzluSoz")->value() << "\"";

		cout << endl;
		
		auto * drivers_root_node = vehicle_node->first_node("Suruculer");
		int j = 0;
		for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
		{
			cout << "\tSurucu-" << ++j << "\t" << "\t" << driver_node->first_node("Adi")->value()
				<< "\t" << driver_node->first_node("Yasi")->value()
				<< "\t" << driver_node->first_node("EhliyetSinifi")->value() << endl;
		}	

		// Yuk ve Yolcu icin gerekli kodu size birakiyorum
		// Bu programi bir fonksiyon haline getirip kullanmalisiniz
	}

	return 0;
}