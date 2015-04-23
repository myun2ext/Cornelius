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
			struct document
			{
				head_ head;
				body_ body;

				::std::string serialize() const
				{
					::std::string buffer = "<!DOCTYPE html><html>";
					buffer += head.serialize();
					buffer += body.serialize();
					return buffer + "</html>";
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
