#include "stresstesting.h"
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int http_recv(int s, char *buf, int len)
{
	return read(s, buf, len);
}
int http_send(int s, const char *buf, int len)
{
	return write(s, buf, len);
}
int http_puts(int s, const char *buf)
{
	return http_send(s, buf, strlen(buf));
}
/*
 * parser GET url from @buf eg: "GET /test.html HTTP/1.1"
 * */
static char *parser_http_get_url(char *buf, char *path)
{
	char *p, *e;
	p = buf + 4;		// @buf = "GET /test.html HTTP/1.1"
	e = strchr(p, ' ');
	*e = '\0';
	strcpy(path, p);	// @path = "/test.html"
	*e = ' ';
	return path;
}
static int http_get(int s, char *path, int path_len)
{
	int fd, len;
	char buf[4096];

	if (path_len == 0)
		goto not_found;
	fprintf(stderr, "PTM:%s %d(%s)\n", __FUNCTION__, __LINE__, path);
	if (strcmp(path, "/") == 0)
		strcpy(path, "index.html");
	fprintf(stderr, "PTM:%s %d\n", __FUNCTION__, __LINE__);
	if (*path == '/')
		path++;
	if ((fd = open(path, O_RDONLY)) == -1)
		goto not_found;

	http_puts(s, "HTTP/1.1 200 OK\r\n");
	http_puts(s, "Connection: close\r\n");
	http_puts(s, "Content-Type: text/html\r\n\r\n");
	//sprintf(buf, "Content-Length: %d\r\n\r\n", 17);
	//http_puts(s, buf);
	while ((len = read(fd, buf, sizeof(buf))) > 0) {
		http_send(s, buf, len);
	}
	close(fd);
	return 0;
not_found:
	http_puts(s, "HTTP/1.1 404 Not Found\r\n\r\n");
	return -1;
}
/*
 *  Parsring @url and feedback HTTP header/bodys to @stderr.
 *  Return 0 success, -1 failure.
 */
#define MAX_PATH_LEN	24
int StressTesting::testStressTesting(char *url, int path_len)
{
    char path[MAX_PATH_LEN];
    
    //fprintf(stderr, "PTM:%s %d, url:%s, n = %d\n", __FUNCTION__, __LINE__, url, path_len);
    if (path_len >  MAX_PATH_LEN)
        return -1;
    if (url == NULL)
        return -1;
    strncpy(path, url, MAX_PATH_LEN - 1);
    return http_get(2 /* @stderr */, path, path_len);
}
