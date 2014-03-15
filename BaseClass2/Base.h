#define SAVE 	vector<int*> MEMBERS = vector<int*>
#define REG_MEMBER(x) &x
#define ENDSAVE ;\
	void Save(char* name)\
	{\
		ofstream file(name);\
		for (size_t i = 0; i < MEMBERS.size() && file << *MEMBERS[i] << " "; i++);\
	}\
	void Load(char* name)\
	{\
		ifstream file(name);\
		for (size_t i = 0; i < MEMBERS.size() && file >> *MEMBERS[i]; i++);\
	}\

#include <vector>
#include <fstream>

using std::vector;
using std::ofstream;
using std::ifstream;

class Point{
public:
	int x;
	int y;
	int z; // z - не будет сериализоваться
	SAVE{
		REG_MEMBER(x),
		REG_MEMBER(y)
	}
	ENDSAVE;	
};
