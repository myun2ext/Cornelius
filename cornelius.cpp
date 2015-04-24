#include <stdio.h>
#include <string>
#include "http/request.hpp"
#include "http/response.hpp"
#include "css.hpp"
#include "html.hpp"

using namespace myun2;
using namespace myun2::cornelius;

int main()
{
	http::request r = http::request::parse("GET / HTTP/1.1\r\n");

	printf("Method:   \"%s\"\n", r.method.c_str());
	printf("Path:     \"%s\"\n", r.path.c_str());
	printf("Protocol: \"%s\"\n", r.protocol.c_str());

	//-- CSS Rendering Section ----------------------------------------
	printf("\n");
	css::selector style_h1 = css::selector("h1");
	style_h1["background-color"] = "#ffffff";
	printf("CSS:\n%s\n", style_h1.serialize().c_str());

	//-- HTML Rendering Section ---------------------------------------
	printf("\n");
	html::document<5> doc;
	doc.head.title = "Title";
	doc.body = html::tags::h1("Title");
	printf("HTML:\n%s\n", doc.serialize().c_str());

	return 0;
}
