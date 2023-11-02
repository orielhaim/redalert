require 'socket.io-client-simple'

socket = SocketIO::Client::Simple.connect 'https://redalert.auto-host.xyz'

socket.on :alert do |data|
  puts data
end

socket.connect
