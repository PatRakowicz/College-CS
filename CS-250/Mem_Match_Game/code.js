function table(row, col) {
    document.write('<table>');
    for (let r = 0; r < row; r++) {
        document.write('<tr>');
        for( let c = 0; c < col; c++) {
            document.write('<td>');
            // TODO | input Function
            //  Change 'text fill' with fnc randomizer
            document.write('text fill');
            document.write('</td>');
        }
        document.write('</tr>');
    }
}

function randomizer() {
    // TODO | Randomizer
    //  loop random location for text
    //  different everytime
}

let row = 3;
let col = 4;

table(row, col);
