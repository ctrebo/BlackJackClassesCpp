#ifndef ID_GENERATOR
#define ID_GENERATOR

class IdGenerator {
private:
    static int s_idGenerator;
    int m_id;

public:
    IdGenerator(); // grab the next value from the id generator

    int getID() const;

    void reset();
};

int IdGenerator::s_idGenerator = 0; // start our ID generator with value 1



#endif