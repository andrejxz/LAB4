#include "stdafx.h"
#include "Reader.h"

template<>
void Serialize<Reader>(std::ostream &os, Reader& value)
{

}
template<>
Reader Deserialize<Reader>(std::istream &is)
{
	return Reader();
}
