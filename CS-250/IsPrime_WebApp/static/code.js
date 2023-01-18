let link = document.getElementById('link');

window.onload = function() {
    let val = 1;
    link.innerHTML = "Is " + val + " a prime?";
    link.href = "http://127.0.0.1:5000/IsPrime_WebApp/isPrime/" + val;
}

function sliderChange(val) {
    link.innerHTML = "Is " + val + " a prime?";
    link.href = "http://127.0.0.1:5000/IsPrime_WebApp/isPrime/" + val;
}
