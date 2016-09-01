#include "Pen.h"



Pen::Pen(int inkCapacity): inkCapacity(inkCapacity), inkAmount(inkCapacity) {
	this->refill();
}
	
Pen::~Pen() {
	this->inkCapacity = 0;
	this->inkAmount = 0;
}
	
int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    int inkNeeded = message.size();
    
    if( this->inkAmount < inkNeeded ) {
        int symbols = this->inkAmount;
        std::string subStr = message.substr (0, symbols);
        
        try {
	        paper.addContent(sunStr);
        } catch ( OutOfSpace ex ) {
    	    throw OutOfSpace();    	
        }
        this->inkAmount = 0;
        throw OutOfInk();
    }
    
    try {
	    paper.addContent(message);
    } catch ( OutOfSpace ex ) {
    	throw OutOfSpace();    	
    }
    this->inkAmount -= inkNeeded;    
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}
