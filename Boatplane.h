#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		virtual ~Boatplane();

		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		virtual void TravelByMachina();

	private:
		enum { IDLE_TIME = 3, MOVE_TIME = 1};
	};
}