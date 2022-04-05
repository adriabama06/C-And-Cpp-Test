const EventEmitter = require('events');
const net = require('net');

const server = net.createServer();

const events = new EventEmitter();

server.on('connection', async (socket) => {
    /**
     * @type {string}
     */
    const data = await new Promise(async (resolve) => {
        var d = "";
        const timeout = 1000;
        var lastTime = 0;
        var currentTime = lastTime;
        var doMilis = setInterval(async () => {
            currentTime += 100;
        }, 100);

        socket.on('data', async (buffer) => {
            lastTime = currentTime;
            d += buffer.toString();
        });
        socket.on('close', async () => {
            resolve(d);
        });
        while(true) {
            if((currentTime - lastTime) >= timeout) {
                clearInterval(doMilis);
                break;
            }            
            await new Promise(async (endSleep) => {
                setTimeout(endSleep, 300);
            });
        }
        resolve(d);
    });
    console.log(data);
    const headers = new Map();

});

server.listen(8081, '0.0.0.0', async () => {
    console.log('Server ready at localhost:8081');
});

events.on('http', async (/** @type {Map<string, string>} */ headers, /** @type {string} */ body) => {
    
});