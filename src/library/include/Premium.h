#ifndef RESTAURANT_PREMIUM_H
#define RESTAURANT_PREMIUM_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "ClientType.h"

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////////// Class definition
	class Premium
			: public ClientType
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		Premium();

		//----------------------------------------------------------------------------- Destructor <
		~Premium() = default;

		//-------------------------------------------------------------------------------- Getters <
		double 	getDiscountPercentage() const override;
		int 	getMaximumTableCount() 	const override;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_PREMIUM_H */
