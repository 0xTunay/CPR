const express = require('express');
const path = require('path');
const app = express();


app.set('view engine', 'ejs');
app.use(express.static('public'))

app.use(express.static(path.join(__dirname, 'public')));

app.get('/', (req, res) => {
    res.render('index');
});

app.get('/', (req, res) => {
    res.render('install');
});

const PORT = 1111;

app.listen(PORT, () => {
    console.log(`Server ON: http://localhost:${PORT}`);
});
