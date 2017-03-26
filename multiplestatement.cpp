#include "multiplestatement.h"

MultipleStatement::MultipleStatement() {

}
	
MultipleStatement::~MultipleStatement() {

}
	
void MultipleStatement::addStatement(Statement *statement) {
	if(statement != NULL) {
		statements.push_back(statement);
	}
}

string MultipleStatement::print() const {
	return "";
}