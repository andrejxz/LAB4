#pragma once
#include "stdafx.h"
#include <iostream>

template<class T>
void Serialize(std::ostream &os, T &value)
{
	os.write((char*)&value, sizeof(value));
}

template<class T>
T Deserialize(std::istream &is)
{
	T value;
	is.read((char*)&value, sizeof(T));
	return value;
}

template<>
void Serialize(std::ostream &os, CString &value);
template<>
CString Deserialize<CString>(std::istream &is);