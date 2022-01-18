#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina() {};
		static DeusExMachina* mInstance;
		enum { MAX_VEHICLES_COUNT = 10 };
		Vehicle** mVehicles;
		unsigned int mVehiclesCount;
	};
}
