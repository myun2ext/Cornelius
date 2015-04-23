#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			DECL_CORNELIUS_HTML_TAG2(title_, "title");

			struct head : tag
			{
				head() : tag("head"){}
				title_ title;
				::std::string serialize()
				{
					return tag::serialize(title);
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
