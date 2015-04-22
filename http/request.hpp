#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTTP__REQUEST_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTTP__REQUEST_HPP__

#include <string>

namespace myun2
{
	namespace cornelius
	{
		namespace http
		{
			struct request
			{
				::std::string method;
				::std::string path;
				::std::string protocol;

				static request parse(const char* s)
				{
					request r;
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
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTTP_HPP__
