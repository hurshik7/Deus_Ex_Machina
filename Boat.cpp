#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int totalMaxPassengersCount = GetMaxPassengersCount() + plane.GetMaxPassengersCount();
		Boatplane bp(totalMaxPassengersCount);
		for (size_t i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}
		plane.TransferAllPassengers();

		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		TransferAllPassengers();

		return bp;
	}

	unsigned int Boat::GetSailSpeed() const
	{
		return std::max(static_cast<int>(800 - 10 * GetPassengersWeight()), 20);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	void Boat::TravelByMachina()
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