package main

import (
	"log"
	"github.com/googollee/go-socket.io"
)

func main() {
	client, err := socketio.NewClient(socketio.GetUrl("https://redalert.auto-host.xyz", nil))
	if err != nil {
		log.Fatal(err)
	}

	client.On("alert", func(data string) {
		log.Println(data)
	})

	select {}
}
