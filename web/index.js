const http = require('http');
const fs = require('fs');
const path = require('path');

const server = http.createServer((req, res) => {
    const filePath = path.join(__dirname, 'front', 'index.html');

    fs.readFile(filePath, (err, data) => {
        if (err) {
            console.error(`Error reading file: ${err}`);
            res.writeHead(500, {'Content-Type': 'text/plain; charset=utf-8'});
            res.end('500 Internal Server Error');
            return;
        }

        res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
        res.end(data);
    });
});

const PORT = 3000;
const HOST = 'localhost';

server.listen(PORT, HOST, () => {
    console.log(`Server ON: http://${HOST}:${PORT}`);
});
