#pragma once

// Static Variables. ---------------------------------------------------------------------------

int Airplane::MaxCount = 100;
int Airplane::staticID = 0;

// Constructors. -------------------------------------------------------------------------------

Airplane::Airplane()
{
	if (MaxCount < 1) assert(!"\nTeyyare sayi Maksimumdur. Yeni Teyyare Yaradila Bilmez !\n");

	if (MaxCount > 0) MaxCount--;

	staticID++;
	_ID = staticID;

	_Model = nullptr;
	_Color = nullptr;
	_Engine = 0.0;
	_Capacity = 0;
}
Airplane::Airplane(const char* Model) : Airplane()
{
	Set_Model(Model);
}
Airplane::Airplane(const char* Model, const char* Color) : Airplane(Model)
{
	Set_Color(Color);
}
Airplane::Airplane(const char* Model, const char* Color, const double Engine) : Airplane(Model, Color)
{
	Set_Engine(Engine);
}
Airplane::Airplane(const char* Model, const char* Color, const double Engine, const int Capacity) : Airplane(Model, Color, Engine)
{
	Set_Capacity(Capacity);
}
Airplane::Airplane(const Airplane& airplane)
{
	if (MaxCount < 1) assert(!"\nTeyyare sayi Maksimumdur. Yeni Teyyare Yaradila Bilmez !\n");

	if (MaxCount > 0) MaxCount--;

	this->_ID = airplane._ID;
	this->Set_Model(airplane._Model);
	this->Set_Color(airplane._Color);
	this->Set_Engine(airplane._Engine);
	this->Set_Capacity(airplane._Capacity);
}

// Setter Methods. ---------------------------------------------------------------------------

void Airplane::Set_Id(const int sfId)
{
	if (sfId > staticID)
		_ID = sfId;
}
void Airplane::Set_Model(const char* sfModel)
{
	if (sfModel == nullptr) assert(!"Gonderilen Model nullptr -dir.");

	int mLen = strlen(sfModel);

	if (mLen < 4) assert(!"Modelin Herf Sayi 3 den Chox Olmalidir.");

	if (_Model != nullptr) delete[] _Model;

	_Model = new char[mLen + 1];

	strcpy_s(_Model, mLen + 1, sfModel);
}
void Airplane::Set_Color(const char* sfColor)
{
	if (sfColor == nullptr) assert(!"Gonderilen Reng nullptr -dir.");

	int cLen = strlen(sfColor);

	if (cLen < 2) assert(!"Rengin Herf Sayi 1 den Chox Olmalidir.");

	if (_Color != nullptr) delete[] _Color;

	_Color = new char[cLen + 1];

	strcpy_s(_Color, cLen + 1, sfColor);
}
void Airplane::Set_Engine(const double sfEngine)
{
	if (sfEngine < 0) assert(!"Muherrik Hecmi 0 -dan Chox Olmalidir.");

	_Engine = sfEngine;
}
void Airplane::Set_Capacity(const int sfCapacity)
{
	if (sfCapacity < 3) assert(!"Teyyarenin Tutumu 2 -den Chox Olmalidir.");

	_Capacity = sfCapacity;
}

// Getter Methods. ---------------------------------------------------------------------------

const int Airplane::Get_ID() { return _ID; }
const int Airplane::Get_StaticID() { return staticID; }
const int Airplane::Get_MaxCount() { return MaxCount; }
const char* Airplane::Get_Model() { return _Model; }
const char* Airplane::Get_Color() { return _Color; }
const double Airplane::Get_Engine() { return _Engine; }
const int Airplane::Get_Capacity() { return _Capacity; }

// Methods. -----------------------------------------------------------------------------------

void Airplane::Print()
{
	if (this == nullptr) return;

	cout << endl;

	cout << "\nAirplane Id >>>  " << _ID << "  <<<" << endl;
	cout << "\nAirplane Model >>>  " << (_Model == nullptr ? "Nullptr" : _Model) << "  <<<" << endl;
	cout << "\nAirplane Color >>>  " << (_Color == nullptr ? "Nullptr" : _Color) << "  <<<" << endl;
	cout << "\nAirplane Engine >>>  " << _Engine << "  <<<" << endl;
	cout << "\nAirplane Capacity >>>  " << _Capacity << "  <<<" << endl;

	cout << endl << endl;
}

