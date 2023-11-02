#include <iostream>
#include <sio_client.h>
#include <sio_message.h>

void on_alert(const sio::event& event) {
    sio::message::ptr message = event.get_message();
    if (message->get_flag() == sio::message::flag_object) {
        sio::object_message* obj = dynamic_cast<sio::object_message*>(message.get());
        if (obj) {
            std::string json = obj->get_map().at("data")->get_string();
            std::cout << json << std::endl;
        }
    }
}

int main() {
    sio::client client;
    client.connect("https://redalert.auto-host.xyz");
    client.socket()->on("alert", &on_alert);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Keep the program alive for a while

    return 0;
}
