const io = require('socket.io-client');
const socket = io('https://redalert.auto-host.xyz');

socket.on("alert", function(data) {
  console.log(data);
});
