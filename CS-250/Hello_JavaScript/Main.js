var x;
var count = 0;

do {
    x = prompt('enter a non-zero positive int');
} while (x <= 0);

document.write('<h1> Factors of ', x, ':</h1>');

for (var i = 1; i <= x; i++) {
    if (x % i == 0) {
        document.write('<p>', i, '</p>');
        count++;
    }
}

if (count <= 2) {
    document.write('<h2>', x, ' is a prime</h2>')
} else {
    document.write('<h2>', x, ' is NOT a prime</h2>')
}