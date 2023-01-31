// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <zmq.hpp>
#include <iostream>

#include <chrono>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>

int main()
{
    zmq::context_t ctx(2);
    zmq::socket_t socket(ctx, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");

    while (true) {
        std::cout << "Awaiting request...\n";

        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Receive Hello\n";

        //do work
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        zmq::message_t reply(5);
        std::memcpy(reply.data(), "World", 5);
        socket.send(reply, zmq::send_flags::none);
    }




    std::getchar();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
