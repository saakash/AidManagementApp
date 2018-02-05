/* Name: Aakash Shrestha
Student ID: 140051160
OOP 244 SDD
Final Project: Milestone 4
Date: 2017 July 16
*/

// Product.h
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include <iostream>
#include "Streamable.h"
#include "general.h"
namespace sict {
	class Product :public Streamable {
	private:
		//private data members
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		//public member functions
		Product(); //default constructor
		Product(const char* SKU, const char* Name, bool taxed = false, double price = 0.0, int quantity_=0, int neededQty = 0);
		
		//copy constructor
		Product(const Product& src);

		//copy assignment operator
		Product& operator=(const Product& src);

		//settor functions for the data members
		void sku(const char* SKU);
		void price(double price);
		void name(const char* name);
		void taxed(bool taxed);
		void quantity(int qty);
		void qtyNeeded(int qtyNeeded);

		//querries that describes the state of data members
		const char* sku() const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;

		//member operator overloaded functions
		bool operator==(const char* sku);
		int operator+=(int quantity);
		int operator-=(int quantity);

		//virtual functions
		virtual std::ostream& write(std::ostream& os, bool linear)const =0;
		virtual std::istream& read(std::istream& is)=0 ;
		virtual ~Product(); //destructor
};
	//non-member operator overload functions
	double operator+=(double& value,const Product& P);
	std::istream& operator>>(std::istream& ostr, Product& P);
	std::ostream& operator<<(std::ostream& ostr, const Product& P);
	

}
#endif