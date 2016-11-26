#include "stdafx.h"
#include "Serializer.h"

template<>
void Serialize(std::ostream &os, CString &value)
{
	int len = value.GetLength();
	Serialize(os, len);
	wchar_t c;
	for (int i = 0; i < len;++i) {
		c = value[i];
		Serialize(os, c);
	}
}

template<>
CString Deserialize<CString>(std::istream &is)
{
	CString str;
	int len = Deserialize<int>(is);
	wchar_t c;
	for (int i = 0; i < len;++i) str += Deserialize<wchar_t>(is);
	return str;
}