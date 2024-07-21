const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');

const app = express();
const port = 3000;

// Настройка парсинга данных из формы
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Статические файлы
app.use(express.static('public'));

// Обработчик маршрута для корневого URL
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'public', 'form.html'));
});

// Создание каталога, если он не существует
const directoryPath = path.join(__dirname, 'files');
if (!fs.existsSync(directoryPath)) {
  fs.mkdirSync(directoryPath);
}

// Обработчик POST-запроса
app.post('/save', (req, res) => {
  const formData = req.body;

  // Формируем имя файла и путь
  const fileName = `package_${Date.now()}.txt`;
  const filePath = path.join(directoryPath, fileName);

  // Формируем содержимое файла
  const fileContent = `
Name: ${formData.name}
Version: ${formData.version}
Description: ${formData.description}
Author: ${formData.author}
Dependencies: ${formData.dependencies}
Project Directory: ${formData.files}
Repository URL: ${formData.repository_url}
`;

  // Записываем данные в файл
  fs.writeFile(filePath, fileContent, (err) => {
    if (err) {
      return res.status(500).send('Error writing file');
    }
    res.send('File created successfully');
  });
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
