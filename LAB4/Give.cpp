#include "stdafx.h"
#include "Give.h"

template<>
void Serialize<Give>(std::ostream &os, Give& value)
{

}
template<>
Give Deserialize<Give>(std::istream &is)
{
	Give give;
	return give;
}