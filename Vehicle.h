#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();
		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& rhs);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetPassengersWeight() const;
		void TransferAllPassengers();
		
		unsigned int GetOdo() const;
		void AddOdo(unsigned int distance);
		unsigned int GetIdleTime() const;
		void AddIdleTime();
		void ResetIdleTIme();
		unsigned int GetMoveTime() const;
		void AddMoveTime();
		void ResetMoveTime();
		virtual void TravelByMachina() = 0;

	private:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		unsigned int mPassengersWeight;
		unsigned int mOdo;
		unsigned int mIdleTime;
		unsigned int mMoveTime;
		const Person** mPassengersArray;
	};
}