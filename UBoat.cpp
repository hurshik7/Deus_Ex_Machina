#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetDiveSpeed() ? GetSailSpeed() : GetDiveSpeed();
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		return std::max(static_cast<int>((550 - GetPassengersWeight() / static_cast<double>(10)) + 0.5), 200);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>((500 * log((GetPassengersWeight() + 150) / static_cast<double>(150)) + 30) + 0.5);
	}

	void UBoat::TravelByMachina()
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