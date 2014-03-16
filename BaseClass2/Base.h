#pragma once

#define SAVE vector<BasePair> MEMBERS = vector<BasePair>
#define REG_MEMBER(x, y) BasePair(BaseClass::x, static_cast<void*>(&y))
#define ENDSAVE ;\
	void Save(char* name)\
	{\
		ofstream file(name);\
		BaseClass::Save_(file, MEMBERS);\
	}\
	void Save_(ostream &os)\
	{\
		BaseClass::Save_(os, MEMBERS); \
	}\
	void Load_(istream &is)\
	{\
		BaseClass::Load_(is, MEMBERS); \
	}\
	void Load(char* name)\
	{\
		ifstream file(name);\
		BaseClass::Load_(file, MEMBERS); \
	}


#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::pair;

class BaseClass // Abstract BaseClass
{	
public:
	enum TYPE
	{
		_int, _uint, _char, _uchar, _long, _ulong, _float, _double, _string, _derive
	};

	typedef pair<TYPE, void*> BasePair;
	
	void Save_(ostream &os, const vector<BasePair> &MEMBERS);
	void Load_(istream &is, vector<BasePair> &MEMBERS);

	virtual void Save(char *name) = 0;	
	virtual void Save_(ostream &os) = 0;	
	virtual void Load(char *name) = 0;
	virtual void Load_(istream &is) = 0;

	friend ostream &operator<<(ostream &os, BasePair p);
	friend istream &operator>>(istream &is, BasePair p);
};