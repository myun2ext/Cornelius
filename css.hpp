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
				typedef typename ::std::map<::std::string, ::std:string>::iterator
					attribute_iterator;

				::std::string serialize() const
				{
					std::string buffer = name + "{";
					for(attribute_iterator it=attributes.begin(); it!=attributes.end(); it++)
						buffer += it.first() + ":" + it.second() + ";";
					return buffer;
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__CSS_HPP__
