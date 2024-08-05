const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('packages.db');

db.serialize(() => {
    db.run(`
        CREATE TABLE IF NOT EXISTS packages (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            version TEXT,
            description TEXT,
            author TEXT,
            dependencies TEXT,
            repository_url TEXT
        )
    `);
});
db.close();
