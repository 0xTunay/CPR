const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const sqlite3 = require('sqlite3').verbose();

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.static('public'));

app.get('/', (req, res) => {
    res.render('index');
});

app.get('/menu', (req, res) => {
    res.render('menu');
});

const directoryPath = path.join(__dirname, 'date');
if (!fs.existsSync(directoryPath)) {
    fs.mkdirSync(directoryPath);
}

const db = new sqlite3.Database('packages.db');

// Старый маршрут для сохранения файла с уникальным именем
app.post('/save', (req, res) => {
    const formData = req.body;

    const fileName = `package_${Date.now()}.txt`;
    const filePath = path.join(directoryPath, fileName);

    const fileContent = `
        Name: ${formData.name}
        Version: ${formData.version}
        Description: ${formData.description}
        Author: ${formData.author}
        Dependencies: ${formData.dependencies}
        Repository URL: ${formData.repository_url}
`;

    fs.writeFile(filePath, fileContent, (err) => {
        if (err) {
            return res.status(500).send('Error writing file');
        }
        res.send('File created successfully');
    });
});

app.post('/save-custom', (req, res) => {
    const formData = req.body;

    const fileName = `${formData.name}.txt`; 
    const filePath = path.join(directoryPath, fileName);

    const fileContent = `
Name: ${formData.name}
Version: ${formData.version}
Description: ${formData.description}
Author: ${formData.author}
Dependencies: ${formData.dependencies}
Repository URL: ${formData.repository_url}
`;

    fs.writeFile(filePath, fileContent, (err) => {
        if (err) {
            return res.status(500).send('Error writing file');
        }
        
        db.run(`
            INSERT INTO packages (name, version, description, author, dependencies, repository_url)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        `, [formData.name, formData.version, formData.description, formData.author, formData.dependencies, formData.repository_url], (dbErr) => {
            if (dbErr) {
                return res.status(500).send('Error saving data to database');
            }
            res.send('File created and data saved to database successfully');
        });
    });
});

const PORT = 2222;

app.listen(PORT, () => {
    console.log(`Server ON: http://localhost:${PORT}`);
});
