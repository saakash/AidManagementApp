/* Name: Aakash Shrestha
Student ID: 140051160
OOP244 SDD
Final Project: Milestone 5
Date: 2017 July 25
*/

// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <cstring>
#include <cstdio>
#include "AmaProduct.h"

using namespace std;

namespace sict {
	//one argument constructor which sets the incoming filetag character to member variable fileTag_
	//if no argument is received, the constructor sets fileTag_ to 'N', default declared in prototype
	AmaProduct::AmaProduct(char c) {
		fileTag_ = c;
	}

	//returns the pointer to address of member variable unit_
	const char* AmaProduct::unit() const {
		return unit_;
	}

	//setter member function for unit_;
	void AmaProduct::unit(const char* value) {
		strncpy(unit_, value, 10);
		unit_[11] = '\0';
	}

	//store function, which stores the comma separated fields to file
	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const {
		file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded();
		if (addNewLine == true) { file << endl; }
		return file;
	}

	//load function, which reads the comma separated fields from a file
	std::fstream& AmaProduct::load(std::fstream& file) {
		char buf[2000];
		int ibuf;
		double dbuf;
		file.getline(buf, MAX_SKU_LEN, ','); //reads the sku delimited by ',' and extracts the delimiter
		sku(buf);			//sets sku
		file.getline(buf, 20, ','); //reads name, ignores the ',' delimiter
		name(buf);			//sets name
		file >> dbuf;		//reads price
		price(dbuf);		//sets price
		file.ignore(1);		//ignores the delimiter
		file >> ibuf;		//reads taxed value	
		taxed(ibuf);		//sets taxed
		file.ignore(1);		//ignores the delimiter
		file >> ibuf;		//reads quantity on hand
		quantity(ibuf);		//sets the quantity
		file.ignore(1);		//ignores the delimiter
		file.getline(buf, 10, ',');  //reads unit of quantity
		unit(buf);			//sets unit_
		file >> ibuf;		//reads quantity needed
		qtyNeeded(ibuf);	//sets quantity needed
		return file;
	}

	//displays the product details 
	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const {
		if (!err_.isClear()) { os << err_; } //displays error message if any
		else {
			if (linear) {  //displays the details in linear format
				os.setf(ios::fixed);
				os.fill(' ');
				os.width(MAX_SKU_LEN);
				os.setf(ios::left);
				os << sku()<<"|";
				os.width(20);
				os.setf(ios::left);
				os << name() << "|";
				os.width(7);
				os.setf(ios::right);
				os.precision(2);
				os << cost() << "|";
				os.width(4);
				os.setf(ios::right);
				os << quantity() << "|";
				os.width(10);
				os.unsetf(ios::right);
				os.setf(ios::left);
				os << unit_ <<"|";
				os.width(4);
				os.setf(ios::right);
				os << qtyNeeded() << "|";
				os.unsetf(ios::right);
			}
			else {  //displays the details in form format
				os << "Sku: " << sku() << endl;
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;
				if (fileTag_ == 'P') {
					os << "Price after tax: N/A" << endl;
				}else{ os << "Price after tax: " << cost() << endl; }
				os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
				os << "Quantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}

	//reads the user input of all product details
	std::istream& AmaProduct::read(std::istream& is) {
		char buf[2000];
		double dbuf;
		int ibuf=0;
		char cbuf;
		cout << "Sku: "; 
		is >> buf;		//reads sku
		sku(buf);		//sets sku
		cout << "Name: ";
		is >> buf;		//reads name
		name(buf);		//sets name
		cout << "Unit: ";
		cin.ignore();
		cbuf = getchar();
		while (cbuf != '\n') {
			buf[ibuf] = cbuf;
			cbuf = getchar();
			ibuf++;
		}
		buf[ibuf] = '\0';
		unit(buf);		//sets unit
		cout << "Taxed? (y/n): ";
		is >> cbuf;		//reads taxed or not
		if (cbuf == 'Y' || cbuf == 'y' || cbuf == 'N' || cbuf == 'n') {
			err_.clear();			//clears the error message
			if (cbuf == 'Y' || cbuf == 'y') { taxed(true); }	//if uesr press Y or y, sets taxed to true
			else { taxed(false); }		//if user presses N or n, taxed is set false
			cout << "Price: ";
			is >> dbuf;		//reads price
			if (is.fail()) {
				err_.message("Invalid Price Entry");	//if reading fails, sets the related error message
			}
			else {
				price(dbuf);		//sets the price if no error in reading the input
				cout << "Quantity On hand: ";
				is >> ibuf;			//reads quantity of product
				if (is.fail()) { err_.message("Invalid Quantity Entry"); }  //if reading fails, sets the related error message
				else {
					quantity(ibuf);		//sets the quantity if no error in reading the input
					cout << "Quantity Needed: ";
					is >> ibuf;		//reads quantity needed of product
					if (is.fail()) { err_.message("Invalid Quantity Needed Entry"); }	//if reading fails, sets the related error message
					else {
						qtyNeeded(ibuf);		//sets the quantity needed if no error in reading the input
					}
				}
			}
		}
		else { err_.message("Only (Y)es or (N)o are acceptable");		//if user presses other than yes or no, related error message is set
		is.setstate(ios::failbit);
		}
		return is;
	}
}