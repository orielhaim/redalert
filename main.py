import socketio

sio = socketio.Client()
sio.connect('https://redalert.orielhaim.repl.co')

@sio.on('alert')
def on_alert(data):
    print(data)

sio.wait()
