#include "stdafx.h"
#include "Journal.h"


template<>
void Serialize<Journal>(std::ostream &os, Journal& value)
{

}
template<>
Journal Deserialize<Journal>(std::istream &is)
{
	return Journal();
}