Airplane& Airplane::operator=(const Airplane& other)
{
	if (this->_Model != nullptr) {
		delete[] this->_Model;
		this->_Model = nullptr;
	}
	if (this->_Color != nullptr) {
		delete[] this->_Color;
		this->_Color = nullptr;
	}

	this->_ID = other._ID;
	this->Set_Model(other._Model);
	this->Set_Color(other._Color);
	this->Set_Engine(other._Engine);
	this->Set_Capacity(other._Capacity);

	return *this;
}

// Destructor. --------------------------------------------------------------------------------

Airplane::~Airplane()
{
	if (_Model != nullptr)
	{
		delete[] _Model; _Model = nullptr;
	}

	if (_Color != nullptr)
	{
		delete[] _Color; _Color = nullptr;
	}
}



// ------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------



//>>>>>>>   Garage class.	<<<<<<<<<<<<<<<<<<

// Constructors. ------------------------------------------------------------------------------

Garage::Garage()
{
	_Airplanes = nullptr;
	_Name = nullptr;
	_Address = nullptr;
	_Count = 0;
}
Garage::Garage(const char* Name) : Garage()
{
	Set_Name(Name);
}
Garage::Garage(const char* Name, const char* Address) : Garage(Name)
{
	Set_Address(Address);
}
Garage::Garage(const char* Name, const char* Address, Airplane** Airplanes, const int Count) : Garage(Name, Address)
{
	Set_Airplanes(Airplanes, Count);
}
Garage::Garage(const Garage& garage)
{
	this->_Count = garage._Count;
	this->Set_Name(garage._Name);
	this->Set_Address(garage._Address);
	this->Set_Airplanes(garage._Airplanes, garage._Count);
}

// Setter Methods. ----------------------------------------------------------------------------

void Garage::Set_Airplanes(Airplane** sfAirplanes, const int sfCount)
{
	if (sfAirplanes == nullptr) assert(!"\nGonderilen Teyyareler nullptr -dir.\n");
	if (sfCount < 1) assert(!"\nGonderilen Say Minimum 1 Olmalidir.\n");

	for (int a = 0; a < sfCount; a++) AddAirplane(sfAirplanes[a]);
}
void Garage::Set_Name(const char* sfName)
{
	if (sfName == nullptr) assert(!"Gonderilen Ad nullptr -dir.");

	int nameLen = strlen(sfName);

	if (nameLen < 4) assert(!"Adin Herf Sayi 3 den Chox Olmalidir.");

	if (_Name != nullptr) delete[] _Name;

	_Name = new char[nameLen + 1];

	strcpy_s(_Name, nameLen + 1, sfName);
}
void Garage::Set_Address(const char* sfAddress)
{
	if (sfAddress == nullptr) assert(!"\nGonderilen Address nullptr -dir.\n");

	int adrLen = strlen(sfAddress);

	if (adrLen < 4) assert(!"\nAddressin Herf Sayi 3 den Chox Olmalidir.\n");

	if (_Address != nullptr) delete[] _Address;

	_Address = new char[adrLen + 1];

	strcpy_s(_Address, adrLen + 1, sfAddress);
}

// Getter Methods. ----------------------------------------------------------------------------

Airplane** Garage::Get_Airplanes()
{
	if (_Count > 0) 
	{
		Airplane** CopyAirplanes = new Airplane * [_Count];

		for (int a = 0; a < _Count; a++)
		{
			Airplane* CopyAirplane = new Airplane(*(_Airplanes[a]));

			CopyAirplanes[a] = CopyAirplane;
		}

		return CopyAirplanes;
	}
	return nullptr;
}

const int Garage::Get_Count() { return _Count; }
const char* Garage::Get_Name() { return _Name; }
const char* Garage::Get_Address() { return _Address; }

// Methods. -----------------------------------------------------------------------------------

Garage& Garage::operator=(const Garage& other)
{
	if (this->_Name != nullptr) {
		delete[] this->_Name;
		this->_Name = nullptr;
	}

	if (this->_Address != nullptr) {
		delete[] this->_Address;
		this->_Address = nullptr;
	}

	if (this->_Airplanes != nullptr)
	{
		for (int r = 0; r < this->_Count; r++)
		{
			if (this->_Airplanes[r] != nullptr)
			{
				delete this->_Airplanes[r];
				this->_Airplanes[r] = nullptr;
			}
		}
		delete[] this->_Airplanes;
		this->_Airplanes = nullptr;
	}

	this->Set_Name(other._Name);
	this->Set_Address(other._Address);
	this->Set_Airplanes(other._Airplanes, other._Count);
	this->_Count = other._Count;

	return *this;
}

