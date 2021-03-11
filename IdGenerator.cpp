#include "IdGenerator.h"

IdGenerator::IdGenerator() {
	m_id = s_idGenerator++;
}

int IdGenerator::getID() const {
	return m_id;
}

void IdGenerator::reset(){
	s_idGenerator = 0;
}