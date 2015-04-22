#ifndef __MYUN2_GITHUB_COM__CORNELIUS__CSS_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__CSS_HPP__

#include <string>
#include <map>

namespace myun2
{
	namespace cornelius
	{
		namespace css
		{
			struct selector
			{
				::std::string name;
				::std::map<::std::string, ::std:string> attributes;
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__CSS_HPP__
