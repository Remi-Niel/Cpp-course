#include "main.ih"

int main()
{
    BitSet gross(144);              // A gross of bits, initialized to 0s
    BitSet dozen(101101101111_bits);// A smaller BitSet, with initial value;

    stringstream ss(00000000000000101010101100000000_bits);

    ss >> gross;                            // Extraction

    cout << "gross = " << gross << "\n"     // Insertions
         "dozen = " << dozen << '\n';

    cout << "bits:\n"               // manipulating/outputting bits;
         << (gross[143] = dozen[0]) << '\n'; 

    cout << "shifting:\n"
         << gross << '\n'
         << (gross << 5) << '\n'; // Shift operator

    cout << "bitwise OR:\n"
         << dozen << '\n'
         << (dozen | gross ) << '\n' // bitwise OR
         << dozen << '\n';

    BitSet const no_change;
    // no_change[2] = false;        // WC!

    dozen = gross;                  // copy assignment
    dozen = BitSet{4};              // move assignment
}
