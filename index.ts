import * as io from 'socket.io-client';

const socket = io('https://redalert.auto-host.xyz');

socket.on('alert', (json: string) => {
  const data = JSON.parse(json);
  console.log(data);
});
