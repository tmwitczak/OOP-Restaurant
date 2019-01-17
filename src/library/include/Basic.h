#ifndef RESTAURANT_BASIC_H
#define RESTAURANT_BASIC_H
/////////////////////////////////////////////////////////////////////////////////// Included headers
#include "ClientType.h"

namespace Restaurant
{
	/////////////////////////////////////////////////////////////////////////////// Class definition
	class Basic
			: public ClientType
	{
	//---------------------------------------------------------------------------------- [ Methods ]
	public:
		//--------------------------------------------------------------------------- Constructors <
		Basic();

		//----------------------------------------------------------------------------- Destructor <
		~Basic() = default;

		//-------------------------------------------------------------------------------- Getters <
		double 	getDiscountPercentage() const override;
		int 	getMaximumTableCount() 	const override;
	};
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* RESTAURANT_BASIC_H */