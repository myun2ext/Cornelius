#include <stdio.h>
#include <string>
#include "http/request.hpp"
#include "http/response.hpp"
#include "css.hpp"
#include "html.hpp"
#include "myun2/responder/listener.hpp"

#ifdef WIN32
	#include <winsock2.h>
	#include <io.h>
	#include <fcntl.h>
	#define SO_SYNCHRONOUS_NONALERT 0x20
	#define SO_OPENTYPE     0x7008
#endif

using namespace myun2;
using namespace myun2::cornelius;
using namespace myun2::responder;

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

int server();
int main()
{
#ifdef WIN32
	wsa_cleaner _wsa_cleaner;
	int sockopt = SO_SYNCHRONOUS_NONALERT;
	setsockopt(INVALID_SOCKET, SOL_SOCKET, SO_OPENTYPE, (char *)&sockopt, sizeof(sockopt));
#endif
	return server();
}

int proccess_request(FILE* in, FILE* out)
{
	char buffer[2046];
	fprintf(stderr, "GET / HTTP/1.1 ?\n");
	fprintf(stderr, fgets(buffer, sizeof(buffer), in));

	http::request r = http::request::parse(buffer);
	fprintf(stderr, "Method:   \"%s\"\n", r.method.c_str());
	fprintf(stderr, "Path:     \"%s\"\n", r.path.c_str());
	fprintf(stderr, "Protocol: \"%s\"\n", r.protocol.c_str());
	fprintf(stderr, "\n");

	::std::string content = get_html(r.path.c_str()).serialize().c_str();
	http::write_request(out, content);
	http::write_request(stdout, content);
	printf("\n");
	fflush(out);

	return 0;
}

int server_callback(struct sockaddr_in addr, responder::socket_desc::sock_type sock)
{
	FILE *fp;
#ifdef WIN32
	fp = fdopen(_open_osfhandle(sock, _O_RDWR || _O_TEXT), "r+");
#else
	fp = fdopen(sock, "r+");
#endif
	setvbuf(fp, NULL, _IONBF, 0);
	return proccess_request(fp, fp);
}

int server() {
	fprintf(stderr, "Server listened in 8000 port.\n");
	responder::listener server(19528, 10, server_callback);
	return 0;
}
