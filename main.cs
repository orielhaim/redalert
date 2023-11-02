using System;
using Quobject.SocketIoClientDotNet.Client;

class Program
{
    static void Main()
    {
        var socket = IO.Socket("https://redalert.auto-host.xyz");

        socket.On("alert", (data) =>
        {
            Console.WriteLine(data);
        });

        socket.Connect();

        Console.ReadKey();
    }
}
