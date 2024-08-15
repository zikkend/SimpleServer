#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    while (true)
    {
        try {
        boost::asio::io_context io_context;

        // Create an acceptor to listen on port 12345
        size_t port = 2525;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

        std::cout << "Server is running on port " << port << ", waiting for connection..." << std::endl;

        // Wait for a client connection
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "Client connected!" << std::endl;

        // Receive data from the client
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data));
        std::cout << "Received from client: " << std::string(data, length) << std::endl;

        // Send response back to the client
        std::string response = "Hello from server!";
        boost::asio::write(socket, boost::asio::buffer(response));

        std::cout << "Response sent to client." << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    }
    
    return 0;
}
