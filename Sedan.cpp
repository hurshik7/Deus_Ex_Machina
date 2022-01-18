#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mbIsTrailOn(false)
		, mTrailer(nullptr)
	{
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, mbIsTrailOn(other.mbIsTrailOn)
		, mTrailer(nullptr)
	{
		if (other.mTrailer != nullptr)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		Vehicle::operator=(rhs);

		delete mTrailer;
		mbIsTrailOn = rhs.mbIsTrailOn;
		mTrailer = nullptr;
		if (rhs.mTrailer != nullptr)
		{
			mTrailer = new Trailer(rhs.mTrailer->GetWeight());
		}
		return *this;
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbIsTrailOn == true)
		{
			return false;
		}

		mTrailer = trailer;
		mbIsTrailOn = true;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mbIsTrailOn == false)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = nullptr;
		mbIsTrailOn = false;

		return true;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int ret;
		unsigned int totalWeight = GetPassengersWeight();
		if (mbIsTrailOn == true)
		{
			totalWeight += mTrailer->GetWeight();
		}

		if (totalWeight <= 80)
		{
			ret = 480;
		}
		else if (totalWeight <= 160)
		{
			ret = 458;
		}
		else if (totalWeight <= 260)
		{
			ret = 400;
		}
		else if (totalWeight <= 350)
		{
			ret = 380;
		}
		else
		{
			ret = 300;
		}
		return ret;
	}

	void Sedan::TravelByMachina()
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
		else if (moveTime == MOVE_TIME)
		{
			AddIdleTime();
			if (mbIsTrailOn == true)
			{
				if (GetIdleTime() == IDLE_TIME_TRAIL_ON)
				{
					ResetIdleTIme();
					ResetMoveTime();
				}
			}
			else
			{
				if (GetIdleTime() == IDLE_TIME)
				{
					ResetMoveTime();
					ResetIdleTIme();
				}
			}
		}
	}
}