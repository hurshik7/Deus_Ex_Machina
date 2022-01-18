#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
		, mPassengersWeight(0)
		, mOdo(0)
		, mIdleTime(0)
		, mMoveTime(0)
	{
		mPassengersArray = new const Person*[mMaxPassengersCount];
		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengersArray[i] = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			delete mPassengersArray[i];
			mPassengersArray[i] = nullptr;
		}
		delete[] mPassengersArray;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mPassengersCount(other.mPassengersCount)
		, mPassengersWeight(other.mPassengersWeight)
		, mOdo(other.mOdo)
		, mIdleTime(other.mIdleTime)
		, mMoveTime(other.mMoveTime)
	{
		mPassengersArray = new const Person*[mMaxPassengersCount];
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArray[i] = new Person(other.mPassengersArray[i]->GetName().c_str(), other.mPassengersArray[i]->GetWeight());
		}
		
		for (size_t i = mPassengersCount; i < mMaxPassengersCount; i++)
		{
			mPassengersArray[i] = nullptr;
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			delete mPassengersArray[i];
			mPassengersArray[i] = nullptr;
		}
		delete[] mPassengersArray;

		mMaxPassengersCount = rhs.mMaxPassengersCount;
		mPassengersCount = rhs.mPassengersCount;
		mPassengersWeight = rhs.mPassengersWeight;
		mOdo = rhs.mOdo;
		mIdleTime = rhs.mIdleTime;
		mMoveTime = rhs.mMoveTime;
		mPassengersArray = new const Person*[mMaxPassengersCount];
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArray[i] = new Person(rhs.mPassengersArray[i]->GetName().c_str(), rhs.mPassengersArray[i]->GetWeight());
		}

		for (size_t i = mPassengersCount; i < mMaxPassengersCount; i++)
		{
			mPassengersArray[i] = nullptr;
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengersCount >= mMaxPassengersCount)
		{
			return false;
		}

		mPassengersArray[mPassengersCount] = person;
		mPassengersCount++;
		mPassengersWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengersCount)
		{
			return false;
		}

		mPassengersWeight -= mPassengersArray[i]->GetWeight();

		delete mPassengersArray[i];
		for (i; i < mPassengersCount - 1; i++)
		{
			mPassengersArray[i] = mPassengersArray[i + 1];
		}
		mPassengersArray[i] = nullptr;

		mPassengersCount--;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPassengersCount)
		{
			return nullptr;
		}
		return mPassengersArray[i];
	}

	unsigned int Vehicle::GetPassengersWeight() const
	{
		return mPassengersWeight;
	}

	void Vehicle::TransferAllPassengers()
	{
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPassengersArray[i] = nullptr;
		}
		mPassengersCount = 0;
		mPassengersWeight = 0;
	}

	unsigned int Vehicle::GetOdo() const
	{
		return mOdo;
	}

	void Vehicle::AddOdo(unsigned int distance)
	{
		mOdo += distance;
	}

	unsigned int Vehicle::GetIdleTime() const
	{
		return mIdleTime;
	}

	void Vehicle:: AddIdleTime()
	{
		mIdleTime++;
	}

	void Vehicle::ResetIdleTIme()
	{
		mIdleTime = 0;
	}

	unsigned int Vehicle::GetMoveTime() const
	{
		return mMoveTime;
	}

	void Vehicle::AddMoveTime()
	{
		mMoveTime++;
	}

	void Vehicle::ResetMoveTime()
	{
		mMoveTime = 0;
	}
}