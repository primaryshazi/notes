#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
    struct servent *server = getservbyname("ssh", "tcp");

    if (NULL == server)
    {
        puts("getservbyname() error");
        exit(EXIT_FAILURE);
    }

    /**
     * => ssh 22 tcp
     */
    printf("%s %d %s\n", server->s_name, htons(server->s_port), server->s_proto);

    return 0;
}
