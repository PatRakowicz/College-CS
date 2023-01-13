window.onload = function () {
    let xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if(this.readyState === 4 && this.status === 200) {
            let obj = JSON.parse(this.responseText);
            console.log(obj);

            let src = obj.img;
            document.getElementById('title').innerText = obj.title;
            document.getElementsByTagName('img').src = src;
        }
    };
    xhttp.open("GET", "https://xkcd.com/info.0.json", true);
    xhttp.send();
}

// Get this plugin while working on this class
// moseif origin and cors changer