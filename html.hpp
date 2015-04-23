#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__

#include "html/tag.hpp"
#include "html/head.hpp"

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			struct body
			{
				::std::string serialize()
				{
					::std::string buffer = "<body>";
					return buffer + "</body>";
				}
			};

			template <unsigned char Version>
			struct document
			{
				head _head;
				body _body;

				::std::string serialize()
				{
					::std::string buffer = "<!DOCTYPE html><html>";
					buffer += _head.serialize();
					buffer += _body.serialize();
					return buffer + "</html>";
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
