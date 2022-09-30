/*
var x = prompt('Enter Num: ');

let bool;

while (x < 0 && x !== 0) {
    x = prompt("Empter Pos Number: ");
    if (x < 0 && x !== 0) {
        document.write("<ul>");
        for (var i = 0; i < x; i++) {
            console.log(i);
            document.write("<li>" + i + "</li>");
        }
        document.write("</ul>");
    } else {
        console.log('error with wile loop');
    }
}
*/

var x = prompt('Enter a num');

// if (x < 0) {
//     x   = prompt('Enter Pos Num');
// } else {
//     document.write("<ul>");
//     for (var i = 0; i < x; i++) {
//         console.log(i);
//         document.write("<li>" + i + "</li>");
//     }
//     document.write("<ul>");

while (x < 0 && x != 0) {
    x = prompt('Enter Pos Number');
}

for (let i = 0; i <= x; i++) {
    let flag = 0;

    // looping through 2 to user input number
    for (let j = 2; j < i; j++) {
        if (i % j == 0) {
            flag = 1;
            break;
        }
    }

    // if number greater than 1 and not divisible by other numbers
    document.write("<ul>");
    if (i > 1 && flag == 0) {
        console.log(i);
        document.write("<li>" + i + "</li>");
    }
    document.write("<ul>");
}


/*
// program to print prime numbers between the two numbers

// take input from the user
const lowerNumber = parseInt(prompt('Enter lower number: '));
const higherNumber = parseInt(prompt('Enter higher number: '));

console.log(`The prime numbers between ${lowerNumber} and ${higherNumber} are:`);

// looping from lowerNumber to higherNumber
for (let i = lowerNumber; i <= higherNumber; i++) {
    let flag = 0;

    // looping through 2 to user input number
    for (let j = 2; j < i; j++) {
        if (i % j == 0) {
            flag = 1;
            break;
        }
    }

    // if number greater than 1 and not divisible by other numbers
    if (i > 1 && flag == 0) {
        console.log(i);
    }
}
*/
