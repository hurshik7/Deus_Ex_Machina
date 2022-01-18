#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance != nullptr)
		{
			return mInstance;
		}
		
		mInstance = new DeusExMachina();
		mInstance->mVehicles = new Vehicle*[MAX_VEHICLES_COUNT];
		for (size_t i = 0; i < MAX_VEHICLES_COUNT; i++)
		{
			mInstance->mVehicles[i] = nullptr;
		}
		mInstance->mVehiclesCount = 0;
		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mVehiclesCount; i++)
		{
			mVehicles[i]->TravelByMachina();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehiclesCount >= MAX_VEHICLES_COUNT)
		{
			return false;
		}

		mVehicles[mInstance->mVehiclesCount] = vehicle;
		mVehiclesCount++;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehiclesCount)
		{
			return false;
		}

		delete mVehicles[i];
		for (i; i < mVehiclesCount - 1; i++)
		{
			mVehicles[i] = mVehicles[i + 1];
		}
		mVehicles[i] = nullptr;
		mVehiclesCount--;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehiclesCount == 0)
		{
			return NULL;
		}

		if (mVehicles[0]->GetOdo() == 0)
		{
			return mVehicles[0];
		}

		unsigned int maxDistance = 0;
		size_t maxIndex;

		for (size_t i = 0; i < mVehiclesCount; i++)
		{
			if (mVehicles[i]->GetOdo() > maxDistance)
			{
				maxDistance = mVehicles[i]->GetOdo();
				maxIndex = i;
			}
		}

		return mVehicles[maxIndex];
	}
}