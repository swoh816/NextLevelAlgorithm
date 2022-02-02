// Create bots for stock trades and for copilot
function download(url, dest) {
    return new Promise((resolve, reject) => {
        const file = fs.createWriteStream(dest);
        const request = https.get(url, response => {
            if (response.statusCode !== 200) {
                reject(new Error(`Request Failed.\nStatus Code: ${response.statusCode}`));
            }
            response.pipe(file);
            file.on('finish', () => {
                file.close(resolve);
            });
        });
        request.on('error', error => {
            fs.unlink(dest);
            reject(error);
        });
    });
}

