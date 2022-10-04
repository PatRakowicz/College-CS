function createArray(number) {
    var nums = []
    for (var i = 0; i < number; i++) {
        nums.push(i);
    }
    return nums;
}

function writeToConsole(numbers) {
    for (var i = 0; i < numbers.length; i++) {
        console.log(numbers[i])
    }
}

function writeNumToDoc(number) {
    document.write(number);
    document.write('<br>');
}

var n = prompt('Enter num');
var array = createArray(n);
writeToConsole(array);

array.forEach(function (number) {
    document.write(number);
    document.write('<br>');
});