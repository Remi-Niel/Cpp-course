#include "person.ih"

void Person::extract(std::istream &input)
{
	string name;
	getline(input, name, ',');
	Person::setName(name);

	string address;
	getline(input, address, ',');
	Person::setAddress(address);

	string phone;
	getline(input, phone, ',');
	Person::setPhone(phone);

	string massStr;
	getline(input, massStr);
	size_t mass = stoul(massStr);
	Person::setMass(mass);
}
