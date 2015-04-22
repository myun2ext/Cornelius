#include <stdio.h>
#include <string>
#include "http/request.hpp"
#include "http/response.hpp"
#include "css.hpp"

using namespace myun2;
using namespace myun2::cornelius;

int main()
{
	http::request r = http::request::parse("GET / HTTP/1.1\r\n");

	printf("Method:   \"%s\"\n", r.method.c_str());
	printf("Path:     \"%s\"\n", r.path.c_str());
	printf("Protocol: \"%s\"\n", r.protocol.c_str());

	return 0;
}
