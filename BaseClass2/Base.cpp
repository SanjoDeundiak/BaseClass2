#include "Base.h"
#include <string>

void BaseClass::Save_(ostream &os, const vector<BasePair> &MEMBERS)
{
	bool flag = false;
	for (size_t i = 0; i < MEMBERS.size(); i++)
	{
		if (MEMBERS[i].first != _derive)
			os << MEMBERS[i] << " ";
		else
			flag = true;
	}
	if (flag)
	for (size_t i = 0; i < MEMBERS.size(); i++)
	{
		if (MEMBERS[i].first == _derive)
			(static_cast<BaseClass*>(MEMBERS[i].second))->Save_(os);
	}
}

void BaseClass::Load_(istream &is, vector<BasePair> &MEMBERS)
{
	bool flag = false;
	for (size_t i = 0; i < MEMBERS.size(); i++)
	{		
		if (MEMBERS[i].first != _derive)
			is >> MEMBERS[i];
		else
			flag = true;
	}
	if (flag)
	for (size_t i = 0; i < MEMBERS.size(); i++)
	{
		if (MEMBERS[i].first == _derive)
			(static_cast<BaseClass*>(MEMBERS[i].second))->Load_(is);
	}
}

ostream &operator<<(ostream &os, BaseClass::BasePair p)
{
	switch (p.first)
	{
	case BaseClass::_int:
		os << *static_cast<int*>(p.second) << " ";
		break;
	case BaseClass::_uint:
		os << *static_cast<unsigned int*>(p.second) << " ";
		break;
	case BaseClass::_char:
		os << *static_cast<char*>(p.second) << " ";
		break;
	case BaseClass::_uchar:
		os << *static_cast<unsigned char*>(p.second) << " ";
		break;
	case BaseClass::_long:
		os << *static_cast<long*>(p.second) << " ";
		break;
	case BaseClass::_ulong:
		os << *static_cast<unsigned long*>(p.second) << " ";
		break;
	case BaseClass::_float:
		os << *static_cast<float*>(p.second) << " ";
		break;
	case BaseClass::_double:
		os << *static_cast<double*>(p.second) << " ";
		break;
	case BaseClass::_string:
		os << *static_cast<std::string*>(p.second) << std::endl;
		break;	
	default:
		throw std::invalid_argument("Unknown type output");
	}
	return os;
}

istream &operator>>(istream &is, BaseClass::BasePair p)
{
	switch (p.first)
	{
	case BaseClass::_int:
		is >> *static_cast<int*>(p.second);
		break;
	case BaseClass::_uint:
		is >> *static_cast<unsigned int*>(p.second);
		break;
	case BaseClass::_char:
		is >> *static_cast<char*>(p.second);
		break;
	case BaseClass::_uchar:
		is >> *static_cast<unsigned char*>(p.second);
		break;
	case BaseClass::_long:
		is >> *static_cast<long*>(p.second);
		break;
	case BaseClass::_ulong:
		is >> *static_cast<unsigned long*>(p.second);
		break;
	case BaseClass::_float:
		is >> *static_cast<float*>(p.second);
		break;
	case BaseClass::_double:
		is >> *static_cast<double*>(p.second);
		break;
	case BaseClass::_string:
		std::getline(is, *static_cast<std::string*>(p.second));
		is.get();
		break;
	default:
		throw std::invalid_argument("Unknown type input");
	}

	return is;
}