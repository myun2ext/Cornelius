#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__

#include "html/tag.hpp"
#include "html/tags.hpp"
#include "html/head.hpp"

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			template <unsigned char Version>
			struct doctype { static const char* _ = "<!DOCTYPE html>"; };

			template <unsigned char Version>
			struct document : tag
			{
				document() : tag("html"){}
				head_ head;
				body_ body;

				::std::string serialize() const
				{
					::std::string buffer = doctype<Version>::_;
					return serialize(buffer + head.serialize() + body.serialize());
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
