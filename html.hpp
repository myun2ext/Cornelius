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
			struct doctype;

			template <>
			struct doctype<4> { const char* _; doctype():_(
				"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\""){}
			};

			template <>
			struct doctype<5> { const char* _; doctype():_("<!DOCTYPE html>"){} };


			template <unsigned char Version>
			struct document : tag
			{
				document() : tag("html"){}
				tags::head head;
				tags::body body;

				::std::string serialize() const
				{
					::std::string doctype_s = doctype<Version>()._;
					return doctype_s + tag::serialize(head.serialize() + body.serialize());
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
