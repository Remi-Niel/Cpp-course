
istr >> no1;
cout << "extracted first number: " << no1 << '\n';

istr.clear();
istr.str(argv[2]);
size_t no2 = 0;
istr >> no2;