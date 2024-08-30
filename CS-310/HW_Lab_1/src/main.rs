use rand::Rng;
use std::io;
use std::cmp::Ordering;

fn main() {
    println!("Guess the Number");
    let number = rand::thread_rng().gen_range(1..=100);
    loop {
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Line was not read");

        // let guess = guess.trim().parse().expect("Err not number");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Enter Number");
                continue;
            }
        };

        match guess.cmp(&number) {
            Ordering::Less => println!("too small"),
            Ordering::Greater => println!("Too Big"),
            Ordering::Equal => {
                println!("Correct!");
                break;
            },
        }
    }
}
