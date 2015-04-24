#ifndef __MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__
#define __MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__

#include <stdio.h>
#include <string>
#include <map>

namespace myun2
{
	namespace cornelius
	{
		namespace http
		{
			struct response_status {
				const char* protocol;
				unsigned short status;
				const char* reason;
			};

			int send_response_status_line(
					const char* protocol, unsigned short status, const char* reason,
					FILE* fp)
			{
				return fprintf(fp, "%s %d %s\r\n", protocol, status, reason);
			}

			typedef ::std::map<const char*, ::std::string> attributes;
			typedef attributes::const_iterator const_attribute_iterator;

			int send_response(FILE* fp,
				const char* protocol, unsigned short status, const char* reason,
				const attributes& al,
				const void* data, unsigned long length)
			{
				int sent_length = 0;
				sent_length = send_response_status_line(protocol, status, reason, fp);
				for(const_attribute_iterator it=al.begin(); it!=al.end(); it++)
					sent_length += fprintf(fp, "%s: %s\r\n", it->first, it->second.c_str());
				sent_length += fprintf(fp, "Content-Length: %d\r\n\r\n", length);
				return sent_length + fwrite(data, length, 1, fp);
			}

			int write_request(FILE *fp, const void* s, unsigned long length,
				unsigned short status=200, const char* reason = "OK", const char* protocol = "HTTP/1.1",
				attributes al=attributes())
			{
				return send_response(fp, protocol, status, reason, al, s, length);
			}
			int write_request(FILE *fp, const ::std::string& s, unsigned short status=200,
				const char* reason = "OK", const char* protocol = "HTTP/1.1", attributes al=attributes())
			{
				return send_response(fp, protocol, status, reason, al, s.c_str(), s.size());
			}
		}
	}
}

#endif//__MYUN2_GITHUB_COM__CORNELIUS__HTTP__RESPONSE_HPP__
