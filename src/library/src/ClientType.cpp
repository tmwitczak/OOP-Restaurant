#include "ClientType.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
Restaurant::ClientType::ClientType(std::string const &clientType)
	: 	clientType(clientType)
{
}
//--------------------------------------------------------------------------------------------------
std::string Restaurant::ClientType::getClientType() const
{
	return clientType;
}
////////////////////////////////////////////////////////////////////////////////////////////////////