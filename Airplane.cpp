#include <cmath>
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int totalMaxPassengersCount = GetMaxPassengersCount() + boat.GetMaxPassengersCount();
		Boatplane bp(totalMaxPassengersCount);
		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		TransferAllPassengers();

		for (size_t i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}
		boat.TransferAllPassengers();

		return bp;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flyingSpeed = GetFlySpeed();
		unsigned int drivingSpeed = GetDriveSpeed();
		return flyingSpeed > drivingSpeed ? flyingSpeed : drivingSpeed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>((200.0 * exp((800.0 - GetPassengersWeight()) / 500.0)) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned int>(4.0 * exp(((400.0 - GetPassengersWeight()) / 70.0)) + 0.5);
	}

	void Airplane::TravelByMachina()
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