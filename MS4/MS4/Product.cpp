/* Name: Aakash Shrestha
Student ID: 140051160
OOP 244 SDD
Final Project: Milestone 4
Date: 2017 July 16
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Product.h"
namespace sict {
	//no argument, default constructor which assigns the object to a safe empty state
	Product::Product() {
		sku_[0]='\0';
		name_=nullptr;
		price_=0.0;
		taxed_=0;
		quantity_=0;
		qtyNeeded_=0;
	}
	
	//six argument constructor, last four being optional, set to zero
	Product::Product(const char* SKU, const char* Name, bool taxed, double price, int quantity,int neededQty) {
		bool valid = SKU[0] != '\0'  && Name != nullptr ; //checking for valid data
		if (valid) {
			strncpy(sku_, SKU, strlen(SKU)); //copies sku
			sku_[strlen(SKU)] = '\0';
			name_ = new char[strlen(Name)+1]; //dynamic memory allocation for name_, size being equal to length of incoming Name plus 1
			strcpy(name_,Name);
			taxed_ = taxed;  //taxed is true if function receives its argument, otherwise false
			price_ = price;	 
			quantity_ = quantity;
			qtyNeeded_ = neededQty;
		}
		else {
			sku_[0] = '\0';	//if argument of functions are invalid, sku and name are set to empty state, others are zero by default
			name_ = nullptr;
		}
	}

	//copy constructor
	Product::Product(const Product& src) {
		//shallow copies
		strcpy(sku_, src.sku_);
		taxed_ = src.taxed_;
		price_ = src.price_;
		quantity_ = src.quantity_;
		qtyNeeded_ = src.qtyNeeded_;
		//deep copy for name_
		if (src.name_ != nullptr) {
			name_ = new char[strlen(src.name_) + 1];
			strcpy(name_, src.name_);
		}
		else {
			name_ = nullptr;
		}
	}

	//copy assignment operator
	Product& Product::operator=(const Product& src) {
		if (this != &src) {
			strcpy(sku_, src.sku_);
			taxed_ = src.taxed_;
			price_ = src.price_;
			quantity_ = src.quantity_;
			qtyNeeded_ = src.qtyNeeded_;
			//deallocate previously allocated memory
			delete[] name_;
			//allocate new
			if (src.name_ != nullptr) {
				name_ = new char[strlen(src.name_) + 1];
				strcpy(name_, src.name_);
			}
			else {
				name_ = nullptr;
			}
		}
		return *this;
	}
	//sets the sku_ of Product
	void Product::sku(const char* SKU) {
		strncpy(sku_, SKU, strlen(SKU));
		sku_[strlen(SKU)] = '\0';
	}

	//sets the price_ of Product
	void Product::price(double price) {
		price_ = price;
	}

	//sets the name_ of Product
	void Product::name(const char* name) {
		delete[] name_;
		name_ = nullptr;
		name_ = new char[strlen(name)+1];
		strcpy(name_, name);
	}

	//sets the taxed_ of Product
	void Product::taxed(bool taxed) {
		taxed_ = taxed;
	}

	//sets the quantity_ of Product
	void Product::quantity(int qty) {
		quantity_ = qty;
	}

	//sets the qtyneeded_ of Product
	void Product::qtyNeeded(int qtyNeeded) {
		qtyNeeded_ = qtyNeeded;
	}

	//reports the sku_ of Product
	const char* Product::sku() const {
		return sku_;
	}

	//reports the price_ of Product
	double Product::price() const {
		return price_;
	}

	//reports the name_ of Product
	const char* Product::name() const {
		return name_;
	}

	//reports the taced_ of Product
	bool Product::taxed() const {
		return taxed_;
	}

	//reports the quantity_ of Product
	int Product::quantity() const {
		return quantity_;
	}

	//reports the qtyNeeded_ of Product
	int Product::qtyNeeded() const {
		return qtyNeeded_;
	}

	//returns the cost_ of Product by applying TAX to price if taxed_ is 1, otherwise returns price_
	double Product::cost() const {
		return taxed() == 1 ? price_ + (price_*TAX) : price_;
	}

	//reports the empty state of Product object
	bool Product::isEmpty() const {
		bool valid = sku_[0] == '\0' && name_ == nullptr && price_ == 0 && taxed_ == 0 && quantity_ == 0 && qtyNeeded_ == 0;
		return valid ? true : false; //returns true if empty, otherwise false
	}

	//assignment operator overload to compare if the Product's sku_ and argument sku are equal: returns true if equal, otherwise false
	bool Product::operator==(const char* sku) {
		return strcmp(sku, sku_) == 0 ? true : false;
	}

	//adds the integer value of incoming argument to quantity_ of product and returns it
	int Product::operator+=(int quantity) {
		 return quantity_ += quantity;
	}

	//subtracts the integer value of incoming argument from quantity_ of product and returns it
	int Product::operator-=(int quantity) {
		return quantity_ -= quantity;
	}

	//destructor
	Product::~Product() {
		delete[] name_;
	}

	//adds the total cost of Product to the value and returns the result
	double operator+=(double& value, const Product& P) {
		value+= P.cost()*P.quantity();
		return value;
	}

	//non-member operator overloading: extraction operator
	std::istream& operator >> (std::istream& istr, Product& P) {
		P.read(istr);
		return istr;
	}

	//non-member operator overloading: insertion operator
	std::ostream& operator <<(std::ostream& ostr, const Product& P) {
		P.write(ostr,1);
		return ostr;
	}

}