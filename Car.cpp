#include <iostream>
#include "car.h"

Car::Car()
{
	//default mode
	m_isLightOn = false;
	m_isWiperOn = false;
	m_isHandbrakeOn = true;

	m_totalGears = 5;
	m_currentGear = Gears::NEUTRAL;

	m_totalFuel = 0.0f;
	m_rida = 0.0f;
	m_greitis = 0.0f;
	m_pagreitis = 0.0f;
	m_fuelTankSize = 40.0f;

	std::cout << "car created" << std::endl;

}

Car::~Car()
{
	std::cout << "car destroyed" << std::endl;
}

//setter

void Car::IsLightOn(bool toggle)
{
	m_isLightOn = toggle;
}

void Car::IsWiperOn(bool toggle)
{
	m_isWiperOn = toggle;
}

void Car::IsHandbrakeOn(bool toggle)
{
	m_isHandbrakeOn = toggle;
}

void Car::SetTotalGears(int gears)
{
	m_totalGears = gears;
}

void Car::SetVelocity(float velocity)
{
	m_greitis = velocity;
}

void Car::SetAcceleration(float acceleration)
{
	m_pagreitis = acceleration;
}


//getter

bool Car::IsLightOn()
{
	return m_isLightOn;
}

bool Car::IsWiperOn()
{
	return m_isWiperOn;
}

bool Car::IsHandbrakeOn()
{
	return m_isHandbrakeOn;
}

float Car::GetTotalFuel()
{
	return m_totalFuel;
}

float Car::GetGreitis()
{
	return m_greitis;
}

float Car::GetRida()
{
	return m_rida;
}



void Car::ChangeGear(Gears gear)
{
	if (gear == Gears::REVERSE && m_currentGear != Gears::NEUTRAL)
	{
		std::cout << "You cannot simply switch into reverse" << std::endl;
	}
	else if (m_currentGear == Gears::REVERSE && gear != Gears::NEUTRAL)
	{
		std::cout << "You cannot simply switch into reverse" << std::endl;
	}
	else
	{
		m_currentGear = gear;
	}

}

void Car::Drive() // 1 unit per frame
{
	if (!m_isHandbrakeOn)
	{
		m_greitis = m_greitis + m_pagreitis; //m_velocity = m_velocity + m_acceleration

		m_rida += m_greitis;  // m_distanceTravelled = m_distanceTravelled + m_velocity
	}
	else
	{
		std::cout << "Handbrake is on" << std::endl;
	}
}

void Car::PlayMusic()
{

}

void Car::Dashboard()
{
	system("cls");
	std::cout << "*=======================================*" << std::endl;
	std::cout << " |                DASHBOARD            |" << std::endl;
	std::cout << "*=======================================*" << std::endl;
	std::cout << " | Velocity: " << m_greitis << std::endl;
	std::cout << " | Acceleration: " << m_pagreitis << std::endl;
	std::cout << " | Distance travelled : " << m_rida << std::endl;
	std::cout << " | LIGHTS: " << ((m_isLightOn) ? "ON" : "OFF") << std::endl;
	std::cout << " | WIPERS: " << ((m_isWiperOn) ? "ON" : "OFF") << std::endl;
	std::cout << " | HANDBRAKE: " << ((m_isHandbrakeOn) ? "ON" : "OFF") << std::endl;
	std::cout << " | FUEL: " << m_totalFuel << std::endl;
	std::cout << "*=======================================*" << std::endl;
}

void Car::FillTank(float fuel)
{
	m_totalFuel += fuel;

	if (m_totalFuel >= m_fuelTankSize)
	{
		std::cout << "Your tank is full!" << std::endl;
		m_totalFuel = m_fuelTankSize;
	}


}
