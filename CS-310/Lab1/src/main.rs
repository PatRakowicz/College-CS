use rand::Rng;
use std::io;

fn main() {
    println!("Guess the Number");
    let number = rand::thread_rng().gen_range(1..=100);
    loop {
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Line was not read");

        let guess = guess.trim().parse().expect("Err not number");

        if number > guess {
            println!("Too High");
        } else if number < guess {
            println!("Too Low");
        } else {
            println!("Correct");
            break;
        }
    }
}
