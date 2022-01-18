#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable 
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		Boatplane operator+(Airplane& plane);
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		virtual void TravelByMachina();
	
	private:
		enum { IDLE_TIME = 1, MOVE_TIME = 2 };
	};
}