void Garage::AddAirplane(const Airplane* airplane)
{
	Airplane** NewAirplanes = new Airplane * [_Count + 1];
	
	if (_Airplanes != nullptr  && _Count > 0) {
		for (int a = 0; a < _Count; a++)
			NewAirplanes[a] = _Airplanes[a];
	}

	Airplane* newAirplane = new Airplane(*airplane);

	NewAirplanes[_Count] = newAirplane;

	if (_Airplanes != nullptr) delete[] _Airplanes;

	_Airplanes = NewAirplanes;
	_Count++;
}
void Garage::Print()
{
	if (this == nullptr) return;

	cout << endl << "\t\tGarage Name : " << (_Name == nullptr ? "nullptr" : _Name) << endl;
	cout << "\t\tGarage Address : " << (_Address == nullptr ? "nullptr" : _Address) << endl;
	cout << "\t\tAirplane Count in Garage : " << _Count << endl;

	for (int a = 0; a < _Count; a++)
	{
		cout << "<------------->\n";
		_Airplanes[a]->Print();
	}
	cout << "\n<--------------------------------->\n\n";
}

Airplane* Garage::GetAirplaneById(const int id)
{
	if (id < 1) assert(!"\nGonderilen id 0 -dan Boyuk Olmalidir !\n");

	for (int ap = 0; ap < _Count; ap++)
	{
		if (_Airplanes[ap]->Get_ID() == id)
		{
			Airplane* Ap = new Airplane(*(_Airplanes[ap]));

			return Ap;
		}
	}

	return nullptr;
}
Airplane** Garage::GetAirplanesCapacityGreaterThan(const int capacityCount)
{
	if (capacityCount < 1) assert(!"\nGonderilen Tutum 0 -dan Boyuk Olmalidir !\n");

	Airplane** Planes;

	int countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Capacity() >= capacityCount)
			countOfPlanes++;

	if (countOfPlanes > 0)
		Planes = new Airplane * [countOfPlanes];
	else return nullptr;

	countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Capacity() >= capacityCount)
			Planes[countOfPlanes++] = new Airplane(*(_Airplanes[ap]));

	return Planes;
}
Airplane** Garage::GetAirplanesCapacityLowerThan(const int capacityCount)
{
	if (capacityCount < 1) assert(!"\nGonderilen Tutum 0 -dan Boyuk Olmalidir !\n");

	Airplane** Planes;

	int countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Capacity() <= capacityCount)
			countOfPlanes++;

	if (countOfPlanes > 0)
		Planes = new Airplane * [countOfPlanes];
	else return nullptr;

	countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Capacity() <= capacityCount)
			Planes[countOfPlanes++] = new Airplane(*(_Airplanes[ap]));

	return Planes;
}
Airplane** Garage::GetAirplanesByColor(const char* color)
{
	if (color == nullptr) assert(!"\nGonderilen Reng nullptr -dir !\n");

	int countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (strcmp(_Airplanes[ap]->Get_Color(), color) == 0)
			countOfPlanes++;

	Airplane** Planes;

	if (countOfPlanes > 0)
		Planes = new Airplane * [countOfPlanes];
	else return nullptr;

	countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (strcmp(_Airplanes[ap]->Get_Color(), color) == 0)
			Planes[countOfPlanes++] = new Airplane(*(_Airplanes[ap]));

	return Planes;
}
Airplane** Garage::GetAirplanesByEngine(const double engine)
{
	if (engine < 0.0) assert(!"\nGonderilen Tutum 0-dan Boyuk olmalidir !\n");

	Airplane** Planes;

	int countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Engine() == engine)
			countOfPlanes++;

	if (countOfPlanes > 0)
		Planes = new Airplane * [countOfPlanes];
	else return nullptr;

	countOfPlanes = 0;

	for (int ap = 0; ap < _Count; ap++)
		if (_Airplanes[ap]->Get_Engine() == engine)
			Planes[countOfPlanes++] = new Airplane(*(_Airplanes[ap]));

	return Planes;
}

// Destructor. --------------------------------------------------------------------------------

Garage::~Garage()
{
	if (_Name != nullptr) {
		delete[] _Name;
		_Name = nullptr;
	}

	if (_Address != nullptr) {
		delete[] _Address;
		_Address = nullptr;
	}

	if (_Airplanes != nullptr)
	{
		for (int r = 0; r < _Count; r++)
		{
			if (_Airplanes[r] != nullptr)
			{
				delete _Airplanes[r];
				_Airplanes[r] = nullptr;
			}
		}
		delete[] _Airplanes;
		_Airplanes = nullptr;
	}
}