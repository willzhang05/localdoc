#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

using std::cout;
using std::endl;

int main() {
    int status;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;
    memset(&host_info, 0, sizeof host_info);
    cout << "Setting up structs" << endl;
    host_info.ai_family = AF_UNSPEC;
    host_info.ai_socktype = SOCK_STREAM;
    status = getaddrinfo("www.google.com", "80", &host_info, &host_info_list);
    if(status = 0) cout << "getaddrinfo error" << gai_strerror(status); 
    cout << "Creating a socket" << endl;
    int socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol);
    if(socketfd == -1) cout << "socket error ";
    cout << "Connecting..." << endl;
    status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if(status == -1) cout << "connect error ";
    cout << "sending..." << endl;
    char *msg = "GET / HTTP/1.1\nhost: www.google.com\n\n";
    int len;
    ssize_t bytes_sent;
    len = strlen(msg);
    bytes_sent = send(socketfd, msg, len, 0);
    cout << "Waiting to receive data..." << endl;
    ssize_t bytes_received;
    char incoming_data_buffer[1000];
    bytes_received = recv(socketfd, incoming_data_buffer, 1000, 0);

    if(bytes_received == 0) cout << "Host shut down." << endl;
    if(bytes_received == -1) cout << "Receive error!" << endl;
    cout << bytes_received << " bytes received:" << endl;
    cout << incoming_data_buffer << endl;
    
    return 0;
}
