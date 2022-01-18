#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		virtual ~UBoat();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetDiveSpeed() const;
		virtual void TravelByMachina();

	private:
		enum { IDLE_TIME = 4, MOVE_TIME = 2 };
	};
}