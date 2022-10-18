let images = ['a.png', 'b.png', 'c.png']
let currentImage = 0;

let colors = ['black', 'blue', 'green', 'orange']
let currentColor = 0;


function image() {
    currentImage += 1;
    currentImage %= images.length;

    img.src = images[currentImage];
}