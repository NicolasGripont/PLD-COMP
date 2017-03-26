#include "multipleargument.h"

MultipleArgument::MultipleArgument() {

}

MultipleArgument::~MultipleArgument() {

}

void MultipleArgument::addArgument(Argument * argument) {
	if(argument != NULL) {
		arguments.push_back(argument);
	}
}
	
string MultipleArgument::print() const {
	return "";
}