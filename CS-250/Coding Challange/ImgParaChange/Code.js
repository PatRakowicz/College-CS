let images = [];
let currentImage = 0;

let colors = ['black', 'blue', 'green', 'orange'];
let currentColor = 0;

function image(img){
    currentImage += 1;
    currentImage &= images.length;
    img.src = images[currentImage];
}

function color(p) {
    currentColor += 1;
    currentColor %= colors.length;
    var p = document.getElementById('paragraph');
    p.style = "color:  " + colors[currentColor];
}