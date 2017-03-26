#include "genesis.h"

Genesis::Genesis() {
    
}

Genesis::~Genesis(){
    
}

string Genesis::print() const {
	return "";
}

void Genesis::addDeclaration(Declaration* declaration) {
	if(declaration != NULL) {
		declarations.push_back(declaration);
	}
}
