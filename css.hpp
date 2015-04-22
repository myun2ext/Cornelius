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
				typedef ::std::map<
					::std::string,
					::std::string> attribute_map;
				attribute_map attributes;

				typedef ::std::map< ::std::string, ::std::string>::iterator
					attribute_iterator;
				typedef ::std::map< ::std::string, ::std::string>::const_iterator
					const_attribute_iterator;

				//	Constructors
				selector(const char* name_)
					: name(name_) {}
				selector(const char* name_, const attribute_map& attributes_)
					: name(name_), attributes(attributes_) {}

				//	Serialization
				::std::string serialize() const
				{
					std::string buffer = name + "{";
					for(const_attribute_iterator it=attributes.begin(); it!=attributes.end(); it++)
						buffer += it->first + ":" + it->second + ";";
					return buffer + "}";
				}

				::std::string& operator [](const char* attribute_name) {
					return attributes[attribute_name];
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__CSS_HPP__
