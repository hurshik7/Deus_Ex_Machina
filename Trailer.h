#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		virtual ~Trailer();

		unsigned int GetWeight() const;

	private:
		unsigned int mWeight;
	};
}