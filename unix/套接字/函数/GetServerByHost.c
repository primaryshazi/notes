#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
    struct servent *server = getservbyport(htons(21), "tcp");

    if (NULL == server)
    {
        puts("getservbyport() error");
        exit(EXIT_FAILURE);
    }

    /**
     * => ftp 21 tcp
     */
    printf("%s %d %s\n", server->s_name, htons(server->s_port), server->s_proto);

    return 0;
}
