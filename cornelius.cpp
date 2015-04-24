#include <stdio.h>
#include <string>
#include "http/request.hpp"
#include "http/response.hpp"
#include "css.hpp"
#include "html.hpp"

using namespace myun2;
using namespace myun2::cornelius;

::std::string print_css(const char* path)
{
	::std::string styles;
	css::selector style_h1 = css::selector("h1");
	style_h1["background-color"] = "#ffffff";
	styles += style_h1.serialize();
	return styles;
}

html::document<5> get_html(const char* path)
{
	html::document<5> doc;
	doc.head.title = "Title";
	doc.body += html::tags::h1("Title");
	return doc;
}

int main()
{
	char buffer[2046];
	fprintf(stderr, "GET / HTTP/1.1 ?\n");

	http::request r = http::request::parse(fgets(buffer, sizeof(buffer), stdin));
	fprintf(stderr, "Method:   \"%s\"\n", r.method.c_str());
	fprintf(stderr, "Path:     \"%s\"\n", r.path.c_str());
	fprintf(stderr, "Protocol: \"%s\"\n", r.protocol.c_str());
	fprintf(stderr, "\n");

	puts(get_html(r.path.c_str()).serialize().c_str());

	return 0;
}
