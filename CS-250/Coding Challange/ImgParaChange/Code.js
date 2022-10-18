let colors = ['black', 'blue', 'green', 'orange']
let currentColor = 0;


function color(p) {
    currentColor += 1;
    currentColor %= colors.length;
    var p = document.getElementById('paragraph');
    p.style = "color:  " + colors[currentColor];
}