#ifndef RESTAURANT_PREMIUM_H
#define RESTAURANT_PREMIUM_H
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "ClientType.h"
//--------------------------------------------------------------------------------------------------
namespace Restaurant
{
	class Premium
			: public ClientType
	{
	public:
		~Premium() = default;

		double getDiscountPercentage() const override;
		int getMaximumTableCount() const override;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_PREMIUM_H */
