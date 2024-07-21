document.getElementById('repository_url').addEventListener('input', function() {
    const urlField = document.getElementById('repository_url');
    const errorField = document.getElementById('url-error');
    const urlValue = urlField.value;

    if (urlValue && !urlValue.startsWith('http://') && !urlValue.startsWith('https://')) {
        errorField.textContent = 'Неправильная ссылка';
        errorField.style.color = 'red';
    } else {
        errorField.textContent = '';
    }
});

document.getElementById('install').addEventListener('click', function(event) {
    const fields = ['name', 'version', 'description', 'author', 'dependencies', 'files', 'repository_url'];
    let allFieldsFilled = true;

    fields.forEach(field => {
        const fieldElement = document.getElementById(field);
        if (fieldElement && !fieldElement.value) {
            allFieldsFilled = false;
        }
    });

    if (!allFieldsFilled) {
        event.preventDefault();
        this.style.backgroundColor = 'red';
    } else {
        this.style.backgroundColor = '';
        saveDataToFile();
    }
});

function saveDataToFile() {
    const data = {
        name: document.getElementById('name').value,
        version: document.getElementById('version').value,
        description: document.getElementById('description').value,
        author: document.getElementById('author').value,
        dependencies: document.getElementById('dependencies').value,
        files: document.getElementById('files').value,
        repository_url: document.getElementById('repository_url').value
    };

    fetch('/save', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(response => response.text())
    .then(responseText => {
        alert(responseText);
    })
    .catch(error => {
        console.error('Error:', error);
    });
}
