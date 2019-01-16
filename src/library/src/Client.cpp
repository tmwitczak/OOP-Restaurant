#include "Client.h"
#include "Basic.h"
#include "Premium.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::Client::Client(std::string const &firstName, std::string const &lastName,
		std::string const &telephoneNumber, std::string const &clientType)
	:	firstName(firstName),
		lastName(lastName),
		telephoneNumber(telephoneNumber),
		clientType(makeClientType(clientType))
{
}
//--------------------------------------------------------------------------------------------------
Restaurant::Client::~Client()
{
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::Client::getFirstName() const
{
	return firstName;
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::Client::getLastName() const
{
	return lastName;
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::Client::getTelephoneNumber() const
{
	return telephoneNumber;
}
//--------------------------------------------------------------------------------------------------
double Restaurant::Client::getDiscountPercentage() const
{
	return clientType->getDiscountPercentage();
}
//--------------------------------------------------------------------------------------------------
int Restaurant::Client::getMaximumTableCount() const
{
	return clientType->getMaximumTableCount();
}
//--------------------------------------------------------------------------------------------------
Restaurant::ClientType_Ptr Restaurant::Client::makeClientType(
		std::string const &clientTypeString) const
{
	if(clientTypeString == "basic")
		return std::make_shared<Restaurant::Basic>();
	else if(clientTypeString == "premium")
		return std::make_shared<Restaurant::Premium>();
	/* TODO: Exceptions
	 * else
		throw;*/
	else
		return std::make_shared<Restaurant::Premium>(); // TODO: Exceptions
}
////////////////////////////////////////////////////////////////////////////////////////////////////