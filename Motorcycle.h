#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;
		virtual void TravelByMachina();

	private:
		enum { IDLE_TIME = 1, MOVE_TIME = 5};
	};
}