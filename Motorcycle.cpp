#include <cmath>
#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		return std::max(static_cast<int>(400 + (2 * GetPassengersWeight()) - pow(GetPassengersWeight() / static_cast<double>(15), 3) + 0.5), 0);
	}

	void Motorcycle::TravelByMachina()
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
			AddIdleTime();
			if (GetIdleTime() == IDLE_TIME)
			{
				ResetMoveTime();
				ResetIdleTIme();
			}
		}
	}
}