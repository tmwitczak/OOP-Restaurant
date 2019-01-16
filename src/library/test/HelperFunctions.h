#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
////////////////////////////////////////////////////////////////////////////////////////////////////
std::tuple<std::string, std::string, std::string, std::string> getClientParameters();
//--------------------------------------------------------------------------------------------------
template <typename T>
bool compareVectors(std::vector<T> const &vector1, std::vector<T> const &vector2)
{
	if(vector1.size() < vector2.size())
		return std::equal(vector1.begin(), vector1.end(), vector2.begin());
	else
		return std::equal(vector2.begin(), vector2.end(), vector1.begin());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* HELPERFUNCTIONS_H */
