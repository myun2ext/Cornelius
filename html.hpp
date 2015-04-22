#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			template <unsigned char Version>
			struct document
			{
				::std::string serialize()
				{
					::std::string buffer = "<!DOCTYPE html><html>";
					return buffer + "</html>";
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML_HPP__
