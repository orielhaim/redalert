import io.socket.client.IO;
import io.socket.client.Socket;
import io.socket.emitter.Emitter;

public class Main {
    public static void main(String[] args) {
        try {
            IO.Options opts = new IO.Options();
            opts.forceNew = true;
            Socket socket = IO.socket("https://redalert.auto-host.xyz", opts);

            socket.on("alert", new Emitter.Listener() {
                @Override
                public void call(Object... args) {
                    System.out.println(args[0]);
                }
            });

            socket.connect();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
