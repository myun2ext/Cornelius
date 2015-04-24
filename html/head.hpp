#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__

namespace myun2
{
	namespace cornelius
	{
		namespace html
		{
			namespace tags
			{
				struct head : tag
				{
					head() : tag("head"){}
					tags::title title;

					::std::string serialize() const
					{
						return tag::serialize(title);
					}
				};
			}
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTML__HEAD_HPP__
