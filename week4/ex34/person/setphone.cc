#include "person.ih"

void Person::setPhone(std::string const &phone)
{
	string legalChar= " 0123456789";

	if (phone.find_first_not_of(legalChar) != string::npos) //Search for illegal char
	{
		cout << "Incorrect phone number, it should only contain digits";
		return;
	}

	d_phone = phone;
}
