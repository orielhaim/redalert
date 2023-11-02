import socketio

sio = socketio.Client()
sio.connect('https://redalert.auto-host.xyz')

@sio.on('alert')
def on_alert(data):
    print(data)

sio.wait()
