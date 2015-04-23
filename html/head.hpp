#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			DECL_CORNELIUS_HTML_TAG2(title_, "title");

			struct head_ : tag
			{
				head_() : tag("head"){}
				title_ title;
				::std::string serialize() const
				{
					return tag::serialize(title);
				}
			};
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
