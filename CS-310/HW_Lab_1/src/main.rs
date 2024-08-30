/*
Patrick Rakowicz
CS 310
HW1 and Lab1
*/

use rand::Rng;
use std::io;
use std::cmp::Ordering;

fn main() {
    println!("Guess the Number");

    let num2: f64 = rand::thread_rng().gen_range(1.0..10.0);
    let y: f64 = (num2 * 10.0).round() / 10.0;

    loop {
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Line was not read");

        let guess: f64 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Enter a valid number");
                continue;
            }
        };

        match guess.total_cmp(&y) {
            Ordering::Less => println!("Too small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("Correct! The number was {}", y);
                break;
            },
        }
    }
}

