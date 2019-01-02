#ifndef RESTAURANT_BASIC_H
#define RESTAURANT_BASIC_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ClientType.h"
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Basic
			: public ClientType
	{
	public:
		~Basic() = default;

		double getDiscountPercentage() const override;
		int getMaximumTableCount() const override;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_BASIC_H */