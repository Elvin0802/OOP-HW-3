#include <iostream>
#include <cassert>

using namespace std;

#include "My Classes.h"
#include "Out Of Classes.h"


void main()
{

	Airplane* a1 = new Airplane("asdasdasd","asdasdasd",33.3,1234);
	Airplane* a2 = new Airplane("sdasdasd", "asdasdasd",34.34,123);
	Airplane* a3 = new Airplane("sdasdhrth", "asdasdasd",234.44,543);
	Airplane* a4 = new Airplane("aasdasddpasd", "asdasdasd",434.5,874);

	Airplane** ar = new Airplane*[4]{ a1,a2,a3,a4 };

	Garage a("AzeGarage asdasda","Baku asdasdasd",ar,4);

	Garage b;

	b = a;
	cout << "\n\tAAAAAAA : \n";
	a.Print();
	cout << "\n\n\tBBBBBBB : \n";
	b.Print();

}