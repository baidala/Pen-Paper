#include "Paper.h"

Paper::Paper(int maxSymbols): maxSymbols(maxSymbols), symbols(0), content() {}

Paper::~Paper() {
	this->maxSymbols = 0;
	this->symbols = 0;
	this->content.clear();
}        

int Paper::getMaxSymbols() const {
	return this->maxSymbols;
}

int Paper::getSymbols() const {
	return this->symbols;
}

void Paper::addContent(const std::string& message) {
	int symbolsNeeded = message.size();
	int symbolsFree = this->maxSymbols - this->symbols;
	
	if ( symbolsFree < symbolsNeeded ) {
		std::string subStr = message.substr (0, symbolsFree);

		this->content += subStr;
	    this->symbols = this->maxSymbols;
	    
		throw OutOfSpace();
	}
	
	this->content += message;
	this->symbols += symbolsNeeded;
}        

void Paper::show() const {
	std::cout << this->content << std::endl;
}


