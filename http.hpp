#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTTP_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTTP_HPP__

#include <string>

namespace myun2
{
	namespace cornelius
	{
		struct http_request
		{
			::std::string method;
			::std::string path;
			::std::string protocol;

			int parse(const char* s)
			{
			}
		};

	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTTP_HPP__
