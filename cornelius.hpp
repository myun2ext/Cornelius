#ifndef __MYUN2_GITHUB_COM__CORNELIUS_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS_HPP__

#include <stdio.h>
#include <string>

namespace myun2
{
	namespace cornelius
	{
	}
}
struct cornelius_request
{
	::std::string method;
	::std::string path;
	::std::string protocol;
};

int parse_request(FILE* fp)
{
	char buffer[LINE_BUFFER];
	fgets(buffer, sizeof(buffer), fp);
}

int cornelius_response(FILE* fp)
{
}

int main()
{
	return 0;
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS_HPP__
