#include "person.ih"

void Person::setPhone(std::string const &phone)
{
	string legalChar= " 0123456789";

	//Search for illegal char
	if (phone.find_first_not_of(legalChar) != string::npos)
	{
		cout << "Incorrect phone number, it should only contain digits";
		return;
	}

	d_phone = phone;
}
