#pragma once
#pragma once

//inherintence - class inherit from base class with "is a "
//polymorphiscm - classes overrides to behave in specific way (tank vs car)
//encapsulation - all related put in group
	//object orientated programming
//abstraction ( oop). data hidding from user . can be public also
	//containment - classes within classes


//class Engine;

class Car
{
public:

	Car();
	~Car();

public:

	enum class Gears { REVERSE = -1, NEUTRAL = 0, FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4, HIGH = 5 };

public: //getter setter
	//setters - function that makes a change to member variable

	void IsLightOn(bool toggle);
	void IsWiperOn(bool toggle);
	void IsHandbrakeOn(bool toggle);

	void SetTotalGears(int gears);

	void SetVelocity(float velocity);
	void SetAcceleration(float acceleration);


	//getters - returns a member variable
	bool IsLightOn();
	bool IsWiperOn();
	bool IsHandbrakeOn();

	float GetTotalFuel();
	float GetGreitis();
	float GetRida();

public:

	//BEHAVIOR
	void ChangeGear(Gears gear);
	void Drive();
	void PlayMusic();
	void Dashboard();
	void FillTank(float fuel);

private:

	//STATE
	bool m_isLightOn;
	bool m_isWiperOn;
	bool m_isHandbrakeOn;

	int m_totalGears;
	Gears m_currentGear; //from enum Gears

	float m_totalFuel;
	float m_rida;
	float m_greitis;
	float m_pagreitis;//akseleracija
	float m_fuelTankSize;

	//Engine m_engine;

};