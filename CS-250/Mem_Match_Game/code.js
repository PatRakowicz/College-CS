function table(array) {
    document.write('<table>');
    let incr = 0;
    for (let r = 0; r < 4; r++) {
        document.write('<tr>');
        document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
        incr += 1;

        document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
        incr += 1;

        document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
        incr += 1;
        document.write('</td>');
    }
}

function randomizer(array) {
    let length = array.length;

    while (length != 0) {
        let randId = Math.floor(Math.random() * length);
        length -= 1;
        let temp = array[length];
        array[length] = array[randId];
        array[randId] = temp;
    }
    return array;
}

let array = [
        'Blue.jpg', 'Blue.jpg', 'Green.jpg', 'Green.jpg',
        'Red.jpg', 'Red.jpg', 'Yellow.jpg', 'Yellow.jpg',
        'Purple.jpg', 'Purple.jpg', 'Orange.jpg', 'Orange.jpg'];

let randomArray = randomizer(array);
table(randomArray);
