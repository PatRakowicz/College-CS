// xV0lsfTcQzjDhjeKuoMcbkrKdyIZOmVNsKEvEYE2  (API Key)
// Pass Key to access API
// https://api.nasa.gov/planetary/apod?api_key=xV0lsfTcQzjDhjeKuoMcbkrKdyIZOmVNsKEvEYE2
function fx() {
    const dateControl = document.querySelector('input[type="date"]');
    let xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if(this.readyState === 4 && this.status === 200) {
            let obj = JSON.parse(this.responseText);

            document.getElementById('title').innerText = obj.title;
            document.getElementById('img').src = obj.url;
            document.getElementById('par').innerText = obj.explanation;
        } else {
            document.getElementById('title').innerText = "ERROR 404";
            document.getElementById('img').src = "#";
            document.getElementById('par').innerText = "borked";
        }
    };
    xhttp.open("GET", "https://api.nasa.gov/planetary/apod?api_key=xV0lsfTcQzjDhjeKuoMcbkrKdyIZOmVNsKEvEYE2&date=" + dateControl.value, true);
    xhttp.send();
}