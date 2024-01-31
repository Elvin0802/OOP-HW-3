#pragma once

class Airplane
{
	// Private Variables.

	int _ID;
	char* _Model;
	char* _Color;
	double _Engine;
	int _Capacity;

public:

	// Static Variables.

	static int staticID;
	static int MaxCount;

	// Constructors.

	Airplane();
	explicit Airplane(const char* Model);
	Airplane(const char* Model, const char* Color);
	Airplane(const char* Model, const char* Color, const double Engine);
	Airplane(const char* Model, const char* Color, const double Engine, const int Capacity);
	Airplane(const Airplane& airplane);

	// Setter Methods.

	void Set_Id(const int sfId);
	void Set_Model(const char* sfModel);
	void Set_Color(const char* sfColor);
	void Set_Engine(const double sfEngine);
	void Set_Capacity(const int sfCapacity);

	// Getter Methods.

	const int Get_ID();
	const int Get_StaticID();
	const int Get_MaxCount();
	const char* Get_Model();
	const char* Get_Color();
	const double Get_Engine();
	const int Get_Capacity();
	// Get Max Count yaz.

	// Methods. 

	void Print();

	Airplane& operator=(const Airplane& other);

	// Destructor.

	~Airplane();

};

class Garage
{
	// Private Variables.

	Airplane** _Airplanes;
	size_t _Count;
	char* _Name;
	char* _Address;

public:

	// Constructors.

	Garage();
	explicit Garage(const char* Name);
	Garage(const char* Name, const char* Address);
	Garage(const char* Name, const char* Address,Airplane** Airplanes, const int Count);
	Garage(const Garage& garage);

	// Setter Methods.

	void Set_Airplanes(Airplane** sfAirplanes, const int sfCount);
	void Set_Name(const char* sfName);
	void Set_Address(const char* sfAddress);

	// Getter Methods.

	Airplane** Get_Airplanes();
	const int Get_Count();
	const char* Get_Name();
	const char* Get_Address();

	// Methods. 

	Garage& operator=(const Garage& other);

	void AddAirplane(const Airplane* airplane);
	void Print();

	Airplane* GetAirplaneById(const int id);
	Airplane** GetAirplanesCapacityGreaterThan(const int capacityCount);
	Airplane** GetAirplanesCapacityLowerThan(const int capacityCount);
	Airplane** GetAirplanesByColor(const char* color);
	Airplane** GetAirplanesByEngine(const double engine);

	// Destructor.

	~Garage();

};