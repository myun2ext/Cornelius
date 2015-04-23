#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML__TAG_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML__TAG_HPP__

#include <string>
#include <map>

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			struct tag
			{
				const char* name;
				::std::string content;

				typedef ::std::map<
					::std::string,
					::std::string> attribute_map;
				attribute_map attributes;

				typedef ::std::map< ::std::string, ::std::string>::iterator
					attribute_iterator;
				typedef ::std::map< ::std::string, ::std::string>::const_iterator
					const_attribute_iterator;

				//	Constructors
				tag(const char* name_in, const char* content_in="")
					: name(name_in), content(content_in) {}

				::std::string serialize(const ::std::string& content_in) const { return serialize(content_in.c_str()); }
				::std::string serialize(const char* content_in = 0) const
				{
					::std::string buffer = "<";
					buffer += name;

					for(const_attribute_iterator it=attributes.begin(); it!=attributes.end(); it++)
						buffer += " " + it->first + "=\"" + it->second + ";\"";

					buffer += ">" + (content_in ? content_in : content);
					return buffer + "</" + name + ">";
				}
				operator ::std::string() const {
					return serialize();
				}
			};
		}
	}
}

#define DECL_CORNELIUS_HTML_TAG(NAME)	struct NAME : tag { NAME() : tag(#NAME){} };
#define DECL_CORNELIUS_HTML_TAG2(CLASS_NAME, TAG_NAME)	\
	struct CLASS_NAME : tag { CLASS_NAME() : tag(TAG_NAME){} };

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML__TAG_HPP__
