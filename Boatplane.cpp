#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(round(150.0 * exp((500.0 - GetPassengersWeight()) / 300.0)));
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		return std::max(static_cast<int>(round(800.0 - 1.7 * GetPassengersWeight())), 20);
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flyingSpeed = GetFlySpeed();
		unsigned int sailingSpeed = GetSailSpeed();
		return flyingSpeed > sailingSpeed ? flyingSpeed : sailingSpeed;
	}

	void Boatplane::TravelByMachina()
	{
		unsigned int moveTime = GetMoveTime();
		unsigned int idleTime = GetIdleTime();
		unsigned int speed = GetMaxSpeed();
		//check available
		if (moveTime < MOVE_TIME)
		{
			//move
			AddMoveTime();
			AddOdo(speed);
		}
		else if (moveTime == MOVE_TIME && idleTime < IDLE_TIME)
		{ 
			//idle time
			AddIdleTime();
			if (GetIdleTime() == IDLE_TIME)
			{
				ResetMoveTime();
				ResetIdleTIme();
			}
		}
	}
}