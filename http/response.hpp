#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__

#include <stdio.h>

namespace myun2
{
	namespace cornelius
	{
		namespace http
		{
			int send_response_header(
					const char* protocol, unsigned short status, const char* reason,
					FILE* fp)
			{
				return fprintf(fp, "%s %d %s\r\n", protocol, status, reason);
			}
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__
