use std::{env, fs, process};
use crate::lib::Config;
use crate::lib::run;

mod lib;
fn main() {
    // let args: Vec<String> = env::args().collect();

    let conf = Config::parse_args(env::args()).unwrap_or_else(|err| {
        println!("problem parsing  args: {err}");
        process::exit(1)
    });

    if let Err(err) = run(conf) {
        println!("Error: {err}");
        process::exit(1);
    }
}
