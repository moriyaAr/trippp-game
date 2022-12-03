#pragma once
#include <map>
#include <string>
#include "Helper.h"
class MovedObject;
//---------------------------------------------------
typedef vector< std::unique_ptr<MovedObject>(*)()> myObject;
//--------------------------------------------------------
class Factory
{
	public:
		std::unique_ptr<MovedObject> lottery();
		static std::unique_ptr<MovedObject> create(const MyObject & type);
		static bool registerit(const MyObject& type, std::unique_ptr<MovedObject>(*)());
	private:
		static myObject& getMap()
		{
			static myObject m_map(e_maxObject);
			return m_map;
		}
};