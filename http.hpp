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

			static http_request parse(const char* s)
			{
				http_request r;
				const char *prev = s;
				while(*s != '\0' && *s != '\r' && *s != '\n')
				{
					if (*s == ' ') {
						if (r.method.empty())
							r.method = ::std::string(s, s - prev);
						else if (r.path.empty())
							r.path = ::std::string(s, s - prev);
					}
				}
				r.protocol = ::std::string(s, s - prev);
				return r;
			}
		};
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTTP_HPP__
