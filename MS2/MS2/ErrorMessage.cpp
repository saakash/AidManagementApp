/*Name: Aakash Shrestha
  Student ID: 140051160
  OOP244 SDD
  Final Project: Milestone 2
  Date: 2017 July 09
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"ErrorMessage.h"
namespace sict {
	//no argument (default) constructor
	ErrorMessage::ErrorMessage() {
		message_ = nullptr;
	}

	//one argument constructor that sets the error message
	ErrorMessage::ErrorMessage(const char* errorMessage) {
		message_ = nullptr;
		message(errorMessage); //calls message() member function to copy the error message to class's data member, message_
	}

	//assignment operator overloading
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {
		clear(); //calls the clear() function to deallocate previous memory
		message(errorMessage); //calls message() function to set the error message
		return *this; //returns the reference of current object
	}

	//destructor, clears the previously dynamically allocated memory
	ErrorMessage:: ~ErrorMessage() {
		clear();
	}

	//this function clears the memory pointed by message_
	void ErrorMessage::clear() {
		delete[] message_;
		message_ = nullptr;
	}

	//this function checks if the pointer variable (message_) is clear or not: returns true if it is equal to nullptr
	bool ErrorMessage::isClear()const {
		return message_ == nullptr ? true : false;
	}

	//this function sets the message_ of the ErrorMessage object to a new value
	void ErrorMessage::message(const char* value) {
		clear();	//deallocates the memory pointed by message_
		message_ = new char[strlen(value) + 1];	//allocates memory to the length of value+1
		strcpy(message_, value);	//copies the error message to message_
	}

	//this function returns the address of message_
	const char* ErrorMessage::message()const {
		return message_;
	}

	//overloaded << operator that prints the error message of the object. It prints nothing if the object's message_ is clear
	std::ostream& operator<<(std::ostream& ostr,const ErrorMessage& E) {
		if (!E.isClear()) {
			ostr<< E.message();
		}
		return ostr;
	}
}