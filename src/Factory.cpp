#include "Factory.h"
#include "MovedObject.h"
//----------------------------
const int RANGE_OF_RANDOM_LOT = 8;

//------------------------------
//the func create a random object
std::unique_ptr<MovedObject> Factory::lottery()
{
	int num = rand() % RANGE_OF_RANDOM_LOT;
	return create(MyObject(num));
}
//------------------------------
// the function create spesific object
std::unique_ptr<MovedObject> Factory::create(const MyObject& type)
{
	return getMap()[type]();
}

//------------------------------
//the func regist class thet asked her to regist them
bool Factory::registerit(const MyObject& type, std::unique_ptr<MovedObject>(*f)())
{
	getMap()[type]= f;
	return true;
}
