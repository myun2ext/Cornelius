#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			struct head
			{
				::std::string serialize()
				{
					::std::string buffer = "<head>";
					return buffer + "</head>";
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
