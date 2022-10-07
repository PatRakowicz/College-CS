function table(array) {
    document.write('<table>');
    let incr = 0;
    for (let r = 0; r < 4; r++) {
        document.write('<tr>');
            document.write('<td>' + array[incr] + '</td>');
            incr += 1;

            document.write('<td>' + array[incr] + '</td>');
            incr += 1;

            document.write('<td>' + array[incr] + '</td>');
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

let array = ['one', '1', 'two', '2', 'three', '3', 'four', '4', 'five', '5', 'six', '6'];
let randomArray = randomizer(array);

// document.write('<p>' + randomizer(array) + '</p>');

table(randomArray);
