fn main() {
    let ordinals = [
        "1st", "2nd",
        "3rd", "4th",
        "5th", "6th",
        "7th", "8th",
        "9th", "10th",
        "11th", "12th"];
    let gifts = [
        "A partridge in a pear tree",
        "Two tutle doves",
        "three French hens",
        "four calling birds",
        "five gold rings",
        "six geese a-laying",
        "seven swans a-swimming",
        "eight maids a-milking",
        "nine ladies dancing",
        "ten lords a-leaping",
        "eleven pipers piping",
        "twelve drummers drumming"
    ];

    for day in 0..11 {
        println!("On the {} day of Christmas my true love sent to me", ordinals[day]);

        for gift in (0..=day).rev() {
            if day > 0 && gift == 0 {
                println!("And {}", gifts[gift])
            } else {
                println!("{}", gifts[gift])
            }
        }
        println!()
    }
}

